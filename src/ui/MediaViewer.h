#pragma once
#include <QObject>
#include <QString>

// C++ backend for image/video/audio fullscreen display
class MediaViewer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool    visible        READ visible        NOTIFY visibleChanged)
    Q_PROPERTY(QString mediaPath      READ mediaPath      NOTIFY mediaChanged)
    Q_PROPERTY(QString mediaThumbnail READ mediaThumbnail NOTIFY mediaChanged)
    Q_PROPERTY(QString mediaType      READ mediaType      NOTIFY mediaChanged)
    Q_PROPERTY(QString fileName       READ fileName       NOTIFY mediaChanged)

public:
    explicit MediaViewer(QObject* parent = nullptr);

    bool    visible()   const { return m_visible; }
    QString mediaPath() const { return m_mediaPath; }
    QString mediaThumbnail() const { return m_mediaThumbnail; }
    QString mediaType() const { return m_mediaType; }
    QString fileName()  const;

public slots:
    void open(const QString& path, const QString& type, const QString& thumbnail = QString());
    void close();
    // Open the file from the system file manager
    void openWithSystem(const QString& path);

signals:
    void visibleChanged();
    void mediaChanged();

private:
    bool    m_visible   = false;
    QString m_mediaPath;
    QString m_mediaThumbnail;
    QString m_mediaType;
};
