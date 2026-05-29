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
            height: WAPageTheme.headerHeight + 30 // wider
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
                text:           langManager.currentTranslations["my_profile"]
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
        ScrollView {
            Layout.fillWidth:  true
            Layout.fillHeight: true
            clip:              true
            ScrollBar.vertical.policy:   ScrollBar.AsNeeded
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

            Column {
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

                Rectangle { width: parent.width; height: 1; color: WAPageTheme.divider; opacity: 0.5 }
                
                // Other settings (theme, etc.) may be added here in the future
            }
        }

        // Footer — version + copyright, bottom-left, theme- and language-aware
        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                anchors {
                    left:         parent.left
                    bottom:       parent.bottom
                    leftMargin:   16
                    bottomMargin: 12
                }
                text:           "WAPage " + langManager.currentTranslations["app_version"]
                              + " 1.3.0 © "
                              + langManager.currentTranslations["app_copyright"].replace("%1", "Mahmud Bayramov")
                color:          WAPageTheme.chatListSubText
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeMicro
                wrapMode:       Text.NoWrap
                elide:          Text.ElideRight
                width:          parent.width - 24
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
}
