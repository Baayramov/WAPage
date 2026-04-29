#pragma once
#include <QString>
#include <QtGlobal>
#include <string>

// Writes all logs to app.log file — only uses Qt, no 3rd parties
namespace Logger {

void init(const QString& logDir, const QString& level = "info");
void shutdown();

void trace(const QString& msg);
void debug(const QString& msg);
void info(const QString& msg);
void warn(const QString& msg);
void error(const QString& msg);
void critical(const QString& msg);

// const char* overloads - resolves string literal ambiguity
inline void init(const char* d, const char* l = "info") { init(QString(d), QString(l)); }
inline void trace(const char* m)    { trace(QString(m)); }
inline void debug(const char* m)    { debug(QString(m)); }
inline void info(const char* m)     { info(QString(m)); }
inline void warn(const char* m)     { warn(QString(m)); }
inline void error(const char* m)    { error(QString(m)); }
inline void critical(const char* m) { critical(QString(m)); }

// std::string overloads
inline void init(const std::string& d, const std::string& l = "info") { init(QString::fromStdString(d), QString::fromStdString(l)); }
inline void trace(const std::string& m)    { trace(QString::fromStdString(m)); }
inline void debug(const std::string& m)    { debug(QString::fromStdString(m)); }
inline void info(const std::string& m)     { info(QString::fromStdString(m)); }
inline void warn(const std::string& m)     { warn(QString::fromStdString(m)); }
inline void error(const std::string& m)    { error(QString::fromStdString(m)); }
inline void critical(const std::string& m) { critical(QString::fromStdString(m)); }

// Qt message handler — with qInstallMessageHandler
void qtMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString& msg);

} // namespace Logger
