#include "DatabaseManager.h"
#include "utils/Logger.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDir>
#include <QFileInfo>

DatabaseManager::DatabaseManager(const QString& dbPath)
    : m_dbPath(dbPath)
{
}

DatabaseManager::~DatabaseManager()
{
    close();
}

bool DatabaseManager::open()
{
    QDir().mkpath(QFileInfo(m_dbPath).absolutePath());

    m_db = QSqlDatabase::addDatabase("QSQLITE", "wapage_conn");
    m_db.setDatabaseName(m_dbPath);

    if (!m_db.open()) {
        Logger::error("Failed to open DB: " + m_db.lastError().text().toStdString());
        return false;
    }

    // WAL mode – write faster
    QSqlQuery pragma(m_db);
    pragma.exec("PRAGMA journal_mode=WAL");
    pragma.exec("PRAGMA foreign_keys=ON");
    pragma.exec("PRAGMA synchronous=NORMAL");

    if (!createTables()) {
        return false;
    }

    // Old chats with the deleted orange avatar are valid avatars, sorry.
    QSqlQuery migrate(m_db);
    if (!migrate.exec(
            "UPDATE chats "
            "SET custom_avatar_path='qrc:/assets/red_avatar.svg' "
            "WHERE custom_avatar_path='qrc:/assets/orange_avatar.svg'")) {
        Logger::warn("Avatar migration error: " + migrate.lastError().text());
    } else if (migrate.numRowsAffected() > 0) {
        Logger::info(QString("Avatar migration applied: %1 chats")
                     .arg(migrate.numRowsAffected()));
    }

    return true;
}

void DatabaseManager::close()
{
    if (m_db.isOpen()) m_db.close();
}

bool DatabaseManager::isOpen() const
{
    return m_db.isOpen();
}

bool DatabaseManager::createTables()
{
    QSqlQuery q(m_db);

    const bool ok =
        q.exec(R"(
            CREATE TABLE IF NOT EXISTS chats (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                contact_name TEXT NOT NULL,
                chat_type TEXT DEFAULT 'direct',
                zip_source_path TEXT,
                custom_avatar_path TEXT,
                imported_at DATETIME DEFAULT CURRENT_TIMESTAMP,
                last_message_time DATETIME
            )
        )") &&
        q.exec(R"(
            CREATE TABLE IF NOT EXISTS settings (
                key TEXT PRIMARY KEY,
                value TEXT
            )
        )") &&
        q.exec(R"(
            CREATE TABLE IF NOT EXISTS messages (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                chat_id INTEGER NOT NULL REFERENCES chats(id) ON DELETE CASCADE,
                sender TEXT NOT NULL,
                content TEXT,
                timestamp DATETIME NOT NULL,
                is_from_me INTEGER DEFAULT 0,
                message_type TEXT DEFAULT 'text',
                media_path TEXT,
                media_thumbnail_path TEXT,
                media_duration_ms INTEGER DEFAULT 0,
                read_status INTEGER DEFAULT 3,
                media_meta TEXT,
                waveform TEXT,
                edited_label TEXT DEFAULT ''
            ) 
        )") &&
        q.exec(R"(
            CREATE TABLE IF NOT EXISTS participants (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                chat_id INTEGER NOT NULL REFERENCES chats(id) ON DELETE CASCADE,
                participant_name TEXT NOT NULL,
                custom_avatar_path TEXT,
                UNIQUE(chat_id, participant_name)
            )
        )") &&
        q.exec("CREATE INDEX IF NOT EXISTS idx_msg_chat ON messages(chat_id)") &&
        q.exec("CREATE INDEX IF NOT EXISTS idx_msg_time ON messages(timestamp)") &&
        q.exec("CREATE INDEX IF NOT EXISTS idx_participants_chat ON participants(chat_id)");

    // Add columns for old DBs
    q.exec("ALTER TABLE messages ADD COLUMN media_meta TEXT");
    q.exec("ALTER TABLE messages ADD COLUMN waveform TEXT");
    q.exec("ALTER TABLE messages ADD COLUMN edited_label TEXT DEFAULT ''");
    q.exec("ALTER TABLE chats ADD COLUMN chat_type TEXT DEFAULT 'direct'");

    if (!ok) {
        Logger::error("Failed to create tables: " + q.lastError().text().toStdString());
    }
    return ok;
}

int DatabaseManager::insertChat(const Chat& chat)
{
    QSqlQuery q(m_db);
    q.prepare(R"(
        INSERT INTO chats (contact_name, chat_type, zip_source_path, imported_at, last_message_time)
        VALUES (:name, :ctype, :zip, :imported, :lastmsg)
    )");
    q.bindValue(":name",     chat.contactName);
    q.bindValue(":ctype",    chat.chatType.trimmed().isEmpty() ? QStringLiteral("direct") : chat.chatType);
    q.bindValue(":zip",      chat.zipSourcePath);
    q.bindValue(":imported", chat.importedAt.toString(Qt::ISODate));
    q.bindValue(":lastmsg",  chat.lastMessageTime.toString(Qt::ISODate));

    if (!q.exec()) {
        Logger::error("Chat insert error: " + q.lastError().text().toStdString());
        return -1;
    }
    return q.lastInsertId().toInt();
}

bool DatabaseManager::updateChatAvatar(int chatId, const QString& avatarPath)
{
    QSqlQuery q(m_db);
    q.prepare("UPDATE chats SET custom_avatar_path=:path WHERE id=:id");
    q.bindValue(":path", avatarPath);
    q.bindValue(":id",   chatId);
    return q.exec();
}

bool DatabaseManager::updateChatName(int chatId, const QString& contactName)
{
    QSqlQuery q(m_db);
    q.prepare("UPDATE chats SET contact_name=:name WHERE id=:id");
    q.bindValue(":name", contactName);
    q.bindValue(":id",   chatId);
    return q.exec();
}

bool DatabaseManager::updateChatType(int chatId, const QString& chatType)
{
    QSqlQuery q(m_db);
    q.prepare("UPDATE chats SET chat_type=:ctype WHERE id=:id");
    q.bindValue(":ctype", chatType.trimmed().isEmpty() ? QStringLiteral("direct") : chatType);
    q.bindValue(":id",    chatId);
    return q.exec();
}

bool DatabaseManager::deleteChat(int chatId)
{
    if (chatId < 0) {
        return false;
    }

    QSqlQuery q(m_db);
    q.prepare("DELETE FROM chats WHERE id=:id");
    q.bindValue(":id", chatId);
    if (!q.exec()) {
        return false;
    }

    // Keep chat IDs dense with current DB state so media folder naming
    // follows existing chats (1..N) instead of historical max ID.
    int maxChatId = 0;
    QSqlQuery maxQ(m_db);
    if (maxQ.exec("SELECT COALESCE(MAX(id), 0) FROM chats") && maxQ.next()) {
        maxChatId = maxQ.value(0).toInt();
    }

    bool seqOk = true;
    if (maxChatId <= 0) {
        QSqlQuery resetQ(m_db);
        seqOk = resetQ.exec("DELETE FROM sqlite_sequence WHERE name='chats'");
        if (!seqOk) {
            Logger::warn("Chat ID sequence reset skipped: " + resetQ.lastError().text());
        }
    } else {
        QSqlQuery updateQ(m_db);
        updateQ.prepare("UPDATE sqlite_sequence SET seq=:seq WHERE name='chats'");
        updateQ.bindValue(":seq", maxChatId);
        seqOk = updateQ.exec();

        if (seqOk && updateQ.numRowsAffected() == 0) {
            QSqlQuery insertQ(m_db);
            insertQ.prepare("INSERT INTO sqlite_sequence(name, seq) VALUES('chats', :seq)");
            insertQ.bindValue(":seq", maxChatId);
            seqOk = insertQ.exec();
            if (!seqOk) {
                Logger::warn("Chat ID sequence insert failed: " + insertQ.lastError().text());
            }
        } else if (!seqOk) {
            Logger::warn("Chat ID sequence update failed: " + updateQ.lastError().text());
        }
    }

    Q_UNUSED(seqOk);
    return true;
}

QList<Chat> DatabaseManager::allChats()
{
    QList<Chat> chats;
    QSqlQuery q(m_db);
    q.exec(R"(
        SELECT c.id, c.contact_name, c.chat_type, c.zip_source_path,
               c.custom_avatar_path, c.imported_at, c.last_message_time,
               (SELECT content FROM messages WHERE chat_id=c.id
                ORDER BY timestamp DESC LIMIT 1) AS last_msg
        FROM chats c
        ORDER BY c.last_message_time DESC
    )");

    while (q.next()) {
        Chat ch;
        ch.id                = q.value(0).toInt();
        ch.contactName       = q.value(1).toString();
        ch.chatType          = q.value(2).toString().trimmed().isEmpty() ? QStringLiteral("direct") : q.value(2).toString();
        ch.zipSourcePath     = q.value(3).toString();
        ch.customAvatarPath  = q.value(4).toString();
        ch.importedAt        = QDateTime::fromString(q.value(5).toString(), Qt::ISODate);
        ch.lastMessageTime   = QDateTime::fromString(q.value(6).toString(), Qt::ISODate);
        ch.lastMessagePreview= q.value(7).toString();
        chats.append(ch);
    }
    return chats;
}

bool DatabaseManager::upsertParticipant(int chatId, const QString& participantName, const QString& avatarPath)
{
    const QString trimmedName = participantName.trimmed();
    if (chatId < 0 || trimmedName.isEmpty()) {
        return false;
    }

    QSqlQuery q(m_db);
    q.prepare(R"(
        INSERT OR IGNORE INTO participants (chat_id, participant_name, custom_avatar_path)
        VALUES (:cid, :name, :avatar)
    )");
    q.bindValue(":cid", chatId);
    q.bindValue(":name", trimmedName);
    q.bindValue(":avatar", avatarPath);
    if (!q.exec()) {
        Logger::error("Participant upsert error: " + q.lastError().text().toStdString());
        return false;
    }

    if (!avatarPath.trimmed().isEmpty()) {
        return updateParticipantAvatar(chatId, trimmedName, avatarPath);
    }
    return true;
}

bool DatabaseManager::updateParticipantName(int chatId, const QString& oldName, const QString& newName)
{
    const QString oldTrimmed = oldName.trimmed();
    const QString newTrimmed = newName.trimmed();
    if (chatId < 0 || oldTrimmed.isEmpty() || newTrimmed.isEmpty()) {
        return false;
    }
    if (oldTrimmed == newTrimmed) {
        return true;
    }

    if (!m_db.transaction()) {
        return false;
    }

    QSqlQuery qp(m_db);
    qp.prepare("UPDATE participants SET participant_name=:newName WHERE chat_id=:cid AND participant_name=:oldName");
    qp.bindValue(":newName", newTrimmed);
    qp.bindValue(":cid", chatId);
    qp.bindValue(":oldName", oldTrimmed);
    if (!qp.exec()) {
        Logger::error("Participant rename error: " + qp.lastError().text().toStdString());
        m_db.rollback();
        return false;
    }

    QSqlQuery qm(m_db);
    qm.prepare("UPDATE messages SET sender=:newName WHERE chat_id=:cid AND sender=:oldName");
    qm.bindValue(":newName", newTrimmed);
    qm.bindValue(":cid", chatId);
    qm.bindValue(":oldName", oldTrimmed);
    if (!qm.exec()) {
        Logger::error("Message sender rename error: " + qm.lastError().text().toStdString());
        m_db.rollback();
        return false;
    }

    if (!m_db.commit()) {
        m_db.rollback();
        return false;
    }
    return true;
}

bool DatabaseManager::updateParticipantAvatar(int chatId, const QString& participantName, const QString& avatarPath)
{
    const QString trimmedName = participantName.trimmed();
    if (chatId < 0 || trimmedName.isEmpty()) {
        return false;
    }

    QSqlQuery q(m_db);
    q.prepare("UPDATE participants SET custom_avatar_path=:path WHERE chat_id=:cid AND participant_name=:name");
    q.bindValue(":path", avatarPath);
    q.bindValue(":cid", chatId);
    q.bindValue(":name", trimmedName);
    if (!q.exec()) {
        Logger::error("Participant avatar update error: " + q.lastError().text().toStdString());
        return false;
    }

    if (q.numRowsAffected() <= 0) {
        return upsertParticipant(chatId, trimmedName, avatarPath);
    }
    return true;
}

QList<Participant> DatabaseManager::participantsForChat(int chatId)
{
    QList<Participant> participants;
    QSqlQuery q(m_db);
    q.prepare(R"(
        SELECT id, chat_id, participant_name, custom_avatar_path
        FROM participants
        WHERE chat_id=:cid
        ORDER BY participant_name COLLATE NOCASE ASC
    )");
    q.bindValue(":cid", chatId);
    if (!q.exec()) {
        Logger::error("Participant list query error: " + q.lastError().text().toStdString());
        return participants;
    }

    while (q.next()) {
        Participant p;
        p.id = q.value(0).toInt();
        p.chatId = q.value(1).toInt();
        p.name = q.value(2).toString();
        p.customAvatarPath = q.value(3).toString();
        participants.append(p);
    }
    return participants;
}

QHash<QString, QString> DatabaseManager::participantAvatarMap(int chatId)
{
    QHash<QString, QString> map;
    QSqlQuery q(m_db);
    q.prepare("SELECT participant_name, custom_avatar_path FROM participants WHERE chat_id=:cid");
    q.bindValue(":cid", chatId);
    if (!q.exec()) {
        Logger::error("Participant avatar map query error: " + q.lastError().text().toStdString());
        return map;
    }

    while (q.next()) {
        const QString name = q.value(0).toString().trimmed();
        if (!name.isEmpty()) {
            map.insert(name, q.value(1).toString());
        }
    }
    return map;
}

int DatabaseManager::participantCountForChat(int chatId)
{
    QSqlQuery q(m_db);
    q.prepare("SELECT COUNT(*) FROM participants WHERE chat_id=:cid");
    q.bindValue(":cid", chatId);
    if (q.exec() && q.next()) {
        return q.value(0).toInt();
    }
    return 0;
}

bool DatabaseManager::seedParticipantsFromMessages(int chatId, const QString& ownerName)
{
    if (chatId < 0) {
        return false;
    }

    const QString ownerTrimmed = ownerName.trimmed();
    QSqlQuery q(m_db);
    q.prepare(R"(
        SELECT sender, MAX(is_from_me)
        FROM messages
        WHERE chat_id=:cid
        GROUP BY sender
    )");
    q.bindValue(":cid", chatId);
    if (!q.exec()) {
        Logger::error("Seed participants query error: " + q.lastError().text().toStdString());
        return false;
    }

    bool allOk = true;
    while (q.next()) {
        const QString sender = q.value(0).toString().trimmed();
        const bool isFromMe = q.value(1).toInt() == 1;
        if (sender.isEmpty()) {
            continue;
        }
        if (isFromMe) {
            continue;
        }
        if (!ownerTrimmed.isEmpty() && sender == ownerTrimmed) {
            continue;
        }
        if (!upsertParticipant(chatId, sender)) {
            allOk = false;
        }
    }
    return allOk;
}

bool DatabaseManager::insertMessages(
    const QList<Message>& messages,
    const std::function<void(int insertedCount, int totalCount)>& progressCallback)
{
    if (messages.isEmpty()) return true;

    Logger::info(("DB insert started: " + QString::number(messages.size()) + " messages").toStdString());

    // Performance PRAGMAs — bulk import time
    QSqlQuery pragma(m_db);
    pragma.exec("PRAGMA synchronous=OFF");        // Turn off disk sync (biggest speedup!)
    pragma.exec("PRAGMA journal_mode=MEMORY");    // Keep journal in RAM
    pragma.exec("PRAGMA cache_size=-16000");       // 16MB cache
    pragma.exec("PRAGMA temp_store=MEMORY");
    pragma.exec("PRAGMA locking_mode=EXCLUSIVE");

    m_db.transaction();
    QSqlQuery q(m_db);
    q.prepare(R"(
        INSERT INTO messages
            (chat_id, sender, content, timestamp, is_from_me,
             message_type, media_path, media_thumbnail_path,
             media_duration_ms, read_status, media_meta, waveform, edited_label)
        VALUES
            (:cid, :sender, :content, :ts, :from_me,
             :mtype, :mpath, :mthumb, :mdur, :rstat, :mmeta, :wave, :elbl)
    )");

    static const QMap<MessageType, QString> typeStr = {
        {MessageType::Text,     "text"},
        {MessageType::Image,    "image"},
        {MessageType::Video,    "video"},
        {MessageType::Audio,    "audio"},
        {MessageType::Ptt,      "ptt"},
        {MessageType::Sticker,  "sticker"},
        {MessageType::Document, "document"},
        {MessageType::Deleted,  "deleted"},
        {MessageType::System,   "system"},
        {MessageType::Location, "location"},
        {MessageType::Contact,  "contact"},
    };

    for (int i = 0; i < messages.size(); ++i) {
        const auto& msg = messages[i];
        q.bindValue(":cid",    msg.chatId);
        q.bindValue(":sender", msg.sender);
        q.bindValue(":content",msg.content);
        q.bindValue(":ts",     msg.timestamp.toString(Qt::ISODate));
        q.bindValue(":from_me",msg.isFromMe ? 1 : 0);
        q.bindValue(":mtype",  typeStr.value(msg.type, "text"));
        q.bindValue(":mpath",  msg.mediaPath);
        q.bindValue(":mthumb", msg.mediaThumbnailPath);
        q.bindValue(":mdur",   msg.mediaDurationMs);
        q.bindValue(":rstat",  static_cast<int>(msg.readStatus));
        q.bindValue(":mmeta",  msg.mediaMeta);
        q.bindValue(":wave",   msg.waveform);
        q.bindValue(":elbl",   msg.editedText);
        if (!q.exec()) {
            Logger::error("Message insert error: " + q.lastError().text().toStdString());
            m_db.rollback();
            // Restore PRAGMAs
            pragma.exec("PRAGMA synchronous=NORMAL");
            pragma.exec("PRAGMA journal_mode=DELETE");
            pragma.exec("PRAGMA locking_mode=NORMAL");
            return false;
        }

        if (progressCallback && (((i + 1) % 500 == 0) || (i + 1 == messages.size()))) {
            progressCallback(i + 1, messages.size());
        }

        // Progress log — every 25,000 messages
        if ((i + 1) % 25000 == 0) {
            Logger::info(QString("DB insert progress: %1/%2")
                         .arg(i + 1).arg(messages.size()).toStdString());
        }
    }

    bool ok = m_db.commit();

    // Reset PRAGMAs to safe defaults
    pragma.exec("PRAGMA synchronous=NORMAL");
    pragma.exec("PRAGMA journal_mode=DELETE");
    pragma.exec("PRAGMA locking_mode=NORMAL");

    Logger::info(("DB insert completed: " + QString::number(messages.size()) + " messages").toStdString());
    return ok;
}

QList<Message> DatabaseManager::messagesForChat(int chatId)
{
    QList<Message> msgs;
    QSqlQuery q(m_db);
    q.prepare(R"(
        SELECT id, chat_id, sender, content, timestamp, is_from_me,
               message_type, media_path, media_thumbnail_path,
               media_duration_ms, read_status, media_meta, waveform, edited_label
        FROM messages WHERE chat_id=:cid ORDER BY timestamp ASC
    )");
    q.bindValue(":cid", chatId);
    q.exec();

    static const QMap<QString, MessageType> strType = {
        {"text",     MessageType::Text},     {"image",   MessageType::Image},
        {"video",    MessageType::Video},    {"audio",   MessageType::Audio},
        {"ptt",      MessageType::Ptt},      {"sticker", MessageType::Sticker},
        {"document", MessageType::Document}, {"deleted", MessageType::Deleted},
        {"system",   MessageType::System},   {"location",MessageType::Location},
        {"contact",  MessageType::Contact},
    };

    while (q.next()) {
        Message m;
        m.id                  = q.value(0).toInt();
        m.chatId              = q.value(1).toInt();
        m.sender              = q.value(2).toString();
        m.content             = q.value(3).toString();
        m.timestamp           = QDateTime::fromString(q.value(4).toString(), Qt::ISODate);
        m.isFromMe            = q.value(5).toInt() == 1;
        m.type                = strType.value(q.value(6).toString(), MessageType::Text);
        m.mediaPath           = q.value(7).toString();
        m.mediaThumbnailPath  = q.value(8).toString();
        m.mediaDurationMs     = q.value(9).toLongLong();
        m.mediaMeta           = q.value(11).toString();
        m.waveform            = q.value(12).toString();
        m.editedText          = q.value(13).toString();
        msgs.append(m);
    }
    return msgs;
}

int DatabaseManager::messageCountForChat(int chatId)
{
    QSqlQuery q(m_db);
    q.prepare("SELECT COUNT(*) FROM messages WHERE chat_id=:cid");
    q.bindValue(":cid", chatId);
    if (q.exec() && q.next())
        return q.value(0).toInt();
    return 0;
}

// Calculate total height without loading all messages.
// Reads only message_type counts (very fast SQL GROUP BY).
// Same logic as fixed heights in MessageBubble.qml:
//   image/video → 208+12=220px, audio/ptt → 64+8=72px,
//   sticker → 176+12=188px, location → 170+8=178px,
//   contact → 80+8=88px, document → 74+8=82px,
//   system → 36px, deleted/text → 70px (average value)
// + For date separator: every new day +40px (average: ~5% of messages)
qint64 DatabaseManager::estimateTotalHeight(int chatId)
{
    QSqlQuery q(m_db);
    q.prepare(R"(
        SELECT message_type, media_meta, COUNT(*) as cnt
        FROM messages
        WHERE chat_id=:cid
        GROUP BY message_type, (CASE WHEN media_meta='omitted' THEN 1 ELSE 0 END)
    )");
    q.bindValue(":cid", chatId);

    qint64 total = 0;
    int msgCount = 0;

    if (q.exec()) {
        while (q.next()) {
            const QString type    = q.value(0).toString();
            const QString meta    = q.value(1).toString();
            const int     cnt     = q.value(2).toInt();
            bool omitted = (meta == "omitted");
            int h = 70; // default: text/deleted

            if (type == "image" || type == "video")
                h = omitted ? 72 + 8 : 208 + 12;
            else if (type == "audio" || type == "ptt")
                h = omitted ? 60 + 8 : 64 + 8;
            else if (type == "sticker")
                h = omitted ? 60 + 8 : 176 + 12;
            else if (type == "location")
                h = 170 + 8;
            else if (type == "contact")
                h = 80 + 8;
            else if (type == "document")
                h = 74 + 8;
            else if (type == "system")
                h = 36;

            total += static_cast<qint64>(h) * cnt;
            msgCount += cnt;
        }
    }

    // Addition for date separators: count the total number of days
    QSqlQuery dq(m_db);
    dq.prepare(R"(
        SELECT COUNT(DISTINCT date(timestamp)) FROM messages WHERE chat_id=:cid
    )");
    dq.bindValue(":cid", chatId);
    if (dq.exec() && dq.next()) {
        total += dq.value(0).toInt() * 40;
    }

    // Header + footer (Items in MessagePanel)
    total += 80;

    return total;
}


QList<Message> DatabaseManager::messagesForChatPaged(int chatId, int offset, int limit)
{
    QList<Message> msgs;
    QSqlQuery q(m_db);
    q.prepare(R"(
        SELECT id, chat_id, sender, content, timestamp, is_from_me,
               message_type, media_path, media_thumbnail_path,
               media_duration_ms, read_status, media_meta, waveform, edited_label
        FROM messages WHERE chat_id=:cid ORDER BY timestamp ASC
        LIMIT :lim OFFSET :off
    )");
    q.bindValue(":cid", chatId);
    q.bindValue(":lim", limit);
    q.bindValue(":off", offset);
    q.exec();

    static const QMap<QString, MessageType> strType = {
        {"text",     MessageType::Text},     {"image",   MessageType::Image},
        {"video",    MessageType::Video},    {"audio",   MessageType::Audio},
        {"ptt",      MessageType::Ptt},      {"sticker", MessageType::Sticker},
        {"document", MessageType::Document}, {"deleted", MessageType::Deleted},
        {"system",   MessageType::System},   {"location",MessageType::Location},
        {"contact",  MessageType::Contact},
    };

    while (q.next()) {
        Message m;
        m.id                  = q.value(0).toInt();
        m.chatId              = q.value(1).toInt();
        m.sender              = q.value(2).toString();
        m.content             = q.value(3).toString();
        m.timestamp           = QDateTime::fromString(q.value(4).toString(), Qt::ISODate);
        m.isFromMe            = q.value(5).toInt() == 1;
        m.type                = strType.value(q.value(6).toString(), MessageType::Text);
        m.mediaPath           = q.value(7).toString();
        m.mediaThumbnailPath  = q.value(8).toString();
        m.mediaDurationMs     = q.value(9).toLongLong();
        m.mediaMeta           = q.value(11).toString();
        m.waveform            = q.value(12).toString();
        m.editedText          = q.value(13).toString();
        msgs.append(m);
    }
    return msgs;
}

QList<Message> DatabaseManager::searchMessages(int chatId, const QString& query)
{
    QList<Message> results;
    if (query.trimmed().isEmpty()) return results;

    QSqlQuery q(m_db);
    q.prepare(R"(
        SELECT id, chat_id, sender, content, timestamp, is_from_me,
               message_type, media_path, media_thumbnail_path,
               media_duration_ms, read_status
        FROM messages
        WHERE chat_id=:cid AND content LIKE :q
        ORDER BY timestamp ASC
    )");
    q.bindValue(":cid", chatId);
    q.bindValue(":q",   "%" + query + "%");
    q.exec();

    while (q.next()) {
        Message m;
        m.id        = q.value(0).toInt();
        m.chatId    = q.value(1).toInt();
        m.sender    = q.value(2).toString();
        m.content   = q.value(3).toString();
        m.timestamp = QDateTime::fromString(q.value(4).toString(), Qt::ISODate);
        m.isFromMe  = q.value(5).toInt() == 1;
        results.append(m);
    }
    return results;
}

bool DatabaseManager::updateLastMessageTime(int chatId)
{
    QSqlQuery q(m_db);
    q.prepare(R"(
        UPDATE chats SET last_message_time=(
            SELECT timestamp FROM messages WHERE chat_id=:cid
            ORDER BY timestamp DESC LIMIT 1
        ) WHERE id=:cid
    )");
    q.bindValue(":cid", chatId);
    return q.exec();
}

bool DatabaseManager::updateMessageWaveform(int messageId, const QString& waveform)
{
    if (messageId <= 0) return false;
    QSqlQuery q(m_db);
    q.prepare("UPDATE messages SET waveform=:wave WHERE id=:id");
    q.bindValue(":wave", waveform);
    q.bindValue(":id", messageId);
    return q.exec();
}

QString DatabaseManager::getSetting(const QString& key, const QString& def)
{
    QSqlQuery q(m_db);
    q.prepare("SELECT value FROM settings WHERE key=:k");
    q.bindValue(":k", key);
    if (q.exec() && q.next()) {
        return q.value(0).toString();
    }
    return def;
}

void DatabaseManager::setSetting(const QString& key, const QString& value)
{
    QSqlQuery q(m_db);
    q.prepare("INSERT OR REPLACE INTO settings (key, value) VALUES (:k, :v)");
    q.bindValue(":k", key);
    q.bindValue(":v", value);
    if (!q.exec()) {
        Logger::error("Setting save error: " + q.lastError().text().toStdString());
    }
}
