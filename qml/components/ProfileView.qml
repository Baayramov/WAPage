import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1 as Platform
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Contact profile view
// It comes sliding in from the right
Rectangle {
    id: root
    color: WAPageTheme.profileBg

    property bool nameEditMode: false
    property string draftChatName: ""
    property string participantAvatarTargetName: ""

    // Prevent clicks from going to messages in the background (consume mouse events)
    MouseArea {
        anchors.fill: parent
        onClicked: {}
    }

    function open() {
        root.draftChatName = mainWindow.activeChatName
        root.nameEditMode = false
        root.participantAvatarTargetName = ""
        root.visible = true
    }

    function close() {
        root.nameEditMode = false
        root.participantAvatarTargetName = ""
        root.visible = false
    }

    function saveChatName() {
        const trimmed = root.draftChatName.trim()
        if (trimmed.length === 0 || mainWindow.activeChatId < 0) {
            root.draftChatName = mainWindow.activeChatName
            root.nameEditMode = false
            return
        }
        mainWindow.setChatName(mainWindow.activeChatId, trimmed)
        root.draftChatName = trimmed
        root.nameEditMode = false
    }

    // Login animation
    property real slideX: root.visible ? 0 : root.width
    x: slideX
    Behavior on x { NumberAnimation { duration: 200; easing.type: Easing.OutCubic } }

    Connections {
        target: mainWindow
        function onActiveChatChanged() {
            if (!root.nameEditMode) {
                root.draftChatName = mainWindow.activeChatName
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing:      0

        // ── Header ──────────────────────────────────────────────
        Rectangle {
            Layout.fillWidth: true
            height: WAPageTheme.headerHeight
            color:  WAPageTheme.profileHeaderBg

            // Back button - WAPage style
            Rectangle {
                id: backBtn
                width: 40
                height: 40
                radius: 20
                color: backBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.1) : "transparent"
                anchors {
                    left: parent.left
                    leftMargin: 8
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

            Text {
                anchors {
                    left: backBtn.right
                    leftMargin: 12
                    verticalCenter: parent.verticalCenter
                }
                text:           langManager.currentTranslations["contact_info"]
                color:          "#FFFFFF"
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: 18
                font.weight:    Font.Medium
            }
        }

        // Avatar section
        Rectangle {
            Layout.fillWidth: true
            height:  260
            color:   WAPageTheme.profileHeaderBg

            Column {
                anchors.centerIn: parent
                spacing: 16

                // Large avatar — clickable (change image)
                AvatarCircle {
                    anchors.horizontalCenter: parent.horizontalCenter
                    size:        WAPageTheme.avatarSizeLarge
                    avatarPath:  mainWindow.activeChatAvatar
                    initials:    mainWindow.activeChatInitials
                    avatarColor: mainWindow.activeChatColor

                    MouseArea {
                        anchors.fill: parent
                        cursorShape:  Qt.PointingHandCursor
                        onClicked:    avatarFileDlg.open()
                    }
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           mainWindow.activeChatName
                    color:          "#FFFFFF"
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: 20
                    font.weight:    Font.Medium
                }
            }
        }

        // ── About / sections ───────────────────────────────
        ScrollView {
            Layout.fillWidth:  true
            Layout.fillHeight: true
            clip:              true
            ScrollBar.vertical.policy:   ScrollBar.AlwaysOff
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

            Column {
                width: root.width
                spacing: 0

                // Editable name block (WAPage-like)
                Rectangle {
                    width: parent.width
                    height: root.nameEditMode ? 108 : 72
                    color: "transparent"

                    Column {
                        anchors {
                            fill: parent
                            leftMargin: 20
                            rightMargin: 20
                            topMargin: 12
                            bottomMargin: 12
                        }
                        spacing: 6

                        Text {
                            text: langManager.currentTranslations["name_label"]
                                  ? langManager.currentTranslations["name_label"]
                                  : "Name"
                            color: WAPageTheme.accent
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                        }

                        RowLayout {
                            width: parent.width
                            spacing: 8

                            TextField {
                                id: nameInput
                                visible: root.nameEditMode
                                Layout.fillWidth: true
                                text: root.draftChatName
                                selectByMouse: true
                                color: WAPageTheme.chatListText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                                placeholderText: langManager.currentTranslations["contact_name_placeholder"]
                                                 ? langManager.currentTranslations["contact_name_placeholder"]
                                                 : "Contact name"
                                placeholderTextColor: WAPageTheme.chatListSubText
                                background: Rectangle {
                                    radius: 8
                                    color: WAPageTheme.panelBg
                                    border.width: 1
                                    border.color: WAPageTheme.accent
                                }
                                onTextChanged: root.draftChatName = text
                                onAccepted: root.saveChatName()
                            }

                            Text {
                                visible: !root.nameEditMode
                                Layout.fillWidth: true
                                text: mainWindow.activeChatName
                                color: WAPageTheme.chatListText
                                font.family: WAPageTheme.fontFamily
                                font.pixelSize: WAPageTheme.fontSizeNormal
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }

                            Rectangle {
                                id: editOrSaveBtn
                                width: 32
                                height: 32
                                radius: 16
                                color: editOrSaveMouse.containsMouse ? Qt.rgba(0, 0, 0, 0.08) : "transparent"
                                border.width: root.nameEditMode ? 0 : 1
                                border.color: WAPageTheme.divider

                                Text {
                                    anchors.centerIn: parent
                                    text: root.nameEditMode ? "✓" : "✎"
                                    color: root.nameEditMode ? WAPageTheme.accentGreen : WAPageTheme.chatListSubText
                                    font.family: WAPageTheme.fontFamily
                                    font.pixelSize: 16
                                    font.weight: Font.Medium
                                }

                                MouseArea {
                                    id: editOrSaveMouse
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        if (!root.nameEditMode) {
                                            root.draftChatName = mainWindow.activeChatName
                                            root.nameEditMode = true
                                            nameInput.forceActiveFocus()
                                            nameInput.selectAll()
                                            return
                                        }
                                        root.saveChatName()
                                    }
                                }
                            }

                            Rectangle {
                                visible: root.nameEditMode
                                width: 32
                                height: 32
                                radius: 16
                                color: cancelNameMouse.containsMouse ? Qt.rgba(0, 0, 0, 0.08) : "transparent"
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
                                    id: cancelNameMouse
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        root.draftChatName = mainWindow.activeChatName
                                        root.nameEditMode = false
                                    }
                                }
                            }
                        }
                    }
                }

                Rectangle { width: parent.width; height: 1; color: WAPageTheme.divider; opacity: 0.5 }

                // Message number
                ProfileInfoRow {
                    icon:  "qrc:/assets/icon_message.svg"
                    label: langManager.currentTranslations["msg_count"]
                    value: mainWindow.messageModel.totalCount + " " + langManager.currentTranslations["messages"]
                }

                Rectangle { width: parent.width; height: 1; color: WAPageTheme.divider; opacity: 0.5 }

                // Import tarixi
                ProfileInfoRow {
                    icon:  "qrc:/assets/icon_calendar.svg"
                    label: langManager.currentTranslations["import_date"]
                    // We reactivate the binding by adding langManager.currentLanguage
                    value: langManager.formatDate(mainWindow.activeChatImportedAt) + (langManager.currentLanguage ? "" : "")
                }

                Rectangle {
                    visible: mainWindow.activeChatIsGroup
                    width: parent.width
                    height: visible ? participantsContent.implicitHeight + 24 : 0
                    color: "transparent"

                    Column {
                        id: participantsContent
                        width: parent.width - 40
                        anchors {
                            top: parent.top
                            topMargin: 12
                            left: parent.left
                            leftMargin: 20
                            right: parent.right
                            rightMargin: 20
                        }
                        spacing: 8

                        Text {
                            text: (langManager.currentTranslations["participants_label"]
                                   ? langManager.currentTranslations["participants_label"]
                                   : "Qrup iştirakçıları")
                                  + " (" + mainWindow.activeChatParticipantCount + ")"
                            color: WAPageTheme.accent
                            font.family: WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeMicro
                        }

                        Repeater {
                            model: mainWindow.activeChatParticipants

                            delegate: Rectangle {
                                property bool editMode: false
                                property string originalName: modelData.name || ""
                                property string draftName: modelData.name || ""

                                width: participantsContent.width
                                height: editMode ? 72 : 56
                                radius: 8
                                color: WAPageTheme.panelBg
                                border.width: 1
                                border.color: WAPageTheme.divider

                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    spacing: 10

                                    AvatarCircle {
                                        size: 34
                                        avatarPath: modelData.avatarPath || ""
                                        initials: modelData.initials || "?"
                                        avatarColor: modelData.avatarColor || "#00BFA5"

                                        MouseArea {
                                            anchors.fill: parent
                                            cursorShape: Qt.PointingHandCursor
                                            onClicked: {
                                                root.participantAvatarTargetName = originalName
                                                participantAvatarFileDlg.open()
                                            }
                                        }
                                    }

                                    ColumnLayout {
                                        Layout.fillWidth: true
                                        spacing: 4

                                        TextField {
                                            id: participantNameInput
                                            visible: editMode
                                            Layout.fillWidth: true
                                            text: draftName
                                            selectByMouse: true
                                            color: WAPageTheme.chatListText
                                            font.family: WAPageTheme.fontFamily
                                            font.pixelSize: WAPageTheme.fontSizeNormal
                                            placeholderText: langManager.currentTranslations["contact_name_placeholder"]
                                                             ? langManager.currentTranslations["contact_name_placeholder"]
                                                             : "Ad"
                                            placeholderTextColor: WAPageTheme.chatListSubText
                                            background: Rectangle {
                                                radius: 8
                                                color: WAPageTheme.panelBg
                                                border.width: 1
                                                border.color: WAPageTheme.accent
                                            }
                                            onTextChanged: draftName = text
                                            onAccepted: {
                                                const trimmed = draftName.trim()
                                                if (trimmed.length > 0) {
                                                    mainWindow.setParticipantName(mainWindow.activeChatId, originalName, trimmed)
                                                }
                                                editMode = false
                                            }
                                        }

                                        Text {
                                            visible: !editMode
                                            Layout.fillWidth: true
                                            text: originalName
                                            color: WAPageTheme.chatListText
                                            font.family: WAPageTheme.fontFamily
                                            font.pixelSize: WAPageTheme.fontSizeNormal
                                            elide: Text.ElideRight
                                        }
                                    }

                                    Rectangle {
                                        id: participantEditOrSaveBtn
                                        width: 32
                                        height: 32
                                        radius: 16
                                        color: participantEditOrSaveMouse.containsMouse ? Qt.rgba(0, 0, 0, 0.08) : "transparent"
                                        border.width: editMode ? 0 : 1
                                        border.color: WAPageTheme.divider

                                        Text {
                                            anchors.centerIn: parent
                                            text: editMode ? "✓" : "✎"
                                            color: editMode ? WAPageTheme.accentGreen : WAPageTheme.chatListSubText
                                            font.family: WAPageTheme.fontFamily
                                            font.pixelSize: 14
                                            font.weight: Font.Medium
                                        }

                                        MouseArea {
                                            id: participantEditOrSaveMouse
                                            anchors.fill: parent
                                            hoverEnabled: true
                                            cursorShape: Qt.PointingHandCursor
                                            onClicked: {
                                                if (!editMode) {
                                                    draftName = originalName
                                                    editMode = true
                                                    participantNameInput.forceActiveFocus()
                                                    participantNameInput.selectAll()
                                                    return
                                                }
                                                const trimmed = draftName.trim()
                                                if (trimmed.length > 0) {
                                                    mainWindow.setParticipantName(mainWindow.activeChatId, originalName, trimmed)
                                                }
                                                editMode = false
                                            }
                                        }
                                    }

                                    Rectangle {
                                        visible: editMode
                                        width: 32
                                        height: 32
                                        radius: 16
                                        color: participantCancelMouse.containsMouse ? Qt.rgba(0, 0, 0, 0.08) : "transparent"
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
                                            id: participantCancelMouse
                                            anchors.fill: parent
                                            hoverEnabled: true
                                            cursorShape: Qt.PointingHandCursor
                                            onClicked: {
                                                draftName = originalName
                                                editMode = false
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Avatar file selector
    Platform.FileDialog {
        id: avatarFileDlg
        title:       langManager.currentTranslations["profile_photo"]
        nameFilters: [langManager.currentTranslations["image_files_filter"]
                      ? langManager.currentTranslations["image_files_filter"]
                      : "Image files (*.jpg *.jpeg *.png *.webp)"]
        onAccepted: {
            var path = file.toString()
            if (Qt.platform.os === "windows") {
                path = path.replace("file:///", "")
            } else {
                path = path.replace("file://", "")
            }
            mainWindow.setChatAvatar(mainWindow.activeChatId, path)
        }
    }

    Platform.FileDialog {
        id: participantAvatarFileDlg
        title:       langManager.currentTranslations["profile_photo"]
        nameFilters: [langManager.currentTranslations["image_files_filter"]
                      ? langManager.currentTranslations["image_files_filter"]
                      : "Image files (*.jpg *.jpeg *.png *.webp)"]
        onAccepted: {
            var path = file.toString()
            if (Qt.platform.os === "windows") {
                path = path.replace("file:///", "")
            } else {
                path = path.replace("file://", "")
            }
            if (mainWindow.activeChatId >= 0 && root.participantAvatarTargetName.length > 0) {
                mainWindow.setParticipantAvatar(mainWindow.activeChatId,
                                                root.participantAvatarTargetName,
                                                path)
            }
        }
    }

    // Auxiliary component
    component ProfileInfoRow: Rectangle {
        property string icon:  ""
        property string label: ""
        property string value: ""

        width:  parent.width
        height: 56
        color:  "transparent"

        Row {
            anchors {
                fill:        parent
                leftMargin:  20
                rightMargin: 20
            }
            spacing: 16

            Item {
                width:  22
                height: 22
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    id: rowIcon
                    source:   icon
                    width:    22
                    height:   22
                    visible:  false
                }

                ColorOverlay {
                    anchors.fill: rowIcon
                    source:       rowIcon
                    color:        WAPageTheme.dark ? "#FFFFFF" : "#4A4A4A"
                    opacity:      0.75
                }
            }

            Column {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2
                Text {
                    text:           label
                    color:          WAPageTheme.chatListSubText
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
                Text {
                    text:           value
                    color:          WAPageTheme.chatListText
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeNormal
                }
            }
        }
    }
}
