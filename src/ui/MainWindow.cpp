#include "MainWindow.h"
#include "utils/Logger.h"
#include "core/LanguageManager.h"
#include "utils/WAPageTextFormatter.h"

#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QThread>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <QElapsedTimer>
#include <QVariantMap>
#include <QTimer>
#include <QPointer>
#include <QMutexLocker>
#include <QCoreApplication>
#include <QThreadPool>

MainWindow::MainWindow(const QString& dataDir, QObject* parent)
    : QObject(parent)
    , m_dataDir(dataDir)
{
    m_db.reset(new DatabaseManager(dataDir + "/chats.db"));
    m_media = QSharedPointer<MediaManager>::create(dataDir + "/media");
    m_audioSpeed.reset(new AudioSpeedProcessor(this));
    m_audioSpeed->setCacheDir(dataDir + "/audio_cache");
    connect(m_audioSpeed.data(), &AudioSpeedProcessor::ready,
            this, &MainWindow::audioSpeedReady);
    m_chatModel.reset(new ChatListModel(this));
    m_messageModel.reset(new MessageListModel(this));

    if (!m_db->open()) {
        Logger::critical("Failed to open the database.");
        return;
    }

    const QString savedTheme = m_db->getSetting("ui_theme", "dark").trimmed().toLower();
    if (savedTheme == "light") {
        m_isDarkTheme = false;
    } else if (savedTheme == "dark") {
        m_isDarkTheme = true;
    }
    
    // Load autoPlayNextVoice setting (default: true/enabled)
    const QString savedAutoPlay = m_db->getSetting("autoPlayNextVoice", "true").trimmed().toLower();
    m_autoPlayNextVoice = (savedAutoPlay != "false");
}

void MainWindow::loadAll()
{
    const auto chats = m_db->allChats();
    m_chatModel->setChats(chats);
    Logger::info("Loaded: " + std::to_string(chats.size()) + " chats");
    
    // Migrate profile library to use normalized names (runs once, safe to call multiple times)
    m_db->migrateProfileLibraryNormalization();
    
    // Load profile library
    loadProfileLibrary();
}

void MainWindow::setLanguageManager(LanguageManager* lm)
{
    if (m_langManager) {
        QObject::disconnect(m_langManager, nullptr, this, nullptr);
    }

    m_langManager = lm;
    if (m_messageModel) {
        m_messageModel->setLanguageManager(lm);
    }
    if (m_chatModel) {
        m_chatModel->setLanguageManager(lm);
    }

    if (!m_langManager || !m_db) {
        return;
    }

    QString savedLanguage = m_db->getSetting("app_language", "").trimmed();
    if (savedLanguage.isEmpty()) {
        savedLanguage = "Azerbaijani";
        m_db->setSetting("app_language", savedLanguage);
    }

    m_langManager->setCurrentLanguage(savedLanguage);
    if (m_langManager->currentLanguage() != savedLanguage) {
        // If the saved language value is invalid, fall back to a safe default.
        m_langManager->setCurrentLanguage("Azerbaijani");
        m_db->setSetting("app_language", "Azerbaijani");
    }

    QObject::connect(m_langManager, &LanguageManager::languageChanged, this, [this]() {
        if (!m_langManager || !m_db) {
            return;
        }
        m_db->setSetting("app_language", m_langManager->currentLanguage());
    });
}

QString MainWindow::activeChatName() const
{
    if (m_activeChatId < 0) return {};
    const int row = m_chatModel->indexOfChat(m_activeChatId);
    if (row < 0) return {};
    return m_chatModel->chatAt(row).contactName;
}

QString MainWindow::activeChatAvatar() const
{
    if (m_activeChatId < 0) return {};
    const int row = m_chatModel->indexOfChat(m_activeChatId);
    if (row < 0) return {};
    return m_chatModel->chatAt(row).customAvatarPath;
}

QString MainWindow::activeChatInitials() const
{
    QString name = activeChatName();
    if (name.isEmpty()) return "?";
    
    // Strip tilde prefix for initials calculation (iOS/Android compatibility)
    name = name.trimmed();
    if (name.startsWith("~ ")) {
        name = name.mid(2).trimmed();
    } else if (name.startsWith('~')) {
        name = name.mid(1).trimmed();
    }
    
    if (name.isEmpty()) return "?";
    const QStringList parts = name.split(' ', Qt::SkipEmptyParts);
    if (parts.size() == 1) return parts[0].left(2).toUpper();
    return QString(parts[0][0]).toUpper() + QString(parts[1][0]).toUpper();
}

QString MainWindow::activeChatColor() const
{
    // Same color as ChatListModel's static method.
    if (m_activeChatId < 0) return "#00BFA5";
    const int row = m_chatModel->indexOfChat(m_activeChatId);
    if (row < 0) return "#00BFA5";
    return m_chatModel->data(m_chatModel->index(row), ChatListModel::AvatarColorRole).toString();
}

QDateTime MainWindow::activeChatImportedAt() const
{
    if (m_activeChatId < 0) return {};
    const int row = m_chatModel->indexOfChat(m_activeChatId);
    if (row < 0) return {};
    return m_chatModel->chatAt(row).importedAt;
}

void MainWindow::setDarkTheme(bool dark)
{
    if (m_isDarkTheme != dark) {
        m_isDarkTheme = dark;
        if (m_db) {
            m_db->setSetting("ui_theme", m_isDarkTheme ? "dark" : "light");
        }
        emit themeChanged();
    }
}

void MainWindow::setAutoPlayNextVoice(bool enabled)
{
    if (m_autoPlayNextVoice != enabled) {
        m_autoPlayNextVoice = enabled;
        if (m_db) {
            m_db->setSetting("autoPlayNextVoice", m_autoPlayNextVoice ? "true" : "false");
        }
        emit autoPlayNextVoiceChanged();
    }
}

void MainWindow::debugLog(const QString& msg)
{
    Logger::info(msg.toStdString());
}

void MainWindow::importZip(const QString& zipFilePath, const QString& ownerName)
{
    if (m_isImporting) return;
    setImporting(true);
    Logger::info("Import started: " + zipFilePath.toStdString());

    // Run on a background thread.
    auto* watcher = new QFutureWatcher<void>(this);
    connect(watcher, &QFutureWatcher<void>::finished, this, [watcher](){
        watcher->deleteLater();
    });

    const QString dataDir  = m_dataDir;
    const QString ownerN   = ownerName;
    // editedLabel is no longer used by ChatParser — it now saves a fixed "1" flag.
    // The display label is resolved dynamically in QML from langManager.currentTranslations["edited"].
    QString editedLabel;  // kept for API compatibility with ChatParser::parse()
    // deletedMessageLabel / youDeletedMessageLabel are no longer stored in DB content.
    // ChatParser now writes "__deleted__" / "__deleted_by_me__" markers; QML resolves display text dynamically.
    QString deletedMessageLabel;      // kept for API compatibility
    QString youDeletedMessageLabel;   // kept for API compatibility
    
    QFuture<void> future = QtConcurrent::run([=]() {
        QElapsedTimer totalTimer;
        totalTimer.start();
        QElapsedTimer uiThrottle;
        uiThrottle.start();

        double wExtract  = 20.0;
        double wParse    = 45.0;
        double wChat     = 2.0;
        double wMedia    = 16.0;
        double wDb       = 15.0;
        double wCleanup  = 1.5;
        double wFinalize = 0.5;

        double fExtract  = 0.0;
        double fParse    = 0.0;
        double fChat     = 0.0;
        double fMedia    = 0.0;
        double fDb       = 0.0;
        double fCleanup  = 0.0;
        double fFinalize = 0.0;

        double emittedProgress = 0.0;
        int lastLoggedPercent = -1;

        auto rawProgress = [&]() {
            const double weighted = (wExtract * fExtract) +
                                    (wParse * fParse) +
                                    (wChat * fChat) +
                                    (wMedia * fMedia) +
                                    (wDb * fDb) +
                                    (wCleanup * fCleanup) +
                                    (wFinalize * fFinalize);
            const double totalWeight = wExtract + wParse + wChat + wMedia + wDb + wCleanup + wFinalize;
            if (totalWeight <= 0.0) {
                return 0.0;
            }
            return qBound(0.0, weighted / totalWeight, 1.0);
        };

        auto pushProgress = [&](const QString& reason, bool force = false) {
            const double raw = rawProgress();
            const double nextProgress = qMax(emittedProgress, raw); // Monotonic: never decrease

            if (!force && uiThrottle.elapsed() < 60 && (nextProgress - emittedProgress) < 0.001) {
                return;
            }
            if (!force && qAbs(nextProgress - emittedProgress) < 0.0002) {
                return;
            }

            emittedProgress = nextProgress;
            uiThrottle.restart();

            const int percent = qBound(0, static_cast<int>(emittedProgress * 100.0), 100);
            if (percent != lastLoggedPercent) {
                lastLoggedPercent = percent;
                Logger::info(QString("ImportProgress: %1%% | reason=%2 | ext=%3 parse=%4 media=%5 db=%6")
                             .arg(percent)
                             .arg(reason)
                             .arg(fExtract, 0, 'f', 3)
                             .arg(fParse, 0, 'f', 3)
                             .arg(fMedia, 0, 'f', 3)
                             .arg(fDb, 0, 'f', 3)
                             .toStdString());
            }

            QMetaObject::invokeMethod(this, [this, emittedProgress]() {
                setImportProgress(emittedProgress, -1);
            }, Qt::QueuedConnection);
        };

        pushProgress("start", true);

        // 1. Open ZIP
        QElapsedTimer stepTimer;
        stepTimer.start();
        const QString tempDir = dataDir + "/temp";
        auto zipResult = ZipExtractor::extract(zipFilePath, tempDir,
                                               [&](const ZipExtractor::ExtractProgress& p) {
            fExtract = qBound(0.0, p.progress, 1.0);
            if ((p.processedItems % 250) == 0 || p.progress >= 0.999) {
                pushProgress(QString("zip-%1 %2/%3")
                             .arg(p.phase)
                             .arg(p.processedItems)
                             .arg(qMax(1, p.totalItems)));
            } else {
                pushProgress(QString("zip-%1").arg(p.phase));
            }
        });

        if (!zipResult.success) {
            if (!zipResult.extractDir.isEmpty()) {
                ZipExtractor::cleanup(zipResult.extractDir);
            }
            QString zipError = zipResult.errorMsg.trimmed();
            if (zipError.isEmpty()) {
                zipError = "ZIP acilamadi. Fayl natamamdir, zedelenib, veya vaxt limiti asilib.";
            }
            QMetaObject::invokeMethod(this, [=]() {
                setImportProgress(0.0, -1);
                setImporting(false);
                emit importError(zipError);
            }, Qt::QueuedConnection);
            return;
        }
        fExtract = 1.0;
        pushProgress("zip-done", true);
        Logger::info(QString("ZIP extract: %1ms").arg(stepTimer.elapsed()).toStdString());

        // Dynamically adjust stage weights based on chat/media size.
        const double fixedWeight = wExtract + wChat + wCleanup + wFinalize;
        const double dynamicBudget = qMax(10.0, 100.0 - fixedWeight);

        const double parseWork = qMax(1.0, static_cast<double>(qMax<qint64>(zipResult.chatTxtBytes, 1)) / (1.6 * 1024.0 * 1024.0));
        const double dbWork = qMax(1.0, static_cast<double>(qMax<qint64>(zipResult.chatTxtBytes, 1)) / (20.0 * 1024.0 * 1024.0));
        const double mediaWork = (zipResult.mediaCount > 0)
                ? qMax(1.0,
                       static_cast<double>(zipResult.mediaBytes) / (140.0 * 1024.0 * 1024.0) +
                       static_cast<double>(zipResult.mediaCount) / 12000.0)
                : 0.0;

        const double totalWork = parseWork + dbWork + mediaWork;
        if (totalWork > 0.0) {
            const double baseParse = dynamicBudget * (parseWork / totalWork);
            const double parseFloor = dynamicBudget * (mediaWork > 0.0 ? 0.30 : 0.55);
            wParse = qMax(baseParse, parseFloor);

            const double remainingBudget = qMax(0.0, dynamicBudget - wParse);
            const double restWork = dbWork + mediaWork;
            if (restWork > 0.0) {
                wDb = remainingBudget * (dbWork / restWork);
                wMedia = remainingBudget * (mediaWork / restWork);
            } else {
                wDb = 0.0;
                wMedia = 0.0;
            }

            const double dbFloor = dynamicBudget * 0.08;
            if (wDb < dbFloor) {
                const double delta = dbFloor - wDb;
                wDb = dbFloor;
                wMedia = qMax(0.0, wMedia - delta);
            }

            if (mediaWork <= 0.0) {
                wMedia = 0.0;
                const double allocated = wParse + wDb;
                if (allocated < dynamicBudget) {
                    wParse += (dynamicBudget - allocated);
                }
            }
        }
        pushProgress("weights-ready", true);

        // 2. Parse _chat.txt
        stepTimer.restart();
        const qint64 parseTotalBytes = qMax<qint64>(zipResult.chatTxtBytes, 1);
        const bool useAndroidParser = (zipResult.chatFormat == ZipExtractor::ChatFormat::Android);
        Logger::info(QString("Import parser selected by chat filename rule: %1")
                 .arg(useAndroidParser ? "android" : "ios")
                 .toStdString());

        auto parseResult = ChatParser::parse(zipResult.chatTxtPath,
                                             ownerN,
                                             0,
                                             editedLabel,
                                             deletedMessageLabel,
                                             youDeletedMessageLabel,
                                             [&](const ChatParser::ParseProgress& progress) {
            const double bytesRatio = (progress.totalBytes > 0)
                    ? qBound(0.0,
                             static_cast<double>(progress.bytesRead) / static_cast<double>(progress.totalBytes),
                             1.0)
                    : 0.0;

            const double lineEstimate = qMax(1.0, static_cast<double>(parseTotalBytes) / 75.0);
            const double lineRatio = qBound(0.0,
                                            static_cast<double>(progress.linesRead) / lineEstimate,
                                            1.0);

            const double messageEstimate = qMax(1.0, lineEstimate * 0.58);
            const double messageRatio = qBound(0.0,
                                               static_cast<double>(progress.parsedMessages) / messageEstimate,
                                               1.0);

            fParse = qBound(0.0, (bytesRatio * 0.75) + (lineRatio * 0.15) + (messageRatio * 0.10), 1.0);
            pushProgress(QString("parse %1l %2m")
                         .arg(progress.linesRead)
                         .arg(progress.parsedMessages));
        },
        useAndroidParser);

        if (!parseResult.success) {
            ZipExtractor::cleanup(zipResult.extractDir);
            QString parseError = parseResult.errorMsg.trimmed();
            if (parseError.isEmpty()) {
                parseError = "Messages could not be parsed. Export TXT format is unsupported or the file is incomplete.";
            }
            Logger::error("Import parse error: " + parseError.toStdString());
            QMetaObject::invokeMethod(this, [=]() {
                setImportProgress(0.0, -1);
                setImporting(false);
                emit importError(parseError);
            }, Qt::QueuedConnection);
            return;
        }

        fParse = 1.0;
        pushProgress("parse-done", true);
        Logger::info(QString("Parse: %1 messages, %2ms")
                     .arg(parseResult.messages.size())
                     .arg(stepTimer.elapsed())
                     .toStdString());

        // 3. Insert chat into DB
        stepTimer.restart();
        Chat chat;
        chat.contactName    = parseResult.isGroup && !parseResult.groupName.trimmed().isEmpty()
                              ? parseResult.groupName.trimmed()
                              : parseResult.contactName;
        chat.chatType       = parseResult.isGroup ? "group" : "direct";
        
        // Strip tilde prefix from contact name (~ indicates no phone number in WhatsApp)
        if (chat.contactName.trimmed().startsWith('~')) {
            chat.contactName = chat.contactName.trimmed().mid(1).trimmed();
            Logger::info(QString("Import: Stripped tilde from contact name: %1").arg(chat.contactName).toStdString());
        }
        
        if (chat.chatType == "group" && chat.contactName.trimmed().isEmpty()) {
            chat.contactName = "Unknown Group";
        }
        chat.zipSourcePath  = zipFilePath;
        chat.importedAt     = QDateTime::currentDateTime();
        if (!parseResult.messages.isEmpty())
            chat.lastMessageTime = parseResult.messages.last().timestamp;

        chat.customAvatarPath = parseResult.isGroup
                    ? randomGroupAvatarResourcePath()
                    : randomAvatarResourcePath();
        
        // For DIRECT chats, check if contact exists in Profile Library and use their avatar
        if (!parseResult.isGroup && !chat.contactName.trimmed().isEmpty()) {
            QString contactName = chat.contactName.trimmed();
            QString libraryAvatar = m_db->getProfileLibraryAvatar(contactName);
            if (!libraryAvatar.isEmpty()) {
                chat.customAvatarPath = libraryAvatar;
                Logger::info(QString("Import: Using Profile Library avatar for direct chat: %1")
                           .arg(contactName).toStdString());
            }
        }

        const int chatId = m_db->insertChat(chat);
        if (chatId < 0) {
            ZipExtractor::cleanup(zipResult.extractDir);
            QMetaObject::invokeMethod(this, [=]() {
                setImportProgress(0.0, -1);
                setImporting(false);
                emit importError("Sohbət bazaya yazıla bilmədi.");
            }, Qt::QueuedConnection);
            return;
        }

        if (!chat.customAvatarPath.isEmpty())
            m_db->updateChatAvatar(chatId, chat.customAvatarPath);

        QList<Message> msgs = parseResult.messages;
        for (auto& msg : msgs) {
            msg.chatId = chatId;
        }

        QStringList participants = parseResult.participants;
        if (!parseResult.isGroup) {
            participants = { chat.contactName };
        }

        const QString ownerTrimmed = ownerN.trimmed();
        QStringList cleanedParticipants;
        for (const QString& participantName : participants) {
            QString trimmedName = participantName.trimmed();
            if (trimmedName.isEmpty()) {
                continue;
            }
            
            // Strip tilde prefix from participant name
            if (trimmedName.startsWith('~')) {
                trimmedName = trimmedName.mid(1).trimmed();
            }
            
            if (!ownerTrimmed.isEmpty() && trimmedName == ownerTrimmed) {
                continue;
            }
            if (!cleanedParticipants.contains(trimmedName)) {
                cleanedParticipants.append(trimmedName);
            }
        }

        for (const QString& participantName : cleanedParticipants) {
            QString avatarPath;
            
            // PRIORITY 1: Check Profile Library first (includes both custom and default avatars)
            QString libraryAvatar = m_db->getProfileLibraryAvatar(participantName);
            if (!libraryAvatar.isEmpty()) {
                avatarPath = libraryAvatar;
                Logger::info(QString("[IMPORT-AVATAR] Participant '%1' -> Profile Library: %2")
                    .arg(participantName).arg(avatarPath).toStdString());
            } else {
                // PRIORITY 2: New participant - assign random default avatar and add to profile library
                avatarPath = randomAvatarResourcePath();
                
                // Add to profile library as a default avatar (is_default=1)
                m_db->addProfileToLibrary(participantName, avatarPath, true);
                
                Logger::info(QString("[IMPORT-AVATAR] Participant '%1' -> New default added to library: %2")
                    .arg(participantName).arg(avatarPath).toStdString());
            }
            
            m_db->upsertParticipant(chatId, participantName, avatarPath);
        }

        // Add owner as participant (for both group and direct chats)
        // This ensures owner messages display the correct avatar
        if (!ownerTrimmed.isEmpty()) {
            QString ownerAvatarPath;
            
            // Check if owner name matches any profile in library
            QString ownerLibraryAvatar = m_db->getProfileLibraryAvatar(ownerTrimmed);
            if (!ownerLibraryAvatar.isEmpty()) {
                // Found in profile library - use that avatar
                ownerAvatarPath = ownerLibraryAvatar;
            } else {
                // Not in library - check if it matches default owner name
                QString defaultOwnerName = m_db->getSetting("default_owner_name", "").trimmed();
                
                // Normalize both names for comparison
                QString normalizedOwner = DatabaseManager::normalizeString(ownerTrimmed);
                QString normalizedDefault = DatabaseManager::normalizeString(defaultOwnerName);
                
                // Also check with/without tilde (~) prefix for fuzzy matching
                QString ownerWithoutTilde = normalizedOwner.startsWith('~') 
                    ? normalizedOwner.mid(1).trimmed() 
                    : normalizedOwner;
                QString defaultWithoutTilde = normalizedDefault.startsWith('~') 
                    ? normalizedDefault.mid(1).trimmed() 
                    : normalizedDefault;
                
                bool isDefaultOwner = false;
                if (!defaultOwnerName.isEmpty()) {
                    // Check exact match or tilde-fuzzy match
                    isDefaultOwner = (normalizedOwner == normalizedDefault) ||
                                   (ownerWithoutTilde == defaultWithoutTilde) ||
                                   (ownerWithoutTilde == normalizedDefault) ||
                                   (normalizedOwner == defaultWithoutTilde);
                }
                
                if (isDefaultOwner) {
                    // Matches default owner - use myAvatar
                    ownerAvatarPath = myAvatar();
                } else {
                    // Different person - assign random avatar and add to profile library as default
                    ownerAvatarPath = randomAvatarResourcePath();
                    m_db->addProfileToLibrary(ownerTrimmed, ownerAvatarPath, true); // true = default avatar
                }
            }
            
            m_db->upsertParticipant(chatId, ownerTrimmed, ownerAvatarPath);
        }

        // Always seed participants from messages for group chats
        // This ensures any participants missed by the parser are still added to database
        // upsertParticipant uses INSERT OR IGNORE so duplicates are handled automatically
        if (parseResult.isGroup) {
            QString ownerAvatarPath = myAvatar();
            m_db->seedParticipantsFromMessages(chatId, ownerN, ownerAvatarPath);
        }

        fChat = 1.0;
        pushProgress("chat-done", true);
        Logger::info(QString("Chat insert + chatId set: %1ms").arg(stepTimer.elapsed()).toStdString());

        // 4. Copy media
        stepTimer.restart();
        int mediaMessageCount = 0;
        for (const auto& msg : msgs) {
            if (!msg.mediaPath.isEmpty()) {
                mediaMessageCount++;
            }
        }

        qint64 estimatedMediaBytes = 0;
        if (mediaMessageCount > 0) {
            if (zipResult.mediaCount > 0 && zipResult.mediaBytes > 0) {
                estimatedMediaBytes = (zipResult.mediaBytes * mediaMessageCount) / qMax(1, zipResult.mediaCount);
            }
            if (estimatedMediaBytes <= 0) {
                estimatedMediaBytes = static_cast<qint64>(mediaMessageCount) * 180000;
            }
        }

        const bool hasMedia = mediaMessageCount > 0;
        if (hasMedia && wMedia > 0.0) {
            m_media->copyMediaToStorage(msgs,
                                        zipResult.extractDir,
                                        chatId,
                                        [&](qint64 processedBytes, int processedItems, int totalItems) {
                double itemRatio = 1.0;
                if (totalItems > 0) {
                    itemRatio = qBound(0.0,
                                       static_cast<double>(processedItems) / static_cast<double>(totalItems),
                                       1.0);
                }

                double byteRatio = itemRatio;
                if (estimatedMediaBytes > 0) {
                    byteRatio = qBound(0.0,
                                       static_cast<double>(processedBytes) / static_cast<double>(estimatedMediaBytes),
                                       1.0);
                }

                fMedia = qBound(0.0,
                                (estimatedMediaBytes > 0)
                                    ? ((byteRatio * 0.75) + (itemRatio * 0.25))
                                    : itemRatio,
                                1.0);

                pushProgress(QString("media %1/%2")
                             .arg(processedItems)
                             .arg(qMax(1, totalItems)));
            });
            fMedia = 1.0;
            pushProgress("media-done", true);
            Logger::info(QString("Media copy: %1ms").arg(stepTimer.elapsed()).toStdString());
        } else {
            fMedia = 1.0;
            pushProgress("media-skip", true);
            Logger::info("Media copy: skipped (no media)");
        }

        // 5. Insert messages into DB
        stepTimer.restart();
        
        // DEBUG: Log sample message sender formats before insertion (iOS compatibility check)
        if (!msgs.isEmpty()) {
            Logger::info(QString("[IMPORT-DEBUG] Sample message sender formats (first 5 of %1):").arg(msgs.size()).toStdString());
            for (int i = 0; i < qMin(5, msgs.size()); ++i) {
                Logger::info(QString("[IMPORT-DEBUG]   msg[%1].sender = '%2'").arg(i).arg(msgs[i].sender).toStdString());
            }
        }
        
        if (!m_db->insertMessages(msgs, [&](int insertedCount, int totalCount) {
            if (totalCount <= 0) {
                return;
            }
            fDb = qBound(0.0,
                         static_cast<double>(insertedCount) / static_cast<double>(totalCount),
                         1.0);
            pushProgress(QString("db %1/%2")
                         .arg(insertedCount)
                         .arg(totalCount));
        })) {
            ZipExtractor::cleanup(zipResult.extractDir);
            QMetaObject::invokeMethod(this, [=]() {
                setImportProgress(0.0, -1);
                setImporting(false);
                emit importError("Mesajlar verilənlər bazasına yazıla bilmədi (SQL xətası).");
            }, Qt::QueuedConnection);
            return;
        }

        fDb = 1.0;
        pushProgress("db-done", true);
        m_db->updateLastMessageTime(chatId);

        Logger::info(QString("DB insert: %1 messages, %2ms")
                     .arg(msgs.size())
                     .arg(stepTimer.elapsed())
                     .toStdString());

        // 6. Remove temp files
        ZipExtractor::cleanup(zipResult.extractDir);
        fCleanup = 1.0;
        pushProgress("cleanup", true);

        // 7. Refresh UI
        const int msgCount = msgs.size();
        const QString contactN = chat.contactName;
        const QString lastPreview = msgs.isEmpty() ? QString() : msgs.last().content.left(60);

        fFinalize = 1.0;
        pushProgress("finalize", true);

        Logger::info(QString("TOTAL import: %1ms").arg(totalTimer.elapsed()).toStdString());

        QMetaObject::invokeMethod(this, [=]() mutable {
            setImportProgress(1.0, -1);

            Chat updatedChat = chat;
            updatedChat.id = chatId;
            updatedChat.lastMessagePreview = lastPreview;
            m_chatModel->addChat(updatedChat);

            setImporting(false);
            emit importSuccess(contactN, msgCount);
            Logger::info(QString("Import completed: %1 - %2 messages")
                         .arg(contactN)
                         .arg(msgCount)
                         .toStdString());
        }, Qt::QueuedConnection);
    });

    watcher->setFuture(future);
}

void MainWindow::selectChat(int chatId)
{
    if (m_activeChatId == chatId && (!m_messageModel || m_messageModel->totalCount() > 0)) {
        return;
    }

    if (m_activeChatId == chatId) {
        Logger::warn(QString("selectChat: forcing refresh for chat=%1 because totalCount is %2")
                     .arg(chatId)
                     .arg(m_messageModel ? m_messageModel->totalCount() : -1)
                     .toStdString());
    }

    m_activeChatId = chatId;
    m_activeParticipants.clear();
    emit activeParticipantsChanged();
    emit activeChatChanged();

    // 1. Show loading screen and reset model.
    m_messageModel->clear();
    m_messageModel->setSenderAvatarMap({});
    if (m_isChatLoading != true) {
        m_isChatLoading = true;
        emit chatLoadingChanged();
    }

    // 2. Load after the event loop turns once so the loading state paints first.
    // Keep DB access on UI thread: QSqlDatabase connections are thread-affine.
    const int cId = chatId;
    QTimer::singleShot(0, this, [this, cId]() {
        if (m_activeChatId != cId) {
            return;
        }

        const int total = m_db->messageCountForChat(cId);
        m_messageModel->initFromDatabase(m_db.get(), cId, total);
        reloadActiveParticipants();
        refreshSenderAvatarMap();

        Logger::debug("Chat selected: id=" + std::to_string(cId) +
                      ", total messages=" + std::to_string(total) +
                      ", estimatedH=" +
                      std::to_string(m_messageModel->estimatedTotalHeight()));

        m_isChatLoading = false;
        emit chatLoadingChanged();
    });
}

void MainWindow::deleteChat(int chatId)
{
    if (chatId < 0) {
        return;
    }

    Logger::info(QString("=== [DELETE-CHAT] START: Deleting chat ID=%1 ===").arg(chatId).toStdString());

    const bool wasActiveChat = (m_activeChatId == chatId);

    if (!m_db->deleteChat(chatId)) {
        return;
    }

    m_chatModel->removeChat(chatId);
    
    if (wasActiveChat) {
        m_activeChatId = -1;
        m_messageModel->clear();
        m_messageModel->setSenderAvatarMap({});
        m_activeParticipants.clear();
        emit activeParticipantsChanged();
        emit activeChatChanged();
    }

    // Media cleanup with retry logic
    if (m_media) {
        // File handles can briefly stay open after view teardown; retry cleanup.
        constexpr int kMaxAttempts = 20;
        constexpr int kRetryDelayMs = 250;

        for (int attempt = 0; attempt <= kMaxAttempts; ++attempt) {
            const int delayMs = attempt * kRetryDelayMs;
            QTimer::singleShot(delayMs, this, [this, chatId, attempt]() {
                if (!m_media) {
                    return;
                }

                const bool removed = m_media->deleteChatMedia(chatId);
                if (!removed && attempt == kMaxAttempts) {
                    Logger::warn("Media cleanup still failed after retries for chat: id=" + std::to_string(chatId));
                }
            });
        }
    }

    Logger::info(QString("=== [DELETE-CHAT] DONE: id=%1 ===").arg(chatId).toStdString());
}

void MainWindow::setChatAvatar(int chatId, const QString& imagePath)
{
    if (!m_db || !m_chatModel) {
        return;
    }
    
    Logger::info(QString("setChatAvatar: chatId=%1, avatar='%2'").arg(chatId).arg(imagePath).toStdString());
    
    m_db->updateChatAvatar(chatId, imagePath);
    const int row = m_chatModel->indexOfChat(chatId);
    if (row >= 0) {
        Chat ch = m_chatModel->chatAt(row);
        ch.customAvatarPath = imagePath;
        m_chatModel->updateChat(ch);
        
        // AUTO-SYNC: For direct (1-1) chats, sync to Profile Library and propagate everywhere
        if (ch.chatType.compare("direct", Qt::CaseInsensitive) == 0 && !ch.contactName.trimmed().isEmpty()) {
            QString contactName = ch.contactName.trimmed();
            
            Logger::info(QString("  → Direct chat detected, syncing contact: %1").arg(contactName).toStdString());
            
            // Add/update in Profile Library
            if (m_db->profileExistsInLibrary(contactName)) {
                m_db->updateProfileLibraryAvatar(contactName, imagePath);
            } else {
                m_db->addProfileToLibrary(contactName, imagePath);
            }
            
            // Propagate EVERYWHERE
            syncAvatarEverywhere(contactName, imagePath);
            
            // Reload profile library UI
            loadProfileLibrary();
        }
    }
    
    if (m_activeChatId == chatId) {
        emit activeChatChanged();
    }
}

QString MainWindow::myAvatar() const
{
    return m_db->getSetting("my_avatar", "");
}

QString MainWindow::defaultOwnerName() const
{
    return m_db->getSetting("default_owner_name", "");
}

void MainWindow::setDefaultOwnerName(const QString& name)
{
    if (!m_db) {
        return;
    }
    
    const QString newOwnerName = name.trimmed();
    const QString oldOwnerName = m_db->getSetting("default_owner_name", "").trimmed();
    
    // If name hasn't changed, nothing to do
    if (newOwnerName == oldOwnerName) {
        return;
    }
    
    Logger::info(QString("Owner name changing: '%1' → '%2'").arg(oldOwnerName).arg(newOwnerName).toStdString());
    
    // Remove old owner from Profile Library (cleanup)
    if (!oldOwnerName.isEmpty()) {
        m_db->removeProfileFromLibrary(oldOwnerName);
        Logger::info(QString("Removed old owner from profile library: %1").arg(oldOwnerName).toStdString());
    }
    
    // Update the setting
    m_db->setSetting("default_owner_name", newOwnerName);
    
    // Update all owner participants across all chats
    if (!oldOwnerName.isEmpty()) {
        auto allChats = m_db->allChats();
        for (const auto& chat : allChats) {
            auto ownerParticipants = m_db->getOwnerParticipantsForChat(chat.id);
            for (const QString& ownerParticipant : ownerParticipants) {
                // Normalize for comparison
                QString normalizedOwnerParticipant = DatabaseManager::normalizeString(ownerParticipant);
                QString normalizedOldOwner = DatabaseManager::normalizeString(oldOwnerName);
                
                if (normalizedOwnerParticipant == normalizedOldOwner) {
                    // Update this owner participant to use new name
                    m_db->updateParticipantName(chat.id, ownerParticipant, newOwnerName);
                    Logger::info(QString("Updated owner participant name in chat %1: %2 → %3")
                               .arg(chat.id).arg(ownerParticipant).arg(newOwnerName).toStdString());
                }
            }
        }
    }
    
    // If new owner has avatar set, ensure it's in Profile Library
    // (It will be filtered from UI but used for avatar lookup)
    QString myAvatar = m_db->getSetting("my_avatar", "").trimmed();
    if (!newOwnerName.isEmpty() && !myAvatar.isEmpty()) {
        if (m_db->profileExistsInLibrary(newOwnerName)) {
            m_db->updateProfileLibraryAvatar(newOwnerName, myAvatar);
        } else {
            m_db->addProfileToLibrary(newOwnerName, myAvatar);
        }
        Logger::info(QString("Added/updated new owner in profile library: %1").arg(newOwnerName).toStdString());
    }
    
    // Reload UI
    if (m_activeChatId >= 0) {
        reloadActiveParticipants();
        refreshSenderAvatarMap();
    }
    
    // Reload profile library (owner will be filtered out)
    loadProfileLibrary();
    
    emit defaultOwnerNameChanged();
    emit profileLibraryChanged(); // Refresh to hide/show profiles
}

void MainWindow::setMyAvatar(const QString& imagePath)
{
    if (!m_db) {
        return;
    }
    
    const QString ownerName = m_db->getSetting("default_owner_name", "").trimmed();
    const QString newAvatarPath = imagePath.trimmed();
    
    Logger::info(QString("Owner avatar changing for '%1': %2").arg(ownerName).arg(newAvatarPath).toStdString());
    
    // Update the setting
    m_db->setSetting("my_avatar", newAvatarPath);
    
    // Add/update owner in Profile Library (it will be filtered from UI)
    if (!ownerName.isEmpty() && !newAvatarPath.isEmpty()) {
        if (m_db->profileExistsInLibrary(ownerName)) {
            m_db->updateProfileLibraryAvatar(ownerName, newAvatarPath);
        } else {
            m_db->addProfileToLibrary(ownerName, newAvatarPath);
        }
        Logger::info(QString("Updated owner in profile library: %1").arg(ownerName).toStdString());
    }
    
    // Update all owner participants across all chats with new avatar
    if (!ownerName.isEmpty() && !newAvatarPath.isEmpty()) {
        auto allChats = m_db->allChats();
        for (const auto& chat : allChats) {
            auto ownerParticipants = m_db->getOwnerParticipantsForChat(chat.id);
            for (const QString& ownerParticipant : ownerParticipants) {
                // Normalize for comparison
                QString normalizedOwnerParticipant = DatabaseManager::normalizeString(ownerParticipant);
                QString normalizedOwner = DatabaseManager::normalizeString(ownerName);
                
                if (normalizedOwnerParticipant == normalizedOwner) {
                    // Update this owner participant avatar
                    m_db->updateParticipantAvatar(chat.id, ownerParticipant, newAvatarPath);
                    Logger::info(QString("Updated owner participant avatar in chat %1: %2")
                               .arg(chat.id).arg(ownerParticipant).toStdString());
                }
            }
        }
    }
    
    // Reload UI
    if (m_activeChatId >= 0) {
        reloadActiveParticipants();
        refreshSenderAvatarMap();
    }
    
    // Reload profile library (owner will be filtered out from display)
    loadProfileLibrary();
    
    emit myAvatarChanged();
    emit profileLibraryChanged(); // Refresh favorites if needed
}

void MainWindow::searchInChat(const QString& query)
{
    const QString trimmedQuery = query.trimmed();
    if (trimmedQuery.isEmpty()) {
        clearSearch();
        return;
    }

    if (m_activeChatId < 0) {
        return;
    }

    const int searchChatId = m_activeChatId;
    QElapsedTimer timer;
    timer.start();

    m_messageModel->setSearchQuery(trimmedQuery);

    if (searchChatId != m_activeChatId) {
        Logger::debug(QString("searchInChat: stale result ignored, chat switched from %1 to %2")
                      .arg(searchChatId)
                      .arg(m_activeChatId));
        return;
    }

    const int firstIdx = m_messageModel->firstSearchResultIndex();
    const int total    = m_messageModel->searchResultCount();
    if (total > 0) {
        m_messageModel->setCurrentSearchResult(0);
    }

    Logger::debug(QString("searchInChat: chat=%1 queryLen=%2 results=%3 elapsed=%4ms loaded=%5/%6")
                  .arg(searchChatId)
                  .arg(trimmedQuery.size())
                  .arg(total)
                  .arg(timer.elapsed())
                  .arg(m_messageModel->rowCount())
                  .arg(m_messageModel->totalCount()));

    emit searchResultReady(firstIdx, total);
}

void MainWindow::clearSearch()
{
    m_messageModel->clearSearch();
}

void MainWindow::scrollToSearchResult(int resultNumber)
{
    m_messageModel->setCurrentSearchResult(resultNumber);
    const int messageIndex = m_messageModel->searchResultIndexAt(resultNumber);
    emit scrollIndexReady(messageIndex);
}

QString MainWindow::getWaveform(const QString& audioPath)
{
    if (audioPath.isEmpty()) return "";
    // Call the existing method in MediaManager.
    return m_media->generateWaveform(audioPath);
}

void MainWindow::requestWaveform(const QString& audioPath)
{
    if (audioPath.isEmpty()) return;

    // De-duplicate: if a job for this path is already running, skip.
    {
        QMutexLocker lk(&m_waveformMutex);
        if (m_waveformInFlight.contains(audioPath)) return;
        m_waveformInFlight.insert(audioPath);
    }

    // Shared ownership keeps MediaManager alive even if MainWindow is destroyed
    // while the background job is still running.
    QSharedPointer<MediaManager> mediaCopy = m_media;
    QPointer<MainWindow> selfGuard(this);
    const QString path = audioPath;

    QThreadPool::globalInstance()->start([path, mediaCopy, selfGuard]() {
        const QString result = mediaCopy->generateWaveform(path);

        // Hop back to the UI thread to update bookkeeping, persist to DB and
        // emit the signal — DB writes and model updates must happen on the
        // thread that owns those QObjects.
        QMetaObject::invokeMethod(qApp, [path, result, selfGuard]() {
            MainWindow* self = selfGuard.data();
            if (!self) return;  // MainWindow gone — drop result silently.

            {
                QMutexLocker lk(&self->m_waveformMutex);
                self->m_waveformInFlight.remove(path);
            }

            // Cache the result: update the loaded model rows AND persist to
            // SQLite so the next chat load reads it for free.
            if (!result.isEmpty() && self->m_messageModel) {
                self->m_messageModel->setWaveformByPath(path, result);
            }

            emit self->waveformReady(path, result);
        }, Qt::QueuedConnection);
    });
}

QString MainWindow::audioSpeedCachedPath(const QString& audioPath, qreal rate) const
{
    return m_audioSpeed ? m_audioSpeed->cachedPathIfExists(audioPath, rate)
                        : QString();
}

void MainWindow::requestAudioSpeed(const QString& audioPath, qreal rate)
{
    if (m_audioSpeed) m_audioSpeed->requestStretched(audioPath, rate);
}

QVariantList MainWindow::getMediaForBrowser(const QString& mediaType)
{
    QVariantList result;
    if (!m_db || m_activeChatId < 0) {
        return result;
    }

    auto messages = m_db->getMediaMessages(m_activeChatId, mediaType);
    for (const auto& msg : messages) {
        QVariantMap item;
        item["id"] = msg.id;
        item["sender"] = msg.sender;
        item["timestamp"] = msg.timestamp;
        
        // Add file:/// prefix for QML Image/Video components (cross-platform)
        QString mediaPath = msg.mediaPath;
        if (!mediaPath.isEmpty() && !mediaPath.startsWith("file://") && !mediaPath.startsWith("qrc:")) {
            // QUrl::fromLocalFile handles cross-platform path correctly
            mediaPath = QUrl::fromLocalFile(mediaPath).toString();
        }
        
        QString thumbnailPath = msg.mediaThumbnailPath;
        if (!thumbnailPath.isEmpty() && !thumbnailPath.startsWith("file://") && !thumbnailPath.startsWith("qrc:")) {
            thumbnailPath = QUrl::fromLocalFile(thumbnailPath).toString();
        }
        
        item["mediaPath"] = mediaPath;
        item["thumbnailPath"] = thumbnailPath;
        item["content"] = msg.content;
        item["isFromMe"] = msg.isFromMe;
        result.append(item);
    }
    return result;
}

QVariantList MainWindow::getLinksForBrowser()
{
    QVariantList result;
    if (!m_db || m_activeChatId < 0) {
        return result;
    }

    auto links = m_db->getLinks(m_activeChatId);
    for (const auto& link : links) {
        QVariantMap item;
        item["url"] = link;
        result.append(item);
    }
    return result;
}

QVariantList MainWindow::getLocationsForBrowser()
{
    QVariantList result;
    if (!m_db || m_activeChatId < 0) {
        return result;
    }

    auto messages = m_db->getLocationMessages(m_activeChatId);
    for (const auto& msg : messages) {
        QVariantMap item;
        item["id"] = msg.id;
        item["sender"] = msg.sender;
        item["timestamp"] = msg.timestamp;
        item["content"] = msg.content;
        item["mediaMeta"] = msg.mediaMeta;  // Contains lat,lng coordinates
        item["isFromMe"] = msg.isFromMe;
        result.append(item);
    }
    return result;
}

void MainWindow::setImporting(bool v)
{

    if (m_isImporting == v) return;
    m_isImporting = v;
    if (v) {
        setImportProgress(0.0, -1);
    }
    emit importingChanged();
}

void MainWindow::setImportProgress(double value, int etaSeconds)
{
    const double clamped = qBound(0.0, value, 1.0);
    const bool progressChanged = qAbs(m_importProgress - clamped) > 0.0005;
    const bool etaChanged = m_importEtaSeconds != etaSeconds;
    if (!progressChanged && !etaChanged) {
        return;
    }

    m_importProgress = clamped;
    m_importEtaSeconds = etaSeconds;
    emit importProgressChanged();
}

// ============================================================================
// Profile Library Management
// ============================================================================

void MainWindow::loadProfileLibrary()
{
    if (!m_db) {
        return;
    }
    
    m_profileLibrary.clear();
    QHash<QString, QString> profiles = m_db->getAllProfileLibrary();
    
    // Get current owner name to filter it out from the visible profile library
    QString ownerName = m_db->getSetting("default_owner_name", "").trimmed();
    QString normalizedOwnerName = DatabaseManager::normalizeString(ownerName);
    
    for (auto it = profiles.constBegin(); it != profiles.constEnd(); ++it) {
        QString profileName = it.key();
        QString normalizedProfileName = DatabaseManager::normalizeString(profileName);
        
        // FILTER: Skip owner profile - it should be hidden from profile library UI
        if (!normalizedOwnerName.isEmpty() && normalizedProfileName == normalizedOwnerName) {
            Logger::info(QString("Filtering owner profile from library UI: %1").arg(profileName).toStdString());
            continue;
        }
        
        QVariantMap profile;
        profile.insert("name", profileName);
        profile.insert("avatarPath", it.value());
        profile.insert("initials", initialsForName(profileName));
        profile.insert("avatarColor", colorForName(profileName));
        m_profileLibrary.append(profile);
    }
    
    emit profileLibraryChanged();
    Logger::info(QString("Loaded %1 profiles from library (owner filtered)").arg(m_profileLibrary.size()).toStdString());
}

bool MainWindow::addProfileToLibrary(const QString& name, const QString& avatarPath)
{
    if (!m_db) {
        return false;
    }
    
    // Normalize the input name for consistent Unicode representation
    const QString normalizedName = name.normalized(QString::NormalizationForm_C).trimmed();
    if (normalizedName.isEmpty()) {
        return false;
    }
    
    // Check if name is same as owner name (both normalized for comparison)
    const QString ownerName = defaultOwnerName().normalized(QString::NormalizationForm_C);
    if (!ownerName.isEmpty() && normalizedName.compare(ownerName, Qt::CaseInsensitive) == 0) {
        // Emit error signal with translated message
        if (m_langManager) {
            const QString errorMsg = m_langManager->currentTranslations().value("profile_owner_conflict", 
                "Cannot add profile with same name as owner").toString();
            emit importError(errorMsg);
        } else {
            emit importError("Cannot add profile with same name as owner");
        }
        return false;
    }
    
    // Check if profile already exists (DatabaseManager will normalize again for consistency)
    if (m_db->profileExistsInLibrary(normalizedName)) {
        if (m_langManager) {
            const QString errorMsg = m_langManager->currentTranslations().value("profile_exists", 
                "Profile with this name already exists").toString();
            emit importError(errorMsg);
        } else {
            emit importError("Profile with this name already exists");
        }
        return false;
    }
    
    QString finalAvatarPath = avatarPath.trimmed();
    if (finalAvatarPath.isEmpty()) {
        finalAvatarPath = randomAvatarResourcePath();
    }
    
    if (!m_db->addProfileToLibrary(normalizedName, finalAvatarPath)) {
        return false;
    }
    
    loadProfileLibrary();
    
    // Reload active participants to apply new profile immediately
    if (m_activeChatId >= 0) {
        reloadActiveParticipants();
        refreshSenderAvatarMap();
    }
    
    return true;
}

void MainWindow::removeProfileFromLibrary(const QString& name)
{
    if (!m_db) {
        Logger::error("removeProfileFromLibrary: m_db is null");
        return;
    }
    
    const QString trimmedName = name.trimmed();
    if (trimmedName.isEmpty()) {
        Logger::error("removeProfileFromLibrary: name is empty");
        return;
    }
    
    Logger::info(QString("removeProfileFromLibrary called: name='%1'").arg(trimmedName).toStdString());
    
    // Generate a random default avatar for this person
    QString defaultAvatar = randomAvatarResourcePath();
    
    // Remove from profile library database
    bool removed = m_db->removeProfileFromLibrary(trimmedName);
    Logger::info(QString("removeProfileFromLibrary database result: %1").arg(removed ? "SUCCESS" : "FAILED").toStdString());
    
    // Propagate default avatar EVERYWHERE
    syncAvatarEverywhere(trimmedName, defaultAvatar);
    
    // Reload profile library UI
    loadProfileLibrary();
    Logger::info(QString("Profile library reloaded, size: %1").arg(m_profileLibrary.size()).toStdString());
}

// ============================================================================
// CENTRAL SYNC FUNCTION: Propagate avatar changes everywhere
// ============================================================================
void MainWindow::syncAvatarEverywhere(const QString& participantName, const QString& avatarPath)
{
    if (!m_db || participantName.trimmed().isEmpty()) {
        return;
    }
    
    const QString trimmedName = participantName.trimmed();
    const QString normalizedTarget = DatabaseManager::normalizeString(trimmedName);
    
    Logger::info(QString("syncAvatarEverywhere: name='%1', avatar='%2'")
                .arg(trimmedName).arg(avatarPath).toStdString());
    
    auto allChats = m_db->allChats();
    QSet<int> affectedDirectChats;
    bool needsChatListRefresh = false;
    bool needsMessageRefresh = false;
    
    // 1. Update ALL participants with this name across ALL chats
    for (const auto& chat : allChats) {
        auto participants = m_db->participantsForChat(chat.id);
        for (const auto& participant : participants) {
            QString normalizedParticipant = DatabaseManager::normalizeString(participant.name);
            
            if (normalizedParticipant == normalizedTarget) {
                // Update participant avatar
                m_db->updateParticipantAvatar(chat.id, participant.name, avatarPath);
                Logger::info(QString("  → Updated participant in chat %1").arg(chat.id).toStdString());
                
                // Track if this affects a direct chat
                if (chat.chatType.compare("direct", Qt::CaseInsensitive) == 0) {
                    affectedDirectChats.insert(chat.id);
                }
                
                // Track if active chat is affected
                if (chat.id == m_activeChatId) {
                    needsMessageRefresh = true;
                }
            }
        }
    }
    
    // 2. Update direct chats where this participant is the contact
    for (int chatId : affectedDirectChats) {
        const int row = m_chatModel->indexOfChat(chatId);
        if (row >= 0) {
            Chat chat = m_chatModel->chatAt(row);
            QString normalizedChatName = DatabaseManager::normalizeString(chat.contactName);
            
            if (normalizedChatName == normalizedTarget) {
                // Update chat avatar in database
                m_db->updateChatAvatar(chatId, avatarPath);
                
                // Update ChatListModel cache
                chat.customAvatarPath = avatarPath;
                m_chatModel->updateChat(chat);
                needsChatListRefresh = true;
                
                Logger::info(QString("  → Updated direct chat avatar (chatId=%1)").arg(chatId).toStdString());
                
                // Trigger activeChatChanged if this is the active chat
                if (chatId == m_activeChatId) {
                    emit activeChatChanged();
                }
            }
        }
    }
    
    // 3. Refresh active chat UI if affected
    if (needsMessageRefresh && m_activeChatId >= 0) {
        reloadActiveParticipants();
        refreshSenderAvatarMap();
        Logger::info("  → Refreshed active chat message model");
    }
    
    // 4. Trigger favorites refresh
    emit profileLibraryChanged();
    Logger::info("  → Triggered favorites refresh");
    
    Logger::info(QString("syncAvatarEverywhere complete: %1 direct chats affected")
                .arg(affectedDirectChats.size()).toStdString());
}

// ============================================================================

void MainWindow::updateProfileLibraryAvatar(const QString& name, const QString& avatarPath)
{
    if (!m_db) {
        return;
    }
    
    const QString trimmedName = name.trimmed();
    if (trimmedName.isEmpty()) {
        return;
    }
    
    Logger::info(QString("updateProfileLibraryAvatar: name='%1', avatar='%2'")
                .arg(trimmedName).arg(avatarPath).toStdString());
    
    // Update in Profile Library database
    m_db->updateProfileLibraryAvatar(trimmedName, avatarPath);
    
    // Propagate avatar change EVERYWHERE
    syncAvatarEverywhere(trimmedName, avatarPath);
    
    // Reload profile library UI
    loadProfileLibrary();
}

QString MainWindow::getProfileLibraryAvatar(const QString& name)
{
    if (!m_db) {
        return QString();
    }
    
    const QString trimmedName = name.trimmed();
    if (trimmedName.isEmpty()) {
        return QString();
    }
    
    return m_db->getProfileLibraryAvatar(trimmedName);
}

QStringList MainWindow::getMessageDatesForCurrentChat()
{
    if (!m_db || m_activeChatId < 0) {
        return QStringList();
    }
    
    return m_db->getMessageDatesForChat(m_activeChatId);
}

void MainWindow::jumpToDate(const QString& date)
{
    if (!m_db || m_activeChatId < 0 || date.isEmpty()) {
        return;
    }
    
    const int messageIndex = m_db->getFirstMessageIndexForDate(m_activeChatId, date);
    if (messageIndex >= 0) {
        // Ensure all messages are loaded (needed for accurate positioning)
        m_messageModel->ensureAllLoaded();
        emit jumpToDateIndex(messageIndex);
        Logger::info(QString("Jump to date: %1, index: %2").arg(date).arg(messageIndex).toStdString());
    }
}


// ============================================================================
// Favorites (Starred Messages)
// ============================================================================

bool MainWindow::addToFavorites(int chatId, int messageId)
{
    if (!m_db) {
        return false;
    }
    
    bool success = m_db->addToFavorites(chatId, messageId);
    if (success) {
        emit favoritesChanged();
        Logger::info(QString("Added to favorites: chatId=%1, messageId=%2").arg(chatId).arg(messageId).toStdString());
    }
    return success;
}

bool MainWindow::removeFromFavorites(int chatId, int messageId)
{
    if (!m_db) {
        return false;
    }
    
    bool success = m_db->removeFromFavorites(chatId, messageId);
    if (success) {
        emit favoritesChanged();
        Logger::info(QString("Removed from favorites: chatId=%1, messageId=%2").arg(chatId).arg(messageId).toStdString());
    }
    return success;
}

bool MainWindow::isMessageFavorite(int chatId, int messageId)
{
    if (!m_db) {
        return false;
    }
    
    return m_db->isMessageFavorite(chatId, messageId);
}

// Helper function to format media duration (ms) as MM:SS
static QString formatDuration(qint64 ms)
{
    if (ms <= 0) return "0:00";
    const int totalSec = static_cast<int>(ms / 1000);
    const int mins     = totalSec / 60;
    const int secs     = totalSec % 60;
    return QString("%1:%2").arg(mins).arg(secs, 2, 10, QChar('0'));
}

QVariantList MainWindow::getAllFavorites()
{
    QVariantList result;
    
    if (!m_db || !m_chatModel) {
        return result;
    }
    
    auto favorites = m_db->getAllFavorites();
    
    for (const auto& fav : favorites) {
        int chatId = fav.first;
        int messageId = fav.second;
        
        // Get chat info
        int chatRow = m_chatModel->indexOfChat(chatId);
        if (chatRow < 0) {
            continue; // Chat deleted
        }
        
        Chat chat = m_chatModel->chatAt(chatRow);
        bool isGroupChat = (chat.chatType.compare("group", Qt::CaseInsensitive) == 0);
        
        // Get ONLY this specific message by ID (efficient - no loading all messages!)
        bool found = false;
        Message foundMessage = m_db->getMessageById(chatId, messageId, &found);
        
        if (!found) {
            continue; // Message deleted
        }
        
        // Get sender avatar - use Profile Library for synchronization
        QString senderAvatarPath;
        QString senderName;
        
        if (foundMessage.isFromMe) {
            // For messages sent by me, try to determine the actual sender name
            // This could be from the message sender field or owner participants
            
            if (!foundMessage.sender.trimmed().isEmpty()) {
                // If message has sender field, use it
                senderName = foundMessage.sender.trimmed();
            } else {
                // Fallback: try to get owner participant for this chat
                auto ownerParticipants = m_db->getOwnerParticipantsForChat(chatId);
                if (!ownerParticipants.isEmpty()) {
                    senderName = (*ownerParticipants.begin()).trimmed();
                }
            }
            
            // If we have a sender name, get their avatar
            if (!senderName.isEmpty()) {
                // Strip tilde prefix for profile lookup (iOS compatibility)
                QString lookupName = senderName;
                if (lookupName.startsWith("~ ")) {
                    lookupName = lookupName.mid(2).trimmed();
                } else if (lookupName.startsWith("~")) {
                    lookupName = lookupName.mid(1).trimmed();
                }
                
                // Try Profile Library first (using clean name without tilde)
                senderAvatarPath = m_db->getProfileLibraryAvatar(lookupName);
                
                // If not in library, try participants table
                if (senderAvatarPath.isEmpty()) {
                    auto participants = m_db->participantsForChat(chatId);
                    for (const auto& p : participants) {
                        QString normalizedParticipantName = DatabaseManager::normalizeString(p.name);
                        QString normalizedLookupName = DatabaseManager::normalizeString(lookupName);
                        
                        if (normalizedParticipantName == normalizedLookupName) {
                            senderAvatarPath = p.customAvatarPath;
                            break;
                        }
                    }
                }
                
                // Fallback: get avatar from participantAvatarMap
                if (senderAvatarPath.isEmpty()) {
                    auto avatarMap = m_db->participantAvatarMap(chatId);
                    if (avatarMap.contains(senderName)) {
                        senderAvatarPath = avatarMap.value(senderName);
                    } else if (avatarMap.contains(lookupName)) {
                        senderAvatarPath = avatarMap.value(lookupName);
                    }
                }
            }
            
            // Fallback to myAvatar setting (global default)
            if (senderAvatarPath.isEmpty()) {
                senderAvatarPath = m_db->getSetting("my_avatar", "");
            }
            
            // Last resort: random avatar (but consistent via avatarMap)
            if (senderAvatarPath.isEmpty()) {
                senderAvatarPath = randomAvatarResourcePath();
            }
        } else {
            // For received messages, use sender field
            senderName = foundMessage.sender.trimmed();
            
            if (!senderName.isEmpty()) {
                // Strip tilde prefix for profile lookup (iOS compatibility)
                QString lookupName = senderName;
                if (lookupName.startsWith("~ ")) {
                    lookupName = lookupName.mid(2).trimmed();
                } else if (lookupName.startsWith("~")) {
                    lookupName = lookupName.mid(1).trimmed();
                }
                
                // Try Profile Library first (using clean name without tilde)
                senderAvatarPath = m_db->getProfileLibraryAvatar(lookupName);
                
                // If not in library, try participants table (with both original and clean name)
                if (senderAvatarPath.isEmpty()) {
                    auto participants = m_db->participantsForChat(chatId);
                    for (const auto& p : participants) {
                        QString normalizedParticipantName = DatabaseManager::normalizeString(p.name);
                        QString normalizedLookupName = DatabaseManager::normalizeString(lookupName);
                        QString normalizedOriginalName = DatabaseManager::normalizeString(senderName);
                        
                        if (normalizedParticipantName == normalizedLookupName ||
                            normalizedParticipantName == normalizedOriginalName) {
                            senderAvatarPath = p.customAvatarPath;
                            break;
                        }
                    }
                }
                
                // Fallback: get avatar from participantAvatarMap (uses new logic with messages table)
                if (senderAvatarPath.isEmpty()) {
                    auto avatarMap = m_db->participantAvatarMap(chatId);
                    if (avatarMap.contains(senderName)) {
                        senderAvatarPath = avatarMap.value(senderName);
                    } else if (avatarMap.contains(lookupName)) {
                        senderAvatarPath = avatarMap.value(lookupName);
                    }
                }
                
                // Last resort: random avatar (but this will be consistent per sender via avatarMap)
                if (senderAvatarPath.isEmpty()) {
                    senderAvatarPath = randomAvatarResourcePath();
                }
            } else {
                // No sender info - use random avatar
                senderAvatarPath = randomAvatarResourcePath();
            }
        }
        
        // Prepare formatted content (apply link formatting if text message)
        QString formattedContent = foundMessage.content;
        if (foundMessage.type == MessageType::Text) {
            formattedContent = WAPageTextFormatter::formatFull(foundMessage.content);
        } else if (foundMessage.type == MessageType::System) {
            // Translate system messages
            if (m_langManager && foundMessage.content.startsWith(QStringLiteral("__sys:"))) {
                formattedContent = m_langManager->translateSystemMessage(foundMessage.content);
            }
        } else if (foundMessage.type == MessageType::Deleted) {
            // Keep raw content for deleted messages (QML handles display)
            formattedContent = foundMessage.content;
        }
        
        // Map MessageType enum to string
        QString msgTypeStr = "text";
        switch (foundMessage.type) {
            case MessageType::Image:    msgTypeStr = "image"; break;
            case MessageType::Video:    msgTypeStr = "video"; break;
            case MessageType::Audio:    msgTypeStr = "audio"; break;
            case MessageType::Ptt:      msgTypeStr = "ptt"; break;
            case MessageType::Sticker:  msgTypeStr = "sticker"; break;
            case MessageType::Document: msgTypeStr = "document"; break;
            case MessageType::Location: msgTypeStr = "location"; break;
            case MessageType::Contact:  msgTypeStr = "contact"; break;
            case MessageType::System:   msgTypeStr = "system"; break;
            case MessageType::Deleted:  msgTypeStr = "deleted"; break;
            default: break;
        }
        
        // Build complete item with all MessageBubble properties
        QVariantMap item;
        
        // For DIRECT chats, determine the correct chat avatar (contact's avatar)
        // In direct chats, the chat name IS the contact name (not owner name)
        QString finalChatAvatar = chat.customAvatarPath;
        if (!isGroupChat) {
            // For direct chats, try to get contact avatar by contact name
            QString contactName = chat.contactName.trimmed();
            if (!contactName.isEmpty()) {
                // Try Profile Library first
                QString contactAvatar = m_db->getProfileLibraryAvatar(contactName);
                
                // If not in library, try participants table
                if (contactAvatar.isEmpty()) {
                    auto participants = m_db->participantsForChat(chatId);
                    for (const auto& p : participants) {
                        if (DatabaseManager::normalizeString(p.name) == 
                            DatabaseManager::normalizeString(contactName)) {
                            contactAvatar = p.customAvatarPath;
                            break;
                        }
                    }
                }
                
                if (!contactAvatar.isEmpty()) {
                    finalChatAvatar = contactAvatar;
                }
            }
            
            // If still empty, use random
            if (finalChatAvatar.isEmpty()) {
                finalChatAvatar = randomAvatarResourcePath();
            }
        } else {
            // For group chats, use chat's own avatar
            if (finalChatAvatar.isEmpty()) {
                finalChatAvatar = randomGroupAvatarResourcePath();
            }
        }
        
        // Chat identification (for jump functionality)
        item["chatId"] = chatId;
        item["messageId"] = messageId;
        item["chatName"] = chat.contactName;
        item["chatAvatar"] = finalChatAvatar;
        item["isGroupChat"] = isGroupChat;
        
        // MessageBubble properties
        item["msgId"] = foundMessage.id;
        item["isFromMe"] = foundMessage.isFromMe;
        item["formattedContent"] = formattedContent;
        item["msgTime"] = foundMessage.timestamp.toString("HH:mm");
        item["sender"] = foundMessage.sender;
        item["senderAvatar"] = senderAvatarPath;
        item["msgDate"] = foundMessage.timestamp.toString("dd.MM.yyyy");
        item["readStatus"] = static_cast<int>(foundMessage.readStatus);
        item["msgType"] = msgTypeStr;
        
        // Media paths - ensure they are absolute file paths
        QString mediaPath = foundMessage.mediaPath;
        if (!mediaPath.isEmpty() && !mediaPath.startsWith("file:///") && !mediaPath.startsWith("qrc:/")) {
            // Convert relative path to absolute if needed
            QDir mediaDir(m_dataDir + "/media");
            if (!QFileInfo(mediaPath).isAbsolute()) {
                mediaPath = mediaDir.absoluteFilePath(mediaPath);
            }
        }
        
        QString thumbnailPath = foundMessage.mediaThumbnailPath;
        if (!thumbnailPath.isEmpty() && !thumbnailPath.startsWith("file:///") && !thumbnailPath.startsWith("qrc:/")) {
            QDir mediaDir(m_dataDir + "/media");
            if (!QFileInfo(thumbnailPath).isAbsolute()) {
                thumbnailPath = mediaDir.absoluteFilePath(thumbnailPath);
            }
        }
        
        item["mediaPath"] = mediaPath;
        item["mediaThumbnail"] = thumbnailPath;
        item["mediaDuration"] = formatDuration(foundMessage.mediaDurationMs);
        item["mediaMeta"] = foundMessage.mediaMeta;
        item["waveform"] = foundMessage.waveform;
        item["editedText"] = foundMessage.editedText.isEmpty() ? "" : "1";
        item["timestamp"] = foundMessage.timestamp; // For sorting/display
        
        // Fixed values for favorites display
        item["isFirstInGroup"] = true;  // Always show sender name for favorites
        item["isLastInGroup"] = true;   // Always show avatar for favorites
        item["showDate"] = false;       // No date separator needed in favorites
        
        result.append(item);
    }
    
    return result;
}

void MainWindow::jumpToFavoriteMessage(int chatId, int messageId)
{
    if (!m_db || chatId < 0 || messageId < 0) {
        return;
    }
    
    // Switch to the chat if not already active
    if (m_activeChatId != chatId) {
        selectChat(chatId);
    }
    
    // Ensure all messages are loaded
    m_messageModel->ensureAllLoaded();
    
    // Find the message index
    int messageIndex = -1;
    for (int i = 0; i < m_messageModel->rowCount(); ++i) {
        QModelIndex idx = m_messageModel->index(i, 0);
        int msgId = m_messageModel->data(idx, MessageListModel::IdRole).toInt();
        if (msgId == messageId) {
            messageIndex = i;
            break;
        }
    }
    
    if (messageIndex >= 0) {
        emit scrollIndexReady(messageIndex);
        Logger::info(QString("Jump to favorite message: chatId=%1, messageId=%2, index=%3")
                    .arg(chatId).arg(messageId).arg(messageIndex).toStdString());
    }
}
