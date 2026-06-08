# WAPage
<img src="https://i.imgur.com/xj1Bt6c.png" align="right" width="120">
WhatsApp provides an export feature for conversations, but offers no official tool to read them afterward. This application was built to fill that gap. <br> WAPage parses exported WhatsApp chat files and renders them in a clean visual interface. <br>
What separates this program from other readers is that it works with C++ in a .exe program format, it does not need a browser and it's open source.

## Downlaod (Windows)

### 1.Download directly last version from this link

<a>https://github.com/Baayramov/WAPage/releases/download/v1.4.0/WAPage-v1.4.0.zip</a> <br>

**2.Download from release tab on right**

**3.Download using Windows PowerShell** <br>

<pre><code>Invoke-WebRequest -Uri "https://github.com/Baayramov/WAPage/releases/download/v1.4.0/WAPage-v1.4.0.zip" -OutFile "WAPage-v1.4.0.zip"</code></pre>

## VirusTotal Scan Link

<a>https://www.virustotal.com/gui/file/331975fe4683566a12a19407dab219c38e538942c18d6a25fe23ce6208f30326/detection</a>

### Windows SmartScreen Warning

When you first open the program, you may see a Windows SmartScreen warning. This is because the program is not signed with a Code Signing Certificate. This method was not chosen because Code Signing Certificates are expensive. This is not a cause for concern because the source code reflects reality.

### Linux version now is here

The project can now be built and run on Linux. Since the Linux version is still new, there may be some problems, which will be fixed in time. It is not only in Appimage format that it will work on every computer, but also on computers with Qt libraries installed. Since making an Appimage is difficult, it will take some time. There is a section below on how to build the Linux version.

### Features

- Supports both Android and iOS exports
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
- Written up to <b>21.000</b> code lines <br><br>


<br><br>
<b>Some sensitive texts/images were blurred in screenshots</b>
<br>
<div align="center">
  <img src="https://i.imgur.com/ZaodYuh.jpeg" />
  <img src="https://i.imgur.com/o2gDtQA.jpeg" />
  <img src="https://i.imgur.com/bCbqE0K.gif" />
  <img src="https://i.imgur.com/M7XUojW.gif" />
</div>

### Tests (on Windows)

As a result of the highest test, it was able to insert a 3.66 Gb ZIP file with more than 400.000 messages and media in an average time of 6 minutes.

### Interface Languages

`Azerbaijan, Turkish, English, Spanish, Italian, German, French, Polish, Portuguese, Russian, Ukrainian, Mongolian, Hindi, Arabic, Chinese (Simplified), Japanese, Korean, Uzbek`

### Supported Export Types

| Platform | With Media| Chat Only (Without Media) |
|----------|-----------|----------------------------|
| Android  | Supported | Supported                  |
| iOS      | Supported | Supported                  |

**Important:** The chat parser currently supports only exports made from a device with the system language set to English. This is required because time zone data and system-generated messages (such as group join/leave events, name changes, etc.) are only recognized in the English export format. The content inside the chats — messages, names, and media — can be in any language without restriction.

### Supported Platforms

| Platform                                  |  Status   |
|-------------------------------------------|-----------|
| Windows 10 64-bit (version 1507 and above)| Supported |
| Windows 11 64-bit                         | Supported |
| Linux (Ubuntu 22.04 LTS or Debian 12)     | Supported |
| macOS                                     |  Planned  |

### Build Instructions (Windows)

To compile the project from the source code, please follow these steps carefully to ensure all required dependencies are properly installed via the Qt Online Installer.

**1. Installing Required Qt Components**
- Open the Qt Online Installer. Navigate to the Customize section and ensure the Archive option is enabled from the Show filter menu in the top right corner.
- Under Qt -> Qt 6.7.3, select and install the following modules:
  - MSVC 2022 64-bit
  - Qt 5 Compatibility Module
  - Qt Shader Tools
- Under Qt -> Qt 6.7.3 -> Additional Libraries, select and install:
  - Qt Image Formats
  - Qt Multimedia
- Under Qt Development -> Build Tools, select and install:
  - CMake 3.30.5
  - Ninja 1.12.1
- Under Qt Creator, select and install:
  - Qt Creator 19.0.0 (or latest version)

**2. Building the Project**
- Launch Qt Creator. Click on Open Project... and select the `CMakeLists.txt` file located in the source code directory.
- In the Kit Selection screen, strictly choose Desktop Qt 6.7.3 MSVC2022 64-bit.
- It is highly recommended to set the build configuration to Release. The application requires specific DLLs to be present in the release folder for optimal performance. (You may select Debug for error-checking purposes, but note that this will result in noticeable performance degradation).
- Click Configure Project and wait for the configuration process to finish.
- Once the configuration is successfully completed, the Build button (the hammer icon in the bottom-left corner) will become active. Click it to start compiling.
- After the build finishes successfully, a new `build` directory will be generated inside the project folder. Within this directory, navigate to the `Desktop_Qt_6_7_3_MSVC2022_64bit-Release` or `Desktop_Qt_6_7_3_MSVC2022_64bit-Debug` folder to find your fully compiled executable program.

### Build Instructions (Linux)

To compile the project from the source code, please follow these steps carefully to ensure all required dependencies are properly installed via the Qt Online Installer.

**1. Installing Required Qt Components**
- Open the Qt Online Installer. Navigate to the Customize section and ensure the Archive option is enabled from the Show filter menu in the top right corner.
- Under Qt for Development -> Qt -> Qt 6.7.3, select and install the following modules:
  - Desktop
  - Qt 5 Compatibility Module
  - Qt Shader Tools
- Under Qt for Development -> Qt -> Qt 6.7.3 -> Additional Libraries, select and install:
  - Qt Image Formats
  - Qt Multimedia
- Under Qt for Development -> Qt -> Build Tools, select and install:
  - CMake 3.30.5
  - Ninja 1.12.1
- Under Developer Tools -> Qt Creator, select and install:
  - Qt Creator 19.0.0 (or latest version)

**2. Building the Project**
- Launch Qt Creator. Click on Open Project... and select the `CMakeLists.txt` file located in the source code directory.
- In the Kit Selection screen, strictly choose Desktop.
- It is highly recommended to set the build configuration to Release for optimal performance. (You may select Debug for error-checking purposes, but note that this will result in noticeable performance degradation).
- Click Configure Project and wait for the configuration process to finish.
- Once the configuration is successfully completed, the Build button (the hammer icon in the bottom-left corner) will become active. Click it to start compiling.
- After the build finishes successfully, a new `build` directory will be generated inside the project folder. Within this directory, navigate to the `Desktop-Release` or `Desktop-Debug` folder to find your fully compiled executable program.

### Future Plans

- macOS platform support
- Support for chats exported from devices with non-English system languages
- Additional language and format support

### Support

If you find this project useful and would like to support me:

<a href="https://www.paypal.com/ncp/payment/AZ26AYEFY35D4">
  <img src="https://i.imgur.com/1iuuok4.png" width="120">
</a>

---

This software is licensed under a custom proprietary license. See LICENSE for details. <br>
Qt 6.7.3 — LGPL v3 — <a>https://www.qt.io/licensing/open-source-lgpl-obligations</a> <br>
NotoColorEmoji font (OFL 1.1) — <a>https://fonts.google.com/noto</a> <br>

*This project exists because WhatsApp, despite offering a chat export feature, provides no means to actually read the exported files officially. This application does exactly that.*
