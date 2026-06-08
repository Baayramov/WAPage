#pragma once
#include <QString>

// Convert WAPage text styles to HTML:
// *bold* → <b>bold</b>
// _italic_ → <i>italic</i>
// ~~strikethrough~~ → <s>strike</s>
// `monospace` → <code>mono</code>
namespace WAPageTextFormatter {

// Converts plain text to HTML with WAPage styles
QString toHtml(const QString& waText);

// Converts URLs in text to clickable links
QString linkify(const QString& text);

// Combines both (format + linkify)
QString formatFull(const QString& waText);

} // namespace WAPageTextFormatter
