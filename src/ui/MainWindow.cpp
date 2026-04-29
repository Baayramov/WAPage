#include "MainWindow.h"
#include "utils/Logger.h"
#include "core/LanguageManager.h"

#include <QDateTime>
#include <QDir>
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
}

void MainWindow::loadAll()
{
    const auto chats = m_db->allChats();
    m_chatModel->setChats(chats);
    Logger::info("Loaded: " + std::to_string(chats.size()) + " chats");
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
    const QString name = activeChatName();
    if (name.isEmpty()) return "?";
    const QStringList parts = name.trimmed().split(' ', Qt::SkipEmptyParts);
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
            const QString trimmedName = participantName.trimmed();
            if (trimmedName.isEmpty()) {
                continue;
            }
            if (!ownerTrimmed.isEmpty() && trimmedName == ownerTrimmed) {
                continue;
            }
            if (!cleanedParticipants.contains(trimmedName)) {
                cleanedParticipants.append(trimmedName);
            }
        }

        for (const QString& participantName : cleanedParticipants) {
            m_db->upsertParticipant(chatId, participantName, randomAvatarResourcePath());
        }

        if (parseResult.isGroup && cleanedParticipants.isEmpty()) {
            m_db->seedParticipantsFromMessages(chatId, ownerN);
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

    const bool wasActiveChat = (m_activeChatId == chatId);

    if (!m_db->deleteChat(chatId)) {
        Logger::error("Chat delete failed: id=" + std::to_string(chatId));
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

    Logger::info("Chat deleted: id=" + std::to_string(chatId));
}

void MainWindow::setChatAvatar(int chatId, const QString& imagePath)
{
    m_db->updateChatAvatar(chatId, imagePath);
    const int row = m_chatModel->indexOfChat(chatId);
    if (row >= 0) {
        Chat ch     = m_chatModel->chatAt(row);
        ch.customAvatarPath = imagePath;
        m_chatModel->updateChat(ch);
    }
    if (m_activeChatId == chatId)
        emit activeChatChanged();
}

QString MainWindow::myAvatar() const
{
    return m_db->getSetting("my_avatar", "");
}

void MainWindow::setMyAvatar(const QString& imagePath)
{
    m_db->setSetting("my_avatar", imagePath);
    emit myAvatarChanged();
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
