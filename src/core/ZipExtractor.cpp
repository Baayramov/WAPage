#include "ZipExtractor.h"
#include "utils/Logger.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QUuid>
#include <QProcess>
#include <QDirIterator>
#include <QElapsedTimer>
#include <QRegularExpression>
#include <QTextStream>

static bool runExpandArchive(const QString& archivePath,
                             const QString& destinationDir,
                             qint64 timeoutMs,
                             QString& errorOut)
{
    QString escapedArchivePath = archivePath;
    QString escapedDestinationDir = destinationDir;
    escapedArchivePath.replace("'", "''");
    escapedDestinationDir.replace("'", "''");

    QProcess process;
    process.setProgram("powershell");
    process.setArguments({
        "-NoProfile", "-Command",
        QString("Expand-Archive -LiteralPath '%1' -DestinationPath '%2' -Force")
            .arg(escapedArchivePath, escapedDestinationDir)
    });

    process.start();
    if (!process.waitForStarted(5000)) {
        errorOut = "ZIP extraction could not start (PowerShell failed to launch).";
        return false;
    }

    QElapsedTimer waitTimer;
    waitTimer.start();

    while (process.state() != QProcess::NotRunning) {
        if (process.waitForFinished(180)) {
            break;
        }

        if (waitTimer.elapsed() > timeoutMs) {
            process.kill();
            process.waitForFinished(3000);
            errorOut = QString("ZIP extraction timeout (%1ms)").arg(timeoutMs);
            return false;
        }
    }

    const QString stdErr = QString::fromUtf8(process.readAllStandardError()).trimmed();
    const QString stdOut = QString::fromUtf8(process.readAllStandardOutput()).trimmed();

    if (process.exitStatus() != QProcess::NormalExit || process.exitCode() != 0) {
        errorOut = QString("ZIP extraction error: process exit code=%1").arg(process.exitCode());
        if (!stdErr.isEmpty()) {
            errorOut += " stderr: " + stdErr;
        }
        if (!stdOut.isEmpty()) {
            errorOut += " stdout: " + stdOut;
        }
        return false;
    }

    return true;
}

static bool looksLikeAndroidTranscript(const QString& txtPath)
{
    QFile file(txtPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::Utf8);

    static const QRegularExpression reAndroidHeader(
        R"(^\s*\d{1,2}[\./]\d{1,2}[\./]\d{2,4},\s*\d{1,2}:\d{2}(?::\d{2})?(?:\s*[APap]\.?[Mm]\.?)?\s-\s.+$)");

    int inspectedLines = 0;
    int matchedLines = 0;

    while (!stream.atEnd() && inspectedLines < 120) {
        const QString line = stream.readLine().trimmed();
        if (line.isEmpty()) {
            continue;
        }

        inspectedLines++;
        if (reAndroidHeader.match(line).hasMatch()) {
            matchedLines++;
            if (matchedLines >= 3) {
                return true;
            }
        }
    }

    return (inspectedLines >= 5 && matchedLines >= 2);
}

ZipExtractor::ExtractResult ZipExtractor::extract(
    const QString& zipPath,
    const QString& destDir,
    const std::function<void(const ExtractProgress&)>& progressCallback)
{
    ExtractResult result;

    const QString uid    = QUuid::createUuid().toString(QUuid::WithoutBraces).left(8);
    const QString outDir = destDir + "/" + uid;
    QDir().mkpath(outDir);
    result.extractDir = outDir;

    Logger::info("Opening ZIP: " + zipPath);
    Logger::info("Extraction directory: " + outDir);

    QElapsedTimer extractionTimer;
    extractionTimer.start();
    QElapsedTimer callbackThrottle;
    callbackThrottle.start();

    auto emitProgress = [&](double progress,
                            const QString& phase,
                            int processedItems,
                            int totalItems,
                            qint64 processedBytes,
                            qint64 totalBytes,
                            const QString& currentFile,
                            bool force = false) {
        if (!progressCallback) {
            return;
        }

        if (!force && callbackThrottle.elapsed() < 70) {
            return;
        }
        callbackThrottle.restart();

        ExtractProgress payload;
        payload.progress = qBound(0.0, progress, 1.0);
        payload.phase = phase;
        payload.processedItems = processedItems;
        payload.totalItems = totalItems;
        payload.processedBytes = processedBytes;
        payload.totalBytes = totalBytes;
        payload.currentFile = currentFile;
        progressCallback(payload);
    };

    emitProgress(0.0, "extract", 0, 0, 0, 0, QString(), true);

    auto runExpandArchiveFallback = [&](QString& errorOut) {
        constexpr qint64 kExtractTimeoutMs = 10 * 60 * 1000;
        emitProgress(0.08,
                     "extract",
                     0,
                     0,
                     0,
                     0,
                     QString(),
                     true);

        const bool ok = runExpandArchive(zipPath, outDir, kExtractTimeoutMs, errorOut);
        if (ok) {
            emitProgress(0.96,
                         "extract",
                         1,
                         1,
                         0,
                         0,
                         QString(),
                         true);
        }
        return ok;
    };

    QString extractionError;
    if (!runExpandArchiveFallback(extractionError)) {
        result.errorMsg = extractionError.isEmpty()
                ? "ZIP could not be extracted."
                : extractionError;
        Logger::error(result.errorMsg);
        return result;
    }

    // Scan extracted files: _chat.txt is iOS transcript; Android transcript is
    // a non-_chat .txt that matches Android chat line pattern.
    // Any other .txt is treated as a normal attachment document.
    QDirIterator it(outDir, QDir::Files, QDirIterator::Subdirectories);
    int fileCount = 0;

    struct TxtCandidate {
        QString absolutePath;
        qint64 size = 0;
        bool exactUnderscoreChat = false;
    };

    QList<TxtCandidate> iosCandidates;
    QList<TxtCandidate> androidCandidates;

    int expectedScanFiles = 0;
    QDirIterator countIt(outDir, QDir::Files, QDirIterator::Subdirectories);
    while (countIt.hasNext()) {
        countIt.next();
        expectedScanFiles++;
    }
    expectedScanFiles = qMax(1, expectedScanFiles);

    while (it.hasNext()) {
        it.next();
        const QFileInfo fi = it.fileInfo();
        if (!fi.isFile()) {
            continue;
        }

        fileCount++;
        if (fileCount <= 20 || fileCount % 500 == 0) {
            Logger::info(QString("ZIP file[%1]: %2")
                         .arg(fileCount)
                         .arg(fi.fileName()));
        }

        const QString fnLower = fi.fileName().toLower();
        if (fnLower.endsWith(".txt")) {
            TxtCandidate candidate;
            candidate.absolutePath = fi.absoluteFilePath();
            candidate.size = fi.size();
            candidate.exactUnderscoreChat = (fnLower == "_chat.txt");

            if (candidate.exactUnderscoreChat) {
                iosCandidates.append(candidate);
            } else if (looksLikeAndroidTranscript(candidate.absolutePath)) {
                androidCandidates.append(candidate);
            } else {
                result.mediaFiles.append(fi.absoluteFilePath());
                result.mediaBytes += fi.size();
                result.mediaCount++;
            }
        } else {
            result.mediaFiles.append(fi.absoluteFilePath());
            result.mediaBytes += fi.size();
            result.mediaCount++;
        }

        const double scanRatio = qMin(1.0,
                                      static_cast<double>(fileCount) /
                                      static_cast<double>(expectedScanFiles));
        emitProgress(0.96 + (scanRatio * 0.04),
                     "scan",
                     fileCount,
                     expectedScanFiles,
                     0,
                     1,
                     fi.fileName());
    }

    auto pickLargest = [](const QList<TxtCandidate>& list) -> TxtCandidate {
        TxtCandidate chosen;
        if (list.isEmpty()) {
            return chosen;
        }

        chosen = list.first();
        for (const TxtCandidate& c : list) {
            if (c.size > chosen.size) {
                chosen = c;
            }
        }
        return chosen;
    };

    if (!iosCandidates.isEmpty()) {
        const TxtCandidate chosen = pickLargest(iosCandidates);
        result.chatTxtPath = chosen.absolutePath;
        result.chatTxtBytes = chosen.size;
        result.chatFormat = ChatFormat::Ios;
        Logger::info(QString("Chat file selected (iOS): %1 (ios candidates: %2)")
                     .arg(result.chatTxtPath)
                     .arg(iosCandidates.size()));
    } else if (!androidCandidates.isEmpty()) {
        const TxtCandidate chosen = pickLargest(androidCandidates);
        result.chatTxtPath = chosen.absolutePath;
        result.chatTxtBytes = chosen.size;
        result.chatFormat = ChatFormat::Android;
        Logger::info(QString("Chat file selected (Android): %1 (android txt candidates: %2)")
                     .arg(result.chatTxtPath)
                     .arg(androidCandidates.size()));
    }

    Logger::info("ZIP file count: " + QString::number(fileCount));

    if (result.chatTxtPath.isEmpty()) {
        result.errorMsg = "No chat transcript TXT found in ZIP. "
                          "Expected _chat.txt for iOS or Android-style chat TXT.";
        Logger::error(result.errorMsg);
        return result;
    }

    result.success = true;
    emitProgress(1.0,
                 "scan",
                 expectedScanFiles,
                 expectedScanFiles,
                 0,
                 1,
                 QString(),
                 true);
    Logger::info("ZIP extracted successfully. Media: " +
                 QString::number(result.mediaFiles.size()) + " files");
    Logger::info(QString("ZIP extraction completed: %1ms").arg(extractionTimer.elapsed()).toStdString());
    return result;
}

bool ZipExtractor::cleanup(const QString& dir)
{
    if (dir.isEmpty()) return false;
    return QDir(dir).removeRecursively();
}
