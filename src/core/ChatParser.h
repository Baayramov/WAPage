#pragma once
#include "models/Message.h"
#include <functional>
#include <QString>
#include <QList>

// iOS WAPage parses the _chat.txt file
// Format example:
//   [27.05.2024, 14:23:11] John Doe: Hello how are you?
//   [27.05.2024, 14:23:45] John Doe: <attached: IMG-20240527-WA0001.jpg>
//   [27.05.2024, 14:24:00] Jane Smith: I'm good, you?
class ChatParser
{
public:
    struct ParseProgress {
        qint64 bytesRead = 0;
        qint64 totalBytes = 0;
        int linesRead = 0;
        int parsedMessages = 0;
    };

    struct ParseResult {
        QList<Message> messages;
        QString        contactName;   // The name of the party not ours
        QString        groupName;     // Group title extracted from system intro line
        QStringList    participants;  // Distinct senders except owner/group pseudo sender
        bool           isGroup  = false;
        QString        ownerName;     // "I" (asked during import)
        bool           success  = false;
        QString        errorMsg;
    };

    // chatTxtPath: the path to the unzipped _chat.txt file
    // ownerName: user's own name (asked during import)
    static ParseResult parse(const QString& chatTxtPath,
                             const QString& ownerName,
                             int            chatId,
                             const QString& editedLabel,
                             const QString& deletedMessageLabel,
                             const QString& youDeletedMessageLabel,
                             const std::function<void(const ParseProgress&)>& progressCallback = {},
                             bool useAndroidParser = false);

private:
    // Regexes that recognize date formats
    // iOS formats: [DD.MM.YYYY, HH:MM:SS] or [M/D/YY, HH:MM:SS AM/PM]
    static QDateTime parseTimestamp(const QString& raw);
    static MessageType detectMediaType(const QString& filename);
    static QString extractAttachmentName(const QString& content);
};
