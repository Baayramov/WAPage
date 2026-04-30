#pragma once
#include "Message.h"
#include "core/LanguageManager.h"
class DatabaseManager;
#include <QAbstractListModel>
#include <QHash>
#include <QList>
#include <QObject>

// Qt model for the message list in the right pane
// PERFORMANCE: Virtual windowed model — stores only downloaded messages.
// In large chats (400K messages), it loads lazily as you scroll.
class MessageListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)
    // Total number of messages (including those not yet downloaded)
    Q_PROPERTY(int totalCount READ totalCount NOTIFY totalCountChanged)
    // Is the download in progress?
    Q_PROPERTY(bool loading READ isLoading NOTIFY loadingChanged)
    // Approximate total height (px) of all messages (including unloaded)
    // To know ListView contentHeight in advance — rubber band fix
    Q_PROPERTY(qint64 estimatedTotalHeight READ estimatedTotalHeight NOTIFY estimatedTotalHeightChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        SenderRole,
        SenderAvatarRole,
        ContentRole,
        FormattedContentRole,  // HTML formatted text
        TimestampRole,         // "14:23" format
        DateRole,              // "May 27, 2024" — for the date separator
        IsFromMeRole,
        MessageTypeRole,       // "text","image","video","audio","ptt","sticker","document","deleted","system","location","contact"
        MediaPathRole,
        MediaThumbRole,
        MediaDurationRole,     // "0:43" format
        ReadStatusRole,        // 1,2,3
        MediaMetaRole,         // Location: "lat,lng" | Contact: name | Omitted: "omitted"
        WaveformRole,          // Real audio waveform data (comma-separated string)
        ShowDateSeparatorRole, // Show date separator before this message?
        IsFirstInGroupRole,    // It is the first message from the same sender → bubble edge
        IsLastInGroupRole,     // This is the last message from the same sender → show tail
        EditedTextRole,        // Has the message been edited? 
    };
    Q_ENUM(Roles)

    // Number of messages uploaded at one time (first download)
    static constexpr int INITIAL_LOAD   = 200;
    // The number of messages that are added as you scroll up
    static constexpr int PAGE_SIZE      = 150;
    // Threshold for large chats (from which the following are all loaded)
    static constexpr int SMALL_CHAT_MAX = 500;

    explicit MessageListModel(QObject* parent = nullptr);

    int      rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // For small chats (≤ SMALL_CHAT_MAX): give all directly
    void setMessages(const QList<Message>& messages);
    void setSenderAvatarMap(const QHash<QString, QString>& avatarsBySender);
    void renameSender(const QString& oldName, const QString& newName);

    // For large chats: Load paged from DB
    // First, it loads the last INITIAL_LOAD message
    void initFromDatabase(DatabaseManager* db, int chatId, int totalMsgCount);

    // Called from QML: load previous messages when scrolling up
    // contentY and contentHeight — ListView's current values ​​in QML
    // After the insert, the scrollRestoreNeeded(newContentY) signal is sent
    Q_INVOKABLE bool loadMoreOlderMessages(qreal currentContentY, qreal currentContentHeight);

    // Total number of messages (including unloaded)
    int totalCount() const { return m_totalCount; }
    bool isLoading() const { return m_loading; }
    qint64 estimatedTotalHeight() const { return m_estimatedTotalHeight; }

    void clear();

    // Stores a freshly computed waveform for every loaded message whose
    // mediaPath matches `audioPath`. Updates the model (so QML re-binds)
    // and persists it to the database via m_db so the next chat load can
    // skip the FFmpeg decode entirely. Returns affected message ids.
    QList<int> setWaveformByPath(const QString& audioPath, const QString& waveform);
 
    void setLanguageManager(LanguageManager* lm) {
        m_langManager = lm;
        if (lm) {
            connect(lm, &LanguageManager::languageChanged, this, [this]() {
                if (!m_messages.isEmpty()) {
                    // Refresh DateRole for all rows so separators re-render in new language
                    emit dataChanged(index(0), index(m_messages.size() - 1), {DateRole});
                    // Refresh system message translations
                    for (int i = 0; i < m_messages.size(); ++i) {
                        if (m_messages[i].type == MessageType::System) {
                            emit dataChanged(index(i), index(i), {FormattedContentRole});
                        }
                    }
                }
            });
        }
    }

    // To highlight the search result
    Q_INVOKABLE void setSearchQuery(const QString& q);
    Q_INVOKABLE void clearSearch();
    Q_INVOKABLE int  firstSearchResultIndex() const;
    Q_INVOKABLE int  searchResultCount() const;
    Q_INVOKABLE int  searchResultIndexAt(int n) const;
    Q_INVOKABLE void setCurrentSearchResult(int resultNum);

    // Download all messages for search (if necessary)
    Q_INVOKABLE void ensureAllLoaded();

signals:
    void countChanged();
    void totalCountChanged();
    void loadingChanged();
    void estimatedTotalHeightChanged();
    // Loaded old messages — QML uses insertedCount for accurate recovery
    void scrollRestoreNeeded(qreal newContentY, int insertedCount);

private:
    static QString formatDuration(qint64 ms);
    static QString normalizeAzerbaijani(const QString& text);
    bool containsNormalized(const QString& text, const QString& query) const;
    QString highlightMatches(const QString& content, int messageIndex) const;
    // ShowDateSeparator count between 2 messages (for messages outside of m_messages)
    bool computeShowDateSep(int row) const;
    bool computeIsFirstInGroup(int row) const;
    bool computeIsLastInGroup(int row) const;

    QList<Message> m_messages;      // Downloaded messages (window)
    QHash<QString, QString> m_senderAvatars;
    int m_totalCount   = 0;         // Total number of messages in DB
    int m_loadedOffset = 0;         // Offset of m_messages[0] in DB
    bool m_allLoaded   = true;      // Are they all loaded?
    bool m_loading     = false;     // Downloading?
    qint64 m_estimatedTotalHeight = 0;  // Approximate total height for rubber band

    DatabaseManager* m_db    = nullptr;
    int              m_chatId = -1;

    QString        m_searchQuery;
    QString        m_normalizedQuery;
    int            m_currentSearchResult = -1;
    QList<int>     m_searchResultIndices;
    LanguageManager* m_langManager = nullptr;
};

