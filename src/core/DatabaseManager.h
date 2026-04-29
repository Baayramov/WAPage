#pragma once
#include "models/Chat.h"
#include "models/Message.h"
#include "models/Participant.h"
#include <functional>
#include <QHash>
#include <QList>
#include <QString>
#include <QSqlDatabase>

// SQLite operations — all persistent storage is here
class DatabaseManager
{
public:
    explicit DatabaseManager(const QString& dbPath);
    ~DatabaseManager();

    bool open();
    void close();
    bool isOpen() const;

    // Chat CRUD
    int     insertChat(const Chat& chat);
    bool    updateChatAvatar(int chatId, const QString& avatarPath);
    bool    updateChatName(int chatId, const QString& contactName);
    bool    updateChatType(int chatId, const QString& chatType);
    bool    deleteChat(int chatId);
    QList<Chat> allChats();

    // Participant CRUD
    bool              upsertParticipant(int chatId, const QString& participantName, const QString& avatarPath = QString());
    bool              updateParticipantName(int chatId, const QString& oldName, const QString& newName);
    bool              updateParticipantAvatar(int chatId, const QString& participantName, const QString& avatarPath);
    QList<Participant> participantsForChat(int chatId);
    QHash<QString, QString> participantAvatarMap(int chatId);
    int               participantCountForChat(int chatId);
    bool              seedParticipantsFromMessages(int chatId, const QString& ownerName = QString());

    // Message CRUD
    bool    insertMessages(
               const QList<Message>& messages,
               const std::function<void(int insertedCount, int totalCount)>& progressCallback = {}); // Batch insert
    QList<Message> messagesForChat(int chatId);
    // Paged loading: returns messages from offset to limit (oldest to newest)
    QList<Message> messagesForChatPaged(int chatId, int offset, int limit);
    // Returns the total number of messages
    int     messageCountForChat(int chatId);
    // Estimates total height based on type counts only without loading all messages
    // Used to pre-know the contentHeight of the ListView (rubber band fix)
    qint64  estimateTotalHeight(int chatId);
    QList<Message> searchMessages(int chatId, const QString& query);

    // For last message preview
    bool    updateLastMessageTime(int chatId);

    // Persist a freshly computed audio waveform so it is reused on next
    // chat load instead of re-running the FFmpeg decode pipeline.
    bool    updateMessageWaveform(int messageId, const QString& waveform);

    // Settings
    QString getSetting(const QString& key, const QString& def = "");
    void    setSetting(const QString& key, const QString& value);

private:
    bool createTables();

    QString       m_dbPath;
    QSqlDatabase  m_db;
};
