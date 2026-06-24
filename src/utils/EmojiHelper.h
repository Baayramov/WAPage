#pragma once
#include <QString>

// Emoji helper functions
namespace EmojiHelper {

// Converts Unicode emojis in text to span for Qt RichText
// Most emojis are rendered automatically with Qt 6 + Noto Color Emoji font
// This function may only be needed for old font fallback
QString processEmoji(const QString& text);

// Returns the font family of the emoji (platform-specific)
QString emojiFontFamily();

} // namespace EmojiHelper
