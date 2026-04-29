#pragma once

#include <QString>

struct Participant {
    int id = 0;
    int chatId = 0;
    QString name;
    QString customAvatarPath;
};
