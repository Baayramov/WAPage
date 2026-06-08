#include "AudioSpeedProcessor.h"
#include "utils/Logger.h"

#include <QAudioBuffer>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDataStream>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>
#include <QPointer>
#include <QThreadPool>
#include <QTimer>
#include <QUrl>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

namespace {

// Fixed cache format. Mono 22050 Hz Int16 — small files, plenty for voice
// and acceptable for music. Picked for compatibility with Qt MediaPlayer
// reading WAV PCM on every Windows version we ship to.
constexpr int kSampleRate = 22050;
constexpr int kChannels   = 1;

// Decode `path` synchronously to mono int16 PCM at kSampleRate using
// Qt's bundled FFmpeg backend. Drives a local QEventLoop so it is safe to
// call from a QThreadPool worker (no enclosing event loop required).
QByteArray decodePcm(const QString& path)
{
    if (path.isEmpty() || !QFile::exists(path)) return {};

    QAudioFormat fmt;
    fmt.setSampleRate(kSampleRate);
    fmt.setChannelCount(kChannels);
    fmt.setSampleFormat(QAudioFormat::Int16);

    QAudioDecoder decoder;
    decoder.setAudioFormat(fmt);

    QByteArray pcm;
    pcm.reserve(256 * 1024);

    QEventLoop loop;
    bool finishedOnce = false;

    QObject::connect(&decoder, &QAudioDecoder::bufferReady, &loop, [&]() {
        const QAudioBuffer buf = decoder.read();
        if (!buf.isValid()) return;
        pcm.append(reinterpret_cast<const char*>(buf.constData<char>()),
                   buf.byteCount());
    });
    QObject::connect(&decoder, &QAudioDecoder::finished, &loop, [&]() {
        if (finishedOnce) return;
        finishedOnce = true;
        loop.quit();
    });
    QObject::connect(&decoder,
                     qOverload<QAudioDecoder::Error>(&QAudioDecoder::error),
                     &loop, [&](QAudioDecoder::Error) { loop.quit(); });

    QTimer timeout;
    timeout.setSingleShot(true);
    QObject::connect(&timeout, &QTimer::timeout, &loop, &QEventLoop::quit);
    timeout.start(30000);

    decoder.setSource(QUrl::fromLocalFile(path));
    decoder.start();
    loop.exec();
    decoder.stop();

    return pcm;
}

// WSOLA: Waveform Similarity Overlap-Add. Operates on int16 mono PCM at
// kSampleRate. Preserves pitch by overlapping windowed input frames at a
// constant *output* hop while picking the input position whose first
// hopOut samples best match the output's tail (normalized cross-correlation).
QByteArray wsolaStretch(const QByteArray& pcmIn, qreal rate)
{
    if (qFuzzyCompare(rate, qreal(1.0)) || pcmIn.isEmpty()) return pcmIn;

    const int16_t* in = reinterpret_cast<const int16_t*>(pcmIn.constData());
    const int N = pcmIn.size() / 2;

    // Frame parameters tuned for speech/music at 22050 Hz.
    const int frameSize  = kSampleRate * 60 / 1000;     // 60 ms (1323 samples)
    const int hopOut     = frameSize / 2;               // 30 ms (50% overlap)
    const int hopInIdeal = qRound(hopOut * rate);       // 1.5x: 991, 2x: 1322
    const int searchHalf = kSampleRate * 15 / 1000;     // ±15 ms search window

    if (N < frameSize + 2 * searchHalf) return pcmIn;

    // Hann window — at 50% overlap it sums to a constant 1.0 in steady state
    // (perfect-reconstruction property), so unity gain after OLA.
    std::vector<float> w(frameSize);
    for (int i = 0; i < frameSize; ++i) {
        w[i] = 0.5f - 0.5f * std::cos(2.0f * float(M_PI) * float(i) /
                                       float(frameSize - 1));
    }

    // Output accumulator (float for OLA summation; converted to int16 at end).
    std::vector<float> out;
    out.reserve(static_cast<size_t>(double(N) / rate) + frameSize);

    // Seed: first frame from input start, windowed.
    for (int i = 0; i < frameSize; ++i) {
        out.push_back(float(in[i]) * w[i]);
    }

    // Critical: drive the analysis pointer by the IDEAL hop, not by `bestPos`.
    // If we used `inPos = bestPos`, the cross-correlation tends to land near
    // the early edge of the search window for periodic speech (best pitch
    // continuity), which shrinks the effective input advance and ruins the
    // stretch ratio (observed: 1.5x produced ~1.0x output). With a fixed
    // analysisPos += hopInIdeal, the output length is guaranteed to be
    // approximately N / rate; the search only chooses *which* nearby frame
    // to copy for the best waveform similarity at the OLA seam.
    int analysisPos = hopInIdeal;

    while (true) {
        const int searchStart = std::max(0, analysisPos - searchHalf);
        const int searchEnd   = std::min(N - frameSize, analysisPos + searchHalf);
        if (searchEnd <= searchStart) break;

        // Output tail (last hopOut floats) is the anchor we want the next
        // frame's first hopOut samples to align with.
        const int outTailStart = static_cast<int>(out.size()) - hopOut;

        int    bestPos  = searchStart;
        double bestCorr = -1e30;

        for (int p = searchStart; p <= searchEnd; ++p) {
            double dot    = 0.0;
            double inNorm = 0.0;
            for (int i = 0; i < hopOut; ++i) {
                const double s = double(in[p + i]);
                dot    += s * double(out[outTailStart + i]);
                inNorm += s * s;
            }
            // Normalize by input frame magnitude to avoid bias toward loud
            // regions. Output-tail magnitude is constant across candidates so
            // we don't need to divide by it.
            const double corr = dot / (std::sqrt(inNorm) + 1e-9);
            if (corr > bestCorr) {
                bestCorr = corr;
                bestPos  = p;
            }
        }

        // Overlap-add the new windowed frame: first hopOut samples sum into
        // the existing output tail, the rest extends the output stream.
        for (int i = 0; i < hopOut; ++i) {
            out[outTailStart + i] += float(in[bestPos + i]) * w[i];
        }
        for (int i = hopOut; i < frameSize; ++i) {
            out.push_back(float(in[bestPos + i]) * w[i]);
        }

        analysisPos += hopInIdeal;
    }

    // Float -> int16 with hard clipping (Hann at 50% overlap keeps level
    // ≈unity in steady state, so clipping is rare except on already-loud
    // sources).
    QByteArray pcmOut;
    pcmOut.resize(static_cast<int>(out.size()) * 2);
    int16_t* out16 = reinterpret_cast<int16_t*>(pcmOut.data());
    for (size_t i = 0; i < out.size(); ++i) {
        float v = out[i];
        if (v >  32767.f) v =  32767.f;
        if (v < -32768.f) v = -32768.f;
        out16[i] = static_cast<int16_t>(v);
    }
    return pcmOut;
}

// Minimal RIFF/WAVE writer for 16-bit PCM. We only ever produce one format,
// so the chunk layout is hard-coded.
bool writeWav(const QString& path, const QByteArray& pcm, int sr, int ch)
{
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;

    QDataStream s(&f);
    s.setByteOrder(QDataStream::LittleEndian);

    const quint32 dataSize   = static_cast<quint32>(pcm.size());
    const quint32 chunkSize  = 36 + dataSize;
    const quint32 byteRate   = static_cast<quint32>(sr) * ch * 2;
    const quint16 blockAlign = static_cast<quint16>(ch * 2);

    f.write("RIFF", 4);
    s << chunkSize;
    f.write("WAVE", 4);
    f.write("fmt ", 4);
    s << quint32(16);             // PCM fmt chunk size
    s << quint16(1);              // format = PCM
    s << quint16(ch);
    s << quint32(sr);
    s << byteRate;
    s << blockAlign;
    s << quint16(16);             // bits per sample
    f.write("data", 4);
    s << dataSize;
    if (!pcm.isEmpty()) f.write(pcm);
    f.close();
    return true;
}

} // namespace

// ─────────────────────────────────────────────────────────────────────────

AudioSpeedProcessor::AudioSpeedProcessor(QObject* parent)
    : QObject(parent)
{
}

void AudioSpeedProcessor::setCacheDir(const QString& dir)
{
    m_cacheDir = dir;
    if (!dir.isEmpty()) {
        QDir().mkpath(dir);
    }
}

QString AudioSpeedProcessor::computeCachePath(const QString& audioPath, qreal rate) const
{
    if (m_cacheDir.isEmpty() || audioPath.isEmpty()) return {};
    // Cache version. Bump whenever the WSOLA implementation changes in a way
    // that affects output (so stale, buggy files get ignored automatically).
    //   v1 — initial release: shipped with broken stretch ratio at 1.5x.
    //   v2 — fixed analysisPos drift: ratio now exact for all rates.
    constexpr const char* kCacheVersion = "v2";
    const QByteArray hash = QCryptographicHash::hash(
        audioPath.toUtf8(), QCryptographicHash::Sha1).toHex().left(16);
    QString rateStr = QString::number(rate, 'f', 2);
    rateStr.replace('.', '_');
    return m_cacheDir + "/" + QString::fromLatin1(hash) + "_"
           + kCacheVersion + "_" + rateStr + ".wav";
}

QString AudioSpeedProcessor::cachedPathIfExists(const QString& audioPath, qreal rate) const
{
    const QString p = computeCachePath(audioPath, rate);
    if (p.isEmpty()) return {};
    return QFile::exists(p) ? p : QString();
}

void AudioSpeedProcessor::requestStretched(const QString& audioPath, qreal rate)
{
    if (m_cacheDir.isEmpty() || audioPath.isEmpty()) return;
    if (qFuzzyCompare(rate, qreal(1.0))) return;     // 1x = original; nothing to do

    const QString cachePath = computeCachePath(audioPath, rate);
    const QString key = audioPath + ":" + QString::number(rate, 'f', 2);

    // Already on disk → fire signal asynchronously to keep call semantics
    // consistent (caller receives ready() via the queued slot, never inline).
    if (QFile::exists(cachePath)) {
        QPointer<AudioSpeedProcessor> selfGuard(this);
        QMetaObject::invokeMethod(qApp, [selfGuard, audioPath, rate, cachePath]() {
            if (auto* self = selfGuard.data()) {
                emit self->ready(audioPath, rate, cachePath);
            }
        }, Qt::QueuedConnection);
        return;
    }

    {
        QMutexLocker lk(&m_mutex);
        if (m_inFlight.contains(key)) return;
        m_inFlight.insert(key);
    }

    QPointer<AudioSpeedProcessor> selfGuard(this);
    QThreadPool::globalInstance()->start(
        [selfGuard, audioPath, rate, cachePath, key]() {
            QString result;
            if (auto* self = selfGuard.data()) {
                result = self->processSync(audioPath, rate, cachePath);
            }

            // Hop back to the UI thread for bookkeeping + signal emit.
            QMetaObject::invokeMethod(qApp,
                [selfGuard, audioPath, rate, result, key]() {
                    auto* self = selfGuard.data();
                    if (!self) return;
                    {
                        QMutexLocker lk(&self->m_mutex);
                        self->m_inFlight.remove(key);
                    }
                    if (!result.isEmpty()) {
                        emit self->ready(audioPath, rate, result);
                    }
                }, Qt::QueuedConnection);
        });
}

QString AudioSpeedProcessor::processSync(const QString& audioPath,
                                         qreal rate,
                                         const QString& outPath) const
{
    Logger::info(QString("[AUDIO-SPEED] start path=%1 rate=%2")
                     .arg(QFileInfo(audioPath).fileName())
                     .arg(rate));

    const QByteArray pcm = decodePcm(audioPath);
    if (pcm.size() < 200) {
        Logger::warn(QString("[AUDIO-SPEED] decode FAIL bytes=%1 path=%2")
                         .arg(pcm.size()).arg(audioPath));
        return {};
    }

    const QByteArray stretched = wsolaStretch(pcm, rate);
    if (stretched.isEmpty()) {
        Logger::warn("[AUDIO-SPEED] wsola FAIL");
        return {};
    }

    if (!writeWav(outPath, stretched, kSampleRate, kChannels)) {
        Logger::warn(QString("[AUDIO-SPEED] write FAIL path=%1").arg(outPath));
        return {};
    }

    Logger::info(QString("[AUDIO-SPEED] done in=%1B out=%2B file=%3")
                     .arg(pcm.size())
                     .arg(stretched.size())
                     .arg(QFileInfo(outPath).fileName()));
    return outPath;
}
