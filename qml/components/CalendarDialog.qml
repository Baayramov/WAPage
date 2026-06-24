import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import WAPage 1.0

// Calendar dialog for date-based navigation
Rectangle {
    id: root
    width: 340
    height: monthSelectorExpanded ? 520 : 420
    radius: 12
    color: WAPageTheme.panelBg
    visible: false
    z: 1000

    property var messageDates: []  // List of dates with messages (YYYY-MM-DD)
    property int currentYear: new Date().getFullYear()
    property int currentMonth: new Date().getMonth() // 0-11
    property bool monthSelectorExpanded: false

    signal dateSelected(string date)

    Behavior on height {
        NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
    }

    // Catch all mouse events inside dialog to prevent closing
    MouseArea {
        anchors.fill: parent
        onClicked: {} // Do nothing, just catch the event
        onPressed: {} // Catch press too
        onReleased: {} // And release
    }

    function open() {
        // Load message dates from MainWindow
        const dates = mainWindow.getMessageDatesForCurrentChat()
        root.messageDates = dates
        
        // Set to last message date if available
        if (dates.length > 0) {
            const lastDate = new Date(dates[dates.length - 1])
            root.currentYear = lastDate.getFullYear()
            root.currentMonth = lastDate.getMonth()
        }
        
        root.monthSelectorExpanded = false
        root.visible = true
    }

    function close() {
        root.visible = false
        root.monthSelectorExpanded = false
    }

    function hasMessagesOnDate(year, month, day) {
        const dateStr = Qt.formatDate(new Date(year, month, day), "yyyy-MM-dd")
        return root.messageDates.indexOf(dateStr) >= 0
    }

    function getDaysInMonth(year, month) {
        return new Date(year, month + 1, 0).getDate()
    }

    function getFirstDayOfMonth(year, month) {
        return new Date(year, month, 1).getDay() // 0=Sunday
    }

    function getMonthName(monthIndex) {
        // Get month names from LanguageManager translations
        const monthKeys = [
            "january", "february", "march", "april", "may", "june",
            "july", "august", "september", "october", "november", "december"
        ]
        const monthName = langManager.currentTranslations[monthKeys[monthIndex]]
        return monthName || ["January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"][monthIndex]
    }

    Column {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12

        // Year selector
        Rectangle {
            width: parent.width
            height: 36
            radius: 6
            color: WAPageTheme.dark ? "#2A3942" : "#E9EDEF"

            Row {
                anchors.centerIn: parent
                spacing: 8

                Rectangle {
                    width: 28
                    height: 28
                    radius: 14
                    color: prevYearMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.15) : "transparent"

                    Text {
                        anchors.centerIn: parent
                        text: "◀"
                        color: WAPageTheme.chatListText
                        font.pixelSize: 12
                    }

                    MouseArea {
                        id: prevYearMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: root.currentYear--
                    }
                }

                Text {
                    text: root.currentYear
                    color: WAPageTheme.chatListText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: 16
                    font.weight: Font.DemiBold
                    anchors.verticalCenter: parent.verticalCenter
                }

                Rectangle {
                    width: 28
                    height: 28
                    radius: 14
                    color: nextYearMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.15) : "transparent"

                    Text {
                        anchors.centerIn: parent
                        text: "▶"
                        color: WAPageTheme.chatListText
                        font.pixelSize: 12
                    }

                    MouseArea {
                        id: nextYearMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: root.currentYear++
                    }
                }
            }
        }

        // Month selector - collapsed/expanded
        Rectangle {
            width: parent.width
            height: 36
            radius: 6
            color: monthSelectorMouse.containsMouse ? (WAPageTheme.dark ? "#3A4A54" : "#DFE5E7") : (WAPageTheme.dark ? "#2A3942" : "#E9EDEF")

            Row {
                anchors.centerIn: parent
                spacing: 8

                Text {
                    text: root.getMonthName(root.currentMonth)
                    color: WAPageTheme.chatListText
                    font.family: WAPageTheme.fontFamily
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text: root.monthSelectorExpanded ? "▲" : "▼"
                    color: WAPageTheme.chatListSubText
                    font.pixelSize: 10
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            MouseArea {
                id: monthSelectorMouse
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: root.monthSelectorExpanded = !root.monthSelectorExpanded
            }
        }

        // Month grid - expandable
        Grid {
            width: parent.width
            height: root.monthSelectorExpanded ? 108 : 0
            visible: height > 0
            clip: true
            columns: 4
            columnSpacing: 4
            rowSpacing: 4

            Behavior on height {
                NumberAnimation { duration: 200; easing.type: Easing.OutCubic }
            }

            Repeater {
                model: 12
                
                Rectangle {
                    width: (parent.width - 12) / 4
                    height: 32
                    radius: 4
                    color: {
                        if (index === root.currentMonth) return WAPageTheme.accent
                        if (monthMouse.containsMouse) return Qt.rgba(0, 0, 0, 0.1)
                        return "transparent"
                    }

                    Text {
                        anchors.centerIn: parent
                        text: root.getMonthName(index)
                        color: index === root.currentMonth ? "#FFFFFF" : WAPageTheme.chatListText
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: 12
                        font.weight: index === root.currentMonth ? Font.DemiBold : Font.Normal
                    }

                    MouseArea {
                        id: monthMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            root.currentMonth = index
                            root.monthSelectorExpanded = false
                        }
                    }
                }
            }
        }

        // Calendar grid - days only (no weekday headers)
        Grid {
            width: parent.width
            columns: 7
            columnSpacing: 2
            rowSpacing: 2

            Repeater {
                model: 42 // 6 weeks max
                
                delegate: Rectangle {
                    width: (parent.width - 12) / 7
                    height: 36
                    radius: 4
                    
                    property int dayOffset: index - root.getFirstDayOfMonth(root.currentYear, root.currentMonth)
                    property int dayNumber: dayOffset + 1
                    property bool isValidDay: dayNumber > 0 && dayNumber <= root.getDaysInMonth(root.currentYear, root.currentMonth)
                    property bool hasMessages: isValidDay && root.hasMessagesOnDate(root.currentYear, root.currentMonth, dayNumber)
                    
                    color: {
                        if (!isValidDay) return "transparent"
                        if (dayMouse.containsMouse && hasMessages) return WAPageTheme.accent
                        return "transparent"
                    }

                    Text {
                        anchors.centerIn: parent
                        text: parent.isValidDay ? parent.dayNumber : ""
                        color: {
                            if (!parent.isValidDay) return "transparent"
                            if (parent.hasMessages) return WAPageTheme.chatListText
                            return WAPageTheme.chatListSubText
                        }
                        opacity: parent.hasMessages ? 1.0 : 0.3
                        font.family: WAPageTheme.fontFamily
                        font.pixelSize: 14
                        font.weight: parent.hasMessages ? Font.DemiBold : Font.Normal
                    }

                    MouseArea {
                        id: dayMouse
                        anchors.fill: parent
                        enabled: parent.hasMessages
                        hoverEnabled: parent.hasMessages
                        cursorShape: parent.hasMessages ? Qt.PointingHandCursor : Qt.Arrow
                        onClicked: {
                            if (parent.hasMessages) {
                                const dateStr = Qt.formatDate(new Date(root.currentYear, root.currentMonth, parent.dayNumber), "yyyy-MM-dd")
                                root.dateSelected(dateStr)
                                root.close()
                            }
                        }
                    }
                }
            }
        }

        // Spacer
        Item { width: parent.width; height: 5 }

        // Close button - smaller
        Rectangle {
            width: parent.width
            height: 32
            radius: 6
            color: closeBtnMouse.containsMouse ? WAPageTheme.accent : WAPageTheme.divider

            Text {
                anchors.centerIn: parent
                text: langManager.currentTranslations["cancel"] || "Cancel"
                color: WAPageTheme.chatListText
                font.family: WAPageTheme.fontFamily
                font.pixelSize: 13
                font.weight: Font.Medium
            }

            MouseArea {
                id: closeBtnMouse
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: root.close()
            }
        }
    }
}
