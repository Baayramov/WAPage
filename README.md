# WAPage

WhatsApp provides an export feature for conversations, but offers no official tool to read them afterward. This application was built to fill that gap. <br> WAPage parses exported WhatsApp chat files and renders them in a clean visual interface. <br>
What separates this program from other readers is that it works with C++ in a new .exe program format, it does not need a browser and it's open source. <br>
### Download WAPage Release via PowerShell

**1. Quick Download (Ready-to-use App):** To download the latest compiled release directly, use Windows PowerShell: <br>
<pre><code>Invoke-WebRequest -Uri "https://github.com/Baayramov/WAPage/releases/download/v1.0.0/WAPage-v1.0.0.zip" -OutFile "WAPage.zip"</code></pre> <br>

### Features

- Interface design that closely mirrors the known app visual style
- Light and Dark theme options
- Interface available in 18 languages — the interface language has no effect on the content inside chats
- Support for both individual (one-on-one) and group conversations
- It refers to both simple and animated stickers sent in chat
- Detection and display of all sent media files, voice messages, shared contacts, and text messages
- Going directly to the first message in the chat
- Ability to rename conversations and set custom profile pictures
- Links inside chats are clickable and open in the default browser
- Location messages open the coordinates in a map via the browser
- Fully offline — no internet connection is made at any point, all data remains on the user's own machine
- Low resource usage, designed to run smoothly even on low-end hardware
- Written up to <b>10.000+</b> code lines <br>
Source code will be shared soon
<br>
<b>Some sensitive texts/images were blurred in screenshots</b>
<br>
<div align="center">
  <img src="" />
  <img src="" />
  <img src="" />
</div>
### Interface Languages

Azerbaijani, Turkish, English, Spanish, Portuguese, Russian, Italian, Arabic, French, German, Chinese, Hindi, Japanese, Korean, Mongolian, Polish, Ukrainian, Uzbek

### Supported Export Types

| Platform | With Media | Chat Only (Without Media) |
|----------|-----------|----------------------------|
| Android  | Supported | Supported                  |
| iOS      | Supported | Supported                  |

**Important:** The chat parser currently supports only exports made from a device with the system language set to English. This is required because time zone data and system-generated messages (such as group join/leave events, name changes, etc.) are only recognized in the English export format. The content inside the chats — messages, names, and media — can be in any language without restriction.

### Supported Platforms

| Platform                                  | Status    |
|-------------------------------------------|-----------|
| Windows 10 64-bit (version 1507 and above)| Supported |
| Windows 11 64-bit                         | Supported |
| Linux                                     | Planned   |
| macOS                                     | Planned   |

### Future Plans

- Linux and macOS platform support
- Support for chats exported from devices with non-English system languages
- Additional language and format support

### Support

If you find this project useful and would like to support me:

<a href="https://www.paypal.com/ncp/payment/AZ26AYEFY35D4">
  <img src="https://i.imgur.com/1iuuok4.png" width="120">
</a>

---

This software is licensed under a custom proprietary license. See LICENSE for details.
FFmpeg (LGPL v2.1 or later) is used for video/image/audio processing. <a>https://ffmpeg.org/legal.html</a>
Qt 6.7.3 — LGPL v3 — <a>https://www.qt.io/licensing/open-source-lgpl-obligations</a>
NotoColorEmoji font (OFL 1.1) — <a>https://fonts.google.com/noto</a>

*This project exists because WhatsApp, despite offering a chat export feature, provides no means to actually read the exported files officially. This application does exactly that.*
