#pragma once
#include "models/Chat.h"
#include "models/Message.h"
#include "models/Participant.h"
#include <functional>
#include <QHash>
#include <QList>
#include <QSet>
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
    QList<Chat> allChats(); // Returns only unlocked chats by default
    QList<Chat> allChats(bool includeLockedChats); // Overload: can include locked chats
    Chat    getChatById(int chatId);  // Get single chat by ID (includes locked chats)

    // Participant CRUD
    bool              upsertParticipant(int chatId, const QString& participantName, const QString& avatarPath = QString());
    bool              updateParticipantName(int chatId, const QString& oldName, const QString& newName);
    bool              updateParticipantAvatar(int chatId, const QString& participantName, const QString& avatarPath);
    QList<Participant> participantsForChat(int chatId);
    QHash<QString, QString> participantAvatarMap(int chatId);
    int               participantCountForChat(int chatId);
    int               messageCountForParticipant(int chatId, const QString& participantName);
    bool              seedParticipantsFromMessages(int chatId, const QString& ownerName = QString(), const QString& ownerAvatarPath = QString());
    QSet<QString>     getOwnerParticipantsForChat(int chatId);

    // Message CRUD
    bool    insertMessages(
               const QList<Message>& messages,
               const std::function<void(int insertedCount, int totalCount)>& progressCallback = {}); // Batch insert
    QList<Message> messagesForChat(int chatId);
    // Get single message by ID (efficient for favorites)
    Message getMessageById(int chatId, int messageId, bool* found = nullptr);
    // Paged loading: returns messages from offset to limit (oldest to newest)
    QList<Message> messagesForChatPaged(int chatId, int offset, int limit);
    // Returns the total number of messages
    int     messageCountForChat(int chatId);
    // Returns list of dates (YYYY-MM-DD) that have messages in this chat
    QStringList getMessageDatesForChat(int chatId);
    // Returns the first message index for a given date
    int     getFirstMessageIndexForDate(int chatId, const QString& date);
    // Estimates total height based on type counts only without loading all messages
    // Used to pre-know the contentHeight of the ListView (rubber band fix)
    qint64  estimateTotalHeight(int chatId);
    QList<Message> searchMessages(int chatId, const QString& query);

    // For last message preview
    bool    updateLastMessageTime(int chatId);

    // Media queries for media browser
    QList<Message> getMediaMessages(int chatId, const QString& mediaType); // "image", "video", "document", etc.
    QStringList    getLinks(int chatId); // Extract links from text messages
    QList<Message> getLocationMessages(int chatId);

    // Persist a freshly computed audio waveform so it is reused on next
    // chat load instead of re-running the FFmpeg decode pipeline.
    bool    updateMessageWaveform(int messageId, const QString& waveform);

    // Settings
    QString getSetting(const QString& key, const QString& def = "");
    void    setSetting(const QString& key, const QString& value);

    // Profile Library - custom profiles for known contacts
    bool              addProfileToLibrary(const QString& name, const QString& avatarPath, bool isDefault = false);
    bool              removeProfileFromLibrary(const QString& name);
    bool              updateProfileLibraryAvatar(const QString& name, const QString& avatarPath);
    QString           getProfileLibraryAvatar(const QString& name);
    QHash<QString, QString> getAllProfileLibrary(); // Returns name -> avatarPath map
    bool              profileExistsInLibrary(const QString& name); // Check all profiles (default overload)
    bool              profileExistsInLibrary(const QString& name, bool onlyCustom); // Overload: filter by custom/default
    void              migrateProfileLibraryNormalization(); // Normalize existing profile names in database

    // Get existing participant avatar from any chat (for import consistency)
    QString           getExistingParticipantAvatar(const QString& participantName);
    
    // Helper function to normalize Unicode strings for consistent comparison
    static QString normalizeString(const QString& str);
    
    // Generate random default avatar
    static QString generateRandomAvatar();
    
    // Compute and cache participant message counts during import
    // This pre-calculates message counts and stores them in participants.message_count
    // so that ProfileView loads instantly without runtime queries on large chats
    bool computeAndCacheParticipantMessageCounts(int chatId);

    // Favorites (starred messages)
    bool    addToFavorites(int chatId, int messageId);
    bool    removeFromFavorites(int chatId, int messageId);
    bool    isMessageFavorite(int chatId, int messageId);
    QList<QPair<int, int>> getAllFavorites(); // Returns list of (chatId, messageId) pairs in order added

    // Lock system
    bool    setMasterPassword(const QString& password);
    QString getMasterPassword();
    bool    hasMasterPassword();
    bool    lockChat(int chatId);
    bool    unlockChat(int chatId);
    bool    isChatLocked(int chatId);
    QList<Chat> getLockedChats();

private:
    bool createTables();

    QString       m_dbPath;
    QSqlDatabase  m_db;
};
