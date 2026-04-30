#pragma once
#include "Chat.h"
#include <QAbstractListModel>
#include <QList>
#include <QLocale>

class LanguageManager;

// Qt model for the chat list in the left panel
class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int visibleCount READ visibleCount NOTIFY visibleCountChanged)
public:
    enum Roles {
        IdRole          = Qt::UserRole + 1,
        ContactNameRole,
        LastMessageRole,
        LastMessageTimeRole,
        AvatarPathRole,
        UnreadCountRole,
        InitialsRole,       // Initials for avatar (eg "JD")
        AvatarColorRole,    // Avatar background color (fixed, calculated from name)
        MatchesSearchRole,  // Whether this chat matches left-panel search query
    };
    Q_ENUM(Roles)

    explicit ChatListModel(QObject* parent = nullptr);

    // Model interface
    int      rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // Fill in the information
    void setChats(const QList<Chat>& chats);
    void addChat(const Chat& chat);
    void updateChat(const Chat& chat);
    bool removeChat(int chatId);
    void setLanguageManager(LanguageManager* lm);
    Q_INVOKABLE void setSearchQuery(const QString& query);
    Q_INVOKABLE void clearSearch();
    int visibleCount() const { return m_visibleCount; }

    // Find Chat by ID
    int indexOfChat(int chatId) const;
    Chat chatAt(int row) const;

private:
    // Calculate fixed color from name (like in WAPage)
    static QString colorForName(const QString& name);
    // Take initials of name (max 2)
    static QString initialsForName(const QString& name);
    static QLocale localeForLanguage(const QString& languageName);
    static QString normalizeAzerbaijani(const QString& text);
    bool chatMatchesSearch(const Chat& chat) const;
    void refreshVisibleCount();

    QList<Chat> m_chats;
    LanguageManager* m_langManager = nullptr;
    QString m_searchQuery;
    QString m_normalizedSearchQuery;
    int m_visibleCount = 0;

signals:
    void visibleCountChanged();
};
