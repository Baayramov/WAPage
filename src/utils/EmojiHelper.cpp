#include "EmojiHelper.h"

namespace EmojiHelper {

QString processEmoji(const QString& text)
{
    // Since Qt 6 + Noto Color Emoji font is bundled
    // no further processing is necessary — emojis are automatically rendered
    return text;
}

QString emojiFontFamily()
{
    // Windows 10+ — Segoe UI Emoji is in our system
    // We also bundle Noto Color Emoji
    return "Noto Color Emoji";
}

} // namespace EmojiHelper
