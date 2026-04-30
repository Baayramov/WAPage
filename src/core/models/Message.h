#pragma once
#include <QString>
#include <QDateTime>

enum class MessageType {
    Text,
    Image,
    Video,
    Audio,     // Normal audio
    Ptt,       // Push-to-talk (voice message)
    Sticker,
    Document,
    Deleted,   // "This message was deleted"
    System,    // System messages such as "About encryption".
    Location,  // Location message (Google Maps link)
    Contact    // VCF contact message
};

enum class ReadStatus {
    Sent      = 1,   // Single gray teak
    Delivered = 2,   // Double gray teak
    Read      = 3    // Double blue teak
};

struct Message {
    int         id          = 0;
    int         chatId      = 0;
    QString     sender;             // Sender Name (from _chat.txt)
    QString     content;            // Plain text (filename for media)
    QDateTime   timestamp;
    bool        isFromMe    = false;
    MessageType type        = MessageType::Text;
    QString     mediaPath;          // The full path of the transferred media file
    QString     mediaThumbnailPath; // Video thumbnail
    qint64      mediaDurationMs = 0; // Audio/Video duration (ms)
    ReadStatus  readStatus  = ReadStatus::Read; // Imported messages are considered read
    QString     mediaMeta;          // Location: "lat,lng"; Contact: name; Omitted: "omitted"
    QString     waveform;           // Comma-separated peak values (0-100)
    QString     editedText;         // "Edited" label in the language at the time of import

    // Lazy cache for WAPageTextFormatter::formatFull(content) — populated on first
    // FormattedContentRole access; mutable so const data() can fill it.
    mutable QString cachedFormatted;
};
