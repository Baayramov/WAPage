#pragma once
#include <QObject>
#include <QString>
#include <QMap>
#include <QVariantMap>
#include <QDateTime>

class LanguageManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentLanguage READ currentLanguage WRITE setCurrentLanguage NOTIFY languageChanged)
    Q_PROPERTY(QVariantMap currentTranslations READ currentTranslations NOTIFY languageChanged)

public:
    enum Language {
        Azerbaijani,
        Turkish,
        English,
        Spanish,
        Portuguese,
        Russian,
        Italian,
        Arabic,
        French,
        German,
        Chinese,
        Hindi,
        Japanese,
        Korean,
        Mongolian,
        Polish,
        Ukrainian,
        Uzbek
    };
    Q_ENUM(Language)

    explicit LanguageManager(QObject* parent = nullptr);

    QString currentLanguage() const { return m_currentLang; }
    void setCurrentLanguage(const QString& lang);

    QVariantMap currentTranslations() const;

    Q_INVOKABLE QString tr(const QString& key) const;
    Q_INVOKABLE QString formatDate(const QDateTime& dt) const;
    Q_INVOKABLE QString getLanguageName(const QString& code) const;
    // Translate a normalised system-message token such as
    //   "__sys:added:Alice:Bob"  →  "Alice added Bob"
    // Returns the original string if it is not a recognised token.
    Q_INVOKABLE QString translateSystemMessage(const QString& token) const;

signals:
    void languageChanged();

private:
    void initTranslations();
    void initSystemTranslations();
    // Populates 2nd-person ("_you" / "_target_you") variants of system-message
    // templates for every supported language. Split out from
    // initSystemTranslations() because the table is large (~520 entries).
    void initSystemTranslationsYou();
    
    QString m_currentLang = "Azerbaijani";
    QMap<QString, QMap<QString, QString>> m_translations;
    QMap<QString, QMap<QString, QString>> m_sysTranslations; // system message templates per language
    QMap<QString, QString> m_langNames;
};
