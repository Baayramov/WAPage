#pragma once
#include <functional>
#include <QString>
#include <QStringList>

// ZIP is extracted with system PowerShell Expand-Archive on Windows.
class ZipExtractor
{
public:
    enum class ChatFormat {
        Unknown,
        Ios,
        Android
    };

    struct ExtractProgress {
        double  progress = 0.0; // 0..1
        QString phase;          // extract / scan
        int     processedItems = 0;
        int     totalItems = 0;
        qint64  processedBytes = 0;
        qint64  totalBytes = 0;
        QString currentFile;
    };

    struct ExtractResult {
        bool        success     = false;
        QString     chatTxtPath;
        ChatFormat  chatFormat  = ChatFormat::Unknown;
        QStringList mediaFiles;
        QString     extractDir;
        QString     errorMsg;
        qint64      chatTxtBytes = 0;
        qint64      mediaBytes = 0;
        int         mediaCount = 0;
    };

    static ExtractResult extract(const QString& zipPath,
                                 const QString& destDir,
                                 const std::function<void(const ExtractProgress&)>& progressCallback = {});
    static bool cleanup(const QString& dir);
};
