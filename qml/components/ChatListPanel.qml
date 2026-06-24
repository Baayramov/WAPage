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

    // Show favorites panel instead of chat list
    property bool showFavorites: false
    
    // Show locked chats panel instead of chat list
    property bool showLockedChats: false
    
    // Bulk selection mode
    property bool bulkSelectionMode: false
    property var selectedChatIds: []
    
    function toggleBulkSelection() {
        bulkSelectionMode = !bulkSelectionMode
        if (!bulkSelectionMode) {
            selectedChatIds = []
        }
    }
    
    function toggleChatSelection(chatId) {
        let arr = selectedChatIds.slice() // Copy array
        let index = arr.indexOf(chatId)
        if (index > -1) {
            arr.splice(index, 1) // Remove
        } else {
            arr.push(chatId) // Add
        }
        selectedChatIds = arr
    }
    
    function isChatSelected(chatId) {
        return selectedChatIds.indexOf(chatId) > -1
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // ── Header ──────────────────────────────────────────────
        Rectangle {
            Layout.fillWidth: true
            height: WAPageTheme.headerHeight
            color:  WAPageTheme.headerBg

            // Settings button (gear icon) - on the left
            Rectangle {
                id: settingsBtn
                anchors {
                    left: parent.left
                    leftMargin: 16
                    verticalCenter: parent.verticalCenter
                }
                width: 40
                height: 40
                radius: 20
                color: settingsBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                property bool tooltipEnabled: true

                Behavior on color {
                    ColorAnimation { duration: 150 }
                }

                Image {
                    id: settingsIcon
                    anchors.centerIn: parent
                    source: "qrc:/assets/settings.svg"
                    width: 24
                    height: 24
                    sourceSize: Qt.size(24, 24)
                    visible: false
                }

                ColorOverlay {
                    anchors.fill: settingsIcon
                    source: settingsIcon
                    color: WAPageTheme.headerText
                    opacity: settingsBtnMouse.containsMouse ? 1.0 : 0.85

                    Behavior on opacity {
                        NumberAnimation { duration: 150 }
                    }
                }

                MouseArea {
                    id: settingsBtnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        settingsBtn.tooltipEnabled = false
                        settingsView.open()
                    }
                    onExited: {
                        settingsBtn.tooltipEnabled = true
                    }
                }

                ToolTip {
                    id: settingsToolTip
                    visible: settingsBtnMouse.containsMouse && settingsBtn.tooltipEnabled
                    text: langManager.currentTranslations["settings"]
                    delay: 500
                    padding: 8
                    
                    background: Rectangle {
                        color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                        radius: 4
                        border.width: 0
                    }
                    
                    contentItem: Text {
                        text: settingsToolTip.text
                        color: "#FFFFFF"
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: 12
                    }
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

                // Lock button (Locked Chats) - NEW
                Rectangle {
                    id: lockBtn
                    width: 40
                    height: 40
                    radius: 20
                    color: lockBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                    property bool tooltipEnabled: true

                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }

                    Image {
                        id: lockIcon
                        anchors.centerIn: parent
                        source: "qrc:/assets/lock.svg"
                        width: 20
                        height: 20
                        sourceSize: Qt.size(20, 20)
                        visible: false
                    }

                    ColorOverlay {
                        anchors.fill: lockIcon
                        source: lockIcon
                        color: WAPageTheme.headerText
                        opacity: lockBtnMouse.containsMouse ? 1.0 : 0.85

                        Behavior on opacity {
                            NumberAnimation { duration: 150 }
                        }
                    }

                    MouseArea {
                        id: lockBtnMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            lockBtn.tooltipEnabled = false
                            lockedChatsPasswordDialog.open()
                        }
                        onExited: {
                            lockBtn.tooltipEnabled = true
                        }
                    }

                    ToolTip {
                        id: lockToolTip
                        visible: lockBtnMouse.containsMouse && lockBtn.tooltipEnabled
                        text: langManager.currentTranslations["locked_chats_access"] || "Kilidlənmiş söhbətlərə giriş"
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                            border.width: 0
                        }
                        
                        contentItem: Text {
                            text: lockToolTip.text
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeSmall
                            color: "#FFFFFF"
                        }
                        
                        enter: Transition {
                            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; duration: 150 }
                        }
                        exit: Transition {
                            NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; duration: 100 }
                        }
                    }
                }

                // Star button (Favorites) - NEW
                Rectangle {
                    id: starBtn
                    width: 40
                    height: 40
                    radius: 20
                    color: starBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                    property bool tooltipEnabled: true

                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }

                    Image {
                        id: starIcon
                        anchors.centerIn: parent
                        source: "qrc:/assets/star.svg"
                        width: 22
                        height: 22
                        sourceSize: Qt.size(22, 22)
                        visible: false
                    }

                    ColorOverlay {
                        anchors.fill: starIcon
                        source: starIcon
                        color: WAPageTheme.headerText
                        opacity: starBtnMouse.containsMouse ? 1.0 : 0.85

                        Behavior on opacity {
                            NumberAnimation { duration: 150 }
                        }
                    }

                    MouseArea {
                        id: starBtnMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            starBtn.tooltipEnabled = false
                            root.showFavorites = !root.showFavorites
                        }
                        onExited: {
                            starBtn.tooltipEnabled = true
                        }
                    }

                    ToolTip {
                        id: starToolTip
                        visible: starBtnMouse.containsMouse && starBtn.tooltipEnabled
                        text: langManager.currentTranslations["favorites"] || "Favoritlər"
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                            border.width: 0
                        }
                        
                        contentItem: Text {
                            text: starToolTip.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: 12
                        }
                    }
                }

                // Theme toggle button - WAPage style
                Rectangle {
                    id: themeBtn
                    width: 40
                    height: 40
                    radius: 20
                    color: themeBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"

                    property bool tooltipEnabled: true

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
                        onClicked: {
                            themeBtn.tooltipEnabled = false
                            mainWindow.isDarkTheme = !mainWindow.isDarkTheme
                        }
                        onExited: {
                            themeBtn.tooltipEnabled = true
                        }
                    }

                    ToolTip {
                        id: themeToolTip
                        visible: themeBtnMouse.containsMouse && themeBtn.tooltipEnabled
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

                    property bool tooltipEnabled: true

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
                        onClicked: {
                            newChatBtn.tooltipEnabled = false
                            importDlg.visible = true
                        }
                        onExited: {
                            newChatBtn.tooltipEnabled = true
                        }
                    }

                    ToolTip {
                        id: newChatToolTip
                        visible: newChatBtnMouse.containsMouse && newChatBtn.tooltipEnabled
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
        
        // Bulk Selection Toolbar
        Rectangle {
            Layout.fillWidth: true
            height: 50
            color: WAPageTheme.chatListBg
            visible: !root.showFavorites && !root.showLockedChats
            
            Row {
                anchors {
                    fill: parent
                    leftMargin: 8
                    rightMargin: 8
                }
                spacing: 8
                
                // Bulk Select Button (left)
                Rectangle {
                    id: bulkSelectBtn
                    width: 40
                    height: 40
                    radius: 20
                    anchors.verticalCenter: parent.verticalCenter
                    color: bulkSelectMouse.containsMouse ? Qt.rgba(0, 0, 0, WAPageTheme.dark ? 0.2 : 0.05) : "transparent"
                    
                    property bool tooltipEnabled: true
                    
                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }
                    
                    Image {
                        id: bulkSelectIcon
                        anchors.centerIn: parent
                        source: "qrc:/assets/listcheck.svg"
                        width: 22
                        height: 22
                        sourceSize: Qt.size(22, 22)
                        visible: false
                    }
                    
                    ColorOverlay {
                        anchors.fill: bulkSelectIcon
                        source: bulkSelectIcon
                        color: root.bulkSelectionMode ? "#00A884" : WAPageTheme.iconColor
                        
                        Behavior on color {
                            ColorAnimation { duration: 200 }
                        }
                    }
                    
                    MouseArea {
                        id: bulkSelectMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            bulkSelectBtn.tooltipEnabled = false
                            root.toggleBulkSelection()
                        }
                        onExited: {
                            bulkSelectBtn.tooltipEnabled = true
                        }
                    }
                    
                    ToolTip {
                        id: bulkSelectToolTip
                        visible: bulkSelectMouse.containsMouse && bulkSelectBtn.tooltipEnabled
                        text: langManager.currentTranslations["bulk_select_tooltip"] || "Toplu Seçim"
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                        }
                        
                        contentItem: Text {
                            text: bulkSelectToolTip.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: 12
                        }
                    }
                }
                
                // Spacer
                Item {
                    width: parent.width - 137  // 5 piksel sola çəkmək üçün 132-dən 137-yə dəyişdik
                    height: 1
                }
                
                // Cancel Button (only visible in bulk mode)
                Rectangle {
                    id: cancelBtn
                    width: 40
                    height: 40
                    radius: 20
                    anchors.verticalCenter: parent.verticalCenter
                    visible: root.bulkSelectionMode
                    color: cancelMouse.containsMouse ? Qt.rgba(0, 0, 0, WAPageTheme.dark ? 0.2 : 0.05) : "transparent"
                    
                    property bool tooltipEnabled: true
                    
                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }
                    
                    Image {
                        id: cancelIcon
                        anchors.centerIn: parent
                        source: "qrc:/assets/icon_close.svg"
                        width: 18
                        height: 18
                        sourceSize: Qt.size(18, 18)
                        visible: false
                    }
                    
                    ColorOverlay {
                        anchors.fill: cancelIcon
                        source: cancelIcon
                        color: WAPageTheme.iconColor
                    }
                    
                    MouseArea {
                        id: cancelMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            cancelBtn.tooltipEnabled = false
                            root.toggleBulkSelection()
                        }
                        onExited: {
                            cancelBtn.tooltipEnabled = true
                        }
                    }
                    
                    ToolTip {
                        id: cancelToolTip
                        visible: cancelMouse.containsMouse && cancelBtn.tooltipEnabled
                        text: langManager.currentTranslations["cancel_selection_tooltip"] || "Ləğv et"
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                        }
                        
                        contentItem: Text {
                            text: cancelToolTip.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: 12
                        }
                    }
                }
                
                // Bulk Delete Button (only visible in bulk mode)
                Rectangle {
                    id: bulkDeleteBtn
                    width: 40
                    height: 40
                    radius: 20
                    anchors.verticalCenter: parent.verticalCenter
                    visible: root.bulkSelectionMode
                    enabled: root.selectedChatIds.length > 0
                    opacity: enabled ? 1.0 : 0.4
                    color: bulkDeleteMouse.containsMouse && enabled ? Qt.rgba(1, 0, 0, 0.1) : "transparent"
                    
                    property bool tooltipEnabled: true
                    
                    Behavior on color {
                        ColorAnimation { duration: 150 }
                    }
                    
                    Behavior on opacity {
                        NumberAnimation { duration: 200 }
                    }
                    
                    Image {
                        id: bulkDeleteIcon
                        anchors.centerIn: parent
                        source: "qrc:/assets/delete.svg"
                        width: 22
                        height: 22
                        sourceSize: Qt.size(22, 22)
                        visible: false
                    }
                    
                    ColorOverlay {
                        anchors.fill: bulkDeleteIcon
                        source: bulkDeleteIcon
                        color: enabled ? "#FF0000" : WAPageTheme.iconColor
                        
                        Behavior on color {
                            ColorAnimation { duration: 200 }
                        }
                    }
                    
                    MouseArea {
                        id: bulkDeleteMouse
                        anchors.fill: parent
                        enabled: parent.enabled
                        hoverEnabled: true
                        cursorShape: enabled ? Qt.PointingHandCursor : Qt.ArrowCursor
                        onClicked: {
                            if (root.selectedChatIds.length > 0) {
                                bulkDeleteBtn.tooltipEnabled = false
                                bulkDeleteDialog.open()
                            }
                        }
                        onExited: {
                            bulkDeleteBtn.tooltipEnabled = true
                        }
                    }
                    
                    ToolTip {
                        id: bulkDeleteToolTip
                        visible: bulkDeleteMouse.containsMouse && bulkDeleteBtn.tooltipEnabled && bulkDeleteBtn.enabled
                        text: langManager.currentTranslations["bulk_delete_tooltip"] || "Toplu Sil"
                        delay: 500
                        padding: 8
                        
                        background: Rectangle {
                            color: WAPageTheme.dark ? "#3B4A54" : "#4A4A4A"
                            radius: 4
                        }
                        
                        contentItem: Text {
                            text: bulkDeleteToolTip.text
                            color: "#FFFFFF"
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: 12
                        }
                    }
                }
            }
        }

        // Chat List
        ListView {
            id: chatList
            Layout.fillWidth:  true
            Layout.fillHeight: true
            model:             mainWindow.chatModel
            clip:              true
            currentIndex:      -1
            visible:           !root.showFavorites && !root.showLockedChats

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
                // Hide LOCKED chats in main panel (they appear in LockedChatsPanel)
                height:       (!model.isLocked && model.matchesSearch) ? 72 : 0
                visible:      (!model.isLocked && model.matchesSearch)
                enabled:      (!model.isLocked && model.matchesSearch)
                chatId:       model.chatId
                contactName:  model.contactName
                lastMessage:  model.lastMessage
                lastTime:     model.lastMessageTime
                avatarPath:   model.avatarPath
                initials:     model.initials
                avatarColor:  model.avatarColor
                isSelected:   chatList.currentIndex === index
                bulkMode:     root.bulkSelectionMode
                isChecked:    root.isChatSelected(model.chatId)

                onClicked: {
                    chatList.currentIndex = index
                    mainWindow.selectChat(model.chatId)
                }
                
                onCheckToggled: {
                    root.toggleChatSelection(model.chatId)
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

    // Favorites Panel
    FavoritesPanel {
        id: favoritesPanel
        anchors.fill: parent
        visible: root.showFavorites
        chatListPanelRef: root
    }

    // Locked Chats Panel
    LockedChatsPanel {
        id: lockedChatsPanel
        anchors.fill: parent
        visible: root.showLockedChats
        chatListPanelRef: root
    }

    SettingsView {
        id: settingsView
        anchors.fill: parent
        visible: false
    }
    
    // Bulk Delete Confirmation Dialog
    Dialog {
        id: bulkDeleteDialog
        anchors.centerIn: parent
        modal: true
        implicitWidth: 340
        width: 340
        title: langManager.currentTranslations["delete_confirm_title"]

        background: Rectangle {
            radius: WAPageTheme.dark ? 8 : 0
            color: WAPageTheme.panelBg
        }

        header: Label {
            text: bulkDeleteDialog.title
            visible: bulkDeleteDialog.title
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
                    onClicked: bulkDeleteDialog.close()
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
                        bulkDeleteDialog.close()
                        
                        // Delete chats sequentially
                        const chatIds = root.selectedChatIds.slice() // Copy array
                        for (let i = 0; i < chatIds.length; i++) {
                            mainWindow.deleteChat(chatIds[i])
                        }
                        
                        // Exit bulk mode
                        root.toggleBulkSelection()
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

    // Locked Chats Password Dialog (for entering locked chats section)
    Dialog {
        id: lockedChatsPasswordDialog
        anchors.centerIn: Overlay.overlay
        modal: true
        implicitWidth: 340
        width: 340
        title: langManager.currentTranslations["locked_chats_password_title"] || "Kilidlənmiş Söhbətlər"

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
                    text: langManager.currentTranslations["locked_chats_password_title"] || "Kilidlənmiş Söhbətlər"
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
                text: langManager.currentTranslations["locked_chats_enter_password"] || "Kilidlənmiş söhbətlərə daxil olmaq üçün şifrə yazın"
                color: WAPageTheme.chatListText
                font.family: WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeNormal
                wrapMode: Text.WordWrap
                width: parent.width - 40
            }

            TextField {
                id: lockedChatsPasswordInput
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
                    border.color: lockedChatsPasswordInput.activeFocus ? WAPageTheme.accent : WAPageTheme.divider
                    border.width: 1
                }

                Keys.onReturnPressed: {
                    if (lockedChatsPasswordInput.text.length === 6) {
                        enterLockedChatsButton.clicked()
                    }
                }
            }

            Text {
                id: lockedChatsErrorText
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
                        lockedChatsPasswordDialog.close()
                        lockedChatsPasswordInput.text = ""
                        lockedChatsErrorText.text = ""
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
                    id: enterLockedChatsButton
                    text: langManager.currentTranslations["enter"] || "Daxil ol"
                    enabled: lockedChatsPasswordInput.text.length === 6
                    onClicked: {
                        lockedChatsErrorText.text = ""
                        
                        if (lockedChatsPasswordInput.text.length !== 6) {
                            lockedChatsErrorText.text = langManager.currentTranslations["password_6_digits"] || "Şifrə 6 rəqəm olmalıdır"
                            return
                        }
                        
                        if (!mainWindow.hasMasterPassword()) {
                            lockedChatsErrorText.text = langManager.currentTranslations["no_master_password"] || "Şifrə təyin edilməyib"
                            return
                        }
                        
                        if (!mainWindow.checkMasterPassword(lockedChatsPasswordInput.text)) {
                            lockedChatsErrorText.text = langManager.currentTranslations["password_incorrect"] || "Şifrə düzgün deyil"
                            return
                        }
                        
                        // Password correct - open locked chats panel
                        root.showLockedChats = true
                        lockedChatsPasswordDialog.close()
                        lockedChatsPasswordInput.text = ""
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
            lockedChatsPasswordInput.forceActiveFocus()
            lockedChatsPasswordInput.text = ""
            lockedChatsErrorText.text = ""
        }
    }
}
