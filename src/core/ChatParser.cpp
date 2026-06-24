#include "ChatParser.h"
#include "utils/Logger.h"

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QFileInfo>
#include <QMap>
#include <QSet>
#include <QElapsedTimer>

// Media attachment regexes (only used on short strings)
static const QRegularExpression RE_ATTACHED_ANGLE(
    R"(<\s*attached\s*:\s*(.+?)\s*>)",
    QRegularExpression::CaseInsensitiveOption
);
static const QRegularExpression RE_ATTACHED_PAREN(
    R"((.+?)\s+\(file attached\))",
    QRegularExpression::CaseInsensitiveOption
);
// Location URL regex — Google Maps, WAPage location links
static const QRegularExpression RE_LOCATION_URL(
    R"(https?://(?:maps\.google\.com|goo\.gl/maps|maps\.app\.goo\.gl|www\.google\.com/maps)[^\s]*)",
    QRegularExpression::CaseInsensitiveOption
);
// iOS WAPage location format: "location: lat,lng"
static const QRegularExpression RE_LOCATION_COORDS(
    R"(location:\s*(-?\d+\.\d+),\s*(-?\d+\.\d+))",
    QRegularExpression::CaseInsensitiveOption
);
static const QRegularExpression RE_HAS_LETTER(R"(\p{L})");

// normalizeSystemMessage
//
// Converts a raw English system-message string (as written in _chat.txt) into
// a compact token understood by LanguageManager::translateSystemMessage().
//
// Format:  __sys:<key>:<p0>:<p1>:<p2>
// Unknown / unrecognised messages are returned unchanged so they are displayed
// as-is (plain text fallback).
// ---
static QString normalizeSystemMessage(const QString& raw)
{
    const QString s = raw.trimmed();
    if (s.isEmpty()) return s;

    // Helper: build token
    auto tok = [](const QString& key,
                  const QString& p0 = {},
                  const QString& p1 = {},
                  const QString& p2 = {}) -> QString {
        QString t = QStringLiteral("__sys:") + key;
        if (!p0.isEmpty()) t += QLatin1Char(':') + p0;
        if (!p1.isEmpty()) t += QLatin1Char(':') + p1;
        if (!p2.isEmpty()) t += QLatin1Char(':') + p2;
        return t;
    };

    // E2E note
    if (s.contains(QStringLiteral("end-to-end encrypted"), Qt::CaseInsensitive) ||
        s.contains(QStringLiteral("end to end encrypted"), Qt::CaseInsensitive))
        return tok("e2e_note");

    // "Anyone in this group can invite new members using a group link."
    if (s.contains(QStringLiteral("Anyone in this group can invite"), Qt::CaseInsensitive))
        return tok("anyone_invite_link");

    // person created group "name" (with or without surrounding quotes)
    if (s.contains(QStringLiteral("created group"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(
            QString("^(.+?) created group[:\\s]+(.+)$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) {
            QString name = m.captured(2).trimmed();
            if (name.endsWith(QLatin1Char('.'))) { name.chop(1); name = name.trimmed(); }
            if (name.length() >= 2) {
                const ushort f = name.front().unicode(), b = name.back().unicode();
                if ((f==0x22||f==0x201C||f==0x201E) && (b==0x22||b==0x201D||b==0x201F)) {
                    QString inner = name.mid(1, name.length()-2).trimmed();
                    if (!inner.isEmpty()) name = inner;
                }
            }
            return tok("created_group", m.captured(1).trimmed(), name);
        }
    }

    // person created this group
    {
        static const QRegularExpression re(
            QString("^(.+?) created this group\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("created_group_noname", m.captured(1).trimmed());
    }

    // person left
    {
        static const QRegularExpression re(
            QString("^(.+?) left\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("left", m.captured(1).trimmed());
    }

    // person added person2
    {
        static const QRegularExpression re(
            QString("^(.+?) added (.+)$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("added", m.captured(1).trimmed(), m.captured(2).trimmed());
    }

    // person was added  (also matches "You were added" — English uses 'were'
    // for 2nd person; the verb form is normalised away here so a single
    // "was_added" key handles both, and translateSystemMessage picks the
    // correct 2nd-person template via "was_added_you" when the actor is "You")
    {
        static const QRegularExpression re(
            QString("^(.+?) (?:was|were) added\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("was_added", m.captured(1).trimmed());
    }

    // person removed person2
    {
        static const QRegularExpression re(
            QString("^(.+?) removed (.+)$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("removed", m.captured(1).trimmed(), m.captured(2).trimmed());
    }

    // You're now an admin
    if (s.contains(QStringLiteral("You're now an admin"), Qt::CaseInsensitive) ||
        s.contains(QStringLiteral("You are now an admin"), Qt::CaseInsensitive))
        return tok("you_now_admin");

    // person now an admin / person is now an admin
    {
        static const QRegularExpression re(
            QString("^(.+?)\\s+(?:is\\s+)?now\\s+an?\\s+admin\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("now_admin", m.captured(1).trimmed());
    }

    // You're no longer an admin
    if (s.contains(QStringLiteral("no longer an admin"), Qt::CaseInsensitive) &&
        s.startsWith(QStringLiteral("You"), Qt::CaseInsensitive))
        return tok("no_longer_admin_you");

    // person is no longer an admin
    {
        static const QRegularExpression re(
            QString("^(.+?)\\s+is no longer an? admin\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("no_longer_admin", m.captured(1).trimmed());
    }

    // person joined using a group link
    {
        static const QRegularExpression re(
            QString("^(.+?) joined using a group link\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("joined_link", m.captured(1).trimmed());
    }

    // person changed this group icon (apostrophe variant handled by contains)
    if (s.contains(QStringLiteral("changed this group"), Qt::CaseInsensitive) &&
        s.contains(QStringLiteral("icon"), Qt::CaseInsensitive))
    {
        static const QRegularExpression re(
            QString("^(.+?) changed"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("changed_icon", m.captured(1).trimmed());
    }

    // Helper: strip surrounding ASCII/Unicode quotes and optional trailing dot from a name.
    // Returns the name as-is if result would be empty (safety fallback).
    auto stripGroupName = [](const QString& raw) -> QString {
        QString n = raw.trimmed();
        if (n.endsWith(QLatin1Char('.'))) { n.chop(1); n = n.trimmed(); }
        if (n.length() >= 2) {
            const ushort f = n.front().unicode(), b = n.back().unicode();
            // ASCII straight quote (0x22), Unicode left/right double quote (0x201C/0x201D)
            bool isOpenQ  = (f == 0x22 || f == 0x201C || f == 0x201E);
            bool isCloseQ = (b == 0x22 || b == 0x201D || b == 0x201F);
            if (isOpenQ && isCloseQ) {
                QString inner = n.mid(1, n.length() - 2).trimmed();
                if (!inner.isEmpty()) n = inner;
            }
        }
        return n;
    };

    // person changed the group name from "old" to "new" (quotes optional)
    if (s.contains(QStringLiteral("changed the group name from"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(
            QString("^(.+?) changed the group name from (.+?) to (.+)$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch())
            return tok("changed_name_from_to",
                       m.captured(1).trimmed(),
                       stripGroupName(m.captured(2)),
                       stripGroupName(m.captured(3)));
    }

    // person changed the group name to "name" (with or without quotes, optional trailing dot)
    if (s.contains(QStringLiteral("changed the group name to"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(
            QString("^(.+?) changed the group name to (.+)$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch())
            return tok("changed_name", m.captured(1).trimmed(), stripGroupName(m.captured(2)));
    }

    // person changed the group description
    {
        static const QRegularExpression re(
            QString("^(.+?) changed the group description\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("changed_desc", m.captured(1).trimmed());
    }

    // Admin approval on/off
    if (s.contains(QStringLiteral("turned on admin approval"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) turned on admin approval"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("admin_approval_on", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("turned off admin approval"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) turned off admin approval"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("admin_approval_off", m.captured(1).trimmed());
    }

    // Reset invite link
    if (s.contains(QStringLiteral("reset this group"), Qt::CaseInsensitive) &&
        s.contains(QStringLiteral("invite link"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) reset"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("reset_link", m.captured(1).trimmed());
    }

    // Settings changes — use contains() to avoid quote/apostrophe issues in regex
    if (s.contains(QStringLiteral("only admins can edit the group settings"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed the settings"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_only_admins_edit", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("all members can edit the group settings"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed the settings"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_all_edit", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("only admins to send messages"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed this group"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_only_admins_send", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("only admins to add others"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed this group"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_only_admins_add", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("all members to add others"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed this group"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_all_add", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("all members to send messages"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed this group"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_all_send", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("only admins to invite people"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed this group"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_only_admins_invite_link", m.captured(1).trimmed());
    }
    if (s.contains(QStringLiteral("all members to invite people"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) changed this group"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s); if (m.hasMatch()) return tok("settings_all_invite_link", m.captured(1).trimmed());
    }

    // Disappearing messages — timer value: "24 Hours" / "7 Days" / "90 Days"
    static const QRegularExpression RE_TIMER(
        QString("\\b(24 Hours?|7 Days?|90 Days?)\\b"),
        QRegularExpression::CaseInsensitiveOption);

    if (s.contains(QStringLiteral("turned on disappearing messages"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) turned on disappearing"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) {
            auto tm = RE_TIMER.match(s);
            return tok("disappear_on", m.captured(1).trimmed(), tm.hasMatch() ? tm.captured(1) : QString());
        }
    }
    if (s.contains(QStringLiteral("turned off disappearing messages"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) turned off disappearing"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) {
            bool tapToChange = s.contains(QStringLiteral("Tap to change"), Qt::CaseInsensitive);
            return tok(tapToChange ? "disappear_off" : "disappear_off2", m.captured(1).trimmed());
        }
    }
    if (s.contains(QStringLiteral("updated the message timer"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(QString("^(.+?) updated the message timer"), QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) {
            auto tm = RE_TIMER.match(s);
            bool tapToChange = s.contains(QStringLiteral("Tap to change"), Qt::CaseInsensitive);
            return tok(tapToChange ? "update_timer" : "update_timer2",
                       m.captured(1).trimmed(),
                       tm.hasMatch() ? tm.captured(1) : QString());
        }
    }

    // Voice / Video call:  "Voice call. 41 sec * 2 joined"
    // bullet character can be Unicode U+2022 or middle dot U+00B7
    if (s.contains(QStringLiteral("call."), Qt::CaseInsensitive) &&
        s.contains(QStringLiteral("joined"), Qt::CaseInsensitive))
    {
        static const QRegularExpression re(
            QString("^(Voice|Video) call\\.\\s+(.+?)\\s+[\\x{2022}\\x{00B7}\\xB7]\\s+(.+?)\\s+joined\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) {
            QString type = m.captured(1).toLower() == QLatin1String("voice") ? "voice_call" : "video_call";
            return tok(type, m.captured(3).trimmed(), m.captured(2).trimmed());
        }
    }

    // ── 1:1 voice / video call status messages ──────────────────────────────
    // These never include a bullet or a "joined" verb, so they are matched
    // separately from the group-call pattern above. Variants:
    //   "Missed Voice call. Tap to call back"   → voice_call_missed   (no params)
    //   "Missed Video call. Tap to call back"   → video_call_missed   (no params)
    //   "Voice call. Ended"                     → voice_call_ended    (no params)
    //   "Video call. Ended"                     → video_call_ended    (no params)
    //   "Voice call. No answer"                 → voice_call_no_answer(no params)
    //   "Video call. No answer"                 → video_call_no_answer(no params)
    //   "Voice call. 41 sec"                    → voice_call_duration (p0=duration)
    //   "Video call. 5 min"                     → video_call_duration (p0=duration)
    // The duration string is left in source-language (English) here; the
    // sec/min/hr unit is localised in LanguageManager::translateSystemMessage().
    if (s.contains(QStringLiteral("call"), Qt::CaseInsensitive))
    {
        // 1) Missed Voice/Video call (with or without "Tap to call back" tail)
        static const QRegularExpression reMissed(
            QString("^Missed (Voice|Video) call\\.?\\s*(?:Tap to call back\\.?)?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = reMissed.match(s);
        if (m.hasMatch()) {
            QString t = m.captured(1).toLower() == QLatin1String("voice")
                            ? "voice_call_missed" : "video_call_missed";
            return tok(t);
        }

        // 2) Voice/Video call. Ended
        static const QRegularExpression reEnded(
            QString("^(Voice|Video) call\\.?\\s*Ended\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        m = reEnded.match(s);
        if (m.hasMatch()) {
            QString t = m.captured(1).toLower() == QLatin1String("voice")
                            ? "voice_call_ended" : "video_call_ended";
            return tok(t);
        }

        // 3) Voice/Video call. No answer
        static const QRegularExpression reNoAns(
            QString("^(Voice|Video) call\\.?\\s*No answer\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        m = reNoAns.match(s);
        if (m.hasMatch()) {
            QString t = m.captured(1).toLower() == QLatin1String("voice")
                            ? "voice_call_no_answer" : "video_call_no_answer";
            return tok(t);
        }

        // 4) Voice/Video call. <duration> (only digits + unit, nothing else)
        //    The unit list mirrors the one in LanguageManager so any value the
        //    parser accepts here is also recognised by the localiser.
        static const QRegularExpression reDur(
            QString("^(Voice|Video) call\\.\\s+(\\d+\\s*(?:seconds?|secs?|minutes?|mins?|hours?|hrs?))\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        m = reDur.match(s);
        if (m.hasMatch()) {
            QString t = m.captured(1).toLower() == QLatin1String("voice")
                            ? "voice_call_duration" : "video_call_duration";
            // Duration is the only payload — store it as p0 so translation
            // template can simply use {0}.
            return tok(t, m.captured(2).trimmed());
        }
    }

    // person changed their phone number to a new number
    if (s.contains(QStringLiteral("changed their phone number"), Qt::CaseInsensitive)) {
        static const QRegularExpression re(
            QString("^(.+?) changed their phone number"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("phone_number_changed", m.captured(1).trimmed());
    }

    // person pinned a message
    {
        static const QRegularExpression re(
            QString("^(.+?) pinned a message\\.?$"),
            QRegularExpression::CaseInsensitiveOption);
        auto m = re.match(s);
        if (m.hasMatch()) return tok("pinned_message", m.captured(1).trimmed());
    }

    // Unknown — return unchanged (plain-text fallback)
    return s;
}


static QString stripControlChars(const QString& input);
static QString comparablePersonName(const QString& input);
static QString personNameSignature(const QString& input);
static bool detectDeletedMessageLine(const QString& content, bool& deletedByMe);

static bool isGroupIntroLine(const QString& content)
{
    QString normalized = stripControlChars(content).toLower();
    normalized.replace(QChar(0x2010), '-'); // hyphen
    normalized.replace(QChar(0x2011), '-'); // non-breaking hyphen
    normalized.replace(QChar(0x2012), '-');
    normalized.replace(QChar(0x2013), '-'); // en dash
    normalized.replace(QChar(0x2014), '-'); // em dash
    normalized.replace(QChar(0x2212), '-'); // minus sign
    normalized = normalized.simplified();

    const bool hasE2E =
        normalized.contains("end-to-end encrypted") ||
        normalized.contains("end to end encrypted");
    const bool hasGroupAudience =
        normalized.contains("only people in this chat") ||
        normalized.contains("in this chat can read, listen") ||
        normalized.contains("can read, listen to, or share");

    return hasE2E && hasGroupAudience;
}

static bool extractEmbeddedSenderAndText(const QString& content,
                                         QString& embeddedSender,
                                         QString& embeddedText)
{
    const QString cleanContent = stripControlChars(content).trimmed();
    const int colonPos = cleanContent.indexOf(':');
    if (colonPos <= 0 || colonPos >= cleanContent.size() - 1) {
        return false;
    }

    embeddedSender = cleanContent.left(colonPos).trimmed();
    embeddedText = cleanContent.mid(colonPos + 1).trimmed();

    if (embeddedSender.isEmpty() || embeddedText.isEmpty()) {
        return false;
    }
    if (embeddedSender.size() > 64) {
        return false;
    }
    if (embeddedSender.contains("http", Qt::CaseInsensitive)) {
        return false;
    }
    if (embeddedSender.startsWith('<') || embeddedSender.startsWith('[')) {
        return false;
    }
    return true;
}

static QString groupNameFromChatTxtPath(const QString& chatTxtPath)
{
    QString base = QFileInfo(chatTxtPath).completeBaseName().trimmed();
    if (base.endsWith("_chat", Qt::CaseInsensitive)) {
        base.chop(5);
        base = base.trimmed();
    }

    const QString waPrefix = QStringLiteral("WhatsApp Chat with ");
    if (base.startsWith(waPrefix, Qt::CaseInsensitive)) {
        base = base.mid(waPrefix.size()).trimmed();
    }

    return base;
}

// To remove Unicode control characters
static QString stripControlChars(const QString& input)
{
    QString result;
    result.reserve(input.size());
    for (const QChar& ch : input) {
        // Skip Unicode control characters.
        ushort code = ch.unicode();
        if (code == 0x200E || code == 0x200F ||  // LRM, RLM
            code == 0x200B || code == 0x200C || code == 0x200D ||  // ZWSP, ZWNJ, ZWJ
            (code >= 0x202A && code <= 0x202E) ||  // Embedding controls
            (code >= 0x2066 && code <= 0x2069) ||  // Isolate controls
            code == 0xFEFF ||  // BOM
            (code < 0x20 && code != '\n' && code != '\r' && code != '\t')) { 
            continue;
        }
        result.append(ch);
    }
    return result;
}

// Strip tilde prefix from WhatsApp contact names (~ indicates no phone number)
static QString stripTildePrefix(const QString& input)
{
    QString cleaned = input.trimmed();
    if (cleaned.startsWith('~')) {
        cleaned = cleaned.mid(1).trimmed();
    }
    return cleaned;
}

static QString comparablePersonName(const QString& input)
{
    QString normalized = stripControlChars(input);
    normalized.replace(QChar(0x00A0), QLatin1Char(' ')); // NBSP
    normalized = normalized.trimmed().toLower();
    if (normalized.startsWith('~')) {
        normalized = normalized.mid(1).trimmed();
    }
    return normalized.simplified();
}

static QString personNameSignature(const QString& input)
{
    QString normalized = comparablePersonName(input);
    if (normalized.isEmpty()) {
        return normalized;
    }

    normalized.replace(QChar(0x0259), 'e');
    normalized.replace(QChar(0x018F), 'e');
    normalized.replace(QChar(0x00FC), 'u');
    normalized.replace(QChar(0x00DC), 'u');
    normalized.replace(QChar(0x00F6), 'o');
    normalized.replace(QChar(0x00D6), 'o');
    normalized.replace(QChar(0x011F), 'g');
    normalized.replace(QChar(0x011E), 'g');
    normalized.replace(QChar(0x0131), 'i');
    normalized.replace(QChar(0x0130), 'i');
    normalized.replace(QChar(0x015F), 's');
    normalized.replace(QChar(0x015E), 's');
    normalized.replace(QChar(0x00E7), 'c');
    normalized.replace(QChar(0x00C7), 'c');

    normalized.remove(QRegularExpression(R"([^a-z0-9])"));

    QString consonants;
    consonants.reserve(normalized.size());
    for (const QChar& ch : normalized) {
        if (ch == QLatin1Char('a') || ch == QLatin1Char('e') ||
            ch == QLatin1Char('i') || ch == QLatin1Char('o') ||
            ch == QLatin1Char('u')) {
            continue;
        }
        consonants.append(ch);
    }

    return consonants.isEmpty() ? normalized : consonants;
}

static bool detectDeletedMessageLine(const QString& content, bool& deletedByMe)
{
    const QString normalized = stripControlChars(content).trimmed();
    const QString lowered = normalized.toLower();

    static const QStringList byMeMarkers = {
        // English
        "you deleted this message",
        // Azerbaijani
        "siz bu mesajı sildiniz",
        "siz bu mesaji sildiniz",
        "bu mesajı siz sildiniz",
        "bu mesaji siz sildiniz",
        "siz bu messaji sildiniz",
        // Turkish
        "bu mesajı siz sildiniz",
        "bu mesaji siz sildiniz",
        // Russian
        "вы удалили это сообщение",
        // Spanish
        "eliminaste este mensaje",
        // Portuguese
        "você apagou esta mensagem",
        "voce apagou esta mensagem",
        // Italian
        "hai eliminato questo messaggio",
        // French
        "vous avez supprimé ce message",
        "vous avez supprime ce message",
        // German
        "du hast diese nachricht gelöscht",
        "du hast diese nachricht geloscht",
        // Arabic
        "لقد حذفت هذه الرسالة",
        // Chinese
        "你删除了此消息",
        // Hindi
        "आपने यह संदेश हटाया",
        // Japanese
        "このメッセージを削除しました",
        // Korean
        "이 메시지를 삭제했습니다",
        // Mongolian
        "та энэ мессежийг устгасан",
        // Polish
        "usunąłeś tę wiadomość",
        "usunieto te wiadomosc",
        // Ukrainian
        "ви видалили це повідомлення",
        // Uzbek
        "siz bu xabarni o'chirdingiz",
        "siz bu xabarni ochirdingiz",
    };

    static const QStringList deletedMarkers = {
        // English
        "this message was deleted",
        // Azerbaijani
        "bu mesaj silindi",
        "bu mesaj silinib",
        "bu mesaj silinmişdir",
        "bu messaj silindi",
        // Turkish
        "bu mesaj silindi",
        // Russian
        "это сообщение удалено",
        // Spanish
        "este mensaje fue eliminado",
        // Portuguese
        "esta mensagem foi apagada",
        // Italian
        "questo messaggio è stato eliminato",
        "questo messaggio e stato eliminato",
        // French
        "ce message a été supprimé",
        "ce message a ete supprime",
        // German
        "diese nachricht wurde gelöscht",
        "diese nachricht wurde geloscht",
        // Arabic
        "تم حذف هذه الرسالة",
        // Chinese
        "此消息已删除",
        // Hindi
        "यह संदेश हटाया गया",
        // Japanese
        "このメッセージは削除されました",
        // Korean
        "이 메시지는 삭제되었습니다",
        // Mongolian
        "энэ мессеж устсан",
        // Polish
        "ta wiadomość została usunięta",
        "ta wiadomosc zostala usunieta",
        // Ukrainian
        "це повідомлення видалено",
        // Uzbek
        "bu xabar o'chirildi",
        "bu xabar ochirildi",
    };

    for (const QString& marker : byMeMarkers) {
        if (lowered.contains(marker)) {
            deletedByMe = true;
            return true;
        }
    }

    for (const QString& marker : deletedMarkers) {
        if (lowered.contains(marker)) {
            deletedByMe = false;
            return true;
        }
    }

    return false;
}

static QString normalizeTimestampText(const QString& raw)
{
    QString normalized = stripControlChars(raw);
    normalized.replace(QChar(0x00A0), QLatin1Char(' ')); // NBSP
    normalized.replace(QChar(0x202F), QLatin1Char(' ')); // narrow NBSP
    normalized.replace(QChar(0x2007), QLatin1Char(' ')); // figure space
    normalized = normalized.trimmed();

    if (normalized.isEmpty())
        return normalized;

    static const QRegularExpression RE_MULTI_SPACE(R"(\s+)");
    static const QRegularExpression RE_COMMA_SPACES(R"(\s*,\s*)");
    static const QRegularExpression RE_AM(R"(\b(a\.?m\.?)\b)",
                                          QRegularExpression::CaseInsensitiveOption);
    static const QRegularExpression RE_PM(R"(\b(p\.?m\.?)\b)",
                                          QRegularExpression::CaseInsensitiveOption);

    normalized.replace(RE_MULTI_SPACE, " ");
    normalized.replace(RE_COMMA_SPACES, ", ");
    normalized.replace(RE_AM, "AM");
    normalized.replace(RE_PM, "PM");
    return normalized;
}

// Timestamp formats
static const QStringList TIMESTAMP_FORMATS = {
    "dd.MM.yyyy, HH:mm:ss",
    "dd.MM.yyyy, HH:mm",
    "d.M.yyyy, HH:mm:ss",
    "d.M.yyyy, HH:mm",
    "dd.MM.yy, HH:mm:ss",
    "dd.MM.yy, HH:mm",
    "d.M.yy, HH:mm:ss",
    "d.M.yy, HH:mm",
    "M/d/yy, h:mm:ss AP",
    "M/d/yy, h:mm AP",
    "M/d/yyyy, h:mm:ss AP",
    "M/d/yyyy, h:mm AP",
    "M/d/yy, HH:mm:ss",
    "M/d/yy, HH:mm",
    "M/d/yyyy, HH:mm:ss",
    "M/d/yyyy, HH:mm",
    "dd/MM/yyyy, HH:mm:ss",
    "dd/MM/yyyy, HH:mm",
    "dd/MM/yy, HH:mm:ss",
    "dd/MM/yy, HH:mm",
    "dd.MM.yyyy HH:mm:ss",
    "dd.MM.yyyy HH:mm",
    "d.M.yyyy HH:mm:ss",
    "d.M.yyyy HH:mm",
    "dd.MM.yy HH:mm:ss",
    "dd.MM.yy HH:mm",
    "d.M.yy HH:mm:ss",
    "d.M.yy HH:mm",
    "dd.MM.yyyy, HH.mm.ss",
    "dd.MM.yyyy, HH.mm",
    "d.M.yyyy, HH.mm.ss",
    "d.M.yyyy, HH.mm",
    "dd.MM.yy, HH.mm.ss",
    "dd.MM.yy, HH.mm",
    "d.M.yy, HH.mm.ss",
    "d.M.yy, HH.mm",
    "dd/MM/yyyy HH:mm:ss",
    "dd/MM/yyyy HH:mm",
    "dd/MM/yy HH:mm:ss",
    "dd/MM/yy HH:mm",
    "yyyy-MM-dd, HH:mm:ss",
    "yyyy-MM-dd, HH:mm",
    "yyyy-MM-dd HH:mm:ss",
    "yyyy-MM-dd HH:mm",
    "dd-MM-yyyy, HH:mm:ss",
    "dd-MM-yyyy, HH:mm",
    "d-M-yyyy, HH:mm:ss",
    "d-M-yyyy, HH:mm",
    "dd-MM-yy, HH:mm:ss",
    "dd-MM-yy, HH:mm",
    "d-M-yy, HH:mm:ss",
    "d-M-yy, HH:mm",
};

// Cached format index — remember the previous successful format
static int s_lastFormatIdx = -1;

QDateTime ChatParser::parseTimestamp(const QString& raw)
{
    const QString normalized = normalizeTimestampText(raw);

    if (normalized.isEmpty())
        return QDateTime();

    // Try last successful format first (same format in 99% cases)
    if (s_lastFormatIdx >= 0 && s_lastFormatIdx < TIMESTAMP_FORMATS.size()) {
        QDateTime dt = QDateTime::fromString(normalized, TIMESTAMP_FORMATS[s_lastFormatIdx]);
        if (dt.isValid()) {
            if (dt.date().year() < 2000) dt = dt.addYears(100);
            return dt;
        }
    }

    // Test all formats
    for (int i = 0; i < TIMESTAMP_FORMATS.size(); ++i) {
        QDateTime dt = QDateTime::fromString(normalized, TIMESTAMP_FORMATS[i]);
        if (dt.isValid()) {
            s_lastFormatIdx = i; // Remember successful format
            if (dt.date().year() < 2000) dt = dt.addYears(100);
            return dt;
        }
    }

    return QDateTime();
}

MessageType ChatParser::detectMediaType(const QString& filename)
{
    const QString ext  = QFileInfo(filename).suffix().toLower();
    const QString base = QFileInfo(filename).fileName();

    // VCF contact file
    if (ext == "vcf")
        return MessageType::Contact;

    // Sticker — files named .webp or with the word "STICKER".
    if (ext == "webp") {
        if (base.contains("STICKER", Qt::CaseInsensitive) || base.startsWith("STK-", Qt::CaseInsensitive))
            return MessageType::Sticker;
        return MessageType::Image;  // Image from other .webp files
    }

    static const QMap<QString, MessageType> extMap = {
        {"jpg",  MessageType::Image},  {"jpeg", MessageType::Image},
        {"png",  MessageType::Image},  {"gif",  MessageType::Image},
        {"heic", MessageType::Image},  {"heif", MessageType::Image},
        {"mp4",  MessageType::Video},  {"mov",  MessageType::Video},
        {"avi",  MessageType::Video},  {"mkv",  MessageType::Video},
        {"mp3",  MessageType::Audio},  {"m4a",  MessageType::Audio},
        {"aac",  MessageType::Audio},  {"wav",  MessageType::Audio},
        {"opus", MessageType::Ptt},    {"ogg",  MessageType::Ptt},
        {"webm", MessageType::Ptt},
        {"pdf",  MessageType::Document},{"doc",  MessageType::Document},
        {"docx", MessageType::Document},{"xls",  MessageType::Document},
        {"xlsx", MessageType::Document},{"txt",  MessageType::Document},
        {"zip",  MessageType::Document},
    };

    if (filename.startsWith("PTT-", Qt::CaseInsensitive))
        return MessageType::Ptt;

    return extMap.value(ext, MessageType::Document);
}

QString ChatParser::extractAttachmentName(const QString& content)
{
    // Remove Unicode control characters.
    const QString cleanContent = stripControlChars(content);
    
    // Debug: Log any content that is "attached".
    if (cleanContent.contains("attached", Qt::CaseInsensitive)) {
        Logger::debug("Attachment check - original: [" + content.left(100).toStdString() + "]");
        Logger::debug("Attachment check - cleaned:  [" + cleanContent.left(100).toStdString() + "]");
    }
    
    auto m1 = RE_ATTACHED_ANGLE.match(cleanContent);
    if (m1.hasMatch()) {
        QString result = m1.captured(1).trimmed();
        Logger::debug("Attachment found: [" + result.toStdString() + "]");
        return result;
    }

    auto m2 = RE_ATTACHED_PAREN.match(cleanContent);
    if (m2.hasMatch()) {
        QString result = m2.captured(1).trimmed();
        Logger::debug("Attachment found (paren): [" + result.toStdString() + "]");
        return result;
    }

    return {};
}

// Manual bracket parsing — 10x faster than regex
// Format: [timestamp] sender: content
static bool parseLine(const QString& line, QString& timestamp, QString& sender, QString& content)
{
    // Skip the control characters at the beginning of the line
    int startPos = 0;
    while (startPos < line.size()) {
        ushort code = line[startPos].unicode();
        if (code == 0x200E || code == 0x200F ||  // LRM, RLM
            code == 0x200B || code == 0x200C || code == 0x200D ||  // ZWSP, ZWNJ, ZWJ
            (code >= 0x202A && code <= 0x202E) ||  // Embedding controls
            (code >= 0x2066 && code <= 0x2069) ||  // Isolate controls
            code == 0xFEFF ||  // BOM
            code < 0x20) {  // ASCII control chars
            startPos++;
            continue;
        }
        break;
    }
    
    // The string must start with '['
    if (startPos >= line.size() || line[startPos] != QLatin1Char('['))
        return false;

    // Find ']'
    const int closeBracket = line.indexOf(']', startPos + 1);
    if (closeBracket < startPos + 2)
        return false;

    timestamp = line.mid(startPos + 1, closeBracket - startPos - 1);

    // '] ' after sender: content
    int pos = closeBracket + 1;
    // Cross the gaps
    while (pos < line.size() && line[pos] == QLatin1Char(' '))
        ++pos;

    // ':' tab — separates sender and content
    const int colonPos = line.indexOf(':', pos);
    if (colonPos < 0 || colonPos == pos)
        return false;

    sender = line.mid(pos, colonPos - pos).trimmed();

    // Content — after ':'
    content = (colonPos + 1 < line.size())
              ? line.mid(colonPos + 1).trimmed()
              : QString();

    return true;
}

// Android export format parser
// Format: M/D/YY, HH:MM - Sender: content
// System lines may have no sender: M/D/YY, HH:MM - Messages and calls are end-to-end encrypted...
static bool parseLineAndroid(const QString& line, QString& timestamp, QString& sender, QString& content)
{
    const QString cleanLine = stripControlChars(line).trimmed();
    if (cleanLine.isEmpty()) {
        return false;
    }

    const int separatorPos = cleanLine.indexOf(" - ");
    if (separatorPos <= 0) {
        return false;
    }

    timestamp = cleanLine.left(separatorPos).trimmed();
    const QString rhs = cleanLine.mid(separatorPos + 3).trimmed();
    if (timestamp.isEmpty() || rhs.isEmpty()) {
        return false;
    }

    const int colonPos = rhs.indexOf(':');
    if (colonPos > 0) {
        const QString senderCandidate = rhs.left(colonPos).trimmed();
        const bool plausibleSender =
            senderCandidate.size() <= 80 &&
            !senderCandidate.contains("://") &&
            !senderCandidate.contains("http", Qt::CaseInsensitive);

        if (plausibleSender) {
            sender = senderCandidate;
            content = rhs.mid(colonPos + 1).trimmed();
            return true;
        }
    }

    sender.clear();
    content = rhs;
    return true;
}

ChatParser::ParseResult ChatParser::parse(const QString& chatTxtPath,
                                          const QString& ownerName,
                                          int            chatId,
                                          const QString& editedLabel,
                                          const QString& deletedMessageLabel,
                                          const QString& youDeletedMessageLabel,
                                          const std::function<void(const ParseProgress&)>& progressCallback,
                                          bool useAndroidParser)
{
    QElapsedTimer timer;
    timer.start();

    ParseResult result;
    s_lastFormatIdx = -1; // Reset cached format

    Logger::info(QString("Parser mode: %1")
                 .arg(useAndroidParser ? "android" : "ios")
                 .toStdString());

    QFile file(chatTxtPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        result.errorMsg = "Failed to open file: " + chatTxtPath;
        Logger::error(result.errorMsg.toStdString());
        return result;
    }

    // Estimated number of messages by file size (average message ~100 bytes)
    const qint64 fileSize = file.size();
    const int estimatedMsgs = static_cast<int>(fileSize / 80);
    result.messages.reserve(estimatedMsgs);

    int                lineNum       = 0;
    int                skippedLines  = 0;
    int                parsedHeaderLines = 0;
    QStringList        invalidTimestampSamples;

    QElapsedTimer progressTimer;
    progressTimer.start();

    auto emitProgress = [&](bool force = false) {
        if (!progressCallback) {
            return;
        }

        if (!force && progressTimer.elapsed() < 70) {
            return;
        }

        ParseProgress payload;
        payload.bytesRead = qBound<qint64>(0, file.pos(), fileSize);
        payload.totalBytes = fileSize;
        payload.linesRead = lineNum;
        payload.parsedMessages = result.messages.size();
        progressCallback(payload);
        progressTimer.restart();
    };

    emitProgress(true);

    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::Utf8);

    const QString ownerComparable = comparablePersonName(ownerName);
    QMap<QString, int> senderMsgCount;
    QStringList         senderOrder;
    Message            currentMsg;
    bool               hasPendingMsg = false;

    auto flushMessage = [&]() {
        if (hasPendingMsg && currentMsg.timestamp.isValid()) {
            // Clear Unicode control chars (For all text)
            currentMsg.content = stripControlChars(currentMsg.content);

            // Check and remove the "This message was edited" tag
            // Extensive regex that can recognize English, Turkish and Azerbaijani variants
            static const QRegularExpression RE_EDIT_TAG(
                R"(\s*\(?<?\s*(This message was edited|Bu mesaj düzenlendi|Redaktə edildi|Düzəliş edilib)\.?\s*>?\)?\s*$)",
                QRegularExpression::CaseInsensitiveOption
            );
            
            auto match = RE_EDIT_TAG.match(currentMsg.content);
            if (match.hasMatch()) {
                // Store a fixed flag "1" instead of a translated label.
                // The actual display text is resolved dynamically in QML from the
                // current language (langManager.currentTranslations["edited"]),
                // so it automatically updates when the user changes the app language.
                currentMsg.editedText = QStringLiteral("1");
                Logger::debug("Edited tag found [" + match.captured(1).toStdString() + "]. Saving flag marker.");
                currentMsg.content.remove(RE_EDIT_TAG);
                currentMsg.content = currentMsg.content.trimmed();
            }

            if (!currentMsg.content.isEmpty() || currentMsg.type != MessageType::Text) {
                // Normalise system messages to language-agnostic tokens so that
                // LanguageManager can translate them on-the-fly when the UI language changes.
                if (currentMsg.type == MessageType::System) {
                    currentMsg.content = normalizeSystemMessage(currentMsg.content);
                }
                currentMsg.isFromMe = (!ownerComparable.isEmpty() &&
                                       comparablePersonName(currentMsg.sender) == ownerComparable);
                currentMsg.chatId   = chatId;
                result.messages.append(currentMsg);
                if (!senderMsgCount.contains(currentMsg.sender)) {
                    senderOrder.append(currentMsg.sender);
                }
                senderMsgCount[currentMsg.sender]++;
            }
        }
        currentMsg    = Message{};
        hasPendingMsg = false;
    };

    QString tsStr, senderStr, contentStr;

    while (!stream.atEnd()) {
        const QString line = stream.readLine();
        lineNum++;

        const bool hasHeader = useAndroidParser
                ? parseLineAndroid(line, tsStr, senderStr, contentStr)
                : parseLine(line, tsStr, senderStr, contentStr);

        if (hasHeader) {
            parsedHeaderLines++;
            flushMessage();

            QDateTime dt = parseTimestamp(tsStr);
            if (!dt.isValid()) {
                skippedLines++;
                if (invalidTimestampSamples.size() < 3) {
                    invalidTimestampSamples.append(
                        QString("line %1: '%2'")
                            .arg(lineNum)
                            .arg(tsStr.left(80))
                    );
                }
                continue;
            }

            currentMsg.timestamp = dt;
            currentMsg.sender    = stripControlChars(senderStr).trimmed();

            // Android system lines can have no sender segment.
            if (currentMsg.sender.isEmpty()) {
                currentMsg.type = MessageType::System;
                QString sc = stripControlChars(contentStr).trimmed();
                currentMsg.content = normalizeSystemMessage(sc);
                hasPendingMsg = !currentMsg.content.isEmpty();
                continue;
            }

            if (result.groupName.trimmed().isEmpty() && isGroupIntroLine(contentStr) && !currentMsg.sender.isEmpty()) {
                result.groupName = currentMsg.sender;
            }

            // Check media
            const QString attachName = extractAttachmentName(contentStr);
            if (!attachName.isEmpty()) {
                currentMsg.type      = detectMediaType(attachName);
                currentMsg.mediaPath = attachName;
                currentMsg.content   = attachName;
                // VCF: read name from file (if data is not available just display filename)
                if (currentMsg.type == MessageType::Contact) {
                    QString vcfName = QFileInfo(attachName).baseName();
                    // Remove "00000023-Ana" prefix
                    static const QRegularExpression RE_NUM_PREFIX(R"(^\d{8}-)");
                    vcfName.remove(RE_NUM_PREFIX);
                    // Format the rest of the text
                    vcfName.replace('-', ' ').replace('_', ' ');
                    currentMsg.mediaMeta = vcfName.trimmed();
                }
            }
            else {
                bool deletedByMe = false;
                if (detectDeletedMessageLine(contentStr, deletedByMe)) {
                    currentMsg.type = MessageType::Deleted;
                    currentMsg.content = deletedByMe
                        ? QStringLiteral("__deleted_by_me__")
                        : QStringLiteral("__deleted__");
                }
                // Location message - Google Maps URL
                else if (RE_LOCATION_URL.match(contentStr).hasMatch()) {
                    currentMsg.type = MessageType::Location;
                    currentMsg.content = contentStr;
                    // Extract coordinates from URL
                    auto locM = RE_LOCATION_URL.match(contentStr);
                    QString url = locM.captured(0);
                    // Find the format q=lat,lng
                    static const QRegularExpression RE_COORD(R"([?&]q=(-?\d+\.\d+),(-?\d+\.\d+))");
                    auto coordM = RE_COORD.match(url);
                    if (coordM.hasMatch()) {
                        currentMsg.mediaMeta = coordM.captured(1) + "," + coordM.captured(2);
                    } else {
                        // Store full URL as meta
                        currentMsg.mediaMeta = url;
                    }
                }
                // iOS location: format
                else if (RE_LOCATION_COORDS.match(contentStr).hasMatch()) {
                    auto lm = RE_LOCATION_COORDS.match(contentStr);
                    currentMsg.type      = MessageType::Location;
                    currentMsg.mediaMeta = lm.captured(1) + "," + lm.captured(2);
                    currentMsg.content   = contentStr;
                }
                // "omitted" messages — Media is not removed during WAPage export
                else if (contentStr.contains("omitted", Qt::CaseInsensitive)) {
                    QString lower = contentStr.toLower();
                    if (lower.contains("video")) {
                        currentMsg.type      = MessageType::Video;
                        currentMsg.mediaMeta = "omitted";
                    } else if (lower.contains("image") || lower.contains("photo")) {
                        currentMsg.type      = MessageType::Image;
                        currentMsg.mediaMeta = "omitted";
                    } else if (lower.contains("audio") || lower.contains("voice") ||
                               lower.contains("ptt")) {
                        currentMsg.type      = MessageType::Ptt;
                        currentMsg.mediaMeta = "omitted";
                    } else if (lower.contains("sticker")) {
                        currentMsg.type      = MessageType::Sticker;
                        currentMsg.mediaMeta = "omitted";
                    } else if (lower.contains("document") || lower.contains("file")) {
                        currentMsg.type      = MessageType::Document;
                        currentMsg.mediaMeta = "omitted";
                    } else {
                        currentMsg.type      = MessageType::System;
                    }
                    currentMsg.content = contentStr;
                    currentMsg.mediaPath.clear(); // Omitted - no file exists
                }
                else if (contentStr.startsWith("\u200e") || contentStr.isEmpty()) {
                    // Remove the LRM symbol, check the rest
                    QString stripped = contentStr;
                    stripped.remove(QChar(0x200E));
                    stripped = stripped.trimmed();
                    if (stripped.isEmpty()) {
                        // Empty system message — sabotage creates artifact
                        hasPendingMsg = false;
                        continue;
                    }
                    currentMsg.type    = MessageType::System;
                    currentMsg.content = stripped;
                }
                else {
                    currentMsg.type    = MessageType::Text;
                    currentMsg.content = contentStr;
                }
            }

            hasPendingMsg = true;
        }
        else if (hasPendingMsg && !line.isEmpty()) {
            if (currentMsg.type == MessageType::Text) {
                currentMsg.content += "\n" + line;
            }
        }

        // Progress log every 50000 lines
        if (lineNum % 50000 == 0) {
            Logger::info(QString("Parse progress: %1 lines, %2 messages")
                         .arg(lineNum).arg(result.messages.size()).toStdString());
        }

        if ((lineNum % 2000 == 0) || progressTimer.elapsed() >= 120) {
            emitProgress();
        }
    }

    flushMessage();
    emitProgress(true);

    // Specify the contact name
    result.ownerName = ownerName;

    // Wrapped export fallback:
    // Some exports place group title as sender and the real member name at content start:
    //   "Group Name: Member Name: message"
    // If intro detection misses this case, unwrap member senders in a second pass.
    if (!result.messages.isEmpty()) {
        QMap<QString, int> outerSenderCount;
        QMap<QString, int> embeddedPatternCountByOuter;
        QMap<QString, QSet<QString>> embeddedSendersByOuter;
        QMap<QString, QMap<QString, int>> embeddedSenderFreqByOuter;
        const QString comparableGroupName = comparablePersonName(result.groupName);

        for (const Message& msg : result.messages) {
            const QString outerSender = msg.sender.trimmed();
            if (outerSender.isEmpty()) {
                continue;
            }

            const QString comparableOuterSender = comparablePersonName(outerSender);
            const bool outerLooksLikeGroupSender =
                outerSender.startsWith('~') ||
                (!comparableGroupName.isEmpty() && comparableOuterSender == comparableGroupName);
            if (!outerLooksLikeGroupSender) {
                continue;
            }

            outerSenderCount[outerSender] = outerSenderCount.value(outerSender) + 1;

            QString embeddedSender;
            QString embeddedText;
            if (!extractEmbeddedSenderAndText(msg.content, embeddedSender, embeddedText)) {
                continue;
            }
            if (embeddedSender.compare(outerSender, Qt::CaseInsensitive) == 0) {
                continue;
            }

            // Wrapped sender should look like a person/token, not an arbitrary phrase.
            if (embeddedSender.contains('<') || embeddedSender.contains('>') ||
                embeddedSender.contains("attached", Qt::CaseInsensitive)) {
                continue;
            }

            const QString comparableEmbeddedSender = comparablePersonName(embeddedSender);
            if (comparableEmbeddedSender.isEmpty() ||
                comparableEmbeddedSender == comparableOuterSender ||
                !RE_HAS_LETTER.match(embeddedSender).hasMatch()) {
                continue;
            }

            embeddedPatternCountByOuter[outerSender] = embeddedPatternCountByOuter.value(outerSender) + 1;
            embeddedSendersByOuter[outerSender].insert(embeddedSender);
            embeddedSenderFreqByOuter[outerSender][embeddedSender] =
                embeddedSenderFreqByOuter[outerSender].value(embeddedSender) + 1;
        }

        QString wrappedOuterSender;
        int wrappedDistinctSenderCount = 0;

        for (auto it = embeddedSendersByOuter.cbegin(); it != embeddedSendersByOuter.cend(); ++it) {
            const QString outerSender = it.key();
            const int distinctEmbedded = it.value().size();
            const int outerCount = outerSenderCount.value(outerSender);
            const int wrappedPatternCount = embeddedPatternCountByOuter.value(outerSender);

            int repeatedEmbeddedSenders = 0;
            const auto senderFreqMap = embeddedSenderFreqByOuter.value(outerSender);
            for (auto fit = senderFreqMap.cbegin(); fit != senderFreqMap.cend(); ++fit) {
                if (fit.value() >= 2) {
                    repeatedEmbeddedSenders++;
                }
            }

            if (distinctEmbedded < 3 || outerCount < 8) {
                continue;
            }
            if (wrappedPatternCount < qMax(5, static_cast<int>(outerCount * 0.7))) {
                continue;
            }
            if (repeatedEmbeddedSenders < 2) {
                continue;
            }

            if (distinctEmbedded > wrappedDistinctSenderCount) {
                wrappedDistinctSenderCount = distinctEmbedded;
                wrappedOuterSender = outerSender;
            }
        }

        if (!wrappedOuterSender.isEmpty()) {
            for (Message& msg : result.messages) {
                if (msg.sender.compare(wrappedOuterSender, Qt::CaseInsensitive) != 0) {
                    continue;
                }

                QString embeddedSender;
                QString embeddedText;
                if (!extractEmbeddedSenderAndText(msg.content, embeddedSender, embeddedText)) {
                    continue;
                }
                if (embeddedSender.compare(wrappedOuterSender, Qt::CaseInsensitive) == 0) {
                    continue;
                }

                msg.sender = embeddedSender;
                msg.content = embeddedText;
            }

            if (!result.isGroup) {
                result.isGroup = true;
            }
            if (result.groupName.trimmed().isEmpty()) {
                result.groupName = wrappedOuterSender;
            }

            Logger::info(QString("Wrapped group pattern detected: outer='%1', embedded senders=%2")
                         .arg(wrappedOuterSender)
                         .arg(wrappedDistinctSenderCount)
                         .toStdString());
        }

        for (Message& msg : result.messages) {
            msg.isFromMe = (!ownerComparable.isEmpty() &&
                            comparablePersonName(msg.sender) == ownerComparable);
        }
    }

    // Resolve owner sender with a conservative fuzzy fallback when encoding
    // mismatches prevent exact name matching.
    QString resolvedOwnerComparable = ownerComparable;
    if (!ownerComparable.isEmpty()) {
        bool hasDirectOwnerMatch = false;
        for (const Message& msg : result.messages) {
            if (msg.isFromMe) {
                hasDirectOwnerMatch = true;
                break;
            }
        }

        if (!hasDirectOwnerMatch) {
            const QString ownerSignature = personNameSignature(ownerName);
            if (!ownerSignature.isEmpty()) {
                QSet<QString> matchedComparableSenders;
                QSet<QString> allComparableSenders;

                for (const Message& msg : result.messages) {
                    const QString comparableSender = comparablePersonName(msg.sender);
                    if (comparableSender.isEmpty()) {
                        continue;
                    }
                    allComparableSenders.insert(comparableSender);
                    if (personNameSignature(msg.sender) == ownerSignature) {
                        matchedComparableSenders.insert(comparableSender);
                    }
                }

                if (matchedComparableSenders.size() == 1 && allComparableSenders.size() >= 2) {
                    resolvedOwnerComparable = *matchedComparableSenders.cbegin();
                    for (Message& msg : result.messages) {
                        msg.isFromMe = (comparablePersonName(msg.sender) == resolvedOwnerComparable);
                    }

                    Logger::info(QString("Owner fuzzy match applied: '%1'")
                                 .arg(resolvedOwnerComparable)
                                 .toStdString());
                }
            }
        }
    }

    // Rebuild sender stats from normalized messages.
    senderMsgCount.clear();
    senderOrder.clear();
    QMap<QString, int> comparableSenderCount;
    QMap<QString, QString> comparableSenderDisplayName;

    for (const Message& msg : result.messages) {
        const QString senderName = stripControlChars(msg.sender).trimmed();
        if (senderName.isEmpty()) {
            continue;
        }
        if (!senderMsgCount.contains(senderName)) {
            senderOrder.append(senderName);
        }
        senderMsgCount[senderName]++;

        const QString comparableSender = comparablePersonName(senderName);
        if (comparableSender.isEmpty()) {
            continue;
        }
        comparableSenderCount[comparableSender] = comparableSenderCount.value(comparableSender) + 1;
        if (!comparableSenderDisplayName.contains(comparableSender)) {
            comparableSenderDisplayName.insert(comparableSender, senderName);
        }
    }

    QString contactName;
    int maxCount = 0;
    for (auto it = comparableSenderCount.cbegin(); it != comparableSenderCount.cend(); ++it) {
        if (it.key() != resolvedOwnerComparable && it.value() > maxCount) {
            maxCount = it.value();
            contactName = comparableSenderDisplayName.value(it.key());
        }
    }

    const int distinctSenders = comparableSenderCount.size();

    // Group rule: only chats with more than 2 distinct senders are treated as groups.
    result.isGroup = (distinctSenders > 2);
    if (!result.isGroup) {
        result.groupName.clear();
    }

    const QString comparableGroupName = comparablePersonName(result.groupName);
    QSet<QString> participantComparableSet;

    for (auto it = comparableSenderCount.cbegin(); it != comparableSenderCount.cend(); ++it) {
        const QString comparableSender = it.key();
        if (comparableSender.isEmpty()) {
            continue;
        }
        if (comparableSender == resolvedOwnerComparable) {
            continue;
        }
        if (result.isGroup && !comparableGroupName.isEmpty() && comparableSender == comparableGroupName) {
            continue;
        }

        if (participantComparableSet.contains(comparableSender)) {
            continue;
        }

        const QString displaySender = comparableSenderDisplayName.value(comparableSender);
        if (!displaySender.isEmpty()) {
            // Strip tilde prefix from participant names (~ indicates no phone number in WhatsApp)
            QString cleanedSender = stripTildePrefix(displaySender);
            result.participants.append(cleanedSender);
            participantComparableSet.insert(comparableSender);
        }
    }

    if (result.isGroup) {
        if (result.groupName.trimmed().isEmpty()) {
            result.groupName = groupNameFromChatTxtPath(chatTxtPath);
        }

        if (!result.groupName.trimmed().isEmpty()) {
            result.contactName = result.groupName.trimmed();
        } else {
            result.contactName = contactName.isEmpty() ? "Unknown Group" : contactName;
        }
    } else {
        result.contactName = contactName.isEmpty() ? "Unknown" : contactName;
        if (!result.contactName.trimmed().isEmpty() && !result.participants.contains(result.contactName.trimmed())) {
            result.participants.append(result.contactName.trimmed());
        }
    }

    result.success     = !result.messages.isEmpty();

    if (!result.success) {
        if (parsedHeaderLines == 0) {
            if (useAndroidParser) {
                result.errorMsg = "Message lines were not recognized. Expected format: date, time - sender: text";
            } else {
                result.errorMsg = "Message lines were not recognized. Expected format: [date] sender: text";
            }
        } else {
            result.errorMsg = QString("Messages could not be parsed: timestamp format not recognized on %1 lines.")
                              .arg(skippedLines);
            if (!invalidTimestampSamples.isEmpty()) {
                result.errorMsg += " Samples: " + invalidTimestampSamples.join(" | ");
            }
        }
        Logger::error(result.errorMsg.toStdString());
    }

    const qint64 elapsed = timer.elapsed();
    Logger::info((QString("Parse completed: %1 messages, %2 skipped, %3ms, contact: %4")
                   .arg(result.messages.size())
                   .arg(skippedLines)
                   .arg(elapsed)
                   .arg(result.contactName)).toStdString());

    Logger::info((QString("Parse diagnostics: isGroup=%1, groupName='%2', distinctSenders=%3, participants=%4")
                  .arg(result.isGroup ? "true" : "false")
                  .arg(result.groupName)
                  .arg(distinctSenders)
                  .arg(result.participants.size())).toStdString());

    if (progressCallback) {
        ParseProgress done;
        done.bytesRead = fileSize;
        done.totalBytes = fileSize;
        done.linesRead = lineNum;
        done.parsedMessages = result.messages.size();
        progressCallback(done);
    }

    return result;
}
