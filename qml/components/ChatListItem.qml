import QtQuick 2.15
import QtQuick.Controls 2.15

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

    signal clicked()

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
        onTapped: root.clicked()
    }

    Row {
        anchors {
            fill:           parent
            leftMargin:     12
            rightMargin:    16
            topMargin:      8
            bottomMargin:   8
        }
        spacing: 12

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
            width: parent.width - WAPageTheme.avatarSize - 12 - 16
            spacing: 3

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
        anchors.leftMargin: 12 + WAPageTheme.avatarSize + 12  // 12 + 40 + 12 = 64
        width:  parent.width - (12 + WAPageTheme.avatarSize + 12)
        height: 1
        color:  WAPageTheme.divider
        opacity: 0.7  // Brighter appearance
    }
}
