#pragma once
#include <QString>
#include <QDateTime>

// Describes a conversation (a row in the left panel)
struct Chat {
    int         id            = 0;
    QString     contactName;
    QString     chatType      = "direct";
    QString     zipSourcePath;
    QString     customAvatarPath;   // If the user selected manually
    QDateTime   importedAt;
    QDateTime   lastMessageTime;
    QString     lastMessagePreview; // The last message text in the left panel
    int         unreadCount   = 0;  // Ready for the future
};
