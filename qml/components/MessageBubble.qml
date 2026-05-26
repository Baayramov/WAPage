import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Single message bubble — sent (right/green) and received (left/white)
Item {
    id: root

    property bool   isFromMe:        false
    property string formattedContent: ""
    property string msgTime:         ""
    property int    readStatus:      3
    property bool   isLastInGroup:   true
    property bool   isFirstInGroup:  true
    property bool   isGroupChat:     false
    property string msgType:         "text"
    property string sender:          ""
    property string senderAvatarPath: ""
    property string msgDate:         ""
    // Media features
    property string mediaPath:       ""
    property string mediaThumbnail:  ""
    property string mediaDuration:   ""
    property string mediaMeta:       ""   // Location: "lat,lng" | Contact: name | Omitted: "omitted"
    property string waveform:        ""   // Real audio waveform data
    property bool   showDate:        false
    property string editedText:      ""
    property bool   isSys:           msgType === "system"
    // Audio playback-speed persistence: forwarded into AudioPlayer instances
    // so the user-selected rate (1.5x/2x/1x) survives ListView delegate recycling
    // within the same chat. The map lives on MessagePanel.msgList and is cleared
    // on chat-change. msgId is the stable Message.id from the C++ model.
    property int    msgId:           -1
    property var    audioSpeedStore: null
    readonly property bool showSenderHeader:
        isGroupChat && !isFromMe && isFirstInGroup && !isSys && msgType !== "sticker"

    function senderInitials(name) {
        if (!name || name.trim().length === 0) return "?"
        const parts = name.trim().split(/\s+/)
        if (parts.length === 1) return parts[0].slice(0, 2).toUpperCase()
        return (parts[0][0] + parts[1][0]).toUpperCase()
    }

    function senderColor(name) {
        const palette = [
            "#D4371C", "#E65100", "#BF360C", "#AD1457",
            "#880E4F", "#6A1B9A", "#4527A0", "#1565C0",
            "#0277BD", "#00695C", "#2E7D32", "#558B2F",
            "#F57F17", "#4E342E", "#37474F", "#00897B"
        ]
        let hash = 0
        const text = name || ""
        for (let i = 0; i < text.length; ++i) {
            hash = ((hash * 31) + text.charCodeAt(i)) & 0x7fffffff
        }
        return palette[hash % palette.length]
    }

    width:  parent.width
    
    // Forced Scaling (The Gravity Lock): 100% Deterministic height
    // To eliminate QML's measurement delay, we pre-freeze the height.
    height: {
        let h = 0
        // 1. Date segment (if necessary)
        if (showDate) h += 40

        // 2. System message or normal bubble
        if (isSys) {
            h += 36 // Fixed prediction for system message
        } else {
            // We calculate the paddings here once
            let topP = isFirstInGroup ? 8 : 4 // A slightly wider and cleaner interval
            let botP = isLastInGroup ? 4 : 0
            let senderExtra = showSenderHeader ? 18 : 0
            
            let typeH = 50 // Default text base
            if (msgType === "image" || msgType === "video")      typeH = (mediaMeta === "omitted" ? 72  : 208)
            else if (msgType === "audio" || msgType === "ptt")   typeH = (mediaMeta === "omitted" ? 60  : 64)
            else if (msgType === "sticker")                      typeH = (mediaMeta === "omitted" ? 60  : 176)
            else if (msgType === "location")                     typeH = 170
            else if (msgType === "contact")                      typeH = 80
            else if (msgType === "document")                     typeH = 74
            else {
                // Text height (We predict until Loader is ready)
                typeH = Math.max(54, contentLoader.item ? contentLoader.item.implicitHeight + 32 : 54)
            }
            h += topP + typeH + botP + senderExtra
        }
        return h
    }

    implicitHeight: height // We align so that the ListView doesn't get confused

    // Let's adjust the bubble height to these constants so that there is no internal breakage
    readonly property int fixedBubbleHeight: {
        let senderExtra = showSenderHeader ? 18 : 0
        if (msgType === "image" || msgType === "video")      return (mediaMeta === "omitted" ? 72  : 208) + senderExtra
        if (msgType === "audio" || msgType === "ptt")        return (mediaMeta === "omitted" ? 60  : 64) + senderExtra
        if (msgType === "sticker")                           return (mediaMeta === "omitted" ? 60  : 176)
        if (msgType === "location") return 170 + senderExtra
        if (msgType === "contact")  return 80 + senderExtra
        if (msgType === "system")   return 36
        if (msgType === "document") return 74 + senderExtra
        return contentLoader.height + WAPageTheme.bubblePaddingV * 2 + metaRow.height + 4 + senderExtra
    }

    // ── 1. Date Separator ─────────────────────────────
    Loader {
        id: dateSepLoader
        active:  root.showDate
        width:   parent.width
        height:  active ? 40 : 0
        anchors.top: parent.top
        sourceComponent: Component {
            Item {
                height: 40
                Rectangle {
                    anchors.centerIn: parent
                    implicitWidth:  dateLabel.implicitWidth + 24
                    implicitHeight: 28
                    radius:         14
                    color:          WAPageTheme.dateSepBg
                    Text {
                        id: dateLabel
                        anchors.centerIn: parent
                        text:           root.msgDate
                        color:          WAPageTheme.dateSepText
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeMicro
                    }
                }
            }
        }
    }

    // ── 2. System Message ─────────────────────────────
    Loader {
        id: sysMsgLoader
        active:  root.isSys
        width:   parent.width
        height:  active ? 36 : 0
        anchors.top: dateSepLoader.active ? dateSepLoader.bottom : parent.top
        sourceComponent: systemComp
    }

    // Space from below
    property int bottomPadding: isLastInGroup ? 8 : 0
    readonly property color bubbleFillColor:
        (root.msgType === "sticker" && root.mediaMeta !== "omitted")
            ? "transparent"
            : (root.isFromMe ? WAPageTheme.bubbleSent : WAPageTheme.bubbleReceived)

    // bubble essence
    Rectangle {
        id: bubble
        visible: !root.isSys
        width: {
            if (root.msgType === "video" && root.mediaMeta === "omitted") return 280
            if (root.msgType === "image" || root.msgType === "video") return 248
            if (root.msgType === "audio" || root.msgType === "ptt")   return 280
            if (root.msgType === "sticker")                           return 168
            if (root.msgType === "location")                          return 240
            if (root.msgType === "contact")                           return 240
            return Math.max(
                Math.min((contentLoader.item ? contentLoader.item.implicitWidth : 0) + WAPageTheme.bubblePaddingH * 2,
                         root.width * 0.75),
                metaRow.width + WAPageTheme.bubblePaddingH * 2 + 4
            )
        }
        height: root.fixedBubbleHeight

        anchors {
            top:   sysMsgLoader.active ? sysMsgLoader.bottom : (dateSepLoader.active ? dateSepLoader.bottom : parent.top)
            right: root.isFromMe ? parent.right : undefined
            left:  root.isFromMe ? undefined    : parent.left
            topMargin:   isFirstInGroup ? 8 : 4
            rightMargin: root.isFromMe ? 8 : 0
            leftMargin:  root.isFromMe ? 0 : (root.isGroupChat ? 44 : 8)
        }

        color:  root.bubbleFillColor
        radius: WAPageTheme.bubbleRadius
        clip:   false  // tail Canvas should be offset - clip remains false

        // The ball with the tail squares off the corner so that it is fully aligned with the tail bubble.
        Rectangle {
            id: tailCornerPatch
            visible: root.isFirstInGroup && root.msgType !== "sticker"
            width: WAPageTheme.bubbleRadius + 1
            height: WAPageTheme.bubbleRadius + 1
            color: root.bubbleFillColor
            radius: 0

            anchors {
                top: parent.top
                right: root.isFromMe ? parent.right : undefined
                left: root.isFromMe ? undefined : parent.left
            }
        }

        // Bubble tail (straight triangle tail according to CSS reference)
        Canvas {
            id: tail
            visible: root.isFirstInGroup && root.msgType !== "sticker"
            width:   10
            height:  20
            antialiasing: true

            property color fillColor: root.bubbleFillColor
            onFillColorChanged: requestPaint()

            anchors {
                top:    parent.top
                right:  root.isFromMe ? parent.right : undefined
                left:   root.isFromMe ? undefined    : parent.left
                rightMargin: root.isFromMe ? -9 : 0
                leftMargin:  root.isFromMe ? 0  : -9
                topMargin:   0
            }

            onPaint: {
                const ctx = getContext("2d")
                ctx.clearRect(0, 0, width, height)
                ctx.fillStyle = fillColor
                ctx.beginPath()
                const w = width
                const h = height

                if (root.isFromMe) {
                    // Right side: right triangle (closer to CSS reference)
                    ctx.moveTo(0, 0)
                    ctx.lineTo(w, 0)
                    ctx.lineTo(0, h)
                } else {
                    // Left side: right triangle (mirror)
                    ctx.moveTo(w, 0)
                    ctx.lineTo(0, 0)
                    ctx.lineTo(w, h)
                }

                ctx.closePath()
                ctx.fill()
            }

            Component.onCompleted: requestPaint()
            Connections {
                target: root
                function onIsFromMeChanged() { tail.requestPaint() }
                function onIsFirstInGroupChanged() { tail.requestPaint() }
                function onBubbleFillColorChanged() { tail.requestPaint() }
            }
        }

        Text {
            id: senderLabel
            visible: root.showSenderHeader
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                topMargin: 1
                leftMargin: WAPageTheme.bubblePaddingH
                rightMargin: WAPageTheme.bubblePaddingH
            }
            text: root.sender
            color: root.senderColor(root.sender)
            font.family: WAPageTheme.fontFamily
            font.pixelSize: WAPageTheme.fontSizeSmall
            font.weight: Font.DemiBold
            elide: Text.ElideRight
            maximumLineCount: 1
        }

        // Content
        Loader {
            id: contentLoader
            anchors {
                top:        parent.top
                left:       parent.left
                right:      parent.right
                topMargin:  {
                    let extra = root.showSenderHeader ? 16 : 0
                    if (root.msgType === "location" || root.msgType === "contact") return extra
                    if ((root.msgType === "image" || root.msgType === "video") && root.mediaMeta !== "omitted") return 4 + extra
                    if (root.msgType === "ptt" || root.msgType === "audio" || (root.msgType === "video" && root.mediaMeta === "omitted")) return WAPageTheme.bubblePaddingV + 2 + extra
                    return WAPageTheme.bubblePaddingV + extra
                }
                leftMargin: {
                    if (root.msgType === "location" || root.msgType === "contact") return 0
                    if ((root.msgType === "image" || root.msgType === "video") && root.mediaMeta !== "omitted") return 4
                    return WAPageTheme.bubblePaddingH
                }
                rightMargin: {
                    if (root.msgType === "location" || root.msgType === "contact") return 0
                    if ((root.msgType === "image" || root.msgType === "video") && root.mediaMeta !== "omitted") return 4
                    return WAPageTheme.bubblePaddingH
                }
            }

            sourceComponent: {
                if (root.msgType === "image")    return (root.mediaMeta === "omitted" ? omittedImageComp : imageComp)
                if (root.msgType === "video")    return (root.mediaMeta === "omitted" ? omittedVideoComp : videoComp)
                if (root.msgType === "audio")    return (root.mediaMeta === "omitted" ? omittedAudioComp : audioComp)
                if (root.msgType === "ptt")      return (root.mediaMeta === "omitted" ? omittedAudioComp : audioComp)
                if (root.msgType === "sticker")  return (root.mediaMeta === "omitted" ? omittedStickerComp : stickerComp)
                if (root.msgType === "document") return (root.mediaMeta === "omitted" ? omittedDocComp : docComp)
                if (root.msgType === "location") return locationComp
                if (root.msgType === "contact")  return contactComp
                if (root.msgType === "deleted")  return deletedComp
                if (root.msgType === "system")   return systemComp
                return textComp
            }
        }

        // ── Meta order: time + tick ─────────────────────────────────
        Row {
            id: metaRow
            visible: {
                if (root.msgType === "location" || root.msgType === "contact") return false
                if (root.msgType === "image" || root.msgType === "video") return root.mediaMeta === "omitted"
                if (root.msgType === "sticker" && root.mediaMeta !== "omitted") return false
                return true
            }
            anchors {
                right:        root.isFromMe || (root.msgType !== "audio" && root.msgType !== "ptt") ? parent.right : undefined
                left:         !root.isFromMe && (root.msgType === "audio" || root.msgType === "ptt") ? parent.left : undefined
                bottom:       parent.bottom
                rightMargin:  WAPageTheme.bubblePaddingH
                leftMargin:   12 // In the received voice messages, we draw to the left (below the Play button)
                bottomMargin: WAPageTheme.bubblePaddingV + 2
            }
            spacing: 3

            Text {
                visible:        root.editedText !== ""
                text:           root.editedText
                color:          root.isFromMe
                                ? WAPageTheme.metaTextSent
                                : WAPageTheme.metaTextRecv
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeMicro
                font.italic:    true
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text:           root.msgTime
                color:          root.isFromMe
                                ? WAPageTheme.metaTextSent
                                : WAPageTheme.metaTextRecv
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeMicro
                anchors.verticalCenter: parent.verticalCenter
            }

            TickMark {
                visible:            root.isFromMe
                readStatus:         root.readStatus
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    AvatarCircle {
        id: senderBlockAvatar
        visible: root.isGroupChat && !root.isFromMe && root.isLastInGroup && !root.isSys
        size: 24
        avatarPath: root.senderAvatarPath
        initials: root.senderInitials(root.sender)
        avatarColor: root.senderColor(root.sender)
        anchors {
            left: parent.left
            leftMargin: 12
            bottom: bubble.bottom
            bottomMargin: 2
        }
    }

    // Components

    Component {
        id: textComp
        TextEdit {
            readOnly:        true
            textFormat:      TextEdit.RichText
            text:            root.formattedContent
            color:           root.isFromMe ? WAPageTheme.bubbleSentText
                                           : WAPageTheme.bubbleRecvText
            font.family:     WAPageTheme.fontFamily
            font.pixelSize:  WAPageTheme.fontSizeNormal
            wrapMode:        TextEdit.WordWrap
            width:           Math.min(implicitWidth,
                                      root.width * 0.75
                                      - WAPageTheme.bubblePaddingH * 2)
            selectByMouse:        true
            selectedTextColor:    "#FFFFFF"
            selectionColor:       WAPageTheme.accent
            onLinkActivated:      Qt.openUrlExternally(link)
            activeFocusOnPress:   false
            cursorVisible:        false
        }
    }

    Component {
        id: imageComp
        MediaBubble {
            mediaPath:   root.mediaPath.replace(/\\/g, "/")
            mediaType:   "image"
            msgTime:     root.msgTime
            editedText:  root.editedText
            readStatus:  root.readStatus
            isFromMe:    root.isFromMe
        }
    }

    Component {
        id: videoComp
        MediaBubble {
            mediaPath:    root.mediaPath.replace(/\\/g, "/")
            mediaThumbnail: root.mediaThumbnail.replace(/\\/g, "/")
            mediaDuration:  root.mediaDuration
            mediaType:    "video"
            msgTime:      root.msgTime
            editedText:   root.editedText
            readStatus:   root.readStatus
            isFromMe:     root.isFromMe
        }
    }

    Component {
        id: audioComp
        AudioPlayer {
            mediaPath:        root.mediaPath.replace(/\\/g, "/")
            duration:         root.mediaDuration
            isVoice:          root.msgType === "ptt"
            isFromMe:         root.isFromMe
            senderName:       root.sender
            senderAvatarPath: root.senderAvatarPath
            waveform:         root.waveform
            msgId:            root.msgId
            speedStore:       root.audioSpeedStore
            width:            280
            height:           48
        }
    }

    Component {
        id: docComp
        Item {
            id: docRoot
            implicitWidth:  220
            implicitHeight: 60

            Rectangle {
                anchors.fill: parent
                color: "transparent"
                radius: 4

                Row {
                    id: docRow
                    anchors {
                        left:           parent.left
                        verticalCenter: parent.verticalCenter
                        leftMargin:     4
                    }
                    spacing: 10

                    Rectangle {
                        width: 40; height: 40
                        radius: 4
                        color: root.isFromMe ? "#1A5C4A" : "#E0E0E0"
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            anchors.centerIn: parent
                            text: {
                                let name = root.mediaPath.split("/").pop().split("\\").pop()
                                let ext = name.split(".").pop().toUpperCase()
                                return ext.length <= 4 ? ext : "DOC"
                            }
                            color: root.isFromMe ? "#AAFFDD" : "#555555"
                            font.pixelSize: 9
                            font.bold: true
                        }
                    }

                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 2

                        Text {
                            text: {
                                let name = root.mediaPath.length > 0
                                           ? root.mediaPath.split("/").pop().split("\\").pop()
                                           : (langManager.currentTranslations["media_document"] || "Sənəd")
                                return name
                            }
                            color:          root.isFromMe ? WAPageTheme.bubbleSentText
                                                          : WAPageTheme.bubbleRecvText
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeSmall
                            font.bold:      true
                            elide:          Text.ElideMiddle
                            width:          160
                        }

                        Text {
                            text:           langManager.currentTranslations["tap_to_open"] || "Açmaq üçün toxun"
                            color:          root.isFromMe ? WAPageTheme.metaTextSent
                                                          : WAPageTheme.metaTextRecv
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                        }
                    }
                }
            }

            MouseArea {
                anchors.fill: parent
                cursorShape:  Qt.PointingHandCursor
                onClicked: {
                    if (root.mediaPath.length > 0)
                        mediaViewer.openWithSystem(root.mediaPath)
                }
                onPressed: parent.opacity = 0.7
                onReleased: parent.opacity = 1.0
            }
        }
    }

    // ── Sticker — WAPage style (like transparent PNG) ─────────
    Component {
        id: stickerComp
        Item {
            width:  168
            height: 168

            // Qt 6.7.3 imageformats renderer (QImageReader/QMovie)
            StickerMovieItem {
                id: stickerQtImage
                anchors.fill: parent
                playing: true
                visible: status === StickerMovieItem.Ready

                source: {
                    if (root.mediaPath.length === 0) return ""
                    var path = root.mediaPath.replace(/\\/g, "/")
                    return path
                }
            }

            // Loading indicator
            BusyIndicator {
                anchors.centerIn: parent
                running: stickerQtImage.status === StickerMovieItem.Loading
                visible: running
            }

            // Error / empty placeholder
            Column {
                anchors.centerIn: parent
                spacing: 8
                visible: root.mediaPath.length === 0 ||
                         stickerQtImage.status === StickerMovieItem.Error

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           "🎭"
                    font.pixelSize: 56
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           langManager.currentTranslations["media_sticker"] || "Stiker"
                    color:          root.isFromMe ? WAPageTheme.metaTextSent
                                                  : WAPageTheme.metaTextRecv
                    font.pixelSize: WAPageTheme.fontSizeMicro
                    font.family:    WAPageTheme.fontFamily
                }
            }
        }
    }

    // ── Location message — WAPage style map card ──────────────
    Component {
        id: locationComp
        Item {
            width:  240
            height: 160

            // Map background (green gradient + grid pattern)
            Rectangle {
                id: mapBg
                anchors { top: parent.top; left: parent.left; right: parent.right }
                height: 110
                color: "#4CAF93"
                radius: WAPageTheme.bubbleRadius
                clip: true

                // Road lines (decorative)
                Rectangle { x: 20;  y: 40; width: parent.width; height: 2; color: "#ffffff"; opacity: 0.3 }
                Rectangle { x: 0;   y: 70; width: parent.width; height: 2; color: "#ffffff"; opacity: 0.3 }
                Rectangle { x: 60;  y: 0;  width: 2; height: parent.height; color: "#ffffff"; opacity: 0.3 }
                Rectangle { x: 160; y: 0;  width: 2; height: parent.height; color: "#ffffff"; opacity: 0.3 }

                // Location pin
                Column {
                    anchors.centerIn: parent
                    spacing: 0
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "📍"
                        font.pixelSize: 32
                    }
                }
            }

            // Bottom info row
            Rectangle {
                anchors { top: mapBg.bottom; left: parent.left; right: parent.right; bottom: parent.bottom }
                color: root.isFromMe ? WAPageTheme.bubbleSent : WAPageTheme.bubbleReceived
                radius: WAPageTheme.bubbleRadius

                Row {
                    anchors {
                        left: parent.left; right: parent.right
                        verticalCenter: parent.verticalCenter
                        leftMargin: 10; rightMargin: 8
                    }
                    spacing: 6

                    Text {
                        text: "📍"
                        font.pixelSize: 14
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        text: langManager.currentTranslations["location"] || "Məkan"
                        color: root.isFromMe ? WAPageTheme.bubbleSentText
                                             : WAPageTheme.bubbleRecvText
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeSmall
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Item { width: 1; height: 1; Layout.fillWidth: true }

                    // Time
                    Row {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 3
                        Text {
                            visible:        root.editedText !== ""
                            text:           root.editedText
                            color:          root.isFromMe ? WAPageTheme.metaTextSent
                                                         : WAPageTheme.metaTextRecv
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                            font.italic:    true
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Text {
                            text: root.msgTime
                            color: root.isFromMe ? WAPageTheme.metaTextSent
                                                 : WAPageTheme.metaTextRecv
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        TickMark {
                            visible: root.isFromMe
                            readStatus: root.readStatus
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }

            // Click — Open Google Maps
            MouseArea {
                anchors.fill: parent
                cursorShape:  Qt.PointingHandCursor
                onClicked: {
                    let meta = root.mediaMeta
                    let url  = ""
                    // lat,lng format
                    if (meta.match(/^-?\d+\.\d+,-?\d+\.\d+$/)) {
                        url = "https://maps.google.com/?q=" + meta
                    } else if (meta.startsWith("http")) {
                        url = meta
                    } else {
                        url = "https://maps.google.com/?q=" + encodeURIComponent(meta)
                    }
                    Qt.openUrlExternally(url)
                }
            }
        }
    }

    // ── Contact (VCF) message — WAPage style contact card ────
    Component {
        id: contactComp
        Item {
            width:  240
            height: 72

            Rectangle {
                anchors.fill: parent
                color: root.isFromMe ? WAPageTheme.bubbleSent : WAPageTheme.bubbleReceived
                radius: WAPageTheme.bubbleRadius

                Row {
                    anchors {
                        left: parent.left; right: parent.right
                        verticalCenter: parent.verticalCenter
                        leftMargin: 10; rightMargin: 8
                    }
                    spacing: 10

                    // Avatar circle
                    Rectangle {
                        width: 42; height: 42; radius: 21
                        color: "#25D366"
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            anchors.centerIn: parent
                            text: {
                                let name = root.mediaMeta.trim()
                                if (name.length === 0) return "?"
                                let parts = name.split(" ")
                                if (parts.length >= 2)
                                    return (parts[0][0] + parts[1][0]).toUpperCase()
                                return name[0].toUpperCase()
                            }
                            color: "#FFFFFF"
                            font.pixelSize: 16
                            font.bold: true
                            font.family: WAPageTheme.fontFamily
                        }
                    }

                    // Name + type
                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 2

                        Text {
                            text: root.mediaMeta.length > 0 ? root.mediaMeta : "Kontakt"
                            color: root.isFromMe ? WAPageTheme.bubbleSentText
                                                 : WAPageTheme.bubbleRecvText
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            font.bold:      true
                            elide:          Text.ElideRight
                            width:          150
                        }
                        Text {
                            text: "WAPage " + (langManager.currentTranslations["contact"] || "Kontaktı")
                            color: root.isFromMe ? WAPageTheme.metaTextSent
                                                 : WAPageTheme.metaTextRecv
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                        }
                    }
                }



                Row {
                    anchors {
                        right:  parent.right
                        bottom: parent.bottom
                        rightMargin:  8
                        bottomMargin: 4
                    }
                    spacing: 3
                    Text {
                        visible:        root.editedText !== ""
                        text:           root.editedText
                        color:          root.isFromMe ? WAPageTheme.metaTextSent
                                                     : WAPageTheme.metaTextRecv
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeMicro
                        font.italic:    true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Text {
                        text: root.msgTime
                        color: root.isFromMe ? WAPageTheme.metaTextSent
                                             : WAPageTheme.metaTextRecv
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeMicro
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    TickMark {
                        visible: root.isFromMe
                        readStatus: root.readStatus
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }

            // Click — Open the VCF file directly
            MouseArea {
                anchors.fill: parent
                cursorShape:  Qt.PointingHandCursor
                onClicked: {
                    if (root.mediaPath.length > 0)
                        mediaViewer.openWithSystem(root.mediaPath)
                }
            }
        }
    }

    // Omitted placeholders
    Component {
        id: omittedVideoComp
        Item {
            implicitWidth: 280
            implicitHeight: 48
            
            Row {
                spacing: 8
                padding: 8
                anchors.verticalCenter: parent.verticalCenter
                Text { text: "🎬"; font.pixelSize: 20; anchors.verticalCenter: parent.verticalCenter }
                Column {
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 2
                    Text {
                        text: langManager.currentTranslations["media_video"] || "Video"
                        color: root.isFromMe ? WAPageTheme.bubbleSentText : WAPageTheme.bubbleRecvText
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeSmall
                        font.bold: true
                    }
                    Text {
                        text: langManager.currentTranslations["media_unavailable"] || "Media mövcud deyil"
                        color: root.isFromMe ? WAPageTheme.metaTextSent : WAPageTheme.metaTextRecv
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeMicro
                    }
                }
            }
        }
    }

    Component {
        id: omittedImageComp
        Row {
            spacing: 8
            padding: 8
            Text { text: "🖼"; font.pixelSize: 20; anchors.verticalCenter: parent.verticalCenter }
            Column {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2
                Text {
                    text: langManager.currentTranslations["media_image"] || "Şəkil"
                    color: root.isFromMe ? WAPageTheme.bubbleSentText : WAPageTheme.bubbleRecvText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    font.bold: true
                }
                Text {
                    text: langManager.currentTranslations["media_unavailable"] || "Media mövcud deyil"
                    color: root.isFromMe ? WAPageTheme.metaTextSent : WAPageTheme.metaTextRecv
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
            }
        }
    }

    Component {
        id: omittedAudioComp
        Row {
            spacing: 8
            padding: 8
            // Microphone icon - for voice message
            Rectangle {
                width: 24; height: 24
                radius: 12
                color: root.isFromMe ? "#005C4B" : "#E0E0E0"
                anchors.verticalCenter: parent.verticalCenter
                
                Text {
                    anchors.centerIn: parent
                    text: root.msgType === "ptt" ? "🎤" : "🎵"
                    font.pixelSize: 14
                }
            }
            Column {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2
                Text {
                    text: root.msgType === "ptt" ? (langManager.currentTranslations["media_voice"] || "Səs mesajı") : (langManager.currentTranslations["media_audio"] || "Audio")
                    color: root.isFromMe ? WAPageTheme.bubbleSentText : WAPageTheme.bubbleRecvText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    font.bold: true
                }
                Text {
                    text: langManager.currentTranslations["media_unavailable"] || "Media mövcud deyil"
                    color: root.isFromMe ? WAPageTheme.metaTextSent : WAPageTheme.metaTextRecv
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
            }
        }
    }

    Component {
        id: omittedStickerComp
        Row {
            spacing: 8
            padding: 8
            Text { text: "🎭"; font.pixelSize: 20; anchors.verticalCenter: parent.verticalCenter }
            Column {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2
                Text {
                    text: langManager.currentTranslations["media_sticker"] || "Stiker"
                    color: root.isFromMe ? WAPageTheme.bubbleSentText : WAPageTheme.bubbleRecvText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    font.bold: true
                }
                Text {
                    text: langManager.currentTranslations["media_unavailable"] || "Media mövcud deyil"
                    color: root.isFromMe ? WAPageTheme.metaTextSent : WAPageTheme.metaTextRecv
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
            }
        }
    }

    Component {
        id: omittedDocComp
        Row {
            spacing: 8
            padding: 8
            Text { text: "📄"; font.pixelSize: 20; anchors.verticalCenter: parent.verticalCenter }
            Column {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2
                Text {
                    text: langManager.currentTranslations["media_document"] || "Sənəd"
                    color: root.isFromMe ? WAPageTheme.bubbleSentText : WAPageTheme.bubbleRecvText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    font.bold: true
                }
                Text {
                    text: langManager.currentTranslations["media_unavailable"] || "Media mövcud deyil"
                    color: root.isFromMe ? WAPageTheme.metaTextSent : WAPageTheme.metaTextRecv
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
            }
        }
    }

    Component {
        id: deletedComp
        Row {
            spacing: 6
            Image {
                source: "qrc:/assets/icon_blocked.svg"
                width: 14; height: 14
                opacity: 0.5
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                text: {
                    const c = root.formattedContent
                    if (c === "__deleted_by_me__")
                        return langManager.currentTranslations["you_deleted_message"] || "You deleted this message"
                    if (c === "__deleted__" || c === "")
                        return langManager.currentTranslations["deleted_message"] || "This message was deleted"
                    // Legacy: pre-existing DB records with translated text — show as-is
                    return c
                }
                color:          root.isFromMe ? WAPageTheme.metaTextSent
                                              : WAPageTheme.metaTextRecv
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeNormal
                font.italic:    true
            }
        }
    }

    Component {
        id: systemComp
        Item {
            height: 36
            width:  parent.width
            Rectangle {
                anchors.centerIn: parent
                implicitWidth:  sysLabel.implicitWidth + 24
                implicitHeight: sysLabel.implicitHeight + 10
                radius:         14
                color:          WAPageTheme.dateSepBg
                Text {
                    id: sysLabel
                    anchors.centerIn: parent
                    text:            root.formattedContent
                    color:           WAPageTheme.dateSepText
                    font.family:     WAPageTheme.fontFamily
                    font.pixelSize:  WAPageTheme.fontSizeMicro
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}
