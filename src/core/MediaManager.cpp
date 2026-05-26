#include "MediaManager.h"
#include "utils/Logger.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDirIterator>
#include <QHash>
#include <QImage>
#include <QUrl>
#include <QEventLoop>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoSink>
#include <QVideoFrame>
#include <QAudioDecoder>
#include <QAudioBuffer>
#include <QAudioFormat>

MediaManager::MediaManager(const QString& mediaStorageDir)
    : m_storageDir(mediaStorageDir)
{
    QDir().mkpath(m_storageDir);
}

QString MediaManager::chatMediaDir(int chatId) const
{
    return m_storageDir + "/" + QString::number(chatId);
}

// Index the files in the Extract folder once
static QHash<QString, QString> buildExtractFileIndex(const QString& rootDir)
{
    QHash<QString, QString> index;
    QDirIterator it(rootDir, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        const QString path = it.next();
        const QString key = it.fileInfo().fileName().toLower();
        // Save the first found in files with the same name (deterministic behavior)
        if (!index.contains(key)) {
            index.insert(key, path);
        }
    }
    return index;
}

void MediaManager::copyMediaToStorage(QList<Message>& messages,
                                       const QString&  tempExtractDir,
                                       int             chatId,
                                       const std::function<void(qint64 processedBytes,
                                                                int processedItems,
                                                                int totalItems)>& progressCallback)
{
    const QString destDir = chatMediaDir(chatId);
    QDir().mkpath(destDir);
    const QHash<QString, QString> fileIndex = buildExtractFileIndex(tempExtractDir);

    int copied = 0;
    int notFound = 0;
    int totalMediaItems = 0;
    int processedMediaItems = 0;
    qint64 processedBytes = 0;

    for (const auto& msg : messages) {
        if (!msg.mediaPath.isEmpty()) {
            totalMediaItems++;
        }
    }

    auto emitProgress = [&]() {
        if (progressCallback) {
            progressCallback(processedBytes, processedMediaItems, totalMediaItems);
        }
    };

    Logger::info(QString("Media index ready: %1 files").arg(fileIndex.size()).toUtf8().constData());

    for (auto& msg : messages) {
        if (msg.mediaPath.isEmpty()) continue;

        const QString fileName = QFileInfo(msg.mediaPath).fileName();
        if (fileName.isEmpty()) {
            msg.mediaPath.clear();
            msg.mediaThumbnailPath.clear();
            msg.waveform.clear();
            notFound++;
            processedMediaItems++;
            emitProgress();
            continue;
        }
        const QString dstPath  = destDir + "/" + fileName;

        // If it already exists, update the path and prepare a thumbnail for the video
        if (QFile::exists(dstPath)) {
            msg.mediaPath = dstPath;
            if (msg.type == MessageType::Video) {
                msg.mediaThumbnailPath = generateVideoThumbnail(dstPath, chatId);
            } else {
                msg.mediaThumbnailPath.clear();
            }
            msg.waveform.clear();
            processedBytes += QFileInfo(dstPath).size();
            processedMediaItems++;
            emitProgress();
            continue;
        }

        const QString srcPath = fileIndex.value(fileName.toLower());

        if (srcPath.isEmpty() || !QFile::exists(srcPath)) {
            Logger::warn(QString("Media not found: %1").arg(fileName).toUtf8().constData());
            msg.mediaPath.clear();
            msg.mediaThumbnailPath.clear();
            msg.waveform.clear();
            notFound++;
            processedMediaItems++;
            emitProgress();
            continue;
        }

        if (QFile::copy(srcPath, dstPath)) {
            msg.mediaPath = dstPath;
            if (msg.type == MessageType::Video) {
                msg.mediaThumbnailPath = generateVideoThumbnail(dstPath, chatId);
            } else {
                msg.mediaThumbnailPath.clear();
            }
            msg.waveform.clear();
            copied++;
            processedBytes += QFileInfo(dstPath).size();
        } else {
            Logger::error(QString("Failed to copy media: %1").arg(srcPath).toUtf8().constData());
            msg.mediaPath.clear();
            msg.mediaThumbnailPath.clear();
            msg.waveform.clear();
        }

        processedMediaItems++;
        emitProgress();
    }

    Logger::info(QString("Media: %1 copied, %2 missing")
                 .arg(copied).arg(notFound).toStdString());
}

QString MediaManager::resolvedPath(const QString& fileName, int chatId) const
{
    const QString full = chatMediaDir(chatId) + "/" + QFileInfo(fileName).fileName();
    return QFile::exists(full) ? full : QString();
}

QString MediaManager::generateVideoThumbnail(const QString& videoPath, int chatId)
{
    const QString thumbDir  = chatMediaDir(chatId) + "/thumbs";
    QDir().mkpath(thumbDir);
    const QString thumbPath = thumbDir + "/" +
                              QFileInfo(videoPath).completeBaseName() + "_thumb.jpg";

    Logger::info(QString("[WAPage-AUDIT] thumbnail: requested file=%1 chat=%2")
                     .arg(QFileInfo(videoPath).fileName()).arg(chatId));

    if (QFile::exists(thumbPath)) {
        Logger::info(QString("[WAPage-AUDIT] thumbnail: cache HIT, reusing existing file=%1")
                         .arg(QFileInfo(thumbPath).fileName()));
        return thumbPath;
    }
    if (!QFile::exists(videoPath)) {
        Logger::warn(QString("[WAPage-AUDIT] thumbnail: source video missing path=%1")
                         .arg(videoPath));
        return {};
    }

    // Extract one frame using Qt Multimedia's bundled FFmpeg backend.
    // QMediaPlayer + QVideoSink decode frames offscreen — no ffmpeg.exe needed.
    auto tryExtractFrame = [&](qint64 positionMs) -> bool {
        Logger::info(QString("[WAPage-AUDIT] thumbnail: trying QMediaPlayer at position=%1ms file=%2")
                         .arg(positionMs).arg(QFileInfo(videoPath).fileName()));
        QMediaPlayer player;
        // Mute audio so seeking/playing doesn't produce sound; some backends
        // require an audio output to be present even when only video is wanted.
        QAudioOutput audioOut;
        audioOut.setMuted(true);
        player.setAudioOutput(&audioOut);

        QVideoSink sink;
        player.setVideoSink(&sink);

        QImage captured;
        QEventLoop loop;
        bool seeked = false;

        QObject::connect(&sink, &QVideoSink::videoFrameChanged, &loop,
            [&](const QVideoFrame& frame) {
                if (!frame.isValid() || !captured.isNull()) return;
                QImage img = frame.toImage();
                if (!img.isNull()) {
                    captured = std::move(img);
                    Logger::info(QString("[WAPage-AUDIT] thumbnail: first valid frame captured size=%1x%2")
                                     .arg(captured.width()).arg(captured.height()));
                    loop.quit();
                }
            });

        QObject::connect(&player, &QMediaPlayer::mediaStatusChanged, &loop,
            [&](QMediaPlayer::MediaStatus s) {
                Logger::info(QString("[WAPage-AUDIT] thumbnail: QMediaPlayer status=%1").arg(int(s)));
                if ((s == QMediaPlayer::LoadedMedia || s == QMediaPlayer::BufferedMedia)
                        && !seeked) {
                    seeked = true;
                    if (positionMs > 0) player.setPosition(positionMs);
                    player.play();
                } else if (s == QMediaPlayer::InvalidMedia) {
                    Logger::warn("[WAPage-AUDIT] thumbnail: QMediaPlayer reports InvalidMedia");
                    loop.quit();
                }
            });

        QObject::connect(&player, &QMediaPlayer::errorOccurred, &loop,
            [&](QMediaPlayer::Error e, const QString& msg) {
                Logger::warn(QString("[WAPage-AUDIT] thumbnail: QMediaPlayer error code=%1 msg=%2")
                                 .arg(int(e)).arg(msg));
                loop.quit();
            });

        // Hard deadline so a stuck decoder cannot hang the worker thread.
        QTimer timeout;
        timeout.setSingleShot(true);
        QObject::connect(&timeout, &QTimer::timeout, &loop, [&]() {
            Logger::warn(QString("[WAPage-AUDIT] thumbnail: timeout (10s) reached at position=%1ms")
                             .arg(positionMs));
            loop.quit();
        });
        timeout.start(10000);

        player.setSource(QUrl::fromLocalFile(videoPath));
        loop.exec();
        player.stop();

        if (captured.isNull()) {
            Logger::warn(QString("[WAPage-AUDIT] thumbnail: no frame captured at position=%1ms")
                             .arg(positionMs));
            return false;
        }

        // Match the previous "scale=320:-1" output: 320px wide, proportional.
        QImage scaled = captured.width() > 320
                          ? captured.scaledToWidth(320, Qt::SmoothTransformation)
                          : captured;
        const bool saved = scaled.save(thumbPath, "JPG", 90);
        Logger::info(QString("[WAPage-AUDIT] thumbnail: save %1 size=%2x%3 bytes=%4 path=%5")
                         .arg(saved ? "OK" : "FAIL")
                         .arg(scaled.width()).arg(scaled.height())
                         .arg(saved ? QFileInfo(thumbPath).size() : 0)
                         .arg(QFileInfo(thumbPath).fileName()));
        return saved;
    };

    // First try at 0.5s (avoid black intro frame), then fall back to frame 0.
    if (tryExtractFrame(500)) {
        Logger::info(QString("[WAPage-AUDIT] thumbnail: SUCCESS via Qt Multimedia at 0.5s file=%1")
                         .arg(QFileInfo(thumbPath).fileName()));
        return thumbPath;
    }
    if (tryExtractFrame(0)) {
        Logger::info(QString("[WAPage-AUDIT] thumbnail: SUCCESS via Qt Multimedia at 0.0s file=%1")
                         .arg(QFileInfo(thumbPath).fileName()));
        return thumbPath;
    }

    Logger::warn(QString("[WAPage-AUDIT] thumbnail: FAIL — Qt Multimedia could not produce a frame for %1")
                     .arg(videoPath));
    return {};
}

qint64 MediaManager::getAudioDuration(const QString& audioPath)
{
    Logger::info(QString("[WAPage-AUDIT] duration: requested file=%1")
                     .arg(QFileInfo(audioPath).fileName()));

    if (audioPath.isEmpty() || !QFile::exists(audioPath)) {
        Logger::warn(QString("[WAPage-AUDIT] duration: file missing path=%1").arg(audioPath));
        return 0;
    }

    // Probe the audio file via Qt Multimedia (bundled FFmpeg backend) instead
    // of spawning ffprobe.exe. We only need the duration metadata.
    QMediaPlayer player;
    QAudioOutput audioOut;
    audioOut.setMuted(true);
    player.setAudioOutput(&audioOut);

    qint64 durationMs = 0;
    QEventLoop loop;

    QObject::connect(&player, &QMediaPlayer::mediaStatusChanged, &loop,
        [&](QMediaPlayer::MediaStatus s) {
            if (s == QMediaPlayer::LoadedMedia || s == QMediaPlayer::BufferedMedia) {
                durationMs = player.duration();
                Logger::info(QString("[WAPage-AUDIT] duration: LoadedMedia, duration=%1ms")
                                 .arg(durationMs));
                loop.quit();
            } else if (s == QMediaPlayer::InvalidMedia) {
                Logger::warn("[WAPage-AUDIT] duration: InvalidMedia");
                loop.quit();
            }
        });
    QObject::connect(&player, &QMediaPlayer::durationChanged, &loop,
        [&](qint64 d) {
            // Some demuxers report duration before reaching LoadedMedia.
            if (d > 0 && durationMs == 0) {
                durationMs = d;
                Logger::info(QString("[WAPage-AUDIT] duration: durationChanged early=%1ms")
                                 .arg(durationMs));
                loop.quit();
            }
        });
    QObject::connect(&player, &QMediaPlayer::errorOccurred, &loop,
        [&](QMediaPlayer::Error e, const QString& msg) {
            Logger::warn(QString("[WAPage-AUDIT] duration: error code=%1 msg=%2")
                             .arg(int(e)).arg(msg));
            loop.quit();
        });

    QTimer timeout;
    timeout.setSingleShot(true);
    QObject::connect(&timeout, &QTimer::timeout, &loop, [&]() {
        Logger::warn("[WAPage-AUDIT] duration: timeout (5s) reached");
        loop.quit();
    });
    timeout.start(5000);

    player.setSource(QUrl::fromLocalFile(audioPath));
    loop.exec();
    Logger::info(QString("[WAPage-AUDIT] duration: %1 result=%2ms file=%3")
                     .arg(durationMs > 0 ? "SUCCESS" : "FAIL")
                     .arg(durationMs)
                     .arg(QFileInfo(audioPath).fileName()));
    return durationMs;
}

QString MediaManager::generateWaveform(const QString& audioPath)
{
    Logger::info(QString("[WAPage-AUDIT] waveform: requested file=%1")
                     .arg(QFileInfo(audioPath).fileName()));

    if (audioPath.isEmpty() || !QFile::exists(audioPath)) {
        Logger::warn(QString("[WAPage-AUDIT] waveform: file missing path=%1").arg(audioPath));
        return "";
    }

    // Decode to PCM using Qt's QAudioDecoder (FFmpeg backend) — replaces the
    // previous external ffmpeg.exe pipe. We request the same format the old
    // pipeline produced: 8000 Hz, mono, 16-bit signed little-endian.
    QAudioFormat fmt;
    fmt.setSampleRate(8000);
    fmt.setChannelCount(1);
    fmt.setSampleFormat(QAudioFormat::Int16);

    QAudioDecoder decoder;
    decoder.setAudioFormat(fmt);

    QByteArray pcmData;
    pcmData.reserve(64 * 1024);
    int bufferCount = 0;
    bool finishedLogged = false;  // QAudioDecoder::finished can fire twice (EOS + stop()).
    QEventLoop loop;

    QObject::connect(&decoder, &QAudioDecoder::bufferReady, &loop, [&]() {
        const QAudioBuffer buf = decoder.read();
        if (!buf.isValid()) return;
        pcmData.append(reinterpret_cast<const char*>(buf.constData<char>()),
                       buf.byteCount());
        ++bufferCount;
    });
    QObject::connect(&decoder, &QAudioDecoder::finished, &loop, [&]() {
        if (!finishedLogged) {
            finishedLogged = true;
            Logger::info(QString("[WAPage-AUDIT] waveform: QAudioDecoder finished buffers=%1 totalBytes=%2")
                             .arg(bufferCount).arg(pcmData.size()));
        }
        loop.quit();
    });
    // QAudioDecoder::error overloads its getter name; bind via qOverload so
    // the connect resolves to the signal, not the accessor.
    QObject::connect(&decoder,
        qOverload<QAudioDecoder::Error>(&QAudioDecoder::error),
        &loop, [&](QAudioDecoder::Error e) {
            Logger::warn(QString("[WAPage-AUDIT] waveform: QAudioDecoder error code=%1 msg=%2")
                             .arg(int(e)).arg(decoder.errorString()));
            loop.quit();
        });

    QTimer timeout;
    timeout.setSingleShot(true);
    QObject::connect(&timeout, &QTimer::timeout, &loop, [&]() {
        Logger::warn(QString("[WAPage-AUDIT] waveform: timeout (15s) reached buffers so far=%1 bytes=%2")
                         .arg(bufferCount).arg(pcmData.size()));
        loop.quit();
    });
    timeout.start(15000);

    decoder.setSource(QUrl::fromLocalFile(audioPath));
    decoder.start();
    loop.exec();
    decoder.stop();

    if (pcmData.size() < 100) {
        Logger::warn(QString("[WAPage-AUDIT] waveform: FAIL — not enough PCM data (%1 bytes) file=%2")
                         .arg(pcmData.size()).arg(QFileInfo(audioPath).fileName()));
        return "";
    }

    const int16_t* samples = reinterpret_cast<const int16_t*>(pcmData.constData());
    int numSamples = pcmData.size() / 2;

    // 2. Count 36 peaks
    const int numBars = 36;
    int samplesPerBar = numSamples / numBars;
    if (samplesPerBar <= 0) samplesPerBar = 1;

    QStringList peaks;
    int maxOverall = 1; // Not to be divisible by 0

    for (int i = 0; i < numBars; ++i) {
        int peak = 0;
        int start = i * samplesPerBar;
        int end = qMin(start + samplesPerBar, numSamples);
        
        // In this part, we find the average absolute value (peak).
        for (int j = start; j < end; ++j) {
            int absVal = qAbs(static_cast<int>(samples[j]));
            if (absVal > peak) peak = absVal;
        }
        if (peak > maxOverall) maxOverall = peak;
        peaks << QString::number(peak);
    }

    // 3. Normalize between 0-100
    for (int i = 0; i < peaks.size(); ++i) {
        int val = peaks[i].toInt();
        int normalized = (val * 100) / maxOverall;
        // Minimum 4px height (about 10%) as in WAPage
        if (normalized < 10) normalized = 10;
        peaks[i] = QString::number(normalized);
    }

    const QString result = peaks.join(",");
    Logger::info(QString("[WAPage-AUDIT] waveform: SUCCESS bars=%1 samples=%2 maxAmp=%3 file=%4")
                     .arg(peaks.size()).arg(numSamples).arg(maxOverall)
                     .arg(QFileInfo(audioPath).fileName()));
    return result;
}

bool MediaManager::deleteChatMedia(int chatId)
{
    if (chatId < 0) {
        return false;
    }

    const QString dirPath = chatMediaDir(chatId);
    QDir dir(dirPath);
    if (!dir.exists()) {
        return true;
    }

    const bool ok = dir.removeRecursively();
    return ok;
}

