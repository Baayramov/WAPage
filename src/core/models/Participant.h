#pragma once

#include <QString>

struct Participant {
    int id = 0;
    int chatId = 0;
    QString name;
    QString customAvatarPath;
    int messageCount = 0;  // Cached message count (pre-computed during import)
};
