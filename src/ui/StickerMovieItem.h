#pragma once

#include <QImage>
#include <QQuickPaintedItem>
#include <QString>

#include <atomic>
#include <memory>

class QMovie;
class QPainter;

class StickerMovieItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(bool animated READ isAnimated NOTIFY animatedChanged)
    Q_PROPERTY(int status READ status NOTIFY statusChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)

public:
    enum LoadStatus {
        Null = 0,
        Ready = 1,
        Loading = 2,
        Error = 3
    };
    Q_ENUM(LoadStatus)

    explicit StickerMovieItem(QQuickItem* parent = nullptr);
    ~StickerMovieItem() override;

    QString source() const;
    void setSource(const QString& source);

    bool playing() const;
    void setPlaying(bool playing);

    bool isAnimated() const;

    int status() const;
    QString errorString() const;

    void paint(QPainter* painter) override;

signals:
    void sourceChanged();
    void playingChanged();
    void animatedChanged();
    void statusChanged();
    void errorStringChanged();

private:
    void loadSource();
    QString resolveLocalPath(const QString& source) const;
    bool shouldUseMovie(const QString& localPath, int imageCount) const;

    void setAnimated(bool animated);
    void setStatus(LoadStatus status);
    void setErrorString(const QString& error);

    QString m_source;
    bool m_playing = true;
    bool m_animated = false;
    LoadStatus m_status = Null;
    QString m_errorString;

    QImage m_staticImage;
    std::unique_ptr<QMovie> m_movie;

    // Cancellation token for the most recent loadSource() background job.
    // When loadSource() is called again (e.g. recycled delegate during scroll)
    // the previous token is flipped to true so its in-flight result is dropped.
    std::shared_ptr<std::atomic<bool>> m_loadToken;
};
