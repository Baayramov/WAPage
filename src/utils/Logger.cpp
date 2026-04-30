#include "Logger.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
#include <QMutex>
#include <QMutexLocker>
#include <QtGlobal>
#include <cstdio>

namespace Logger {

static QFile       s_file;
static QTextStream s_stream;
static QMutex      s_mutex;
static int         s_level = 1; // 0=trace,1=debug,2=info,3=warn,4=error,5=critical

static void writeLog(const QString& level, const QString& msg)
{
    QMutexLocker lock(&s_mutex);
    const QString line = QDateTime::currentDateTime()
                             .toString("[yyyy-MM-dd hh:mm:ss.zzz]")
                         + " [" + level + "] " + msg;
    if (s_file.isOpen()) {
        s_stream << line << "\n";
        s_stream.flush();
    }
    // Use stderr — Qt Creator always shows this
    fprintf(stderr, "%s\n", qPrintable(line));
    fflush(stderr);
}

void init(const QString& logDir, const QString& level)
{
    QDir().mkpath(logDir);

    if (s_file.isOpen()) s_file.close();
    s_file.setFileName(logDir + "/app.log");

    // Start fresh on every launch: clear old app.log content.
    s_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    s_stream.setDevice(&s_file);
    s_stream.setEncoding(QStringConverter::Utf8);

    if      (level == "trace")    s_level = 0;
    else if (level == "debug")    s_level = 1;
    else if (level == "warn")     s_level = 3;
    else if (level == "error")    s_level = 4;
    else if (level == "critical") s_level = 5;
    else                          s_level = 2; // info

    qInstallMessageHandler(qtMessageHandler);
    info("=== WAPage started === " +
         QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void shutdown()
{
    info("=== WAPage stopped ===");
    QMutexLocker lock(&s_mutex);
    if (s_file.isOpen()) s_file.close();
}

void trace(const QString& msg)    { if (s_level <= 0) writeLog("TRACE", msg); }
void debug(const QString& msg)    { if (s_level <= 1) writeLog("DEBUG", msg); }
void info(const QString& msg)     { if (s_level <= 2) writeLog("INFO ", msg); }
void warn(const QString& msg)     { if (s_level <= 3) writeLog("WARN ", msg); }
void error(const QString& msg)    { if (s_level <= 4) writeLog("ERROR", msg); }
void critical(const QString& msg) { writeLog("CRIT ", msg); }

void qtMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString& msg)
{
    Q_UNUSED(ctx)

    switch (type) {
    case QtDebugMsg:    debug("[Qt] " + msg);    break;
    case QtInfoMsg:     info("[Qt] " + msg);     break;
    case QtWarningMsg:  warn("[Qt] " + msg);     break;
    case QtCriticalMsg: error("[Qt] " + msg);    break;
    case QtFatalMsg:
        critical("[Qt FATAL] " + msg);
        shutdown();
        std::abort();
    }
}

} // namespace Logger
