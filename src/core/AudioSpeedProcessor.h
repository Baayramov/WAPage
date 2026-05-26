#pragma once

#include <QObject>
#include <QString>
#include <QSet>
#include <QMutex>

// Pitch-preserving time-stretch for audio bubbles.
//
// We use Qt's bundled FFmpeg backend (via QAudioDecoder) to decode the
// source audio to mono int16 PCM, then apply a small WSOLA implementation
// (Waveform Similarity Overlap-Add) to change the duration without altering
// the pitch — i.e., 1.5x / 2x speed-up without the "helium" effect that
// QMediaPlayer.playbackRate produces.
//
// Output is written as a 22050 Hz mono 16-bit PCM WAV file in the cache
// directory (`<dataDir>/audio_cache`). QML/AudioPlayer swaps its
// MediaPlayer.source to the cached file and keeps playbackRate=1.0, so the
// audio plays back at the new tempo with original pitch.
class AudioSpeedProcessor : public QObject
{
    Q_OBJECT

public:
    explicit AudioSpeedProcessor(QObject* parent = nullptr);

    // Configure where stretched WAV files live. Created if missing.
    void setCacheDir(const QString& dir);

    // Synchronous: returns the cached path if a file already exists for
    // (audioPath, rate). Empty string otherwise. Cheap (single stat call).
    QString cachedPathIfExists(const QString& audioPath, qreal rate) const;

    // Async: spawn a worker that decodes the source, applies WSOLA at
    // `rate`, writes the WAV, and emits ready(audioPath, rate, cachedPath)
    // on the UI thread. Duplicate in-flight requests are de-duplicated.
    // No-op for rate == 1.0 (callers should just use the original source).
    void requestStretched(const QString& audioPath, qreal rate);

signals:
    void ready(const QString& audioPath, qreal rate, const QString& cachedPath);

private:
    QString computeCachePath(const QString& audioPath, qreal rate) const;
    QString processSync(const QString& audioPath, qreal rate, const QString& outPath) const;

    QString        m_cacheDir;
    QSet<QString>  m_inFlight;        // key = audioPath + ":" + rate
    mutable QMutex m_mutex;
};
