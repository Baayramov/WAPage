#pragma once
#include "core/DatabaseManager.h"
#include "core/ZipExtractor.h"
#include "core/ChatParser.h"
#include "core/MediaManager.h"
#include "core/AudioSpeedProcessor.h"
#include "core/models/ChatListModel.h"
#include "core/models/MessageListModel.h"
#include "utils/Logger.h"

class LanguageManager;
#include <QObject>
#include <QString>
#include <QStringList>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QSet>
#include <QMutex>
#include <QDateTime>
#include <QVariantList>
#include <QVariantMap>
#include <QRandomGenerator>

// A basic controller that opens to QML
// All business logic is concentrated here
class MainWindow : public QObject
{
    Q_OBJECT

    // Models read from QML
    Q_PROPERTY(ChatListModel*    chatModel    READ chatModel    CONSTANT)
    Q_PROPERTY(MessageListModel* messageModel READ messageModel CONSTANT)
    Q_PROPERTY(QString  activeChatName  READ activeChatName  NOTIFY activeChatChanged)
    Q_PROPERTY(QString  activeChatAvatar READ activeChatAvatar NOTIFY activeChatChanged)
    Q_PROPERTY(QString  activeChatInitials READ activeChatInitials NOTIFY activeChatChanged)
    Q_PROPERTY(QString  activeChatColor READ activeChatColor NOTIFY activeChatChanged)
    Q_PROPERTY(bool     activeChatIsGroup READ activeChatIsGroup NOTIFY activeChatChanged)
    Q_PROPERTY(int      activeChatParticipantCount READ activeChatParticipantCount NOTIFY activeParticipantsChanged)
    Q_PROPERTY(QVariantList activeChatParticipants READ activeChatParticipants NOTIFY activeParticipantsChanged)
    Q_PROPERTY(QDateTime activeChatImportedAt READ activeChatImportedAt NOTIFY activeChatChanged)
    Q_PROPERTY(QString  myAvatar        READ myAvatar        WRITE setMyAvatar NOTIFY myAvatarChanged)
    Q_PROPERTY(QString  defaultOwnerName READ defaultOwnerName WRITE setDefaultOwnerName NOTIFY defaultOwnerNameChanged)
    Q_PROPERTY(QVariantList profileLibrary READ profileLibrary NOTIFY profileLibraryChanged)
    Q_PROPERTY(int      activeChatId    READ activeChatId    NOTIFY activeChatChanged)
    Q_PROPERTY(bool     isDarkTheme     READ isDarkTheme     WRITE setDarkTheme NOTIFY themeChanged)
    Q_PROPERTY(bool     isImporting     READ isImporting     NOTIFY importingChanged)
    Q_PROPERTY(double   importProgress  READ importProgress  NOTIFY importProgressChanged)
    Q_PROPERTY(int      importEtaSeconds READ importEtaSeconds NOTIFY importProgressChanged)
    Q_PROPERTY(bool     isChatLoading   READ isChatLoading   NOTIFY chatLoadingChanged)
    Q_PROPERTY(bool     autoPlayNextVoice READ autoPlayNextVoice WRITE setAutoPlayNextVoice NOTIFY autoPlayNextVoiceChanged)

public:
    explicit MainWindow(const QString& dataDir, QObject* parent = nullptr);

    ChatListModel*    chatModel()    const { return m_chatModel.get(); }
    MessageListModel* messageModel() const { return m_messageModel.get(); }

    QString activeChatName()     const;
    QString activeChatAvatar()   const;
    QString activeChatInitials() const;
    QString activeChatColor()    const;
    bool    activeChatIsGroup()  const
    {
        if (m_activeChatId < 0) {
            return false;
        }

        const int row = m_chatModel->indexOfChat(m_activeChatId);
        if (row < 0) {
            return false;
        }
        return m_chatModel->chatAt(row).chatType.compare("group", Qt::CaseInsensitive) == 0;
    }
    int     activeChatParticipantCount() const
    {
        return m_activeParticipants.size();
    }
    QVariantList activeChatParticipants() const { return m_activeParticipants; }
    QDateTime activeChatImportedAt() const;
    QString myAvatar()           const;
    QString defaultOwnerName()   const;
    QVariantList profileLibrary() const { return m_profileLibrary; }
    int     activeChatId()       const { return m_activeChatId; }
    bool    isDarkTheme()        const { return m_isDarkTheme; }
    bool    isImporting()        const { return m_isImporting; }
    double  importProgress()     const { return m_importProgress; }
    int     importEtaSeconds()   const { return m_importEtaSeconds; }
    bool    isChatLoading()      const { return m_isChatLoading; }
    bool    autoPlayNextVoice()  const { return m_autoPlayNextVoice; }

    void    setDarkTheme(bool dark);
    void    setAutoPlayNextVoice(bool enabled);

    // Debugging bridge for QML
    Q_INVOKABLE void debugLog(const QString& msg);

    // Audio waveform on-demand (eg for old messages) — synchronous, kept for
    // backwards compatibility. New callers should use requestWaveform() to avoid
    // blocking the UI thread.
    Q_INVOKABLE QString getWaveform(const QString& audioPath);

    // Async waveform: kicks off generation on a background thread and emits
    // waveformReady(audioPath, waveformData) when done. Safe to call multiple
    // times — duplicate in-flight requests for the same path are de-duplicated.
    Q_INVOKABLE void requestWaveform(const QString& audioPath);

    // Pitch-preserving audio speed: returns the cached WAV path if a
    // 1.5x/2x version of `audioPath` is already on disk, empty otherwise.
    Q_INVOKABLE QString audioSpeedCachedPath(const QString& audioPath, qreal rate) const;
    // Async: schedule WSOLA generation for (audioPath, rate). Emits
    // audioSpeedReady when the cached WAV is ready (or already exists).
    Q_INVOKABLE void requestAudioSpeed(const QString& audioPath, qreal rate);
    Q_INVOKABLE void setParticipantName(int chatId, const QString& oldName, const QString& newName)
    {
        if (!m_db || chatId < 0) {
            return;
        }

        const QString oldTrimmed = oldName.trimmed();
        const QString newTrimmed = newName.trimmed();
        if (oldTrimmed.isEmpty() || newTrimmed.isEmpty()) {
            return;
        }

        if (!m_db->updateParticipantName(chatId, oldTrimmed, newTrimmed)) {
            return;
        }

        if (m_messageModel) {
            m_messageModel->renameSender(oldTrimmed, newTrimmed);
        }

        if (m_activeChatId == chatId) {
            reloadActiveParticipants();
            refreshSenderAvatarMap();
        }
    }
    Q_INVOKABLE void setParticipantAvatar(int chatId, const QString& participantName, const QString& imagePath)
    {
        if (!m_db || chatId < 0) {
            return;
        }

        const QString trimmedName = participantName.trimmed();
        if (trimmedName.isEmpty()) {
            return;
        }

        QString avatarPath = imagePath.trimmed();
        if (avatarPath.isEmpty()) {
            avatarPath = randomAvatarResourcePath();
        }

        Logger::info(QString("setParticipantAvatar: chatId=%1, name='%2', avatar='%3'")
                    .arg(chatId).arg(trimmedName).arg(avatarPath).toStdString());

        if (!m_db->updateParticipantAvatar(chatId, trimmedName, avatarPath)) {
            return;
        }

        // AUTO-SYNC: Add/update participant in Profile Library
        if (m_db->profileExistsInLibrary(trimmedName)) {
            m_db->updateProfileLibraryAvatar(trimmedName, avatarPath);
        } else {
            m_db->addProfileToLibrary(trimmedName, avatarPath, false); // false = custom avatar
        }
        
        // Propagate avatar change EVERYWHERE
        syncAvatarEverywhere(trimmedName, avatarPath);
        
        // Reload profile library UI
        loadProfileLibrary();
    }

    // Profile Library Management
    Q_INVOKABLE bool addProfileToLibrary(const QString& name, const QString& avatarPath);
    Q_INVOKABLE void removeProfileFromLibrary(const QString& name);
    Q_INVOKABLE void updateProfileLibraryAvatar(const QString& name, const QString& avatarPath);
    Q_INVOKABLE QString getProfileLibraryAvatar(const QString& name);

    // Date-based navigation
    Q_INVOKABLE QStringList getMessageDatesForCurrentChat();
    Q_INVOKABLE void jumpToDate(const QString& date);

    // Media browser
    Q_INVOKABLE QVariantList getMediaForBrowser(const QString& mediaType);
    Q_INVOKABLE QVariantList getLinksForBrowser();
    Q_INVOKABLE QVariantList getLocationsForBrowser();

    // Favorites (starred messages)
    Q_INVOKABLE bool addToFavorites(int chatId, int messageId);
    Q_INVOKABLE bool removeFromFavorites(int chatId, int messageId);
    Q_INVOKABLE bool isMessageFavorite(int chatId, int messageId);
    Q_INVOKABLE QVariantList getAllFavorites(); // Returns list of favorite messages with details
    Q_INVOKABLE void jumpToFavoriteMessage(int chatId, int messageId);

public slots:
    // ZIP import — "New conversation" button in QML
    void importZip(const QString& zipFilePath, const QString& ownerName);

    // Click chat in the left panel
    void selectChat(int chatId);

    // Delete chat
    void deleteChat(int chatId);

    // Change avatar
    void setChatAvatar(int chatId, const QString& imagePath);
    void setChatName(int chatId, const QString& contactName)
    {
        if (!m_db || !m_chatModel) {
            return;
        }

        const QString trimmedName = contactName.trimmed();
        if (chatId < 0 || trimmedName.isEmpty()) {
            return;
        }

        const int row = m_chatModel->indexOfChat(chatId);
        if (row < 0) {
            return;
        }

        Chat ch = m_chatModel->chatAt(row);
        const QString oldName = ch.contactName;
        
        if (oldName == trimmedName) {
            return;
        }

        if (!m_db->updateChatName(chatId, trimmedName)) {
            return;
        }

        ch.contactName = trimmedName;
        m_chatModel->updateChat(ch);
        
        // For 1-on-1 chats: sync participant name with chat name
        const bool isGroup = ch.chatType.compare("group", Qt::CaseInsensitive) == 0;
        if (!isGroup) {
            auto participants = m_db->participantsForChat(chatId);
            auto ownerParticipants = m_db->getOwnerParticipantsForChat(chatId);
            
            for (const auto& participant : participants) {
                if (ownerParticipants.contains(participant.name)) {
                    continue;
                }
                
                if (!m_db->updateParticipantName(chatId, participant.name, trimmedName)) {
                    // Failed
                } else {
                    if (m_activeChatId == chatId && m_messageModel) {
                        m_messageModel->renameSender(participant.name, trimmedName);
                    }
                }
                
                break;
            }
        }

        if (m_activeChatId == chatId) {
            emit activeChatChanged();
            
            if (!isGroup) {
                reloadActiveParticipants();
                refreshSenderAvatarMap();
            }
        }
    }
    void setMyAvatar(const QString& imagePath);
    void setDefaultOwnerName(const QString& name);

    // Message search
    void searchInChat(const QString& query);
    void clearSearch();
    void scrollToSearchResult(int resultNumber);

    // Load existing data when the program opens
    void loadAll();

    void setLanguageManager(LanguageManager* lm);

signals:
    void activeChatChanged();
    void themeChanged();
    void myAvatarChanged();
    void defaultOwnerNameChanged();
    void profileLibraryChanged();
    void importingChanged();
    void importProgressChanged();
    void importError(const QString& message);
    void importSuccess(const QString& contactName, int messageCount);
    void searchResultReady(int firstIndex, int totalCount);
    void scrollIndexReady(int messageIndex);
    void chatLoadingChanged();
    void activeParticipantsChanged();
    void waveformReady(const QString& audioPath, const QString& waveformData);
    void audioSpeedReady(const QString& audioPath, qreal rate, const QString& cachedPath);
    void jumpToDateIndex(int messageIndex);
    void autoPlayNextVoiceChanged();
    void favoritesChanged(); // Emitted when favorites are added/removed

private:
    void setImporting(bool v);
    void setImportProgress(double value, int etaSeconds);
    void reloadActiveParticipants()
    {
        QVariantList next;

        if (!m_db || m_activeChatId < 0) {
            if (m_activeParticipants != next) {
                m_activeParticipants = next;
                emit activeParticipantsChanged();
            }
            return;
        }

        auto participants = m_db->participantsForChat(m_activeChatId);
        
        if (participants.isEmpty() && activeChatIsGroup()) {
            QString ownerAvatarPath = myAvatar();
            m_db->seedParticipantsFromMessages(m_activeChatId, "", ownerAvatarPath);
            participants = m_db->participantsForChat(m_activeChatId);
        }

        for (Participant& participant : participants) {
            QString avatarPath = participant.customAvatarPath.trimmed();
            
            QString libraryAvatar = m_db->getProfileLibraryAvatar(participant.name.trimmed());
            if (!libraryAvatar.isEmpty()) {
                avatarPath = libraryAvatar;
                m_db->updateParticipantAvatar(m_activeChatId, participant.name, avatarPath);
            } else if (avatarPath.isEmpty()) {
                avatarPath = randomAvatarResourcePath();
                m_db->updateParticipantAvatar(m_activeChatId, participant.name, avatarPath);
            }

            QVariantMap row;
            row.insert("name", participant.name);
            row.insert("avatarPath", avatarPath);
            row.insert("initials", initialsForName(participant.name));
            row.insert("avatarColor", colorForName(participant.name));
            
            int messageCount = m_db->messageCountForParticipant(m_activeChatId, participant.name);
            row.insert("messageCount", messageCount);
            next.append(row);
        }

        if (m_activeParticipants != next) {
            m_activeParticipants = next;
            emit activeParticipantsChanged();
        }
    }
    void refreshSenderAvatarMap()
    {
        if (!m_messageModel) {
            return;
        }

        if (!m_db || m_activeChatId < 0) {
            m_messageModel->setSenderAvatarMap({});
            return;
        }

        m_messageModel->setSenderAvatarMap(m_db->participantAvatarMap(m_activeChatId));
    }
    void loadProfileLibrary();
    void syncAvatarEverywhere(const QString& participantName, const QString& avatarPath);
    static QString randomAvatarResourcePath()
    {
        static const QStringList avatarNames = {
            "blue_avatar.svg", "green_avatar.svg", "lightblue_avatar.svg",
            "lightgreen_avatar.svg", "lightred_avatar.svg",
            "purple_avatar.svg", "red_avatar.svg"
        };
        const int idx = QRandomGenerator::global()->bounded(avatarNames.size());
        return "qrc:/assets/" + avatarNames.at(idx);
    }
    static QString randomGroupAvatarResourcePath()
    {
        static const QStringList groupAvatarNames = {
            "yellow_groupavatar.svg", "red_groupavatar.svg", "orange_groupavatar.svg",
            "blue_groupavatar.svg", "purple_groupavatar.svg"
        };
        const int idx = QRandomGenerator::global()->bounded(groupAvatarNames.size());
        return "qrc:/assets/" + groupAvatarNames.at(idx);
    }
    static QString initialsForName(const QString& name)
    {
        QString cleanName = name.trimmed();
        if (cleanName.isEmpty()) {
            return "?";
        }
        
        // Strip tilde prefix for initials calculation (iOS/Android compatibility)
        if (cleanName.startsWith("~ ")) {
            cleanName = cleanName.mid(2).trimmed();
        } else if (cleanName.startsWith('~')) {
            cleanName = cleanName.mid(1).trimmed();
        }
        
        if (cleanName.isEmpty()) {
            return "?";
        }
        
        const QStringList parts = cleanName.split(' ', Qt::SkipEmptyParts);
        if (parts.size() == 1) {
            return parts[0].left(2).toUpper();
        }
        return QString(parts[0][0]).toUpper() + QString(parts[1][0]).toUpper();
    }
    static QString colorForName(const QString& name)
    {
        static const QStringList palette = {
            "#D4371C", "#E65100", "#BF360C", "#AD1457",
            "#880E4F", "#6A1B9A", "#4527A0", "#1565C0",
            "#0277BD", "#00695C", "#2E7D32", "#558B2F",
            "#F57F17", "#E65100", "#4E342E", "#37474F",
        };

        if (name.isEmpty()) {
            return palette.first();
        }
        
        // Strip tilde prefix for consistent color across tilde/no-tilde variants
        QString cleanName = name.trimmed();
        if (cleanName.startsWith("~ ")) {
            cleanName = cleanName.mid(2).trimmed();
        } else if (cleanName.startsWith('~')) {
            cleanName = cleanName.mid(1).trimmed();
        }
        
        if (cleanName.isEmpty()) {
            return palette.first();
        }
        
        int hash = 0;
        for (const QChar& ch : cleanName) {
            hash = (hash * 31 + ch.unicode()) & 0x7FFFFFFF;
        }
        return palette.at(hash % palette.size());
    }

    QString m_dataDir;
    int     m_activeChatId  = -1;
    bool    m_isDarkTheme   = true;
    bool    m_isImporting   = false;
    bool    m_isChatLoading = false;
    bool    m_autoPlayNextVoice = true; // Default: enabled
    double  m_importProgress = 0.0;
    int     m_importEtaSeconds = -1;
    QVariantList m_activeParticipants;
    QVariantList m_profileLibrary;

    QScopedPointer<DatabaseManager>  m_db;
    // QSharedPointer so that background waveform threads can extend MediaManager's
    // lifetime past MainWindow destruction (prevents dangling-pointer crashes).
    QSharedPointer<MediaManager>     m_media;
    QScopedPointer<AudioSpeedProcessor> m_audioSpeed;
    QScopedPointer<ChatListModel>    m_chatModel;
    QScopedPointer<MessageListModel> m_messageModel;
    LanguageManager*                 m_langManager = nullptr;

    // Tracks which audioPaths currently have an in-flight async waveform job
    // so we don't enqueue duplicates from rapid scroll / re-bind events.
    QSet<QString>                    m_waveformInFlight;
    QMutex                           m_waveformMutex;
};
