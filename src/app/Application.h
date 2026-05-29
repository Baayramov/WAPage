#pragma once
#ifdef Q_OS_WIN
#include <QGuiApplication>
#define Q_APP_BASE QGuiApplication
#else
#include <QApplication>
#define Q_APP_BASE QApplication
#endif
#include <QString>
#include <QMap>

class Application : public Q_APP_BASE
{
    Q_OBJECT
public:
    Application(int& argc, char** argv);

    QString dataDir()  const { return m_dataDir; }
    QString logLevel() const { return m_logLevel; }

private:
    void loadEnv(const QString& envPath);
    void setupDataDir();

    QString m_dataDir;
    QString m_logLevel;
    QMap<QString, QString> m_env;
};
