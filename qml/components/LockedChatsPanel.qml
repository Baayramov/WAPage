import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Locked chats panel - uses SAME ChatListModel as main panel with filter
Rectangle {
    id: root
    color: WAPageTheme.chatListBg

    // Reference to ChatListPanel (will be set by ChatListPanel)
    property var chatListPanelRef: null
    
    // Function to close and return to main chat list
    function close() {
        chatListPanelRef.showLockedChats = false
        // Note: onVisibleChanged will handle clearing active chat
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // ── Header ──────────────────────────────────────────────
        Rectangle {
            Layout.fillWidth: true
            height: WAPageTheme.headerHeight
            color: WAPageTheme.headerBg

            // Back button - on the left
            Rectangle {
                id: backBtn
                anchors {
                    left: parent.left
                    leftMargin: 16
                    verticalCenter: parent.verticalCenter
                }
                width: 40
                height: 40
                radius: 20
                color: backBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                property bool tooltipEnabled: true

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
                    color: WAPageTheme.headerText
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
                    onClicked: {
                        backBtn.tooltipEnabled = false
                        root.close()
                    }
                    onExited: {
                        backBtn.tooltipEnabled = true
                    }
                }

                ToolTip {
                    id: backToolTip
                    visible: backBtnMouse.containsMouse && backBtn.tooltipEnabled
                    text: langManager.currentTranslations["back"] || "Geri"
                    delay: 500
                    padding: 8
                    
                    background: Rectangle {
                        color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                        radius: 4
                        border.width: 0
                    }
                    
                    contentItem: Text {
                        text: backToolTip.text
                        color: "#FFFFFF"
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: 12
                    }
                }
            }

            // Title with Lock Icon
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
                    id: lockIconHeader
                    source: "qrc:/assets/lock.svg"
                    width: 22
                    height: 22
                    sourceSize: Qt.size(22, 22)
                    visible: false
                    Layout.alignment: Qt.AlignVCenter
                }

                ColorOverlay {
                    width: 22
                    height: 22
                    source: lockIconHeader
                    color: "#FFFFFF"
                    Layout.alignment: Qt.AlignVCenter
                }

                Text {
                    text: langManager.currentTranslations["locked_chats"] || "Kilidlənmiş Söhbətlər"
                    color: "#FFFFFF"
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeLarge
                    font.weight: Font.DemiBold
                    Layout.fillWidth: true
                }
            }
        }

        // Search area
        Rectangle {
            Layout.fillWidth: true
            height: 50
            color: WAPageTheme.chatListBg

            Rectangle {
                anchors {
                    fill: parent
                    margins: 8
                }
                radius: 8
                color: WAPageTheme.searchBg

                Row {
                    anchors {
                        fill: parent
                        leftMargin: 12
                        rightMargin: 12
                    }
                    spacing: 8

                    // Search icon
                    Item {
                        width: 16
                        height: 16
                        anchors.verticalCenter: parent.verticalCenter

                        Image {
                            id: chatSearchIcon
                            anchors.fill: parent
                            source: "qrc:/assets/icon_search.svg"
                            sourceSize: Qt.size(16, 16)
                            visible: false
                        }

                        ColorOverlay {
                            anchors.fill: chatSearchIcon
                            source: chatSearchIcon
                            color: WAPageTheme.iconColor
                            opacity: 0.7
                        }
                    }

                    TextField {
                        id: chatSearchInput
                        width: parent.width - 36
                        anchors.verticalCenter: parent.verticalCenter
                        color: WAPageTheme.searchText
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeNormal
                        placeholderText: langManager.currentTranslations["chat_search_placeholder"] || "Axtar..."
                        placeholderTextColor: WAPageTheme.searchPlaceholder
                        background: Item {}
                        onTextChanged: {
                            // Use SAME search system as main chat list
                            mainWindow.chatModel.setSearchQuery(text)
                        }

                        Keys.onEscapePressed: {
                            clear()
                            mainWindow.chatModel.clearSearch()
                        }
                    }
                }
            }
        }

        // Chat List - Uses SAME performant ChatListModel as main panel
        ListView {
            id: chatList
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: mainWindow.chatModel // DIRECT connection to C++ model!
            clip: true
            currentIndex: -1

            property int visibleLockedCount: 0

            // EXACT SAME smooth scrolling config as ChatListPanel
            interactive: true
            flickableDirection: Flickable.VerticalFlick
            boundsBehavior: Flickable.DragAndOvershootBounds
            boundsMovement: Flickable.FollowBoundsBehavior
            flickDeceleration: 600
            maximumFlickVelocity: 8000
            pressDelay: 0
            pixelAligned: true
            cacheBuffer: 10000 // Eager measurement (same as main list)
            smooth: true

            // Bounce areas (same as main list)
            header: Item { height: 20; width: chatList.width }
            footer: Item { height: 40; width: chatList.width }

            // Mouse Wheel Bounce Transform (same as main list)
            transform: Translate { y: wheelBounce.yOffset }

            MouseWheelHandler {
                id: wheelBounce
                target: chatList
                anchors.fill: parent
                overshootAmount: 40
            }

            ScrollBar.vertical: ScrollBar {
                policy: ScrollBar.AlwaysOff
                interactive: false
            }

            delegate: ChatListItem {
                width: chatList.width
                // Only show LOCKED chats that match search
                height: (model.isLocked && model.matchesSearch) ? 72 : 0
                visible: (model.isLocked && model.matchesSearch)
                enabled: (model.isLocked && model.matchesSearch)
                chatId: model.chatId
                contactName: model.contactName
                lastMessage: model.lastMessage
                lastTime: model.lastMessageTime
                avatarPath: model.avatarPath
                initials: model.initials
                avatarColor: model.avatarColor
                isSelected: chatList.currentIndex === index  // Selected state (like normal chats)
                
                onClicked: {
                    chatList.currentIndex = index  // Set currentIndex for selection highlight
                    mainWindow.selectChat(model.chatId)
                }
            }

            function updateVisibleCount() {
                let count = 0
                const model = mainWindow.chatModel
                if (model) {
                    for (let i = 0; i < model.rowCount(); i++) {
                        const idx = model.index(i, 0)
                        const isLocked = model.data(idx, 266) // IsLockedRole
                        const matchesSearch = model.data(idx, 265) // MatchesSearchRole
                        if (isLocked && matchesSearch) {
                            count++
                        }
                    }
                }
                visibleLockedCount = count
            }

            // Initial count when model is ready
            Component.onCompleted: {
                Qt.callLater(updateVisibleCount)
            }

            // Update when model changes
            Connections {
                target: mainWindow.chatModel
                function onDataChanged() {
                    Qt.callLater(chatList.updateVisibleCount)
                }
                function onModelReset() {
                    Qt.callLater(chatList.updateVisibleCount)
                }
            }

            // Empty state
            Item {
                visible: chatList.visibleLockedCount === 0
                anchors.fill: parent
                z: 10

                Column {
                    anchors.centerIn: parent
                    spacing: 16
                    width: Math.min(parent.width - 32, 300)

                    Image {
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: "qrc:/assets/lock.svg"
                        width: 80
                        height: 80
                        sourceSize: Qt.size(80, 80)
                        opacity: 0.3
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: langManager.currentTranslations["no_locked_chats"] || "Kilidlənmiş söhbət yoxdur"
                        color: WAPageTheme.chatListText
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeLarge
                        font.weight: Font.DemiBold
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: langManager.currentTranslations["locked_chats_hint"] || "Söhbəti kilitləmək üçün 3 nöqtə menyusundan 'Söhbəti kilitlə' seçin"
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
    }

    // Clear active chat when entering/leaving locked panel
    onVisibleChanged: {
        if (visible) {
            // Entering locked chats panel - always clear active chat (show welcome screen)
            if (mainWindow.activeChatId >= 0) {
                mainWindow.selectChat(-1)
            }
            // Update visible count
            Qt.callLater(function() {
                chatList.updateVisibleCount()
            })
        } else {
            // Leaving locked chats panel - always clear active chat (show welcome screen)
            if (mainWindow.activeChatId >= 0) {
                mainWindow.selectChat(-1)
            }
            // Clear search
            chatSearchInput.text = ""
            mainWindow.chatModel.clearSearch()
        }
    }
    
    // Update count when model changes
    Connections {
        target: mainWindow.chatModel
        function onDataChanged() {
            Qt.callLater(function() {
                chatList.updateVisibleCount()
            })
        }
        function onRowsInserted() {
            Qt.callLater(function() {
                chatList.updateVisibleCount()
            })
        }
        function onRowsRemoved() {
            Qt.callLater(function() {
                chatList.updateVisibleCount()
            })
        }
    }
}
