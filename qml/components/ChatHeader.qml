import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Top right panel — contact name, avatar, search button
Rectangle {
    id: root
    height: WAPageTheme.headerHeight
    color:  WAPageTheme.headerBg

    signal profileClicked()
    signal searchClicked()
    signal calendarClicked()
    signal firstMessageRequested()
    signal lastMessageRequested()
    signal deleteRequested()

    Item {
        anchors {
            fill:           parent
            leftMargin:     16
            rightMargin:    8
        }

        // Profile MouseArea — first declare that toolButtons are not on top
        MouseArea {
            id: profileArea
            anchors {
                left:   parent.left
                right:  toolButtons.left
                top:    parent.top
                bottom: parent.bottom
            }
            cursorShape:     Qt.PointingHandCursor
            onClicked:       root.profileClicked()
        }

        // Right buttons
        Row {
            id: toolButtons
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            spacing: 4

            // Calendar button - WAPage style
            Rectangle {
                id: headerCalendarBtn
                width: 40
                height: 40
                radius: 20
                color: headerCalendarBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"
                anchors.verticalCenter: parent.verticalCenter

                property bool tooltipEnabled: true

                Behavior on color {
                    ColorAnimation { duration: 150 }
                }

                Image {
                    id: headerCalendarIcon
                    anchors.centerIn: parent
                    source: "qrc:/assets/icon_calendar.svg"
                    width: 22
                    height: 22
                    sourceSize: Qt.size(22, 22)
                    visible: false
                }

                ColorOverlay {
                    anchors.fill: headerCalendarIcon
                    source: headerCalendarIcon
                    color: WAPageTheme.headerText
                    opacity: headerCalendarBtnMouse.containsMouse ? 1.0 : 0.85

                    Behavior on opacity {
                        NumberAnimation { duration: 150 }
                    }
                }

                MouseArea {
                    id: headerCalendarBtnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        headerCalendarBtn.tooltipEnabled = false
                        root.calendarClicked()
                    }
                    onExited: {
                        headerCalendarBtn.tooltipEnabled = true
                    }
                }

                ToolTip {
                    id: headerCalendarToolTip
                    visible: headerCalendarBtnMouse.containsMouse && headerCalendarBtn.tooltipEnabled
                    text: langManager.currentTranslations["calendar_tooltip"]
                          ? langManager.currentTranslations["calendar_tooltip"]
                          : "Tarixə keç"
                    delay: 500
                    padding: 8

                    background: Rectangle {
                        color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                        radius: 4
                        border.width: 0
                    }

                    contentItem: Text {
                        text: headerCalendarToolTip.text
                        color: "#FFFFFF"
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: 12
                    }
                }
            }

            // Search button - WAPage style
            Rectangle {
                id: headerSearchBtn
                width: 40
                height: 40
                radius: 20
                color: headerSearchBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"
                anchors.verticalCenter: parent.verticalCenter

                property bool tooltipEnabled: true

                Behavior on color {
                    ColorAnimation { duration: 150 }
                }

                Image {
                    id: headerSearchIcon
                    anchors.centerIn: parent
                    source: "qrc:/assets/icon_search.svg"
                    width: 22
                    height: 22
                    sourceSize: Qt.size(22, 22)
                    visible: false
                }

                ColorOverlay {
                    anchors.fill: headerSearchIcon
                    source: headerSearchIcon
                    color: WAPageTheme.headerText
                    opacity: headerSearchBtnMouse.containsMouse ? 1.0 : 0.85

                    Behavior on opacity {
                        NumberAnimation { duration: 150 }
                    }
                }

                MouseArea {
                    id: headerSearchBtnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        headerSearchBtn.tooltipEnabled = false
                        root.searchClicked()
                    }
                    onExited: {
                        headerSearchBtn.tooltipEnabled = true
                    }
                }

                ToolTip {
                    id: headerSearchToolTip
                    visible: headerSearchBtnMouse.containsMouse && headerSearchBtn.tooltipEnabled
                    text: langManager.currentTranslations["search_tooltip"]
                          ? langManager.currentTranslations["search_tooltip"]
                          : "Mesajlarda axtar (Ctrl+F)"
                    delay: 500
                    padding: 8

                    background: Rectangle {
                        color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                        radius: 4
                        border.width: 0
                    }

                    contentItem: Text {
                        text: headerSearchToolTip.text
                        color: "#FFFFFF"
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: 12
                    }
                }
            }

            // Chat menu hearing - same hover effect as search
            Rectangle {
                id: headerMenuBtn
                width: 40
                height: 40
                radius: 20
                color: headerMenuBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"
                anchors.verticalCenter: parent.verticalCenter

                Behavior on color {
                    ColorAnimation { duration: 150 }
                }

                Image {
                    id: headerMenuIcon
                    anchors.centerIn: parent
                    source: "qrc:/assets/dots.svg"
                    width: 22
                    height: 22
                    sourceSize: Qt.size(22, 22)
                    visible: false
                }

                ColorOverlay {
                    anchors.fill: headerMenuIcon
                    source: headerMenuIcon
                    color: WAPageTheme.headerText
                    opacity: headerMenuBtnMouse.containsMouse ? 1.0 : 0.85

                    Behavior on opacity {
                        NumberAnimation { duration: 150 }
                    }
                }

                MouseArea {
                    id: headerMenuBtnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: headerContextMenu.popup()
                }
            }
        }

        Menu {
            id: headerContextMenu
            padding: 0

            background: Rectangle {
                implicitWidth: 220
                radius: 0
                color: WAPageTheme.dark ? "#1C1C1C" : WAPageTheme.panelBg
                border.color: WAPageTheme.divider
                border.width: 1
            }

            MenuItem {
                id: firstMessageItem
                text: langManager.currentTranslations["first_message"]
                      ? langManager.currentTranslations["first_message"]
                      : "İlk mesaj"
                implicitHeight: 40
                leftPadding: 0
                rightPadding: 0
                topPadding: 0
                bottomPadding: 0

                contentItem: Item {
                    implicitHeight: 40
                    implicitWidth: 220

                    Row {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.leftMargin: 12
                        anchors.rightMargin: 12
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 10

                        Image {
                            source: "qrc:/assets/first.svg"
                            width: 18
                            height: 18
                            sourceSize: Qt.size(18, 18)
                            fillMode: Image.PreserveAspectFit
                            layer.enabled: true
                            layer.effect: ColorOverlay {
                                color: WAPageTheme.dark ? "#FFFFFF" : "#5F6B73"
                            }
                        }

                        Text {
                            width: parent.width - 28
                            text: langManager.currentTranslations["first_message"]
                                  ? langManager.currentTranslations["first_message"]
                                  : "İlk mesaj"
                            color: WAPageTheme.dark ? "#FFFFFF" : "#5F6B73"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }

                background: Rectangle {
                    radius: 0
                    color: firstMessageItem.highlighted 
                        ? (WAPageTheme.dark ? "#2A2A2A" : "#E3E7EA") 
                        : (WAPageTheme.dark ? "#1C1C1C" : "#EEF1F3")
                }

                onTriggered: root.firstMessageRequested()
            }

            MenuItem {
                id: lastMessageItem
                text: langManager.currentTranslations["last_message"]
                      ? langManager.currentTranslations["last_message"]
                      : "Son mesaj"
                implicitHeight: 40
                leftPadding: 0
                rightPadding: 0
                topPadding: 0
                bottomPadding: 0

                contentItem: Item {
                    implicitHeight: 40
                    implicitWidth: 220

                    Row {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.leftMargin: 12
                        anchors.rightMargin: 12
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 10

                        Image {
                            source: "qrc:/assets/last.svg"
                            width: 18
                            height: 18
                            sourceSize: Qt.size(18, 18)
                            fillMode: Image.PreserveAspectFit
                            layer.enabled: true
                            layer.effect: ColorOverlay {
                                color: WAPageTheme.dark ? "#FFFFFF" : "#5F6B73"
                            }
                        }

                        Text {
                            width: parent.width - 28
                            text: langManager.currentTranslations["last_message"]
                                  ? langManager.currentTranslations["last_message"]
                                  : "Son mesaj"
                            color: WAPageTheme.dark ? "#FFFFFF" : "#5F6B73"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }

                background: Rectangle {
                    radius: 0
                    color: lastMessageItem.highlighted 
                        ? (WAPageTheme.dark ? "#2A2A2A" : "#E3E7EA") 
                        : (WAPageTheme.dark ? "#1C1C1C" : "#EEF1F3")
                }

                onTriggered: root.lastMessageRequested()
            }

            MenuItem {
                id: lockChatItem
                text: mainWindow.isChatLocked(mainWindow.activeChatId) 
                    ? (langManager.currentTranslations["unlock_chat"] || "Bu söhbəti kiliddən çıxart")
                    : (langManager.currentTranslations["lock_chat"] || "Söhbəti kilitlə")
                implicitHeight: 40
                leftPadding: 0
                rightPadding: 0
                topPadding: 0
                bottomPadding: 0

                contentItem: Item {
                    implicitHeight: 40
                    implicitWidth: 220

                    Row {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.leftMargin: 12
                        anchors.rightMargin: 12
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 10

                        Image {
                            source: "qrc:/assets/lock.svg"
                            width: 18
                            height: 18
                            sourceSize: Qt.size(18, 18)
                            fillMode: Image.PreserveAspectFit
                        }

                        Text {
                            width: parent.width - 28
                            text: mainWindow.isChatLocked(mainWindow.activeChatId) 
                                ? (langManager.currentTranslations["unlock_chat"] || "Bu söhbəti kiliddən çıxart")
                                : (langManager.currentTranslations["lock_chat"] || "Söhbəti kilitlə")
                            color: WAPageTheme.dark ? "#FFFFFF" : "#5F6B73"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }

                background: Rectangle {
                    radius: 0
                    color: lockChatItem.highlighted 
                        ? (WAPageTheme.dark ? "#2A2A2A" : "#E3E7EA") 
                        : (WAPageTheme.dark ? "#1C1C1C" : "#EEF1F3")
                }

                onTriggered: {
                    if (mainWindow.isChatLocked(mainWindow.activeChatId)) {
                        // Unlock chat directly (no password required)
                        mainWindow.unlockChat(mainWindow.activeChatId)
                        headerContextMenu.close()
                        // Force UI refresh
                        lockChatItem.text = Qt.binding(function() {
                            return mainWindow.isChatLocked(mainWindow.activeChatId) 
                                ? (langManager.currentTranslations["unlock_chat"] || "Bu söhbəti kiliddən çıxart")
                                : (langManager.currentTranslations["lock_chat"] || "Söhbəti kilitlə")
                        })
                    } else {
                        // Lock chat
                        if (mainWindow.hasMasterPassword()) {
                            // Master password exists, lock directly
                            mainWindow.lockChat(mainWindow.activeChatId)
                            headerContextMenu.close()
                            // Force UI refresh
                            lockChatItem.text = Qt.binding(function() {
                                return mainWindow.isChatLocked(mainWindow.activeChatId) 
                                    ? (langManager.currentTranslations["unlock_chat"] || "Bu söhbəti kiliddən çıxart")
                                    : (langManager.currentTranslations["lock_chat"] || "Söhbəti kilitlə")
                            })
                        } else {
                            // No master password, ask to set one
                            lockPasswordDialog.open()
                        }
                    }
                }
            }

            MenuItem {
                id: deleteChatItem
                text: langManager.currentTranslations["delete_chat"]
                implicitHeight: 40
                leftPadding: 0
                rightPadding: 0
                topPadding: 0
                bottomPadding: 0

                contentItem: Item {
                    implicitHeight: 40
                    implicitWidth: 220

                    Row {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.leftMargin: 12
                        anchors.rightMargin: 12
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 10

                        Image {
                            source: "qrc:/assets/delete.svg"
                            width: 18
                            height: 18
                            sourceSize: Qt.size(18, 18)
                            fillMode: Image.PreserveAspectFit
                        }

                        Text {
                            width: parent.width - 28
                            text: langManager.currentTranslations["delete_chat"]
                            color: "#B80531"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }

                background: Rectangle {
                    radius: 0
                    color: deleteChatItem.highlighted 
                        ? (WAPageTheme.dark ? "#3D1A1A" : "#FAD7E1") 
                        : (WAPageTheme.dark ? "#2D1515" : "#FDE5EB")
                }

                onTriggered: deleteConfirmDlg.open()
            }
        }

        // Chat deletion confirmation
        Dialog {
            id: deleteConfirmDlg
            anchors.centerIn: Overlay.overlay
            modal: true
            implicitWidth: 340
            width: 340
            title: langManager.currentTranslations["delete_confirm_title"]

            background: Rectangle {
                radius: WAPageTheme.dark ? 8 : 0
                color: WAPageTheme.panelBg
            }

            header: Label {
                text: deleteConfirmDlg.title
                visible: deleteConfirmDlg.title
                elide: Label.ElideRight
                padding: 16
                bottomPadding: 0
                font.family: WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeLarge
                font.bold: true
                color: WAPageTheme.chatListText
                background: Rectangle {
                    color: WAPageTheme.panelBg
                }
            }

            contentItem: Column {
                spacing: 16
                padding: 20
                width: 300

                Text {
                    text: langManager.currentTranslations["delete_confirm_text"]
                    color: WAPageTheme.chatListText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeNormal
                    wrapMode: Text.WordWrap
                    width: parent.width - 40
                }

                Row {
                    spacing: 12
                    anchors.right: parent.right
                    anchors.rightMargin: 20

                    Button {
                        text: langManager.currentTranslations["no"]
                        onClicked: deleteConfirmDlg.close()
                        background: Rectangle {
                            radius: 6
                            color: parent.pressed ? "#6D747B" : "#8696A0"
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            horizontalAlignment: Text.AlignHCenter
                            leftPadding: 16
                            rightPadding: 16
                        }
                    }

                    Button {
                        text: langManager.currentTranslations["yes"]
                        onClicked: {
                            deleteConfirmDlg.close()
                            root.deleteRequested()
                        }
                        background: Rectangle {
                            radius: 6
                            color: parent.pressed ? "#C62828" : "#EA4335"
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            horizontalAlignment: Text.AlignHCenter
                            leftPadding: 16
                            rightPadding: 16
                        }
                    }
                }
            }

            footer: Item {}
        }

        // Lock Password Dialog
        Dialog {
            id: lockPasswordDialog
            anchors.centerIn: Overlay.overlay
            modal: true
            implicitWidth: 340
            width: 340
            title: langManager.currentTranslations["lock_chat_title"] || "Söhbəti kilitlə"

            background: Rectangle {
                radius: WAPageTheme.dark ? 8 : 0
                color: WAPageTheme.panelBg
            }

            header: Item {
                implicitHeight: 60
                implicitWidth: 340

                Row {
                    anchors.centerIn: parent
                    spacing: 12

                    Image {
                        source: "qrc:/assets/lock.svg"
                        width: 24
                        height: 24
                        sourceSize: Qt.size(24, 24)
                        fillMode: Image.PreserveAspectFit
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Label {
                        text: langManager.currentTranslations["lock_chat_title"] || "Söhbəti kilitlə"
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeLarge
                        font.bold: true
                        color: WAPageTheme.chatListText
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }

            contentItem: Column {
                spacing: 16
                padding: 20
                width: 300

                Text {
                    text: mainWindow.hasMasterPassword() 
                        ? (langManager.currentTranslations["lock_chat_message"] || "Bu söhbət kilidlənəcək")
                        : (langManager.currentTranslations["lock_chat_set_password"] || "Söhbətləri kilitləmək üçün şifrə yazın")
                    color: WAPageTheme.chatListText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeNormal
                    wrapMode: Text.WordWrap
                    width: parent.width - 40
                }

                TextField {
                    id: lockPasswordInput
                    width: parent.width - 40
                    placeholderText: "000000"
                    echoMode: TextInput.Password
                    maximumLength: 6
                    inputMethodHints: Qt.ImhDigitsOnly
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeNormal
                    color: WAPageTheme.chatListText
                    placeholderTextColor: WAPageTheme.searchPlaceholder
                    
                    validator: RegularExpressionValidator { regularExpression: /[0-9]{0,6}/ }
                    
                    background: Rectangle {
                        radius: 6
                        color: WAPageTheme.searchBg
                        border.color: lockPasswordInput.activeFocus ? WAPageTheme.accent : WAPageTheme.divider
                        border.width: 1
                    }

                    Keys.onReturnPressed: {
                        if (lockPasswordInput.text.length === 6) {
                            lockButton.clicked()
                        }
                    }
                }

                Text {
                    id: lockErrorText
                    text: ""
                    color: "#EA4335"
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    visible: text.length > 0
                    width: parent.width - 40
                    wrapMode: Text.WordWrap
                }

                Row {
                    spacing: 12
                    anchors.right: parent.right
                    anchors.rightMargin: 20

                    Button {
                        text: langManager.currentTranslations["cancel"] || "Ləğv et"
                        onClicked: {
                            lockPasswordDialog.close()
                            lockPasswordInput.text = ""
                            lockErrorText.text = ""
                        }
                        background: Rectangle {
                            radius: 6
                            color: parent.pressed ? "#6D747B" : "#8696A0"
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            horizontalAlignment: Text.AlignHCenter
                            leftPadding: 16
                            rightPadding: 16
                        }
                    }

                    Button {
                        id: lockButton
                        text: langManager.currentTranslations["lock"] || "Kilidlə"
                        enabled: lockPasswordInput.text.length === 6
                        onClicked: {
                            lockErrorText.text = ""
                            
                            if (lockPasswordInput.text.length !== 6) {
                                lockErrorText.text = langManager.currentTranslations["password_6_digits"] || "Şifrə 6 rəqəm olmalıdır"
                                return
                            }
                            
                            // If no master password exists, set it
                            if (!mainWindow.hasMasterPassword()) {
                                mainWindow.setMasterPassword(lockPasswordInput.text)
                                mainWindow.lockChat(mainWindow.activeChatId)
                                lockPasswordDialog.close()
                                lockPasswordInput.text = ""
                                return
                            }
                            
                            // If master password exists, verify it
                            if (!mainWindow.checkMasterPassword(lockPasswordInput.text)) {
                                lockErrorText.text = langManager.currentTranslations["password_incorrect"] || "Şifrə düzgün deyil"
                                return
                            }
                            
                            // Password correct, lock chat
                            mainWindow.lockChat(mainWindow.activeChatId)
                            lockPasswordDialog.close()
                            lockPasswordInput.text = ""
                        }
                        background: Rectangle {
                            radius: 6
                            color: parent.enabled 
                                ? (parent.pressed ? "#006654" : WAPageTheme.accent)
                                : "#CCCCCC"
                        }
                        contentItem: Text {
                            text: parent.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeNormal
                            horizontalAlignment: Text.AlignHCenter
                            leftPadding: 16
                            rightPadding: 16
                        }
                    }
                }
            }

            footer: Item {}
            
            onOpened: {
                lockPasswordInput.forceActiveFocus()
                lockPasswordInput.text = ""
                lockErrorText.text = ""
            }
        }

        // Avatar + name
        Row {
            spacing: 12
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.right: toolButtons.left
            anchors.rightMargin: 12

            AvatarCircle {
                anchors.verticalCenter: parent.verticalCenter
                size:        WAPageTheme.avatarSize
                avatarPath:  mainWindow.activeChatAvatar
                initials:    mainWindow.activeChatInitials
                avatarColor: mainWindow.activeChatColor
            }

            Column {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2

                Text {
                    text:           mainWindow.activeChatName
                    color:          WAPageTheme.headerText
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeNormal
                    font.weight:    Font.DemiBold
                }
            }
        }
    }
}
