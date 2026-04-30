#include "MediaViewer.h"
#include "utils/Logger.h"
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>

MediaViewer::MediaViewer(QObject* parent)
    : QObject(parent)
{}

void MediaViewer::open(const QString& path, const QString& type, const QString& thumbnail)
{
    m_mediaPath      = path;
    m_mediaType      = type;
    m_mediaThumbnail = thumbnail;
    m_visible        = true;
    emit mediaChanged();
    emit visibleChanged();
    Logger::debug("Opening media: " + path.toStdString());
}

void MediaViewer::close()
{
    m_visible = false;
    emit visibleChanged();
}

void MediaViewer::openWithSystem(const QString& path)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

QString MediaViewer::fileName() const
{
    return QFileInfo(m_mediaPath).fileName();
}
