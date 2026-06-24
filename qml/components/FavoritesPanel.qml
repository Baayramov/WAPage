import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Favorites panel - shows starred/favorited messages with full MessageBubble display
Rectangle {
    id: root
    color: "transparent" // Make background transparent to show wallpaper
    
    // Wallpaper background - same as MessagePanel
    Image {
        id: wallpaper
        anchors.fill: parent
        source: WAPageTheme.dark
                ? "qrc:/assets/wallpaper_dark.svg"
                : "qrc:/assets/wallpaper_light.svg"
        fillMode: Image.Tile
        z: -1
    }

    // Function to close and return to chat list
    function close() {
        chatListPanelRef.showFavorites = false
    }
    
    // Reference to ChatListPanel (will be set by ChatListPanel)
    property var chatListPanelRef: null
    
    // Track if panel is visible to reload on show
    onVisibleChanged: {
        if (visible) {
            // Reload favorites when panel becomes visible
            // This ensures profile pictures are up-to-date
            loadFavorites()
        }
    }

    // Header
    Rectangle {
        id: header
        width: parent.width
        height: WAPageTheme.headerHeight
        color: WAPageTheme.headerBg
        z: 1

        // Back button
        Rectangle {
            id: backBtn
            width: 40
            height: 40
            radius: 20
            color: backBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"
            anchors {
                left: parent.left
                leftMargin: 16
                verticalCenter: parent.verticalCenter
            }

            Behavior on color {
                ColorAnimation { duration: 150 }
            }

            Image {
                id: backIcon
                anchors.centerIn: parent
                source: "qrc:/assets/icon_arrow_left.svg"
                width: 22
                height: 22
                sourceSize: Qt.size(22, 22)
                visible: false
            }

            ColorOverlay {
                anchors.fill: backIcon
                source: backIcon
                color: "#FFFFFF"
                opacity: backBtnMouse.containsMouse ? 1.0 : 0.85

                Behavior on opacity {
                    NumberAnimation { duration: 150 }
                }
            }

            MouseArea {
                id: backBtnMouse
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: root.close()
            }
        }

        // Title
        RowLayout {
            anchors {
                left: backBtn.right
                leftMargin: 12
                right: parent.right
                rightMargin: 16
                verticalCenter: parent.verticalCenter
            }
            spacing: 12

            Image {
                id: starIconHeader
                source: "qrc:/assets/star.svg"
                width: 24
                height: 24
                sourceSize: Qt.size(24, 24)
                visible: false
                Layout.alignment: Qt.AlignVCenter
            }

            ColorOverlay {
                width: 24
                height: 24
                source: starIconHeader
                color: "#FFFFFF"
                Layout.alignment: Qt.AlignVCenter
            }

            Text {
                text: langManager.currentTranslations["favorites"] || "Favoritlər"
                color: "#FFFFFF"
                font.family: WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeLarge
                font.weight: Font.DemiBold
                Layout.fillWidth: true
            }
        }
    }

    // Favorites list - using MessageBubble components
    ListView {
        id: favoritesList
        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        clip: true
        model: ListModel { id: favoritesModel }
        spacing: 16

        // Audio speed storage map (for voice message playback)
        property var audioSpeedMap: ({})

        delegate: Item {
            id: favoriteDelegate
            width: favoritesList.width
            // Dynamic height based on message type and content
            height: {
                let baseHeight = bubbleWrapper.height + headerRow.height + 16 // bubble + header + spacing
                return baseHeight
            }

            // Chat header row (chat name + avatar + actions)
            Rectangle {
                id: headerRow
                width: parent.width
                height: 56
                color: "transparent"
                anchors.top: parent.top

                MouseArea {
                    id: headerHoverArea
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        if (model && model.chatId !== undefined && model.messageId !== undefined) {
                            mainWindow.jumpToFavoriteMessage(model.chatId, model.messageId)
                        }
                    }
                }

                Rectangle {
                    anchors.fill: parent
                    color: headerHoverArea.containsMouse 
                           ? Qt.rgba(0, 0, 0, WAPageTheme.dark ? 0.2 : 0.05)
                           : Qt.rgba(0, 0, 0, WAPageTheme.dark ? 0.1 : 0.02)
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: 12
                        anchors.rightMargin: 12
                        spacing: 12

                        // Chat/Sender Avatar (sync with message context)
                        AvatarCircle {
                            size: 40
                            avatarPath: {
                                // For received messages (not from me), show sender avatar
                                if (!model.isFromMe && model.sender && model.sender.trim().length > 0) {
                                    return model.senderAvatar || ""
                                }
                                // For messages from me in DIRECT chats, show chat avatar (the other person)
                                // For messages from me in GROUP chats, show my avatar (senderAvatar)
                                if (model.isFromMe) {
                                    if (model.isGroupChat) {
                                        // In groups, show my avatar
                                        return model.senderAvatar || ""
                                    } else {
                                        // In direct chats, show the other person's avatar (chat avatar)
                                        return model.chatAvatar || ""
                                    }
                                }
                                // Fallback to chat avatar
                                return model.chatAvatar || ""
                            }
                            initials: {
                                // For received messages, use sender name
                                if (!model.isFromMe && model.sender && model.sender.trim().length > 0) {
                                    return getInitials(model.sender)
                                }
                                // For messages from me in groups, use "ME"
                                if (model.isFromMe && model.isGroupChat) {
                                    return "ME"
                                }
                                // For direct chats or default, use chat name
                                return getInitials(model.chatName || "")
                            }
                            avatarColor: {
                                // For received messages, use sender name color
                                if (!model.isFromMe && model.sender && model.sender.trim().length > 0) {
                                    return getColor(model.sender)
                                }
                                // For messages from me in groups, use consistent color
                                if (model.isFromMe && model.isGroupChat) {
                                    return "#00BFA5" // WhatsApp green
                                }
                                // For direct chats or default, use chat name color
                                return getColor(model.chatName || "")
                            }
                            Layout.alignment: Qt.AlignVCenter
                        }

                        // Chat/Sender name + timestamp
                        ColumnLayout {
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignVCenter
                            spacing: 2

                            // Show sender name for received messages, chat name for sent messages
                            Text {
                                text: {
                                    // If message is from me, show chat name
                                    if (model.isFromMe) {
                                        return model.chatName || ""
                                    }
                                    // If message is received, show sender name
                                    if (model.sender && model.sender.trim().length > 0) {
                                        return model.sender
                                    }
                                    // Fallback to chat name
                                    return model.chatName || ""
                                }
                                color: WAPageTheme.chatListText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                                font.weight: Font.DemiBold
                                elide: Text.ElideRight
                                Layout.fillWidth: true
                            }

                            Text {
                                text: formatTimestamp(model.timestamp)
                                color: WAPageTheme.chatListSubText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeSmall
                            }
                        }

                        // Jump button
                        MouseArea {
                            id: jumpMouseArea
                            width: 36
                            height: 36
                            hoverEnabled: true
                            cursorShape: Qt.PointingHandCursor
                            Layout.alignment: Qt.AlignVCenter
                            
                            onClicked: {
                                if (model && model.chatId !== undefined && model.messageId !== undefined) {
                                    mainWindow.jumpToFavoriteMessage(model.chatId, model.messageId)
                                }
                            }

                            Rectangle {
                                anchors.fill: parent
                                radius: 18
                                color: jumpMouseArea.containsMouse ? Qt.rgba(0, 0.5, 1, 0.1) : "transparent"
                            }

                            Image {
                                id: jumpIcon
                                anchors.centerIn: parent
                                source: "qrc:/assets/icon_open_external.svg"
                                width: 18
                                height: 18
                                sourceSize: Qt.size(18, 18)
                                visible: false
                            }

                            ColorOverlay {
                                anchors.fill: jumpIcon
                                source: jumpIcon
                                color: jumpMouseArea.containsMouse ? "#0088FF" : WAPageTheme.iconColor
                            }
                        }

                        // Remove button
                        MouseArea {
                            id: removeMouseArea
                            width: 36
                            height: 36
                            hoverEnabled: true
                            cursorShape: Qt.PointingHandCursor
                            Layout.alignment: Qt.AlignVCenter
                            
                            onClicked: {
                                if (model && model.chatId !== undefined && model.messageId !== undefined) {
                                    mainWindow.removeFromFavorites(model.chatId, model.messageId)
                                    // Don't reload here - wait for favoritesChanged signal to avoid race condition
                                }
                            }

                            Rectangle {
                                anchors.fill: parent
                                radius: 18
                                color: removeMouseArea.containsMouse ? Qt.rgba(1, 0, 0, 0.1) : "transparent"
                            }

                            Image {
                                id: removeIcon
                                anchors.centerIn: parent
                                source: "qrc:/assets/icon_close.svg"
                                width: 18
                                height: 18
                                sourceSize: Qt.size(18, 18)
                                visible: false
                            }

                            ColorOverlay {
                                anchors.fill: removeIcon
                                source: removeIcon
                                color: removeMouseArea.containsMouse ? "#FF0000" : WAPageTheme.iconColor
                            }
                        }
                    }
                }
            }

            // Message bubble wrapper
            Item {
                id: bubbleWrapper
                width: parent.width
                height: messageBubble.height
                anchors.top: headerRow.bottom
                anchors.topMargin: 4

                // Use actual MessageBubble component
                MessageBubble {
                    id: messageBubble
                    width: parent.width
                    
                    // Pass all required properties from model
                    isGroupChat: model.isGroupChat || false
                    msgId: model.msgId || -1
                    audioSpeedStore: favoritesList.audioSpeedMap
                    isFromMe: model.isFromMe || false
                    formattedContent: model.formattedContent || ""
                    msgTime: model.msgTime || ""
                    sender: model.sender || ""
                    senderAvatarPath: model.senderAvatar || ""
                    msgDate: model.msgDate || ""
                    readStatus: model.readStatus || 0
                    isFirstInGroup: model.isFirstInGroup !== undefined ? model.isFirstInGroup : true
                    isLastInGroup: model.isLastInGroup !== undefined ? model.isLastInGroup : true
                    msgType: model.msgType || "text"
                    mediaPath: model.mediaPath || ""
                    mediaThumbnail: model.mediaThumbnail || ""
                    mediaDuration: model.mediaDuration || ""
                    mediaMeta: model.mediaMeta || ""
                    waveform: model.waveform || ""
                    editedText: {
                        if (model.editedText === "1") {
                            return langManager.currentTranslations["edited"] || "Edited"
                        } else if (model.editedText && model.editedText !== "" && model.editedText !== "0") {
                            return langManager.currentTranslations["edited"] || model.editedText
                        }
                        return ""
                    }
                    showDate: model.showDate !== undefined ? model.showDate : false
                }
            }

            // Separator line
            Rectangle {
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 12
                anchors.rightMargin: 12
                height: 1
                color: WAPageTheme.divider
                opacity: 0.5
            }
        }

        // Empty state
        Item {
            visible: favoritesModel.count === 0
            anchors.fill: parent
            z: 10

            Column {
                anchors.centerIn: parent
                spacing: 16
                width: Math.min(parent.width - 32, 300)

                Item {
                    width: 80
                    height: 80
                    anchors.horizontalCenter: parent.horizontalCenter

                    // Show star icon with natural gold color (no overlay)
                    Image {
                        anchors.centerIn: parent
                        source: "qrc:/assets/star.svg"
                        width: 80
                        height: 80
                        sourceSize: Qt.size(80, 80)
                        opacity: 0.5
                    }
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: langManager.currentTranslations["no_favorites"] || "Favoritlər yoxdur"
                    color: WAPageTheme.chatListText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeLarge
                    font.weight: Font.DemiBold
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: langManager.currentTranslations["favorites_hint"] || "Mesaja sağ klik edib favorilərə əlavə edin"
                    color: WAPageTheme.chatListSubText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    opacity: 0.8
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                    width: parent.width
                }
            }
        }
    }

    function loadFavorites() {
        // Get fresh favorites data
        const favorites = mainWindow.getAllFavorites()
        
        // Clear existing model completely
        favoritesModel.clear()
        
        // Rebuild model with fresh data, EXCLUDING locked chats
        for (let i = 0; i < favorites.length; i++) {
            const fav = favorites[i]
            // Skip favorites from locked chats
            if (!mainWindow.isChatLocked(fav.chatId)) {
                favoritesModel.append(fav)
            }
        }
    }

    function formatTimestamp(dt) {
        if (!dt) return ""
        const now = new Date()
        const msgDate = new Date(dt)
        const diffDays = Math.floor((now - msgDate) / (1000 * 60 * 60 * 24))
        
        if (diffDays === 0) {
            return Qt.formatTime(msgDate, "HH:mm")
        } else if (diffDays < 7) {
            return Qt.formatDate(msgDate, "dd.MM")
        } else {
            return Qt.formatDate(msgDate, "dd.MM.yyyy")
        }
    }

    function getInitials(name) {
        if (!name || name.trim().length === 0) return "?"
        // Strip tilde prefix for initials calculation (iOS/Android compatibility)
        let cleanName = name.trim()
        if (cleanName.startsWith("~ ")) {
            cleanName = cleanName.substring(2).trim()
        } else if (cleanName.startsWith("~")) {
            cleanName = cleanName.substring(1).trim()
        }
        if (cleanName.length === 0) return "?"
        const parts = cleanName.split(/\s+/)
        if (parts.length === 1) return parts[0].slice(0, 2).toUpperCase()
        return (parts[0][0] + parts[1][0]).toUpperCase()
    }

    function getColor(name) {
        const palette = [
            "#D4371C", "#E65100", "#BF360C", "#AD1457",
            "#880E4F", "#6A1B9A", "#4527A0", "#1565C0",
            "#0277BD", "#00695C", "#2E7D32", "#558B2F",
            "#F57F17", "#4E342E", "#37474F", "#00897B"
        ]
        // Strip tilde prefix for consistent color across tilde/no-tilde variants
        let text = name || ""
        if (text.startsWith("~ ")) {
            text = text.substring(2).trim()
        } else if (text.startsWith("~")) {
            text = text.substring(1).trim()
        }
        let hash = 0
        for (let i = 0; i < text.length; ++i) {
            hash = ((hash * 31) + text.charCodeAt(i)) & 0x7fffffff
        }
        return palette[hash % palette.length]
    }

    Component.onCompleted: loadFavorites()

    Connections {
        target: mainWindow
        function onFavoritesChanged() {
            loadFavorites()
        }
        
        // Reload when profile library changes (profile pictures updated in Settings)
        function onProfileLibraryChanged() {
            if (root.visible) {
                loadFavorites()
            }
        }
        
        // Reload when active chat changes (chat might be deleted)
        function onActiveChatChanged() {
            if (root.visible) {
                loadFavorites()
            }
        }
    }
    
    // Listen to chat model changes (chat deleted)
    Connections {
        target: mainWindow.chatModel
        function onRowsRemoved() {
            if (root.visible) {
                loadFavorites()
            }
        }
    }
}
