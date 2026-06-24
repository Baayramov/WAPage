import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import WAPage 1.0

// Each chat row in the left panel
Rectangle {
    id: root

    property int    chatId
    property string contactName
    property string lastMessage
    property string lastTime
    property string avatarPath
    property string initials
    property string avatarColor
    property bool   isSelected: false
    property bool   bulkMode: false
    property bool   isChecked: false

    signal clicked()
    signal checkToggled()

    height: 72
    color:  isSelected ? WAPageTheme.chatListActive : WAPageTheme.chatListBg

    Rectangle {
        id: hoverOverlay
        anchors.fill: parent
        color: WAPageTheme.chatListHover
        opacity: (!root.isSelected && hoverHandler.hovered) ? 1 : 0

        Behavior on opacity {
            NumberAnimation {
                duration: 90
                easing.type: Easing.OutCubic
            }
        }
    }

    HoverHandler {
        id: hoverHandler
    }

    TapHandler {
        acceptedButtons: Qt.LeftButton
        onTapped: {
            if (root.bulkMode) {
                root.checkToggled()
            } else {
                root.clicked()
            }
        }
    }

    Row {
        anchors {
            fill:           parent
            leftMargin:     root.bulkMode ? 4 : 12
            rightMargin:    16
            topMargin:      8
            bottomMargin:   8
        }
        spacing: root.bulkMode ? 4 : 12
        
        Behavior on anchors.leftMargin {
            NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
        }
        
        Behavior on spacing {
            NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
        }

        // Checkbox (only visible in bulk mode)
        Rectangle {
            id: checkboxContainer
            width: root.bulkMode ? 32 : 0
            height: 32
            anchors.verticalCenter: parent.verticalCenter
            visible: root.bulkMode
            opacity: root.bulkMode ? 1.0 : 0.0
            color: "transparent"
            
            Behavior on width {
                NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
            }
            
            Behavior on opacity {
                NumberAnimation { duration: 200 }
            }
            
            Rectangle {
                width: 20
                height: 20
                anchors.centerIn: parent
                radius: 3
                border.width: 2
                border.color: root.isChecked ? "#00A884" : WAPageTheme.iconColor
                color: root.isChecked ? "#00A884" : "transparent"
                
                Behavior on color {
                    ColorAnimation { duration: 150 }
                }
                
                Behavior on border.color {
                    ColorAnimation { duration: 150 }
                }
                
                // Checkmark
                Text {
                    anchors.centerIn: parent
                    text: "✓"
                    color: "#FFFFFF"
                    font.pixelSize: 14
                    font.bold: true
                    visible: root.isChecked
                    opacity: root.isChecked ? 1.0 : 0.0
                    
                    Behavior on opacity {
                        NumberAnimation { duration: 150 }
                    }
                }
            }
        }

        // Avatar
        AvatarCircle {
            anchors.verticalCenter: parent.verticalCenter
            size:        WAPageTheme.avatarSize
            avatarPath:  root.avatarPath
            initials:    root.initials
            avatarColor: root.avatarColor
        }

        // Text data
        Column {
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width - WAPageTheme.avatarSize - (root.bulkMode ? 48 : 12) - 16
            spacing: 3
            
            Behavior on width {
                NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
            }

            // Name + time sequence
            Row {
                width: parent.width

                Text {
                    width:          parent.width - timeText.width - 8
                    text:           root.contactName
                    color:          WAPageTheme.chatListText
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeNormal
                    font.weight:    Font.DemiBold
                    elide:          Text.ElideRight
                }

                Text {
                    id: timeText
                    text:           root.lastTime
                    color:          WAPageTheme.chatListTime
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                }
            }

            // Last message
            Text {
                width:          parent.width
                text: {
                    const m = root.lastMessage
                    if (m === "__deleted_by_me__")
                        return langManager.currentTranslations["you_deleted_message"] || "You deleted this message"
                    if (m === "__deleted__")
                        return langManager.currentTranslations["deleted_message"] || "This message was deleted"
                    return m
                }
                color:          WAPageTheme.chatListSubText
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeSmall
                elide:          Text.ElideRight
                maximumLineCount: 1
            }
        }
    }

    // Bottom dividing line - with avatar alignment (clearer)
    Rectangle {
        id: dividerLine
        anchors.bottom: parent.bottom
        anchors.left:   parent.left
        // Start from the right edge of the avatar (avatar left margin + avatar size)
        anchors.leftMargin: (root.bulkMode ? 4 : 12) + (root.bulkMode ? 32 : 0) + WAPageTheme.avatarSize + (root.bulkMode ? 4 : 12)
        width:  parent.width - anchors.leftMargin
        height: 1
        color:  WAPageTheme.divider
        opacity: 0.7
        
        Behavior on anchors.leftMargin {
            NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
        }
    }
}
