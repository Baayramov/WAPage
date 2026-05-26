#include "MessageListModel.h"
#include "utils/WAPageTextFormatter.h"
#include "utils/Logger.h"
#include "core/LanguageManager.h"
#include "core/DatabaseManager.h"

#include <QDateTime>
#include <QElapsedTimer>
#include <QFileInfo>
#include <QRegularExpression>

static const QMap<MessageType, QString> TYPE_STR = {
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

static qreal estimateMessageBubbleHeight(const Message& msg)
{
    const bool omitted = (msg.mediaMeta == "omitted");
    switch (msg.type) {
    case MessageType::Image:
    case MessageType::Video:
        return omitted ? 68.0 : 220.0;
    case MessageType::Audio:
    case MessageType::Ptt:
        return omitted ? 68.0 : 72.0;
    case MessageType::Sticker:
        return omitted ? 68.0 : 188.0;
    case MessageType::Location:
        return 178.0;
    case MessageType::Contact:
        return 88.0;
    case MessageType::Document:
        return 82.0;
    case MessageType::System:
        return 36.0;
    case MessageType::Deleted:
    case MessageType::Text:
    default:
        return 70.0;
    }
}

static qreal estimateInsertedHeight(const QList<Message>& older, const QList<Message>& current)
{
    if (older.isEmpty()) return 0.0;

    qreal total = 0.0;
    QDate prevDate;
    bool hasPrevDate = false;

    for (const Message& msg : older) {
        total += estimateMessageBubbleHeight(msg);

        const QDate currentDate = msg.timestamp.date();
        if (!hasPrevDate || currentDate != prevDate) {
            total += 40.0; // date separator
        }
        prevDate = currentDate;
        hasPrevDate = true;
    }

    if (!current.isEmpty() && older.last().timestamp.date() == current.first().timestamp.date()) {
        // The first existing message will no longer be row0; 
        total -= 40.0;
    }

    return qMax<qreal>(0.0, total);
}

MessageListModel::MessageListModel(QObject* parent)
    : QAbstractListModel(parent)
{}

int MessageListModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) return 0;
    return m_messages.size();
}

QString MessageListModel::normalizeAzerbaijani(const QString& text)
{
    QString result = text.toLower();
    result.replace(QChar(0x0259), 'e');
    result.replace(QChar(0x018F), 'e');
    result.replace(QChar(0x00FC), 'u');
    result.replace(QChar(0x00DC), 'u');
    result.replace(QChar(0x00F6), 'o');
    result.replace(QChar(0x00D6), 'o');
    result.replace(QChar(0x011F), 'g');
    result.replace(QChar(0x011E), 'g');
    result.replace(QChar(0x0131), 'i');
    result.replace(QChar(0x0130), 'i');
    result.replace(QChar(0x015F), 's');
    result.replace(QChar(0x015E), 's');
    result.replace(QChar(0x00E7), 'c');
    result.replace(QChar(0x00C7), 'c');
    return result;
}

bool MessageListModel::containsNormalized(const QString& text, const QString& query) const
{
    QString normalizedText = normalizeAzerbaijani(text);
    return normalizedText.contains(m_normalizedQuery, Qt::CaseInsensitive);
}

QString MessageListModel::highlightMatches(const QString& content, int messageIndex) const
{
    if (m_searchQuery.isEmpty()) return WAPageTextFormatter::formatFull(content);
    
    QString formatted = WAPageTextFormatter::formatFull(content);
    QString normalizedContent = normalizeAzerbaijani(content);
    
    int currentMsgIndex = -1;
    if (m_currentSearchResult >= 0 && m_currentSearchResult < m_searchResultIndices.size()) {
        currentMsgIndex = m_searchResultIndices[m_currentSearchResult];
    }
    
    QString bgColor = (messageIndex == currentMsgIndex) ? "#00CED1" : "#FFC107";
    
    int pos = 0;
    QString result;
    int lastPos = 0;
    
    while ((pos = normalizedContent.indexOf(m_normalizedQuery, pos, Qt::CaseInsensitive)) != -1) {
        result += formatted.mid(lastPos, pos - lastPos);
        QString matchedText = content.mid(pos, m_searchQuery.length());
        result += QString("<mark style='background:%1;color:#000;'>%2</mark>")
                  .arg(bgColor)
                  .arg(matchedText.toHtmlEscaped());
        pos += m_searchQuery.length();
        lastPos = pos;
    }
    result += formatted.mid(lastPos);
    
    return result.isEmpty() ? formatted : result;
}

bool MessageListModel::computeShowDateSep(int row) const
{
    if (row == 0) return true;
    const QDate prev = m_messages[row - 1].timestamp.date();
    const QDate cur  = m_messages[row].timestamp.date();
    return prev != cur;
}

bool MessageListModel::computeIsFirstInGroup(int row) const
{
    if (row == 0) return true;
    const Message& prev = m_messages[row - 1];
    const Message& cur  = m_messages[row];
    if (prev.type == MessageType::System) return true;
    if (prev.sender != cur.sender) return true;
    return prev.timestamp.secsTo(cur.timestamp) > 180;
}

bool MessageListModel::computeIsLastInGroup(int row) const
{
    if (row == m_messages.size() - 1) return true;
    const Message& cur  = m_messages[row];
    const Message& next = m_messages[row + 1];
    if (next.type == MessageType::System) return true;
    if (next.sender != cur.sender) return true;
    return cur.timestamp.secsTo(next.timestamp) > 180;
}

QVariant MessageListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= m_messages.size())
        return {};

    const int row    = index.row();
    const Message& m = m_messages.at(row);

    switch (role) {
    case IdRole:        return m.id;
    case SenderRole:    return m.sender;
    case SenderAvatarRole: return m_senderAvatars.value(m.sender);
    case ContentRole:   return m.content;
    case FormattedContentRole: {
        if (m.type == MessageType::Deleted) {
            return m.content; // Return raw marker — QML deletedComp handles display
        }
        if (m.type == MessageType::System) {
            // Translate normalised __sys: tokens to the current UI language.
            // Falls back to plain content if not a token (legacy or unrecognised).
            if (m_langManager && m.content.startsWith(QStringLiteral("__sys:")))
                return m_langManager->translateSystemMessage(m.content);
            return m.content;
        }
        if (!m_searchQuery.isEmpty() && m.type == MessageType::Text) {
            return highlightMatches(m.content, row);
        }
        // Lazy cache: formatFull() runs once per message per load session.
        if (m.cachedFormatted.isEmpty()) {
            m.cachedFormatted = WAPageTextFormatter::formatFull(m.content);
        }
        return m.cachedFormatted;
    }
    case TimestampRole: return m.timestamp.toString("hh:mm");
    case DateRole:
        if (m_langManager)
            return m_langManager->formatDate(m.timestamp);
        return m.timestamp.toString("d MMMM yyyy");
    case IsFromMeRole:  return m.isFromMe;
    case MessageTypeRole: return TYPE_STR.value(m.type, "text");
    case MediaPathRole: return m.mediaPath;
    case MediaThumbRole: return m.mediaThumbnailPath;
    case MediaDurationRole: return formatDuration(m.mediaDurationMs);
    case ReadStatusRole:    return static_cast<int>(m.readStatus);
    case MediaMetaRole:     return m.mediaMeta;
    case WaveformRole:      return m.waveform;
    case ShowDateSeparatorRole: return computeShowDateSep(row);
    case IsFirstInGroupRole:    return computeIsFirstInGroup(row);
    case IsLastInGroupRole:     return computeIsLastInGroup(row);
    case EditedTextRole: return m.editedText;
    default: return {};
    }
}

QHash<int, QByteArray> MessageListModel::roleNames() const
{
    return {
        {IdRole,                "msgId"},
        {SenderRole,            "sender"},
        {SenderAvatarRole,      "senderAvatar"},
        {ContentRole,           "content"},
        {FormattedContentRole,  "formattedContent"},
        {TimestampRole,         "msgTime"},
        {DateRole,              "msgDate"},
        {IsFromMeRole,          "isFromMe"},
        {MessageTypeRole,       "msgType"},
        {MediaPathRole,         "mediaPath"},
        {MediaThumbRole,        "mediaThumbnail"},
        {MediaDurationRole,     "mediaDuration"},
        {ReadStatusRole,        "readStatus"},
        {MediaMetaRole,         "mediaMeta"},
        {WaveformRole,          "waveform"},
        {ShowDateSeparatorRole, "showDateSeparator"},
        {IsFirstInGroupRole,    "isFirstInGroup"},
        {IsLastInGroupRole,     "isLastInGroup"},
        {EditedTextRole,        "editedText"},
    };
}

void MessageListModel::setMessages(const QList<Message>& messages)
{
    beginResetModel();
    m_messages     = messages;
    m_senderAvatars.clear();
    m_totalCount   = messages.size();
    m_loadedOffset = 0;
    m_allLoaded    = true;
    m_loading      = false;
    m_db           = nullptr;
    m_chatId       = -1;
    m_searchResultIndices.clear();
    m_currentSearchResult = -1;
    endResetModel();
    emit countChanged();
    emit totalCountChanged();
}

void MessageListModel::initFromDatabase(DatabaseManager* db, int chatId, int totalMsgCount)
{
    m_db         = db;
    m_chatId     = chatId;

    int safeTotalCount = totalMsgCount;
    if (safeTotalCount <= 0 && db && chatId >= 0) {
        safeTotalCount = db->messageCountForChat(chatId);
        Logger::warn(QString("initFromDatabase: total count fallback used for chat=%1, recounted=%2")
                     .arg(chatId)
                     .arg(safeTotalCount));
    }
    m_totalCount = qMax(0, safeTotalCount);

    // Precalculate total height (SQL GROUP BY — very fast)
    m_estimatedTotalHeight = db->estimateTotalHeight(chatId);

    beginResetModel();
    m_messages.clear();
    m_senderAvatars.clear();
    m_searchResultIndices.clear();
    m_currentSearchResult = -1;
    m_allLoaded = false;
    m_loading   = false;

    if (m_totalCount <= SMALL_CHAT_MAX) {
        // Small chat — download all
        m_messages     = db->messagesForChat(chatId);
        m_loadedOffset = 0;
        m_allLoaded    = true;
    } else {
        // Large chat — load only the last INITIAL_LOAD message
        int offset     = qMax(0, m_totalCount - INITIAL_LOAD);
        m_messages     = db->messagesForChatPaged(chatId, offset, INITIAL_LOAD);
        m_loadedOffset = offset;
        m_allLoaded    = (offset == 0);
    }

    endResetModel();
    emit countChanged();
    emit totalCountChanged();
    emit estimatedTotalHeightChanged();
}

bool MessageListModel::loadMoreOlderMessages(qreal currentContentY, qreal currentContentHeight)
{
    if (m_loading || !m_db || m_chatId < 0) {
        Logger::info(QString("[SCROLL-RESTORE] cpp:GUARD_BUSY chat=%1 loading=%2 db=%3")
                     .arg(m_chatId)
                     .arg(m_loading)
                     .arg(m_db ? 1 : 0));
        return false;
    }
    if (m_allLoaded || m_loadedOffset <= 0) {
        Logger::info(QString("[SCROLL-RESTORE] cpp:GUARD_ALL_LOADED chat=%1 allLoaded=%2 offset=%3")
                     .arg(m_chatId)
                     .arg(m_allLoaded)
                     .arg(m_loadedOffset));
        m_allLoaded = true;
        m_loadedOffset = 0;
        return false;
    }

    QElapsedTimer timer;
    timer.start();

    m_loading = true;
    emit loadingChanged();

    const int prevOffset = m_loadedOffset;
    const int fetchCount = qMin(PAGE_SIZE, m_loadedOffset);
    const int newOffset  = m_loadedOffset - fetchCount;

    Logger::info(QString("[SCROLL-RESTORE] cpp:enter chat=%1 cY=%2 cH=%3 prevOffset=%4 fetchCount=%5 newOffset=%6 totalCount=%7 loadedSize=%8")
                 .arg(m_chatId)
                 .arg(currentContentY, 0, 'f', 1)
                 .arg(currentContentHeight, 0, 'f', 1)
                 .arg(prevOffset)
                 .arg(fetchCount)
                 .arg(newOffset)
                 .arg(m_totalCount)
                 .arg(m_messages.size()));

    QList<Message> older = m_db->messagesForChatPaged(m_chatId, newOffset, fetchCount);

    if (older.isEmpty()) {
        Logger::warn(QString("[SCROLL-RESTORE] cpp:EMPTY_PAGE chat=%1 offset=%2 fetch=%3")
                     .arg(m_chatId)
                     .arg(newOffset)
                     .arg(fetchCount));
        m_loadedOffset = qMax(0, newOffset);
        if (m_loadedOffset == 0) {
            m_allLoaded = true;
        }
        m_loading = false;
        emit loadingChanged();

        Logger::warn(QString("loadMoreOlderMessages: empty page chat=%1 offset=%2 fetch=%3 elapsed=%4ms")
                     .arg(m_chatId)
                     .arg(prevOffset)
                     .arg(fetchCount)
                     .arg(timer.elapsed()));
        emit scrollRestoreNeeded(currentContentY, 0);
        return false;
    }

    // Save values ​​from QML before insert operation
    const qreal savedContentY      = currentContentY;
    const qreal savedContentHeight = currentContentHeight;
    qreal insertedHeight = estimateInsertedHeight(older, m_messages);

    beginInsertRows(QModelIndex(), 0, older.size() - 1);
    QList<Message> merged;
    merged.reserve(older.size() + m_messages.size());
    merged = older;
    merged.append(m_messages);
    m_messages.swap(merged);

    m_loadedOffset = newOffset;
    if (m_loadedOffset <= 0) {
        m_allLoaded    = true;
        m_loadedOffset = 0;
    }
    endInsertRows();

    m_loading = false;
    emit loadingChanged();
    emit countChanged();

    if (insertedHeight <= 0.0) {
        const qreal fallbackAvg = (m_totalCount > 0 && m_estimatedTotalHeight > 0)
                                  ? static_cast<qreal>(m_estimatedTotalHeight) / static_cast<qreal>(m_totalCount)
                                  : 70.0;
        insertedHeight = older.size() * fallbackAvg;
    }

    const qreal estimatedContentHeightAfterInsert = qMax(savedContentHeight, savedContentHeight + insertedHeight);
    const qreal maxContentY = qMax<qreal>(0.0, estimatedContentHeightAfterInsert - 1.0);
    const qreal newContentY = qBound<qreal>(0.0, savedContentY + insertedHeight, maxContentY);

    Logger::debug(QString("loadMoreOlderMessages: chat=%1 offset=%2->%3 fetch=%4 returned=%5 y=%6->%7 elapsed=%8ms")
                  .arg(m_chatId)
                  .arg(prevOffset)
                  .arg(m_loadedOffset)
                  .arg(fetchCount)
                  .arg(older.size())
                  .arg(savedContentY, 0, 'f', 1)
                  .arg(newContentY, 0, 'f', 1)
                  .arg(timer.elapsed()));

    Logger::info(QString("[SCROLL-RESTORE] cpp:emit chat=%1 inserted=%2 estInsertedH=%3 savedY=%4 savedH=%5 -> newContentY=%6 maxContentY=%7")
                 .arg(m_chatId)
                 .arg(older.size())
                 .arg(insertedHeight, 0, 'f', 1)
                 .arg(savedContentY, 0, 'f', 1)
                 .arg(savedContentHeight, 0, 'f', 1)
                 .arg(newContentY, 0, 'f', 1)
                 .arg(maxContentY, 0, 'f', 1));

    emit scrollRestoreNeeded(newContentY, older.size());
    return true;
}

void MessageListModel::ensureAllLoaded()
{
    if (m_allLoaded || !m_db || m_chatId < 0) return;

    QElapsedTimer timer;
    timer.start();

    m_loading = true;
    emit loadingChanged();

    QList<Message> allOlder = m_db->messagesForChatPaged(m_chatId, 0, m_loadedOffset);

    if (!allOlder.isEmpty()) {
        beginInsertRows(QModelIndex(), 0, allOlder.size() - 1);
        QList<Message> merged;
        merged.reserve(allOlder.size() + m_messages.size());
        merged = allOlder;
        merged.append(m_messages);
        m_messages.swap(merged);
        endInsertRows();
    }

    m_loadedOffset = 0;
    m_allLoaded    = true;
    m_loading      = false;
    emit loadingChanged();
    emit countChanged();

    Logger::debug(QString("ensureAllLoaded: chat=%1 inserted=%2 totalLoaded=%3 elapsed=%4ms")
                  .arg(m_chatId)
                  .arg(allOlder.size())
                  .arg(m_messages.size())
                  .arg(timer.elapsed()));
}

QList<int> MessageListModel::setWaveformByPath(const QString& audioPath,
                                               const QString& waveform)
{
    QList<int> updatedIds;
    if (audioPath.isEmpty() || waveform.isEmpty()) return updatedIds;

    // Walk the loaded window once. The same audio file can in theory appear
    // in multiple messages (e.g. forwarded), so we update every match.
    for (int i = 0; i < m_messages.size(); ++i) {
        Message& m = m_messages[i];
        if (m.mediaPath != audioPath) continue;
        if (m.waveform == waveform) continue;   // already up to date

        m.waveform = waveform;
        updatedIds.append(m.id);
        emit dataChanged(index(i), index(i), {WaveformRole});
    }

    // Persist for every affected row so future sessions skip the FFmpeg
    // decode entirely. DB writes happen on the UI thread (caller hops here
    // via QueuedConnection); a single row UPDATE by primary key is sub-ms.
    if (m_db) {
        for (int id : updatedIds) {
            m_db->updateMessageWaveform(id, waveform);
        }
    }

    Logger::info(QString("[WAPage-AUDIT] waveform: cached rows=%1 dbPersisted=%2 file=%3")
                     .arg(updatedIds.size())
                     .arg(m_db ? updatedIds.size() : 0)
                     .arg(QFileInfo(audioPath).fileName()));

    return updatedIds;
}

void MessageListModel::clear()
{
    beginResetModel();
    m_messages.clear();
    m_senderAvatars.clear();
    m_totalCount   = 0;
    m_loadedOffset = 0;
    m_allLoaded    = true;
    m_loading      = false;
    m_estimatedTotalHeight = 0;
    m_db           = nullptr;
    m_chatId       = -1;
    m_searchResultIndices.clear();
    m_currentSearchResult = -1;
    endResetModel();
    emit countChanged();
    emit totalCountChanged();
}

void MessageListModel::setSenderAvatarMap(const QHash<QString, QString>& avatarsBySender)
{
    m_senderAvatars = avatarsBySender;
    if (!m_messages.isEmpty()) {
        emit dataChanged(index(0), index(m_messages.size() - 1), {SenderAvatarRole});
    }
}

void MessageListModel::renameSender(const QString& oldName, const QString& newName)
{
    if (oldName == newName || oldName.trimmed().isEmpty() || newName.trimmed().isEmpty()) {
        return;
    }

    bool changed = false;
    for (Message& msg : m_messages) {
        if (msg.sender == oldName) {
            msg.sender = newName;
            changed = true;
        }
    }

    if (m_senderAvatars.contains(oldName)) {
        const QString avatar = m_senderAvatars.take(oldName);
        if (!m_senderAvatars.contains(newName)) {
            m_senderAvatars.insert(newName, avatar);
        }
    }

    if (changed && !m_messages.isEmpty()) {
        emit dataChanged(index(0), index(m_messages.size() - 1),
                         {SenderRole, SenderAvatarRole, IsFirstInGroupRole, IsLastInGroupRole});
    }
}

void MessageListModel::setSearchQuery(const QString& q)
{
    m_searchQuery     = q;
    m_normalizedQuery = normalizeAzerbaijani(q);
    m_currentSearchResult = -1;
    m_searchResultIndices.clear();
    
    if (!q.isEmpty()) {
        // Download all first to search
        if (!m_allLoaded) {
            ensureAllLoaded();
        }
        for (int i = 0; i < m_messages.size(); ++i) {
            if (containsNormalized(m_messages[i].content, q)) {
                m_searchResultIndices.append(i);
            }
        }
        if (!m_searchResultIndices.isEmpty()) {
            m_currentSearchResult = 0;
        }
    }
    
    if (!m_messages.isEmpty())
        emit dataChanged(index(0), index(m_messages.size() - 1),
                         {FormattedContentRole});
}

void MessageListModel::clearSearch()
{
    m_searchQuery.clear();
    m_normalizedQuery.clear();
    m_currentSearchResult = -1;
    m_searchResultIndices.clear();
    
    if (!m_messages.isEmpty())
        emit dataChanged(index(0), index(m_messages.size() - 1),
                         {FormattedContentRole});
}

int MessageListModel::firstSearchResultIndex() const
{
    if (m_searchResultIndices.isEmpty()) return -1;
    return m_searchResultIndices.first();
}

int MessageListModel::searchResultCount() const
{
    return m_searchResultIndices.size();
}

int MessageListModel::searchResultIndexAt(int n) const
{
    if (n < 0 || n >= m_searchResultIndices.size()) return -1;
    return m_searchResultIndices[n];
}

void MessageListModel::setCurrentSearchResult(int resultNum)
{
    if (resultNum < 0 || resultNum >= m_searchResultIndices.size()) return;
    if (m_currentSearchResult == resultNum) return;
    
    int oldMsgIndex = (m_currentSearchResult >= 0 && m_currentSearchResult < m_searchResultIndices.size())
                      ? m_searchResultIndices[m_currentSearchResult] : -1;
    int newMsgIndex = m_searchResultIndices[resultNum];
    
    m_currentSearchResult = resultNum;
    
    if (oldMsgIndex >= 0)
        emit dataChanged(index(oldMsgIndex), index(oldMsgIndex), {FormattedContentRole});
    emit dataChanged(index(newMsgIndex), index(newMsgIndex), {FormattedContentRole});
}

QString MessageListModel::formatDuration(qint64 ms)
{
    if (ms <= 0) return "0:00";
    const int totalSec = static_cast<int>(ms / 1000);
    const int mins     = totalSec / 60;
    const int secs     = totalSec % 60;
    return QString("%1:%2").arg(mins).arg(secs, 2, 10, QChar('0'));
}
