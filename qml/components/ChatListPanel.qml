import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Left panel — like the left panel of WAPage Web
Rectangle {
    id: root
    color: WAPageTheme.chatListBg

    // Expose SettingsView to main.qml so that it can connect the openLangDialog signal
    property alias settingsViewRef: settingsView

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // ── Header ──────────────────────────────────────────────
        Rectangle {
            Layout.fillWidth: true
            height: WAPageTheme.headerHeight
            color:  WAPageTheme.headerBg

            // User's global profile avatar — on the left
            AvatarCircle {
                anchors {
                    left: parent.left
                    leftMargin: 16
                    verticalCenter: parent.verticalCenter
                }
                size: 40
                avatarPath: mainWindow.myAvatar
                initials: "M"
                avatarColor: "#25D366" // The default for me is green

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: settingsView.open()
                }
            }

            // Buttons - on the right side
            Row {
                anchors {
                    right: parent.right
                    rightMargin: 10
                    verticalCenter: parent.verticalCenter
                }
                spacing: 0

                // Theme toggle button - WAPage style
                Rectangle {
                    id: themeBtn
                    width: 40
                    height: 40
                    radius: 20
                    color: themeBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }

                    Image {
                        id: themeIcon
                        anchors.centerIn: parent
                        source: mainWindow.isDarkTheme
                                ? "qrc:/assets/icon_sun.svg"
                                : "qrc:/assets/icon_moon.svg"
                        width: 22
                        height: 22
                        sourceSize: Qt.size(22, 22)
                        visible: false
                    }

                    ColorOverlay {
                        anchors.fill: themeIcon
                        source: themeIcon
                        color: WAPageTheme.headerText
                        opacity: themeBtnMouse.containsMouse ? 1.0 : 0.85

                        Behavior on opacity {
                            NumberAnimation { duration: 150 }
                        }
                    }

                    MouseArea {
                        id: themeBtnMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: mainWindow.isDarkTheme = !mainWindow.isDarkTheme
                    }

                    ToolTip {
                        id: themeToolTip
                        visible: themeBtnMouse.containsMouse
                        text: mainWindow.isDarkTheme ? langManager.currentTranslations["light_theme"] : langManager.currentTranslations["dark_theme"]
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                            border.width: 0
                        }
                        
                        contentItem: Text {
                            text: themeToolTip.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: 12
                        }
                    }
                }

                // New chat button - WAPage style
                Rectangle {
                    id: newChatBtn
                    width: 40
                    height: 40
                    radius: 20
                    color: newChatBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }

                    Image {
                        id: newChatIcon
                        anchors.centerIn: parent
                        source: "qrc:/assets/add.svg"
                        width: 22
                        height: 22
                        sourceSize: Qt.size(22, 22)
                        visible: false
                    }

                    ColorOverlay {
                        anchors.fill: newChatIcon
                        source: newChatIcon
                        color: WAPageTheme.headerText
                        opacity: newChatBtnMouse.containsMouse ? 1.0 : 0.85

                        Behavior on opacity {
                            NumberAnimation { duration: 150 }
                        }
                    }

                    MouseArea {
                        id: newChatBtnMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: importDlg.visible = true
                    }

                    ToolTip {
                        id: newChatToolTip
                        visible: newChatBtnMouse.containsMouse
                        text: langManager.currentTranslations["new_chat_tooltip"]
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                            border.width: 0
                        }
                        
                        contentItem: Text {
                            text: newChatToolTip.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: 12
                        }
                    }
                }
            }
        }

        // Search area
        Rectangle {
            Layout.fillWidth: true
            height: 50
            color:  WAPageTheme.chatListBg

            Rectangle {
                anchors {
                    fill:    parent
                    margins: 8
                }
                radius: 8
                color:  WAPageTheme.searchBg

                Row {
                    anchors {
                        fill:        parent
                        leftMargin:  12
                        rightMargin: 12
                    }
                    spacing: 8

                    // Search icon - WAPage style
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
                        width:              parent.width - 36
                        anchors.verticalCenter: parent.verticalCenter
                        color:              WAPageTheme.searchText
                        font.family:        WAPageTheme.fontFamily
                        font.pixelSize:     WAPageTheme.fontSizeNormal
                        placeholderText:    langManager.currentTranslations["chat_search_placeholder"]
                        placeholderTextColor: WAPageTheme.searchPlaceholder
                        background:         Item {}
                        onTextChanged:      mainWindow.chatModel.setSearchQuery(text)

                        Keys.onEscapePressed: {
                            clear()
                            mainWindow.chatModel.clearSearch()
                        }
                    }
                }
            }
        }

        // Chat List Chat List
        ListView {
            id: chatList
            Layout.fillWidth:  true
            Layout.fillHeight: true
            model:             mainWindow.chatModel
            clip:              true
            currentIndex:      -1

            // Completely smooth and symmetrical scrolling "like on the phone".
            interactive:        true
            flickableDirection: Flickable.VerticalFlick
            boundsBehavior:     Flickable.DragAndOvershootBounds
            boundsMovement:     Flickable.FollowBoundsBehavior 
            flickDeceleration:  600  
            maximumFlickVelocity: 8000 
            pressDelay:         0
            pixelAligned:       true 
            cacheBuffer:        10000 // Eager measurement for chat list
            smooth:             true 
            
            // Bounce area on top and bottom edge
            header: Item { height: 20; width: chatList.width }
            footer: Item { height: 40; width: chatList.width } // Fixed footer landing pad

            // Mouse Wheel Bounce Transform (C++ / Desktop specific)
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
                width:        chatList.width
                height:       model.matchesSearch ? 72 : 0
                visible:      model.matchesSearch
                enabled:      model.matchesSearch
                chatId:       model.chatId
                contactName:  model.contactName
                lastMessage:  model.lastMessage
                lastTime:     model.lastMessageTime
                avatarPath:   model.avatarPath
                initials:     model.initials
                avatarColor:  model.avatarColor
                isSelected:   chatList.currentIndex === index

                onClicked: {
                    chatList.currentIndex = index
                    mainWindow.selectChat(model.chatId)
                }
            }

            // empty state
            Text {
                anchors.centerIn: parent
                visible:          mainWindow.chatModel.visibleCount === 0
                text:             chatSearchInput.text.trim().length > 0
                                  ? langManager.currentTranslations["no_results"]
                                  : langManager.currentTranslations["no_chats"]
                color:            WAPageTheme.chatListSubText
                font.family:      WAPageTheme.fontFamily
                font.pixelSize:   WAPageTheme.fontSizeNormal
                horizontalAlignment: Text.AlignHCenter
                lineHeight:       1.5
            }
        }
    }

    SettingsView {
        id: settingsView
        anchors.fill: parent
        visible: false
    }
}
