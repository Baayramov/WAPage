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
    // Windows: Segoe UI Emoji is available in the system
    // Linux:   depends on Noto Color Emoji being installed
    // We also bundle Noto Color Emoji as a resource font
    return "Noto Color Emoji";
}

} // namespace EmojiHelper
