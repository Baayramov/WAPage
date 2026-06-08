import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1 as Platform
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// My profile (Settings) view — like the left profile of WAPage Web
// It comes sliding from left to right
Rectangle {
    id: root
    color: WAPageTheme.profileBg

    // Prevent clicks from going to cracks behind (consume mouse events)
    MouseArea {
        anchors.fill: parent
        onClicked: {}
    }

    function open()  { root.visible = true  }
    function close() { root.visible = false }

    // Login animation
    property real slideX: root.visible ? 0 : -root.width
    x: slideX
    Behavior on x { NumberAnimation { duration: 200; easing.type: Easing.OutCubic } }

    ColumnLayout {
        anchors.fill: parent
        spacing:      0

        // ── Header ──────────────────────────────────────────────
        Rectangle {
            Layout.fillWidth: true
            height: WAPageTheme.headerHeight
            color:  WAPageTheme.profileHeaderBg

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
                    bottom: parent.bottom
                    bottomMargin: 10
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
                }

                MouseArea {
                    id: backBtnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: root.close()
                }
            }

            Text {
                anchors {
                    left: backBtn.right
                    leftMargin: 20
                    verticalCenter: backBtn.verticalCenter
                }
                text:           langManager.currentTranslations["settings"]
                color:          "#FFFFFF"
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: 19
                font.weight:    Font.Medium
            }
        }

        // Avatar section
        Rectangle {
            Layout.fillWidth: true
            height:  260
            color:   WAPageTheme.chatListBg

            Column {
                anchors.centerIn: parent
                spacing: 20

                // Large avatar — clickable
                AvatarCircle {
                    anchors.horizontalCenter: parent.horizontalCenter
                    size:        WAPageTheme.avatarSizeLarge
                    avatarPath:  mainWindow.myAvatar
                    initials:    "ME"
                    avatarColor: "#25D366" // WAPage old

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape:  Qt.PointingHandCursor
                        onClicked:    myAvatarFileDlg.open()
                        
                        Rectangle {
                            anchors.fill: parent
                            radius: parent.width / 2
                            color: "black"
                            opacity: parent.containsMouse ? 0.3 : 0.0
                            Behavior on opacity { NumberAnimation { duration: 150 } }
                            
                            Text {
                                anchors.centerIn: parent
                                text: "📷\n" + langManager.currentTranslations["profile_photo"].toUpperCase()
                                color: "#FFFFFF"
                                font.pixelSize: 12
                                font.weight: Font.Bold
                                horizontalAlignment: Text.AlignHCenter
                                visible: parent.parent.containsMouse
                            }
                        }
                    }
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           langManager.currentTranslations["profile_photo"]
                    color:          WAPageTheme.searchText
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: 14
                }
            }
        }

        // ── Settings / Language Selection ────────────────────────────────
        Item {
            Layout.fillWidth:  true
            Layout.fillHeight: true
            
            Flickable {
                id: settingsFlickable
                anchors.fill: parent
                clip: true
                contentWidth: width
                contentHeight: settingsColumn.height
                
                flickableDirection: Flickable.VerticalFlick
                boundsBehavior: Flickable.DragAndOvershootBounds  // Rubber band effect
                
                // Hide scroll bar
                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOff
                }
                
                Column {
                    id: settingsColumn
                    width: root.width
                    spacing: 0

                // Language selection
                Rectangle {
                    width:  parent.width
                    height: 64
                    color:  langRowHover.containsMouse ? WAPageTheme.itemHovered : "transparent"
                    HoverHandler { id: langRowHover }
                    
                    Row {
                        anchors { fill: parent; leftMargin: 24; rightMargin: 24 }
                        spacing: 20
                        
                        Item {
                            width: 32
                            height: 32
                            anchors.verticalCenter: parent.verticalCenter

                            Image {
                                anchors.fill: parent
                                source: "qrc:/assets/language.svg"
                                fillMode: Image.PreserveAspectFit
                            }
                        }

                        Column {
                            anchors.verticalCenter: parent.verticalCenter
                            spacing: 2
                            Text {
                                text:        langManager.currentTranslations["language"]
                                color:       WAPageTheme.chatListSubText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeMicro
                            }
                            Text {
                                text:        langManager.getLanguageName(langManager.currentLanguage)
                                color:       WAPageTheme.chatListText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: root.openLangDialog()
                    }
                }
                
                // Auto-play next voice messages
                Rectangle {
                    width:  parent.width
                    height: 64
                    color:  autoPlayRowHover.containsMouse ? WAPageTheme.itemHovered : "transparent"
                    HoverHandler { id: autoPlayRowHover }
                    
                    Row {
                        anchors { fill: parent; leftMargin: 24; rightMargin: 24 }
                        spacing: 20
                        
                        Column {
                            anchors.verticalCenter: parent.verticalCenter
                            spacing: 2
                            width: parent.width - 60
                            
                            Text {
                                text: langManager.currentTranslations["auto_play_next_voice"]
                                      ? langManager.currentTranslations["auto_play_next_voice"]
                                      : "Auto-play sequential voice messages"
                                color: WAPageTheme.chatListText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                                wrapMode: Text.WordWrap
                                width: parent.width
                            }
                        }
                        
                        Item { Layout.fillWidth: true; width: 1 }
                        
                        // Checkbox
                        Rectangle {
                            anchors.verticalCenter: parent.verticalCenter
                            width: 24
                            height: 24
                            radius: 4
                            border.width: 2
                            border.color: mainWindow.autoPlayNextVoice 
                                        ? WAPageTheme.accentGreen 
                                        : WAPageTheme.chatListSubText
                            color: mainWindow.autoPlayNextVoice 
                                 ? WAPageTheme.accentGreen 
                                 : "transparent"
                            
                            Behavior on border.color { ColorAnimation { duration: 150 } }
                            Behavior on color { ColorAnimation { duration: 150 } }
                            
                            Text {
                                anchors.centerIn: parent
                                text: "✓"
                                color: "#FFFFFF"
                                font.pixelSize: 16
                                font.bold: true
                                visible: mainWindow.autoPlayNextVoice
                                opacity: mainWindow.autoPlayNextVoice ? 1.0 : 0.0
                                
                                Behavior on opacity { NumberAnimation { duration: 150 } }
                            }
                        }
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            mainWindow.autoPlayNextVoice = !mainWindow.autoPlayNextVoice
                        }
                    }
                }
                
                // Default Owner Name
                Rectangle {
                    property bool editMode: false
                    property string draftOwnerName: mainWindow.defaultOwnerName || ""
                    
                    id: ownerNameSection
                    width:  parent.width
                    height: editMode ? 100 : 64
                    color:  "transparent"
                    
                    Column {
                        anchors {
                            fill: parent
                            leftMargin: 24
                            rightMargin: 24
                            topMargin: 12
                            bottomMargin: 12
                        }
                        spacing: 8
                        
                        Text {
                            text: langManager.currentTranslations["default_owner_name"]
                                  ? langManager.currentTranslations["default_owner_name"]
                                  : "Default Owner Name"
                            color: WAPageTheme.accent
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                        }
                        
                        RowLayout {
                            width: parent.width
                            spacing: 8
                            
                            TextField {
                                id: ownerNameInput
                                visible: ownerNameSection.editMode
                                Layout.fillWidth: true
                                text: ownerNameSection.draftOwnerName
                                selectByMouse: true
                                color: WAPageTheme.chatListText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                                placeholderText: langManager.currentTranslations["owner_name_placeholder"]
                                                 ? langManager.currentTranslations["owner_name_placeholder"]
                                                 : "Your name"
                                placeholderTextColor: WAPageTheme.chatListSubText
                                background: Rectangle {
                                    radius: 8
                                    color: WAPageTheme.panelBg
                                    border.width: 1
                                    border.color: WAPageTheme.accent
                                }
                                onTextChanged: ownerNameSection.draftOwnerName = text
                                onAccepted: {
                                    // Allow empty to clear default name
                                    const trimmed = ownerNameSection.draftOwnerName.trim()
                                    mainWindow.setDefaultOwnerName(trimmed)
                                    ownerNameSection.editMode = false
                                }
                            }
                            
                            Text {
                                visible: !ownerNameSection.editMode
                                Layout.fillWidth: true
                                text: {
                                    const name = mainWindow.defaultOwnerName || ""
                                    if (name.length > 0) {
                                        return name
                                    } else {
                                        return (langManager.currentTranslations["not_set"] || "Not set")
                                    }
                                }
                                color: (mainWindow.defaultOwnerName || "").length > 0 
                                       ? WAPageTheme.chatListText 
                                       : WAPageTheme.chatListSubText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            
                            Rectangle {
                                id: editOrSaveOwnerBtn
                                width: 32
                                height: 32
                                radius: 16
                                color: editOrSaveOwnerMouse.containsMouse ? Qt.rgba(0, 0, 0, 0.08) : "transparent"
                                border.width: ownerNameSection.editMode ? 0 : 1
                                border.color: WAPageTheme.divider
                                
                                // Edit icon (when not in edit mode)
                                Image {
                                    anchors.centerIn: parent
                                    source: "qrc:/assets/edit.svg"
                                    width: 24
                                    height: 24
                                    sourceSize: Qt.size(24, 24)
                                    visible: !ownerNameSection.editMode
                                    fillMode: Image.PreserveAspectFit
                                }

                                // Checkmark text (when in edit mode - save)
                                Text {
                                    anchors.centerIn: parent
                                    text: "✔"  // Bold checkmark instead of regular ✓
                                    color: WAPageTheme.accentGreen
                                    font.family: WAPageTheme.fontFamily
                                    font.pixelSize: 18
                                    font.weight: Font.Bold
                                    visible: ownerNameSection.editMode
                                }
                                
                                MouseArea {
                                    id: editOrSaveOwnerMouse
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        if (!ownerNameSection.editMode) {
                                            ownerNameSection.draftOwnerName = mainWindow.defaultOwnerName || ""
                                            ownerNameSection.editMode = true
                                            ownerNameInput.forceActiveFocus()
                                            ownerNameInput.selectAll()
                                            return
                                        }
                                        // Save: allow empty to clear default name
                                        const trimmed = ownerNameSection.draftOwnerName.trim()
                                        mainWindow.setDefaultOwnerName(trimmed)
                                        ownerNameSection.editMode = false
                                    }
                                }
                            }
                            
                            // Delete button - only visible when NOT in edit mode and name is set
                            Rectangle {
                                visible: !ownerNameSection.editMode && (mainWindow.defaultOwnerName || "").length > 0
                                width: 32
                                height: 32
                                radius: 16
                                color: deleteOwnerMouse.containsMouse ? Qt.rgba(1, 0, 0, 0.1) : "transparent"
                                border.width: 1
                                border.color: deleteOwnerMouse.containsMouse ? "#D4371C" : WAPageTheme.divider
                                
                                Image {
                                    anchors.centerIn: parent
                                    source: "qrc:/assets/delete.svg"
                                    width: 18
                                    height: 18
                                    sourceSize: Qt.size(18, 18)
                                }
                                
                                MouseArea {
                                    id: deleteOwnerMouse
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        mainWindow.setDefaultOwnerName("")
                                    }
                                }
                            }
                            
                            // Cancel button - only visible in edit mode
                            Rectangle {
                                visible: ownerNameSection.editMode
                                width: 32
                                height: 32
                                radius: 16
                                color: cancelOwnerMouse.containsMouse ? Qt.rgba(0, 0, 0, 0.08) : "transparent"
                                border.width: 1
                                border.color: WAPageTheme.divider
                                
                                Text {
                                    anchors.centerIn: parent
                                    text: "✕"
                                    color: WAPageTheme.chatListSubText
                                    font.family: WAPageTheme.fontFamily
                                    font.pixelSize: 14
                                    font.weight: Font.Medium
                                }
                                
                                MouseArea {
                                    id: cancelOwnerMouse
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        ownerNameSection.draftOwnerName = mainWindow.defaultOwnerName || ""
                                        ownerNameSection.editMode = false
                                    }
                                }
                            }
                        }
                    }
                }
                
                // Add spacing of 5px before Profile Library
                Item { width: parent.width; height: 5 }
                
                // Profile Library Section
                Column {
                    width: parent.width
                    spacing: 0
                    
                    // Section header
                    Rectangle {
                        width: parent.width
                        height: 50
                        color: "transparent"
                        
                        Row {
                            anchors {
                                fill: parent
                                leftMargin: 24
                                rightMargin: 24
                            }
                            spacing: 12
                            
                            Text {
                                anchors.verticalCenter: parent.verticalCenter
                                text: langManager.currentTranslations["profile_library"] || "Profile Library"
                                color: WAPageTheme.accent
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeMicro
                                font.weight: Font.Medium
                            }
                            
                            Item { Layout.fillWidth: true; width: 1 }
                            
                            // Add button
                            Item {
                                anchors.verticalCenter: parent.verticalCenter
                                width: 24
                                height: 24
                                
                                Image {
                                    id: addIcon
                                    anchors.fill: parent
                                    source: "qrc:/assets/add.svg"
                                    sourceSize: Qt.size(24, 24)
                                    visible: false
                                }
                                
                                ColorOverlay {
                                    anchors.fill: addIcon
                                    source: addIcon
                                    color: WAPageTheme.accent
                                    opacity: addProfileMouse.containsMouse ? 1.0 : 0.85
                                    
                                    Behavior on opacity { NumberAnimation { duration: 150 } }
                                }
                                
                                MouseArea {
                                    id: addProfileMouse
                                    anchors.fill: parent
                                    anchors.margins: -4  // Expand clickable area slightly
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: addProfileDialog.open()
                                }
                            }
                        }
                    }
                    
                    // Profile list
                    Repeater {
                        model: mainWindow.profileLibrary
                        
                        Rectangle {
                            width: parent.width
                            height: 64
                            color: "transparent"
                            
                            Row {
                                anchors {
                                    fill: parent
                                    leftMargin: 24
                                    rightMargin: 24
                                }
                                spacing: 12
                                
                                // Avatar
                                AvatarCircle {
                                    anchors.verticalCenter: parent.verticalCenter
                                    size: 42
                                    avatarPath: modelData.avatarPath
                                    initials: modelData.initials
                                    avatarColor: modelData.avatarColor
                                    
                                    MouseArea {
                                        anchors.fill: parent
                                        hoverEnabled: true
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            profileAvatarFileDlg.currentProfileName = modelData.name
                                            profileAvatarFileDlg.open()
                                        }
                                        
                                        Rectangle {
                                            anchors.fill: parent
                                            radius: parent.width / 2
                                            color: "black"
                                            opacity: parent.containsMouse ? 0.3 : 0.0
                                            Behavior on opacity { NumberAnimation { duration: 150 } }
                                            
                                            Text {
                                                anchors.centerIn: parent
                                                text: "📷"
                                                font.pixelSize: 16
                                                visible: parent.parent.containsMouse
                                            }
                                        }
                                    }
                                }
                                
                                // Name
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    width: parent.width - 42 - 32 - 24 - 12
                                    text: modelData.name
                                    color: WAPageTheme.chatListText
                                    font.family: WAPageTheme.fontFamily
                                    font.pixelSize: WAPageTheme.fontSizeNormal
                                    elide: Text.ElideRight
                                }
                                
                                Item { Layout.fillWidth: true; width: 1 }
                                
                                // Delete button
                                Rectangle {
                                    anchors.verticalCenter: parent.verticalCenter
                                    width: 32
                                    height: 32
                                    radius: 16
                                    color: {
                                        const mouseArea = deleteProfileMouse
                                        return mouseArea.containsMouse ? Qt.rgba(1, 0, 0, 0.1) : "transparent"
                                    }
                                    border.width: 1
                                    border.color: {
                                        const mouseArea = deleteProfileMouse
                                        return mouseArea.containsMouse ? "#D4371C" : WAPageTheme.divider
                                    }
                                    
                                    Image {
                                        anchors.centerIn: parent
                                        source: "qrc:/assets/delete.svg"
                                        width: 18
                                        height: 18
                                        sourceSize: Qt.size(18, 18)
                                    }
                                    
                                    MouseArea {
                                        id: deleteProfileMouse
                                        anchors.fill: parent
                                        hoverEnabled: true
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: mainWindow.removeProfileFromLibrary(modelData.name)
                                    }
                                    
                                    Behavior on color { ColorAnimation { duration: 150 } }
                                    Behavior on border.color { ColorAnimation { duration: 150 } }
                                }
                            }
                        }
                    }
                    
                    // Empty state
                    Rectangle {
                        visible: mainWindow.profileLibrary.length === 0
                        width: parent.width
                        height: 80
                        color: "transparent"
                        
                        Text {
                            anchors.centerIn: parent
                            text: langManager.currentTranslations["no_profiles_library"] || "No profiles yet. Click + to add."
                            color: WAPageTheme.chatListSubText
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                            font.italic: true
                        }
                    }
                }
                
                // Other settings (theme, etc.) may be added here in the future
            }
            }
            
            // Enable mouse wheel scrolling
            MouseWheelHandler {
                target: settingsFlickable
            }
        }

        // ── Footer — Copyright (always at bottom) ─────────────────────────
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            color: WAPageTheme.chatListBg
            
            Text {
                anchors {
                    left:         parent.left
                    leftMargin:   24
                    verticalCenter: parent.verticalCenter
                }
                text:           "WAPage " + langManager.currentTranslations["app_version"]
                              + " 1.4.0 © "
                              + langManager.currentTranslations["app_copyright"].replace("%1", "Mahmud Bayramov")
                color:          WAPageTheme.chatListSubText
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeMicro
                wrapMode:       Text.NoWrap
                elide:          Text.ElideRight
                width:          parent.width - 48
            }
        }
    }

    // Language selection — dialog is opened by globalLangDialog in main.qml
    // (appears in the center because it is a direct child of appWindow)
    signal openLangDialog()

    // A file picker that works with my (global) Avatar
    Platform.FileDialog {
        id: myAvatarFileDlg
        title:       "Profil şəklinizi seçin"
        nameFilters: ["Şəkil faylları (*.jpg *.jpeg *.png *.webp)"]
        onAccepted: {
            var path = file.toString()
            if (Qt.platform.os === "windows") {
                path = path.replace("file:///", "")
            } else {
                path = path.replace("file://", "")
            }
            mainWindow.setMyAvatar(path)
        }
    }
    
    // File picker for profile library avatar
    Platform.FileDialog {
        id: profileAvatarFileDlg
        property string currentProfileName: ""
        title: langManager.currentTranslations["image_files_filter"] || "Select image"
        nameFilters: [(langManager.currentTranslations["image_files_filter"] || "Image files (*.jpg *.jpeg *.png *.webp)")]
        onAccepted: {
            var path = file.toString()
            if (Qt.platform.os === "windows") {
                path = path.replace("file:///", "")
            } else {
                path = path.replace("file://", "")
            }
            mainWindow.updateProfileLibraryAvatar(currentProfileName, path)
        }
    }
    
    // Add profile dialog
    Dialog {
        id: addProfileDialog
        anchors.centerIn: parent
        modal: true
        title: langManager.currentTranslations["add_profile"] || "Add Profile"
        width: 400
        
        property string draftName: ""
        property string draftAvatar: ""
        
        onOpened: {
            draftName = ""
            draftAvatar = ""
            profileNameInput.text = ""
            profileNameInput.forceActiveFocus()
        }
        
        // Sharp corners - override default background
        background: Rectangle {
            color: WAPageTheme.profileBg
            radius: 0  // Sharp corners
            border.width: 1
            border.color: WAPageTheme.divider
        }
        
        contentItem: Column {
            spacing: 16
            padding: 20
            
            Text {
                text: langManager.currentTranslations["profile_name_label"] || "Name:"
                color: WAPageTheme.chatListText
                font.family: WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeNormal
            }
            
            TextField {
                id: profileNameInput
                width: parent.width - 40
                selectByMouse: true
                color: WAPageTheme.chatListText
                font.family: WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeNormal
                placeholderText: langManager.currentTranslations["contact_name_placeholder"] || "Contact name"
                placeholderTextColor: WAPageTheme.chatListSubText
                background: Rectangle {
                    radius: 8
                    color: WAPageTheme.panelBg
                    border.width: 1
                    border.color: WAPageTheme.divider
                }
                onTextChanged: addProfileDialog.draftName = text
                onAccepted: {
                    if (addProfileDialog.draftName.trim().length > 0) {
                        const success = mainWindow.addProfileToLibrary(addProfileDialog.draftName.trim(), addProfileDialog.draftAvatar)
                        if (success) {
                            addProfileDialog.close()
                        }
                    }
                }
            }
            
            Row {
                spacing: 12
                width: parent.width - 40
                
                Button {
                    text: langManager.currentTranslations["profile_photo"] || "Select Photo"
                    onClicked: addProfileAvatarFileDlg.open()
                }
                
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: addProfileDialog.draftAvatar.length > 0 
                          ? (langManager.currentTranslations["image_selected"] || "✓ Selected") 
                          : (langManager.currentTranslations["optional"] || "(Optional)")
                    color: addProfileDialog.draftAvatar.length > 0 ? WAPageTheme.accentGreen : WAPageTheme.chatListSubText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
            }
        }
        
        footer: DialogButtonBox {
            Button {
                text: langManager.currentTranslations["add_btn"] || "Add"
                DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole
                enabled: addProfileDialog.draftName.trim().length > 0
                onClicked: {
                    const success = mainWindow.addProfileToLibrary(addProfileDialog.draftName.trim(), addProfileDialog.draftAvatar)
                    if (success) {
                        addProfileDialog.close()
                    }
                }
            }
            Button {
                text: langManager.currentTranslations["cancel"] || "Cancel"
                DialogButtonBox.buttonRole: DialogButtonBox.RejectRole
            }
        }
    }
    
    // File picker for add profile dialog
    Platform.FileDialog {
        id: addProfileAvatarFileDlg
        title: langManager.currentTranslations["image_files_filter"] || "Select image"
        nameFilters: [(langManager.currentTranslations["image_files_filter"] || "Image files (*.jpg *.jpeg *.png *.webp)")]
        onAccepted: {
            var path = file.toString()
            if (Qt.platform.os === "windows") {
                path = path.replace("file:///", "")
            } else {
                path = path.replace("file://", "")
            }
            addProfileDialog.draftAvatar = path
        }
    }
}
