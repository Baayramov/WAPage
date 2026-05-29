import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1 as Platform
import WAPage 1.0

// Import dialog — choose ZIP file + ask for owner name
Rectangle {
    id: root
    color: "#80000000"

    // Step: 1=select file, 2=ask for name, 3=loading
    property int    step:         1
    property string selectedZip:  ""
    property string ownerName:    ""

    function reset() {
        step        = 1
        selectedZip = ""
        ownerName   = ""
        ownerInput.text = ""
    }

    MouseArea {
        anchors.fill: parent
        onClicked:    if (!mainWindow.isImporting) { root.visible = false; root.reset() }
    }

    // Central card
    Rectangle {
        anchors.centerIn: parent
        width:   420
        height:  contentCol.height + 48
        radius:  12
        color:   WAPageTheme.panelBg

        MouseArea { anchors.fill: parent } // stop background clicking

        ColumnLayout {
            id: contentCol
            anchors {
                top:        parent.top
                left:       parent.left
                right:      parent.right
                topMargin:  24
                leftMargin: 24
                rightMargin:24
            }

            // Title
            Text {
                Layout.fillWidth: true
                text:           step === 3 ? langManager.currentTranslations["importing"] : langManager.currentTranslations["import_new"]
                color:          step === 3 ? WAPageTheme.accentGreen : WAPageTheme.chatListText
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: 18
                font.weight:    Font.Medium
                horizontalAlignment: step === 3 ? Text.AlignHCenter : Text.AlignLeft
            }

            // ── Step 1: Select ZIP ──────────────────────────────
            ColumnLayout {
                visible:  root.step === 1
                Layout.fillWidth: true
                spacing:  12

                Text {
                    Layout.fillWidth: true
                    text:       langManager.currentTranslations["zip_description"]
                    color:      WAPageTheme.chatListSubText
                    font.family:WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    wrapMode:   Text.WordWrap
                }

                // The selected file pointer
                Rectangle {
                    Layout.fillWidth: true
                    height:  48
                    radius:  8
                    color:   WAPageTheme.searchBg
                    visible: root.selectedZip.length > 0

                    Row {
                        anchors { fill: parent; leftMargin: 12; rightMargin: 12 }
                        spacing: 8
                        Image {
                            source: "qrc:/assets/icon_zip.svg"
                            width:  20; height: 20
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Text {
                            width: parent.width - 40
                            anchors.verticalCenter: parent.verticalCenter
                            text:           root.selectedZip.split("/").pop()
                                             || root.selectedZip.split("\\").pop()
                            color:          WAPageTheme.chatListText
                            font.family:    WAPageTheme.fontFamily
                            font.pixelSize: WAPageTheme.fontSizeSmall
                            elide:          Text.ElideMiddle
                        }
                    }
                }

                // Select ZIP button
                Button {
                    Layout.fillWidth: true
                    text:    root.selectedZip.length > 0
                             ? langManager.currentTranslations["change_zip"] : langManager.currentTranslations["select_zip"]
                    onClicked: zipFileDlg.open()

                    background: Rectangle {
                        radius: 8
                        color:  parent.pressed ? "#006654" : WAPageTheme.accent
                    }
                    contentItem: Text {
                        text:  parent.text
                        color: "#FFFFFF"
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeNormal
                        horizontalAlignment: Text.AlignHCenter
                    }
                }

                // Forward button
                Button {
                    Layout.fillWidth: true
                    visible:  root.selectedZip.length > 0
                    text:     langManager.currentTranslations["continue"]
                    onClicked: root.step = 2

                    background: Rectangle {
                        radius: 8
                        color:  parent.pressed ? Qt.darker(WAPageTheme.accent, 1.1)
                                               : WAPageTheme.accent
                        opacity: 0.85
                    }
                    contentItem: Text {
                        text:  parent.text
                        color: "#FFFFFF"
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeNormal
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }

            // ── Step 2: Enter your name ────────────────────
            ColumnLayout {
                visible:  root.step === 2
                Layout.fillWidth: true
                spacing:  12

                Text {
                    Layout.fillWidth: true
                    text:       langManager.currentTranslations["owner_question"]
                    color:      WAPageTheme.chatListSubText
                    font.family:WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    wrapMode:   Text.WordWrap
                }

                // Name input field
                Rectangle {
                    Layout.fillWidth: true
                    height:  48
                    radius:  8
                    color:   WAPageTheme.searchBg
                    border.color: ownerInput.activeFocus
                                  ? WAPageTheme.accent : "transparent"
                    border.width: 1.5

                    TextField {
                        id: ownerInput
                        anchors { fill: parent; leftMargin: 12; rightMargin: 12 }
                        placeholderText: langManager.currentTranslations["owner_placeholder"]
                        color:           WAPageTheme.searchText
                        font.family:     WAPageTheme.fontFamily
                        font.pixelSize:  WAPageTheme.fontSizeNormal
                        background:      Item {}
                        onTextChanged:   root.ownerName = text

                        Component.onCompleted: if (root.step === 2) forceActiveFocus()
                        Keys.onReturnPressed:   importBtn.clicked()
                    }
                }

                // Import button
                Button {
                    id: importBtn
                    Layout.fillWidth: true
                    text:    langManager.currentTranslations["import_btn"]
                    enabled: root.ownerName.trim().length > 0

                    onClicked: {
                        root.step = 3
                        mainWindow.importZip(root.selectedZip, root.ownerName.trim())
                    }

                    background: Rectangle {
                        radius:  8
                        color:   parent.enabled
                                 ? (parent.pressed
                                    ? Qt.darker(WAPageTheme.accentGreen, 1.1)
                                    : WAPageTheme.accentGreen)
                                 : WAPageTheme.searchBg
                    }
                    contentItem: Text {
                        text:  parent.text
                        color: parent.enabled ? "#FFFFFF" : WAPageTheme.chatListSubText
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeNormal
                        horizontalAlignment: Text.AlignHCenter
                    }
                }

                // Go back
                Button {
                    Layout.fillWidth: true
                    text:    langManager.currentTranslations["back"]
                    onClicked: root.step = 1

                    background: Rectangle {
                        radius:  8
                        color:   "transparent"
                        border.color: parent.pressed ? Qt.darker(WAPageTheme.accent, 1.1) : WAPageTheme.divider
                        border.width: 1
                        opacity: 0.8
                    }
                    contentItem: Text {
                        text:  parent.text
                        color: WAPageTheme.chatListSubText
                        font.family:    WAPageTheme.fontFamily
                        font.pixelSize: WAPageTheme.fontSizeNormal
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }

            // ── Step 3: Loading ────────────────────────────
            ColumnLayout {
                visible: root.step === 3
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                spacing: 18

                Item {
                    id: importSpinner
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 10
                    implicitWidth: 52
                    implicitHeight: 52

                    Rectangle {
                        anchors.fill: parent
                        radius: width / 2
                        color: "transparent"
                        border.width: 3
                        border.color: WAPageTheme.dark ? "#5C6A73" : "#AAB7BF"
                    }

                    Item {
                        anchors.fill: parent
                        transformOrigin: Item.Center

                        RotationAnimator on rotation {
                            from: 0
                            to: 360
                            duration: 900
                            loops: Animation.Infinite
                            running: root.step === 3
                            easing.type: Easing.Linear
                        }

                        Canvas {
                            id: importArc
                            anchors.fill: parent
                            antialiasing: true

                            onWidthChanged: requestPaint()
                            onHeightChanged: requestPaint()
                            onPaint: {
                                const ctx = getContext("2d")
                                ctx.clearRect(0, 0, width, height)

                                const lineW = 3
                                const cx = width / 2
                                const cy = height / 2
                                const r = Math.max(0, Math.min(width, height) / 2 - lineW / 2)

                                ctx.beginPath()
                                ctx.lineWidth = lineW
                                ctx.lineCap = "round"
                                ctx.strokeStyle = WAPageTheme.accentGreen
                                ctx.arc(cx, cy, r, -Math.PI * 0.78, Math.PI * 0.18, false)
                                ctx.stroke()
                            }

                            Component.onCompleted: requestPaint()
                        }
                    }
                }

                Text {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.fillWidth: true
                    text:       langManager.currentTranslations["loading_messages"]
                    color:      WAPageTheme.accentGreen
                    font.family:WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    horizontalAlignment: Text.AlignHCenter
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 8
                    radius: 0
                    color: WAPageTheme.dark ? "#51606A" : "#C6CED3"

                    Rectangle {
                        anchors {
                            left: parent.left
                            top: parent.top
                            bottom: parent.bottom
                        }
                        radius: 0
                        color: WAPageTheme.accentGreen
                        width: parent.width * Math.max(0, Math.min(1, mainWindow.importProgress))

                        Behavior on width {
                            NumberAnimation {
                                duration: 160
                                easing.type: Easing.OutCubic
                            }
                        }
                    }
                }

                Text {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.fillWidth: true
                    color: WAPageTheme.chatListSubText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: Math.max(11, WAPageTheme.fontSizeSmall - 1)
                    horizontalAlignment: Text.AlignHCenter
                    text: {
                        const percent = Math.max(0, Math.min(100, mainWindow.importProgress * 100))
                        return percent.toFixed(1) + "%"
                    }
                }
            }
        }
    }

    // Close the dialog when the import is complete
    Connections {
        target: mainWindow
        function onImportSuccess(contactName, messageCount) {
            root.visible = false
            root.reset()
        }
        function onImportError(message) {
            root.step = 1  // Return if error
        }
    }

    // ZIP file selector
    Platform.FileDialog {
        id: zipFileDlg
        title:       langManager.currentTranslations["select_zip_title"]
        nameFilters: ["ZIP faylları (*.zip)"]
        onAccepted: {
            var path = file.toString()
            // On Windows: file:///C:/path → C:/path
            // On Linux:   file:///home/user/path → /home/user/path
            if (Qt.platform.os === "windows") {
                path = path.replace("file:///", "")
            } else {
                path = path.replace("file://", "")
            }
            root.selectedZip = path
        }
    }
}
