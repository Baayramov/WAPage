#include "Application.h"
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>

Application::Application(int& argc, char** argv)
    : QGuiApplication(argc, argv)
{
    setApplicationName("WAPage");
    setOrganizationName("WAPage");
    setApplicationVersion("1.2.0");

    // Read the .env file from the folder next to the exe
    const QString exeDir = QCoreApplication::applicationDirPath();
    loadEnv(exeDir + "/.env");

    setupDataDir();
}

void Application::loadEnv(const QString& envPath)
{
    QFile f(envPath);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream stream(&f);
    while (!stream.atEnd()) {
        const QString line = stream.readLine().trimmed();
        if (line.startsWith('#') || line.isEmpty()) continue;
        const int eq = line.indexOf('=');
        if (eq < 0) continue;
        const QString key = line.left(eq).trimmed();
        const QString val = line.mid(eq + 1).trimmed();
        m_env[key] = val;
    }
}

void Application::setupDataDir()
{
    m_logLevel = m_env.value("LOG_LEVEL", "info");

    const QString envDataDir = m_env.value("APP_DATA_DIR");
    if (!envDataDir.isEmpty()) {
        m_dataDir = envDataDir;
    } else {
        // Default: %APPDATA%/WAPage
        m_dataDir = QStandardPaths::writableLocation(
                        QStandardPaths::AppDataLocation);
    }
    QDir().mkpath(m_dataDir);
}
