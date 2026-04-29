#include "StickerMovieItem.h"

#include <QCoreApplication>
#include <QFileInfo>
#include <QImageReader>
#include <QMovie>
#include <QPainter>
#include <QPointer>
#include <QThreadPool>
#include <QUrl>

StickerMovieItem::StickerMovieItem(QQuickItem* parent)
    : QQuickPaintedItem(parent)
{
    setOpaquePainting(false);
    setAntialiasing(true);
}

StickerMovieItem::~StickerMovieItem() = default;

QString StickerMovieItem::source() const
{
    return m_source;
}

void StickerMovieItem::setSource(const QString& source)
{
    if (m_source == source) return;
    m_source = source;
    emit sourceChanged();
    loadSource();
}

bool StickerMovieItem::playing() const
{
    return m_playing;
}

void StickerMovieItem::setPlaying(bool playing)
{
    if (m_playing == playing) return;
    m_playing = playing;
    emit playingChanged();

    if (!m_movie) return;

    if (m_playing) {
        if (m_movie->state() != QMovie::Running) {
            m_movie->start();
        }
        m_movie->setPaused(false);
    } else if (m_movie->state() == QMovie::Running) {
        m_movie->setPaused(true);
    }
}

bool StickerMovieItem::isAnimated() const
{
    return m_animated;
}

int StickerMovieItem::status() const
{
    return static_cast<int>(m_status);
}

QString StickerMovieItem::errorString() const
{
    return m_errorString;
}

void StickerMovieItem::paint(QPainter* painter)
{
    QImage frame;

    if (m_movie && m_movie->isValid()) {
        frame = m_movie->currentImage();
    }
    if (frame.isNull()) {
        frame = m_staticImage;
    }
    if (frame.isNull()) {
        return;
    }

    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    const QRectF target = boundingRect();
    const QSizeF sourceSize = frame.size();
    if (sourceSize.isEmpty() || target.isEmpty()) {
        return;
    }

    const QSizeF scaled = sourceSize.scaled(target.size(), Qt::KeepAspectRatio);
    const QRectF drawRect((target.width() - scaled.width()) * 0.5,
                          (target.height() - scaled.height()) * 0.5,
                          scaled.width(),
                          scaled.height());

    painter->drawImage(drawRect, frame);
}

void StickerMovieItem::loadSource()
{
    // Cancel any in-flight background load: the result it produces will be
    // discarded once it sees the token flipped to true.
    if (m_loadToken) m_loadToken->store(true);
    m_loadToken = std::make_shared<std::atomic<bool>>(false);

    m_movie.reset();
    m_staticImage = QImage();
    setErrorString(QString());
    setAnimated(false);

    if (m_source.trimmed().isEmpty()) {
        setStatus(Null);
        update();
        return;
    }

    setStatus(Loading);
    update();  // show Loading state immediately

    const QString localPath = resolveLocalPath(m_source);
    if (localPath.isEmpty() || !QFileInfo::exists(localPath)) {
        setErrorString(QStringLiteral("Sticker file not found"));
        setStatus(Error);
        update();
        return;
    }

    // Format check is a fast string compare — keep on UI thread.
    const QString suffix = QFileInfo(localPath).suffix().toLower();
    bool supportedImageFormat = false;
    const QList<QByteArray> formats = QImageReader::supportedImageFormats();
    for (const QByteArray& format : formats) {
        if (QString::fromLatin1(format).toLower() == suffix) {
            supportedImageFormat = true;
            break;
        }
    }
    if (!supportedImageFormat) {
        setErrorString(QStringLiteral("Unsupported sticker image format: %1").arg(suffix));
        setStatus(Error);
        update();
        return;
    }

    const bool maybeAnimated = (suffix == QLatin1String("webp") ||
                                suffix == QLatin1String("gif"));

    // Capture a guarded pointer + the current token; both are checked again on
    // the UI thread before applying results.
    QPointer<StickerMovieItem> guard(this);
    std::shared_ptr<std::atomic<bool>> token = m_loadToken;

    // Offload all disk I/O and decode work to the global thread pool.
    QThreadPool::globalInstance()->start([guard, token, localPath, maybeAnimated]() {
        if (token->load()) return;

        // Probe frame count to decide static vs animated.
        int frameCount = 0;
        {
            QImageReader probe(localPath);
            probe.setAutoTransform(true);
            frameCount = probe.imageCount();
        }
        if (token->load()) return;

        // Decode the first frame. Constrain the decoded size to the sticker's
        // display footprint (168x168) so animated WebPs don't balloon RAM.
        QImageReader reader(localPath);
        reader.setAutoTransform(true);
        if (reader.size().isValid()) {
            QSize scaled = reader.size().scaled(168, 168, Qt::KeepAspectRatio);
            reader.setScaledSize(scaled);
        }
        const QImage img = reader.read();
        const QString readerErr = reader.errorString();

        if (token->load()) return;

        // Hop back to the UI thread to apply the result. QMovie is not thread
        // safe, so it MUST be created here, not in the worker.
        QMetaObject::invokeMethod(qApp,
            [guard, token, img, readerErr, localPath, maybeAnimated, frameCount]() {
                StickerMovieItem* self = guard.data();
                if (!self) return;
                if (token->load()) return;  // superseded by a newer setSource()

                if (img.isNull()) {
                    self->setErrorString(readerErr.isEmpty()
                                            ? QStringLiteral("Sticker image decode error")
                                            : readerErr);
                    self->setStatus(Error);
                    self->update();
                    return;
                }

                self->m_staticImage = img;

                // Decide whether this is an animated sticker that warrants QMovie.
                if (maybeAnimated && self->shouldUseMovie(localPath, frameCount)) {
                    auto movie = std::make_unique<QMovie>(localPath);
                    if (movie->isValid()) {
                        QObject::connect(movie.get(), &QMovie::frameChanged,
                                         self, [self](int) { self->update(); });
                        QObject::connect(movie.get(), &QMovie::error, self,
                                         [self](QImageReader::ImageReaderError) {
                            const QString lastError = self->m_movie
                                ? self->m_movie->lastErrorString()
                                : QStringLiteral("Sticker animation load error");
                            self->setErrorString(lastError);
                            self->setStatus(Error);
                            self->update();
                        });

                        self->m_movie = std::move(movie);
                        self->setAnimated(true);

                        if (self->m_playing) {
                            self->m_movie->start();
                        } else {
                            self->m_movie->start();
                            self->m_movie->setPaused(true);
                        }
                    }
                }

                self->setStatus(Ready);
                self->update();
            },
            Qt::QueuedConnection);
    });
}

QString StickerMovieItem::resolveLocalPath(const QString& source) const
{
    const QString trimmed = source.trimmed();
    if (trimmed.isEmpty()) return QString();

    const QUrl url(trimmed);
    if (url.isValid() && url.isLocalFile()) {
        return url.toLocalFile();
    }

    if (trimmed.startsWith(QStringLiteral("file:///"), Qt::CaseInsensitive)) {
        return QUrl(trimmed).toLocalFile();
    }

    return trimmed;
}

bool StickerMovieItem::shouldUseMovie(const QString& localPath, int imageCount) const
{
    const QString suffix = QFileInfo(localPath).suffix().toLower();

    if (suffix != QStringLiteral("webp") && suffix != QStringLiteral("gif")) {
        return false;
    }

    if (imageCount > 1) return true;
    if (imageCount == 1) return false;

    // We choose QMovie to preserve animation capability when imageCount is unknown.
    return true;
}

void StickerMovieItem::setAnimated(bool animated)
{
    if (m_animated == animated) return;
    m_animated = animated;
    emit animatedChanged();
}

void StickerMovieItem::setStatus(LoadStatus status)
{
    if (m_status == status) return;
    m_status = status;
    emit statusChanged();
}

void StickerMovieItem::setErrorString(const QString& error)
{
    if (m_errorString == error) return;
    m_errorString = error;
    emit errorStringChanged();
}
