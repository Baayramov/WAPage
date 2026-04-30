#pragma once
#include "models/Message.h"
#include <functional>
#include <QString>
#include <QStringList>

// Moves media files to the program's data folder
// and updates media paths in messages
class MediaManager
{
public:
    explicit MediaManager(const QString& mediaStorageDir);

    // Moves the mediaPath in each message from the temp folder to the data folder
    // Skips existing files (if they have the same name)
    void copyMediaToStorage(QList<Message>& messages,
                            const QString&  tempExtractDir,
                            int             chatId,
                            const std::function<void(qint64 processedBytes,
                                                     int processedItems,
                                                     int totalItems)>& progressCallback = {});

    // Returns the full path of any media file
    QString resolvedPath(const QString& fileName, int chatId) const;

    // Generate thumbnail for video (with Qt without FFmpeg)
    QString generateVideoThumbnail(const QString& videoPath, int chatId);

    // Returns the duration of the audio file in ms
    qint64 getAudioDuration(const QString& audioPath);

    // Generates real audio waveform (peaks)
    QString generateWaveform(const QString& audioPath);

    // Deletes only the media directory of the given chat.
    bool deleteChatMedia(int chatId);

private:
    QString chatMediaDir(int chatId) const;

    QString m_storageDir;
};
