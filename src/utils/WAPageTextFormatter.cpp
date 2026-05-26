#include "WAPageTextFormatter.h"
#include <QRegularExpression>

namespace WAPageTextFormatter {

QString toHtml(const QString& waText)
{
    QString result = waText.toHtmlEscaped();

    // ~~strikethrough~~ — process first (not to be confused with ~~~)
    static const QRegularExpression reStrike(R"(~~(.+?)~~)");
    result.replace(reStrike, "<s>\\1</s>");

    // *bold* — single asterisk, no spaces at start/end
    static const QRegularExpression reBold(R"(\*([^\*\n]+)\*)");
    result.replace(reBold, "<b>\\1</b>");

    // _italic_
    static const QRegularExpression reItalic(R"(_([^_\n]+)_)");
    result.replace(reItalic, "<i>\\1</i>");

    // `monospace`
    static const QRegularExpression reMono(R"(`([^`\n]+)`)");
    result.replace(reMono,
        "<span style='font-family: monospace; "
        "background: rgba(255,255,255,0.1); "
        "border-radius: 3px; padding: 0 3px;'>\\1</span>");

    // Line traversal
    result.replace("\n", "<br/>");

    // Allow only literal <b>...</b> from chat text.
    // Other HTML tags remain escaped because we never unescape them.
    static const QRegularExpression reEscapedBoldTag(
        R"(&lt;b&gt;(.+?)&lt;/b&gt;)",
        QRegularExpression::DotMatchesEverythingOption);
    result.replace(reEscapedBoldTag, "<b>\\1</b>");

    return result;
}

QString linkify(const QString& text)
{
    static const QRegularExpression reUrl(
        R"((https?://[^\s<>"{}|\\^`\[\]]+))");
    QString result = text;
    result.replace(reUrl,
        "<a href='\\1' style='color: #53BDEB;'>\\1</a>");
    return result;
}

QString formatFull(const QString& waText)
{
    return linkify(toHtml(waText));
}

} // namespace WAPageTextFormatter
