import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Message Explorer Pane — Opens under ChatHeader-in
Rectangle {
    id: root
    color:  WAPageTheme.searchBg
    height: 48
    property color holdColorLight: "#B0B7BE"
    property color holdColorDark:  "#FFFFFF"

    // Search icon - on the left side
    Image {
        id: searchIcon
        source:  "qrc:/assets/icon_search.svg"
        width:   18
        height:  18
        anchors {
            left: parent.left
            leftMargin: 16
            verticalCenter: parent.verticalCenter
        }
        visible: false
    }

    ColorOverlay {
        anchors.fill: searchIcon
        source: searchIcon
        color: WAPageTheme.iconColor
        opacity: 0.7
    }

    // Login area
    TextField {
        id: searchInput
        anchors {
            left: searchIcon.right
            leftMargin: 12
            right: controlsRow.left
            rightMargin: 8
            verticalCenter: parent.verticalCenter
        }
        placeholderText: langManager.currentTranslations["search"]
        color:           WAPageTheme.searchText
        placeholderTextColor: WAPageTheme.searchPlaceholder
        font.family:     WAPageTheme.fontFamily
        font.pixelSize:  WAPageTheme.fontSizeNormal
        background:      Item {}

        onVisibleChanged: if (visible) forceActiveFocus()

        Keys.onEscapePressed: searchCtrl.close()
        Keys.onReturnPressed: {
            if (text.trim().length > 0) {
                // If it's the same query, skip to the next result
                if (searchCtrl.query === text && searchCtrl.resultCount > 0) {
                    searchCtrl.nextResult()
                } else {
                    // Start a new search
                    searchCtrl.setQuery(text)
                }
            }
        }
    }

    // The controller on the right
    Row {
        id: controlsRow
        anchors {
            right: parent.right
            rightMargin: 8
            verticalCenter: parent.verticalCenter
        }
        spacing: 2

        // Result counter
        Text {
            visible:         searchCtrl.resultCount > 0
            anchors.verticalCenter: parent.verticalCenter
            text:            (searchCtrl.currentResult + 1) + "/" + searchCtrl.resultCount
            color:           WAPageTheme.searchPlaceholder
            font.family:     WAPageTheme.fontFamily
            font.pixelSize:  WAPageTheme.fontSizeSmall
            rightPadding:    8
        }

        // No result found message
        Text {
            visible:         searchCtrl.query.length > 0 && searchCtrl.resultCount === 0
            anchors.verticalCenter: parent.verticalCenter
            text:            langManager.currentTranslations["no_results"]
            color:           WAPageTheme.chatListSubText
            font.family:     WAPageTheme.fontFamily
            font.pixelSize:  WAPageTheme.fontSizeSmall
            rightPadding:    8
        }

        // Up button - WAPage style
        Rectangle {
            id: prevBtn
            width: 32
            height: 32
            radius: 16
            property bool pressActive: false
            color: prevBtn.pressActive ? (WAPageTheme.dark ? root.holdColorDark : root.holdColorLight) : "transparent"
            anchors.verticalCenter: parent.verticalCenter
            opacity: searchCtrl.resultCount > 0 ? 1.0 : 0.4

            Behavior on color {
                ColorAnimation {
                    duration: prevBtn.pressActive ? 0 : 80
                    easing.type: Easing.OutCubic
                }
            }

            MouseArea {
                id: prevBtnMouse
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton
                preventStealing: true
                cursorShape: searchCtrl.resultCount > 0 ? Qt.PointingHandCursor : Qt.ArrowCursor
                onPressed: prevBtn.pressActive = true
                onReleased: prevBtn.pressActive = false
                onCanceled: prevBtn.pressActive = false
                onClicked: {
                    if (searchCtrl.resultCount > 0)
                        searchCtrl.prevResult()
                }
            }

            Image {
                id: prevIcon
                anchors.centerIn: parent
                source: "qrc:/assets/icon_arrow_up.svg"
                width: 18
                height: 18
                sourceSize: Qt.size(18, 18)
                visible: false
            }

            ColorOverlay {
                anchors.fill: prevIcon
                source: prevIcon
                color: WAPageTheme.iconColor
            }

        }

        // Down button - WAPage style
        Rectangle {
            id: nextBtn
            width: 32
            height: 32
            radius: 16
            property bool pressActive: false
            color: nextBtn.pressActive ? (WAPageTheme.dark ? root.holdColorDark : root.holdColorLight) : "transparent"
            anchors.verticalCenter: parent.verticalCenter
            opacity: searchCtrl.resultCount > 0 ? 1.0 : 0.4

            Behavior on color {
                ColorAnimation {
                    duration: nextBtn.pressActive ? 0 : 80
                    easing.type: Easing.OutCubic
                }
            }

            MouseArea {
                id: nextBtnMouse
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton
                preventStealing: true
                cursorShape: searchCtrl.resultCount > 0 ? Qt.PointingHandCursor : Qt.ArrowCursor
                onPressed: nextBtn.pressActive = true
                onReleased: nextBtn.pressActive = false
                onCanceled: nextBtn.pressActive = false
                onClicked: {
                    if (searchCtrl.resultCount > 0)
                        searchCtrl.nextResult()
                }
            }

            Image {
                id: nextIcon
                anchors.centerIn: parent
                source: "qrc:/assets/icon_arrow_down.svg"
                width: 18
                height: 18
                sourceSize: Qt.size(18, 18)
                visible: false
            }

            ColorOverlay {
                anchors.fill: nextIcon
                source: nextIcon
                color: WAPageTheme.iconColor
            }

        }

        // Close button - WAPage style
        Rectangle {
            id: closeBtn
            width: 32
            height: 32
            radius: 16
            property bool pressActive: false
            color: closeBtn.pressActive ? (WAPageTheme.dark ? root.holdColorDark : root.holdColorLight) : "transparent"
            anchors.verticalCenter: parent.verticalCenter

            Behavior on color {
                ColorAnimation {
                    duration: closeBtn.pressActive ? 0 : 80
                    easing.type: Easing.OutCubic
                }
            }

            MouseArea {
                id: closeBtnMouse
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton
                preventStealing: true
                cursorShape: Qt.PointingHandCursor
                onPressed: closeBtn.pressActive = true
                onReleased: closeBtn.pressActive = false
                onCanceled: closeBtn.pressActive = false
                onClicked: {
                    searchInput.clear()
                    searchCtrl.close()
                }
            }

            Image {
                id: closeIcon
                anchors.centerIn: parent
                source: "qrc:/assets/icon_close.svg"
                width: 18
                height: 18
                sourceSize: Qt.size(18, 18)
                visible: false
            }

            ColorOverlay {
                anchors.fill: closeIcon
                source: closeIcon
                color: WAPageTheme.iconColor
            }

        }
    }

}
