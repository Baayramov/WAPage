import QtQuick 2.15
import QtQuick.Controls 2.15

// Notification toast — for error and success messages
Rectangle {
    id: root
    width:   toastText.width + 32
    height:  44
    radius:  22
    opacity: 0
    color:   "#323232"

    property bool isSuccess: false

    Text {
        id: toastText
        anchors.centerIn: parent
        color:            "#FFFFFF"
        font.family:      WAPageTheme.fontFamily
        font.pixelSize:   WAPageTheme.fontSizeSmall
        maximumLineCount: 2
        wrapMode:         Text.WordWrap
    }

    function show(msg) {
        root.color     = "#323232"
        root.isSuccess = false
        toastText.text = msg
        showAnim.restart()
    }

    function showSuccess(msg) {
        root.color     = "#25D366"
        root.isSuccess = true
        toastText.text = msg
        showAnim.restart()
    }

    SequentialAnimation {
        id: showAnim
        NumberAnimation { target: root; property: "opacity"; to: 1;   duration: 200 }
        PauseAnimation  { duration: 3000 }
        NumberAnimation { target: root; property: "opacity"; to: 0;   duration: 400 }
    }
}
