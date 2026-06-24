#include "ChatListModel.h"
#include "core/LanguageManager.h"
#include <QDateTime>
#include <QLocale>

// Avatar colors in WAPage (fixed palette)
static const QStringList AVATAR_COLORS = {
    "#D4371C", "#E65100", "#BF360C", "#AD1457",
    "#880E4F", "#6A1B9A", "#4527A0", "#1565C0",
    "#0277BD", "#00695C", "#2E7D32", "#558B2F",
    "#F57F17", "#E65100", "#4E342E", "#37474F",
};

static QString localizedYesterday(const QString& languageName)
{
    static const QMap<QString, QString> labels = {
        {"Azerbaijani", "Dünən"},
        {"Turkish",     "Dün"},
        {"English",     "Yesterday"},
        {"Spanish",     "Ayer"},
        {"Portuguese",  "Ontem"},
        {"Russian",     "Вчера"},
        {"Italian",     "Ieri"},
        {"Arabic",      "أمس"},
        {"French",      "Hier"},
        {"German",      "Gestern"},
        {"Chinese",     "昨天"},
        {"Hindi",       "कल"},
        {"Japanese",    "昨日"},
        {"Korean",      "어제"},
        {"Mongolian",   "Өчигдөр"},
        {"Polish",      "Wczoraj"},
        {"Ukrainian",   "Вчора"},
        {"Uzbek",       "Kecha"}
    };

    return labels.value(languageName, QStringLiteral("Yesterday"));
}

ChatListModel::ChatListModel(QObject* parent)
    : QAbstractListModel(parent)
{}

QString ChatListModel::normalizeAzerbaijani(const QString& text)
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

bool ChatListModel::chatMatchesSearch(const Chat& chat) const
{
    if (m_normalizedSearchQuery.isEmpty()) {
        return true;
    }
    return normalizeAzerbaijani(chat.contactName).contains(m_normalizedSearchQuery, Qt::CaseInsensitive);
}

void ChatListModel::refreshVisibleCount()
{
    int count = 0;
    for (const Chat& chat : m_chats) {
        if (chatMatchesSearch(chat)) {
            ++count;
        }
    }

    if (m_visibleCount != count) {
        m_visibleCount = count;
        emit visibleCountChanged();
    }
}

void ChatListModel::setSearchQuery(const QString& query)
{
    const QString trimmed = query.trimmed();
    const QString normalized = normalizeAzerbaijani(trimmed);

    if (trimmed == m_searchQuery && normalized == m_normalizedSearchQuery) {
        return;
    }

    m_searchQuery = trimmed;
    m_normalizedSearchQuery = normalized;

    refreshVisibleCount();
    if (!m_chats.isEmpty()) {
        emit dataChanged(index(0), index(m_chats.size() - 1), {MatchesSearchRole});
    }
}

void ChatListModel::clearSearch()
{
    setSearchQuery(QString());
}

QLocale ChatListModel::localeForLanguage(const QString& languageName)
{
    static const QMap<QString, QLocale> localeMap = {
        {"Azerbaijani", QLocale(QLocale::Azerbaijani)},
        {"Turkish",     QLocale(QLocale::Turkish)},
        {"English",     QLocale(QLocale::English)},
        {"Spanish",     QLocale(QLocale::Spanish)},
        {"Portuguese",  QLocale(QLocale::Portuguese)},
        {"Russian",     QLocale(QLocale::Russian)},
        {"Italian",     QLocale(QLocale::Italian)},
        {"Arabic",      QLocale(QLocale::Arabic)},
        {"French",      QLocale(QLocale::French)},
        {"German",      QLocale(QLocale::German)},
        {"Chinese",     QLocale(QLocale::Chinese)},
        {"Hindi",       QLocale(QLocale::Hindi)},
        {"Japanese",    QLocale(QLocale::Japanese)},
        {"Korean",      QLocale(QLocale::Korean)},
        {"Mongolian",   QLocale(QLocale::Mongolian)},
        {"Polish",      QLocale(QLocale::Polish)},
        {"Ukrainian",   QLocale(QLocale::Ukrainian)},
        {"Uzbek",       QLocale(QLocale::Uzbek)}
    };

    return localeMap.value(languageName, QLocale::system());
}

void ChatListModel::setLanguageManager(LanguageManager* lm)
{
    if (m_langManager == lm) {
        return;
    }

    if (m_langManager) {
        QObject::disconnect(m_langManager, nullptr, this, nullptr);
    }

    m_langManager = lm;

    if (m_langManager) {
        QObject::connect(m_langManager, &LanguageManager::languageChanged, this, [this]() {
            if (m_chats.isEmpty()) {
                return;
            }
            emit dataChanged(index(0), index(m_chats.size() - 1));
        });
    }

    if (!m_chats.isEmpty()) {
        emit dataChanged(index(0), index(m_chats.size() - 1));
    }
}

int ChatListModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) return 0;
    return m_chats.size();
}

QVariant ChatListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= m_chats.size())
        return {};

    const Chat& ch = m_chats.at(index.row());

    switch (role) {
    case IdRole:            return ch.id;
    case ContactNameRole:   return ch.contactName;
    case LastMessageRole: {
        // System messages are stored as normalised "__sys:..." tokens. The chat
        // view localises them via LanguageManager::translateSystemMessage(); do
        // the same here so the left-side preview matches what the user sees in
        // the open conversation (and updates on language change because the
        // languageChanged hook already emits dataChanged for every row).
        const QString& preview = ch.lastMessagePreview;
        if (m_langManager && preview.startsWith(QStringLiteral("__sys:"))) {
            return m_langManager->translateSystemMessage(preview);
        }
        return preview;
    }
    case LastMessageTimeRole: {
        if (!ch.lastMessageTime.isValid()) return QString();
        const QDateTime now = QDateTime::currentDateTime();
        const qint64 daysDiff = ch.lastMessageTime.daysTo(now);
        if (daysDiff == 0)
            return ch.lastMessageTime.toString("hh:mm");
        else if (daysDiff == 1) {
            if (m_langManager) {
                return localizedYesterday(m_langManager->currentLanguage());
            }
            return QStringLiteral("Yesterday");
        }
        else if (daysDiff < 7) {
            const QLocale locale = m_langManager
                ? localeForLanguage(m_langManager->currentLanguage())
                : QLocale::system();
            QString dayName = locale.toString(ch.lastMessageTime.date(), "dddd");
            if (!dayName.isEmpty()) {
                dayName = locale.toUpper(dayName.left(1)) + dayName.mid(1);
            }
            return dayName;
        }
        else
            return ch.lastMessageTime.toString("dd.MM.yyyy");
    }
    case AvatarPathRole:    return ch.customAvatarPath;
    case UnreadCountRole:   return ch.unreadCount;
    case InitialsRole:      return initialsForName(ch.contactName);
    case AvatarColorRole:   return colorForName(ch.contactName);
    case MatchesSearchRole: return chatMatchesSearch(ch);
    case IsLockedRole:      return ch.isLocked;
    default:                return {};
    }
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    return {
        {IdRole,              "chatId"},
        {ContactNameRole,     "contactName"},
        {LastMessageRole,     "lastMessage"},
        {LastMessageTimeRole, "lastMessageTime"},
        {AvatarPathRole,      "avatarPath"},
        {UnreadCountRole,     "unreadCount"},
        {InitialsRole,        "initials"},
        {AvatarColorRole,     "avatarColor"},
        {MatchesSearchRole,   "matchesSearch"},
        {IsLockedRole,        "isLocked"},
    };
}

void ChatListModel::setChats(const QList<Chat>& chats)
{
    beginResetModel();
    m_chats = chats;
    endResetModel();
    refreshVisibleCount();
}

void ChatListModel::addChat(const Chat& chat)
{
    beginInsertRows({}, 0, 0);
    m_chats.prepend(chat);
    endInsertRows();
    refreshVisibleCount();
}

void ChatListModel::updateChat(const Chat& chat)
{
    const int row = indexOfChat(chat.id);
    if (row < 0) return;
    m_chats[row] = chat;
    emit dataChanged(index(row), index(row), {ContactNameRole, LastMessageRole, LastMessageTimeRole,
                    AvatarPathRole, UnreadCountRole, InitialsRole, AvatarColorRole, MatchesSearchRole, IsLockedRole});
    refreshVisibleCount();
}

bool ChatListModel::removeChat(int chatId)
{
    const int row = indexOfChat(chatId);
    if (row < 0) return false;
    beginRemoveRows({}, row, row);
    m_chats.removeAt(row);
    endRemoveRows();
    refreshVisibleCount();
    return true;
}

int ChatListModel::indexOfChat(int chatId) const
{
    for (int i = 0; i < m_chats.size(); ++i)
        if (m_chats[i].id == chatId) return i;
    return -1;
}

Chat ChatListModel::chatAt(int row) const
{
    if (row < 0 || row >= m_chats.size()) return {};
    return m_chats[row];
}

QString ChatListModel::colorForName(const QString& name)
{
    QString cleanName = name.trimmed();
    if (cleanName.isEmpty()) return AVATAR_COLORS.first();
    
    // Strip tilde prefix for consistent color across tilde/no-tilde variants
    if (cleanName.startsWith("~ ")) {
        cleanName = cleanName.mid(2).trimmed();
    } else if (cleanName.startsWith('~')) {
        cleanName = cleanName.mid(1).trimmed();
    }
    
    if (cleanName.isEmpty()) return AVATAR_COLORS.first();
    
    int hash = 0;
    for (const QChar& ch : cleanName)
        hash = (hash * 31 + ch.unicode()) & 0x7FFFFFFF;
    return AVATAR_COLORS[hash % AVATAR_COLORS.size()];
}

QString ChatListModel::initialsForName(const QString& name)
{
    QString cleanName = name.trimmed();
    if (cleanName.isEmpty()) return "?";
    
    // Strip tilde prefix for initials calculation (iOS/Android compatibility)
    if (cleanName.startsWith("~ ")) {
        cleanName = cleanName.mid(2).trimmed();
    } else if (cleanName.startsWith('~')) {
        cleanName = cleanName.mid(1).trimmed();
    }
    
    if (cleanName.isEmpty()) return "?";
    
    const QStringList parts = cleanName.split(' ', Qt::SkipEmptyParts);
    if (parts.size() == 1)
        return parts[0].left(2).toUpper();
    return QString(parts[0][0]).toUpper() + QString(parts[1][0]).toUpper();
}
