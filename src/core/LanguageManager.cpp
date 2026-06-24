#include "LanguageManager.h"
#include <QLocale>
#include <QDateTime>
#include <QRegularExpression>
#include <QSet>

LanguageManager::LanguageManager(QObject* parent)
    : QObject(parent)
{
    // Initialize language names (lightweight, always loaded)
    m_langNames = {
        {"Azerbaijani", "Azərbaycan"},
        {"Afrikaans", "Afrikaans"},
        {"Albanian", "Shqip"},
        {"Arabic", "العربية"},
        {"Bengali", "বাংলা"},
        {"Bulgarian", "Български"},
        {"Catalan", "Català"},
        {"Chinese", "中文"},
        {"ChineseHongKong", "中文 (香港)"},
        {"ChineseTaiwan", "中文 (台灣)"},
        {"Croatian", "Hrvatski"},
        {"Czech", "Čeština"},
        {"Danish", "Dansk"},
        {"Dutch", "Nederlands"},
        {"English", "English"},
        {"Estonian", "Eesti"},
        {"Filipino", "Filipino"},
        {"Finnish", "Suomi"},
        {"French", "Français"},
        {"German", "Deutsch"},
        {"Greek", "Ελληνικά"},
        {"Gujarati", "ગુજરાતી"},
        {"Hebrew", "עברית"},
        {"Hindi", "हिन्दी"},
        {"Hungarian", "Magyar"},
        {"Indonesian", "Bahasa Indonesia"},
        {"Irish", "Gaeilge"},
        {"Italian", "Italiano"},
        {"Japanese", "日本語"},
        {"Kannada", "ಕನ್ನಡ"},
        {"Kazakh", "Қазақша"},
        {"Korean", "한국어"},
        {"Lao", "ລາວ"},
        {"Latvian", "Latviešu"},
        {"Lithuanian", "Lietuvių"},
        {"Macedonian", "Македонски"},
        {"Malay", "Bahasa Melayu"},
        {"Malayalam", "മലയാളം"},
        {"Marathi", "मराठी"},
        {"Mongolian", "Монгол"},
        {"Norwegian", "Norsk"},
        {"Persian", "فارسی"},
        {"Polish", "Polski"},
        {"Portuguese", "Português"},
        {"PortugueseBrazil", "Português (Brasil)"},
        {"Punjabi", "ਪੰਜਾਬੀ"},
        {"Romanian", "Română"},
        {"Russian", "Русский"},
        {"Serbian", "Српски"},
        {"Slovak", "Slovenčina"},
        {"Slovenian", "Slovenščina"},
        {"Spanish", "Español"},
        {"Swahili", "Kiswahili"},
        {"Swedish", "Svenska"},
        {"Tamil", "தமிழ்"},
        {"Telugu", "తెలుగు"},
        {"Thai", "ไทย"},
        {"Turkish", "Türkçe"},
        {"Ukrainian", "Українська"},
        {"UrduPakistan", "اردو"},
        {"Uzbek", "Oʻzbekcha"},
        {"Vietnamese", "Tiếng Việt"}
    };
    
    // DON'T load any translations here - they will be loaded on-demand
    // when setCurrentLanguage() is called by MainWindow
}

void LanguageManager::ensureLanguageLoaded(const QString& lang)
{
    // If this specific language is already loaded, nothing to do
    if (m_translations.contains(lang) && m_sysTranslations.contains(lang)) {
        return;
    }
    
    // Load ALL languages at once (because initTranslations() loads all)
    // This happens only once, when first language is requested
    if (!m_allLanguagesLoaded) {
        initTranslations();
        initSystemTranslations();
        m_allLanguagesLoaded = true;
    }
}

void LanguageManager::setCurrentLanguage(const QString& lang)
{
    if (m_currentLang != lang) {
        // Ensure this language's translations are loaded
        ensureLanguageLoaded(lang);
        
        if (m_translations.contains(lang)) {
            m_currentLang = lang;
            emit languageChanged();
        }
    }
}

QString LanguageManager::tr(const QString& key) const
{
    // Lazy load translations if not yet loaded
    if (!m_allLanguagesLoaded) {
        const_cast<LanguageManager*>(this)->ensureLanguageLoaded(m_currentLang);
    }
    
    if (!m_translations.contains(m_currentLang)) return key;
    return m_translations[m_currentLang].value(key, key);
}

QString LanguageManager::getLanguageName(const QString& code) const
{
    return m_langNames.value(code, code);
}

QVariantMap LanguageManager::currentTranslations() const
{
    // Lazy load translations if not yet loaded
    if (!m_allLanguagesLoaded) {
        const_cast<LanguageManager*>(this)->ensureLanguageLoaded(m_currentLang);
    }
    
    QVariantMap map;
    if (m_translations.contains(m_currentLang)) {
        const auto& langMap = m_translations[m_currentLang];
        for (auto it = langMap.constBegin(); it != langMap.constEnd(); ++it) {
            map.insert(it.key(), it.value());
        }
    }
    return map;
}

QString LanguageManager::formatDate(const QDateTime& dt) const
{
    if (!dt.isValid()) return "";

    const QString format = "d MMMM yyyy";
    
    static const QMap<QString, QLocale> localeMap = {
        {"Azerbaijani", QLocale(QLocale::Azerbaijani)},
        {"Afrikaans", QLocale(QLocale::Afrikaans)},
        {"Albanian", QLocale(QLocale::Albanian)},
        {"Arabic", QLocale(QLocale::Arabic)},
        {"Bengali", QLocale(QLocale::Bengali)},
        {"Bulgarian", QLocale(QLocale::Bulgarian)},
        {"Catalan", QLocale(QLocale::Catalan)},
        {"Chinese", QLocale(QLocale::Chinese)},
        {"ChineseHongKong", QLocale(QLocale::Chinese, QLocale::HongKong)},
        {"ChineseTaiwan", QLocale(QLocale::Chinese, QLocale::Taiwan)},
        {"Croatian", QLocale(QLocale::Croatian)},
        {"Czech", QLocale(QLocale::Czech)},
        {"Danish", QLocale(QLocale::Danish)},
        {"Dutch", QLocale(QLocale::Dutch)},
        {"English", QLocale(QLocale::English)},
        {"Estonian", QLocale(QLocale::Estonian)},
        {"Filipino", QLocale(QLocale::Filipino)},
        {"Finnish", QLocale(QLocale::Finnish)},
        {"French", QLocale(QLocale::French)},
        {"German", QLocale(QLocale::German)},
        {"Greek", QLocale(QLocale::Greek)},
        {"Gujarati", QLocale(QLocale::Gujarati)},
        {"Hebrew", QLocale(QLocale::Hebrew)},
        {"Hindi", QLocale(QLocale::Hindi)},
        {"Hungarian", QLocale(QLocale::Hungarian)},
        {"Indonesian", QLocale(QLocale::Indonesian)},
        {"Irish", QLocale(QLocale::Irish)},
        {"Italian", QLocale(QLocale::Italian)},
        {"Japanese", QLocale(QLocale::Japanese)},
        {"Kannada", QLocale(QLocale::Kannada)},
        {"Kazakh", QLocale(QLocale::Kazakh)},
        {"Korean", QLocale(QLocale::Korean)},
        {"Lao", QLocale(QLocale::Lao)},
        {"Latvian", QLocale(QLocale::Latvian)},
        {"Lithuanian", QLocale(QLocale::Lithuanian)},
        {"Macedonian", QLocale(QLocale::Macedonian)},
        {"Malay", QLocale(QLocale::Malay)},
        {"Malayalam", QLocale(QLocale::Malayalam)},
        {"Marathi", QLocale(QLocale::Marathi)},
        {"Mongolian", QLocale(QLocale::Mongolian)},
        {"Norwegian", QLocale(QLocale::NorwegianBokmal)},
        {"Persian", QLocale(QLocale::Persian)},
        {"Polish", QLocale(QLocale::Polish)},
        {"Portuguese", QLocale(QLocale::Portuguese)},
        {"PortugueseBrazil", QLocale(QLocale::Portuguese, QLocale::Brazil)},
        {"Punjabi", QLocale(QLocale::Punjabi)},
        {"Romanian", QLocale(QLocale::Romanian)},
        {"Russian", QLocale(QLocale::Russian)},
        {"Serbian", QLocale(QLocale::Serbian)},
        {"Slovak", QLocale(QLocale::Slovak)},
        {"Slovenian", QLocale(QLocale::Slovenian)},
        {"Spanish", QLocale(QLocale::Spanish)},
        {"Swahili", QLocale(QLocale::Swahili)},
        {"Swedish", QLocale(QLocale::Swedish)},
        {"Tamil", QLocale(QLocale::Tamil)},
        {"Telugu", QLocale(QLocale::Telugu)},
        {"Thai", QLocale(QLocale::Thai)},
        {"Turkish", QLocale(QLocale::Turkish)},
        {"Ukrainian", QLocale(QLocale::Ukrainian)},
        {"UrduPakistan", QLocale(QLocale::Urdu, QLocale::Pakistan)},
        {"Uzbek", QLocale(QLocale::Uzbek)},
        {"Vietnamese", QLocale(QLocale::Vietnamese)}
    };

    const QLocale locale = localeMap.value(m_currentLang, QLocale::system());
    QString formatted = locale.toString(dt.date(), format);

    // Capitalize the first letter of the month name (e.g.: "1 april 2026" -> "1 April 2026").
    const int firstSpace = formatted.indexOf(' ');
    const int lastSpace  = formatted.lastIndexOf(' ');
    if (firstSpace > 0 && lastSpace > firstSpace + 1) {
        QString month = formatted.mid(firstSpace + 1, lastSpace - firstSpace - 1);
        if (!month.isEmpty()) {
            month = locale.toUpper(month.left(1)) + month.mid(1);
            formatted = formatted.left(firstSpace + 1) + month + formatted.mid(lastSpace);
        }
    }

    return formatted;
}

QString LanguageManager::translateSystemMessage(const QString& token) const
{
    // Lazy load translations if not yet loaded
    if (!m_allLanguagesLoaded) {
        const_cast<LanguageManager*>(this)->ensureLanguageLoaded(m_currentLang);
    }
    
    if (!token.startsWith(QStringLiteral("__sys:")))
        return token;   // Not a normalised system token — return as-is

    // Split into parts using a limit so that a group name or other param
    // containing ":" is preserved intact in the last slot.
    // Format: __sys:key:p0[:p1[:p2]]
    // We never need more than 4 tokens (key + 3 params), so cap at 4.
    const QString body = token.mid(6); // skip "__sys:"
    const int keyEnd = body.indexOf(QLatin1Char(':'));
    const QString key = (keyEnd < 0) ? body : body.left(keyEnd);
    if (key.isEmpty()) return token;

    // Determine how many params this key uses, then split the remainder accordingly.
    // Keys with 3 params: changed_name_from_to (person, old_name, new_name)
    // Keys with 2 params: most others (person, name/timer)
    // Keys with 1 param:  left, you_now_admin, no_longer_admin_you, etc.
    // Keys with 0 params:  e2e_note, anyone_invite_link
    static const QSet<QString> keys3 = {
        QStringLiteral("changed_name_from_to")
    };
    static const QSet<QString> keys1 = {
        QStringLiteral("you_now_admin"), QStringLiteral("no_longer_admin_you"),
        QStringLiteral("e2e_note"), QStringLiteral("anyone_invite_link"),
        QStringLiteral("left"), QStringLiteral("was_added"),
        QStringLiteral("now_admin"), QStringLiteral("no_longer_admin"),
        QStringLiteral("joined_link"), QStringLiteral("changed_icon"),
        QStringLiteral("changed_desc"), QStringLiteral("reset_link"),
        QStringLiteral("disappear_off"), QStringLiteral("disappear_off2"),
        QStringLiteral("phone_number_changed"), QStringLiteral("pinned_message"),
        QStringLiteral("admin_approval_on"), QStringLiteral("admin_approval_off"),
        QStringLiteral("settings_only_admins_edit"), QStringLiteral("settings_all_edit"),
        QStringLiteral("settings_only_admins_send"), QStringLiteral("settings_all_send"),
        QStringLiteral("settings_only_admins_add"), QStringLiteral("settings_all_add"),
        QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("settings_all_invite_link"),
    };

    QString p0, p1, p2;
    if (keyEnd >= 0) {
        const QString rest = body.mid(keyEnd + 1); // everything after key:
        if (keys3.contains(key)) {
            // 3 params: split into at most 3 pieces; p2 gets the rest (may contain colons)
            const int c1 = rest.indexOf(QLatin1Char(':'));
            if (c1 >= 0) {
                p0 = rest.left(c1);
                const QString rest2 = rest.mid(c1 + 1);
                const int c2 = rest2.indexOf(QLatin1Char(':'));
                if (c2 >= 0) {
                    p1 = rest2.left(c2);
                    p2 = rest2.mid(c2 + 1); // rest — may contain colons
                } else {
                    p1 = rest2;
                }
            } else {
                p0 = rest;
            }
        } else if (keys1.contains(key)) {
            // 1 param: everything is p0 (may contain colons — e.g. a person named "A: B")
            p0 = rest;
        } else {
            // 2 params: p0 is up to first colon; p1 is the rest (may contain colons)
            const int c1 = rest.indexOf(QLatin1Char(':'));
            if (c1 >= 0) {
                p0 = rest.left(c1);
                p1 = rest.mid(c1 + 1); // rest — may contain colons (e.g. "8:00 AM Group")
            } else {
                p0 = rest;
            }
        }
    }

    const QMap<QString, QString>& T =
        m_sysTranslations.contains(m_currentLang)
        ? m_sysTranslations[m_currentLang]
        : m_sysTranslations["English"];

    // ── 2nd-person handling ──────────────────────────────────────────────────
    // WhatsApp exports literally write "You" / "you" when the actor or target
    // of a system event is the device owner, regardless of locale. To produce
    // a grammatically natural sentence in each language (e.g. Azerbaijani
    // "Sən bu qrupu yaratdın" instead of "You bu qrupu yaratdı"), we redirect
    // to a "_you" variant of the template when the actor (p0) is "You", or to
    // a "_target_you" variant when the action target (p1) is "you" for keys
    // that have an addressed counterpart (added / removed). When no variant
    // exists for the active language, we fall back to the original 3rd-person
    // template so the message is still understandable.
    QString lookupKey = key;
    const bool actorIsYou =
        !p0.isEmpty() && p0.compare(QLatin1String("You"), Qt::CaseInsensitive) == 0;
    const bool targetIsYou =
        !p1.isEmpty() && p1.compare(QLatin1String("you"), Qt::CaseInsensitive) == 0;
    if (actorIsYou) {
        const QString youKey = key + QLatin1String("_you");
        if (T.contains(youKey)) lookupKey = youKey;
    } else if (targetIsYou &&
               (key == QLatin1String("added") || key == QLatin1String("removed"))) {
        const QString tyKey = key + QLatin1String("_target_you");
        if (T.contains(tyKey)) lookupKey = tyKey;
    }

    if (!T.contains(lookupKey)) return token;   // Unknown key — return raw token

    QString tpl = T[lookupKey];

    // Replace placeholders in order
    tpl.replace(QStringLiteral("{0}"), p0);
    tpl.replace(QStringLiteral("{1}"), p1);
    tpl.replace(QStringLiteral("{2}"), p2);

    // ── Voice / video call duration unit translation ────────────────────────
    // Parser produces tokens like "__sys:voice_call:You:41 sec" where the
    // duration string ("41 sec" / "5 min" / "1 hr") is *always* English
    // because it comes from the WhatsApp export verbatim. WhatsApp only ever
    // emits a single unit per message (never combined like "1 hr 5 min"),
    // but the regex below still handles per-unit replacement so a combined
    // future format would also work without code changes.
    //
    // The unit substitution operates on the already-rendered template (after
    // {0}/{1} replacement) because the duration arrived via p1 → {1}, and we
    // want to leave any other text untouched. We only run the substitution
    // for call keys to avoid accidentally rewriting a person's name or a
    // group title that happens to contain "min"/"sec".
    if (key.startsWith(QLatin1String("voice_call")) ||
        key.startsWith(QLatin1String("video_call"))) {
        // Match a digit followed by a unit so we do not accidentally rewrite
        // standalone words inside group/contact names.
        // Patterns recognised (case-insensitive, with or without trailing 's'):
        //   sec, secs, second, seconds   →  unit_sec
        //   min, mins, minute, minutes   →  unit_min
        //   hr,  hrs,  hour,   hours     →  unit_hr
        auto applyUnit = [&tpl, &T](const QString& pattern, const QString& unitKey) {
            if (!T.contains(unitKey)) return;
            const QRegularExpression re(pattern, QRegularExpression::CaseInsensitiveOption);
            // Qt's QString::replace(QRegularExpression, QString) honours
            // numeric backreferences (\1..\9) in the replacement string, so
            // "\1 <unit>" preserves the original number.
            tpl.replace(re, QStringLiteral("\\1 ") + T.value(unitKey));
        };
        applyUnit(QStringLiteral("(\\d+)\\s*(?:seconds?|secs?)\\b"), QStringLiteral("unit_sec"));
        applyUnit(QStringLiteral("(\\d+)\\s*(?:minutes?|mins?)\\b"),  QStringLiteral("unit_min"));
        applyUnit(QStringLiteral("(\\d+)\\s*(?:hours?|hrs?)\\b"),     QStringLiteral("unit_hr"));
    }

    // Translate the timer value tokens that appear in disappearing-message entries
    // e.g.  "24 Hours" / "7 Days" / "90 Days"
    if (tpl.contains(QStringLiteral("{timer}"))) {
        // p1 holds the timer value for disappear_on / update_timer keys
        const QString timerVal = p1;
        // Case-insensitive comparison — export files may use lowercase (e.g. "7 days")
        const QString timerLower = timerVal.toLower();
        QString timerKey;
        if (timerLower == QLatin1String("24 hours") || timerLower == QLatin1String("24 hour"))
            timerKey = QStringLiteral("timer_24h");
        else if (timerLower == QLatin1String("7 days") || timerLower == QLatin1String("7 day"))
            timerKey = QStringLiteral("timer_7d");
        else if (timerLower == QLatin1String("90 days") || timerLower == QLatin1String("90 day"))
            timerKey = QStringLiteral("timer_90d");
        tpl.replace(QStringLiteral("{timer}"),
                    (!timerKey.isEmpty() && T.contains(timerKey)) ? T[timerKey] : timerVal);
    }

    return tpl.trimmed();
}

// ─────────────────────────────────────────────────────────────────────────────
// System-message translation tables
//
// Key naming mirrors the __sys: tokens that ChatParser emits.
// Placeholders: {0} = first person/name,  {1} = second name / group name / timer,
//               {2} = third param (rare).
// ─────────────────────────────────────────────────────────────────────────────
