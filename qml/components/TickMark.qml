import QtQuick 2.15
import QtQuick.Controls 2.15
import WAPage 1.0

// WAPage read icon
// readStatus: 1 = single gray tick, 2 = double gray tick, 3 = double blue tick
Row {
    id: root
    property int readStatus: 3
    spacing: root.readStatus === 3 ? 0 : -8

    Image {
        visible: root.readStatus === 3
        source: "qrc:/assets/read.svg"
        width: 18
        height: 11
        sourceSize.width: 18
        sourceSize.height: 11
        fillMode: Image.Stretch
        smooth: true
        mipmap: true
    }

    // First tick
    Canvas {
        id: tick1
        width:  14
        height: 10
        visible: root.readStatus !== 3
        onPaint: drawTick(getContext("2d"), false)

        function drawTick(ctx, offset) {
            ctx.clearRect(0, 0, width, height)
            ctx.strokeStyle = root.readStatus === 3
                              ? WAPageTheme.tickBlue
                              : WAPageTheme.tickGray
            ctx.lineWidth   = 1.5
            ctx.lineCap     = "round"
            ctx.lineJoin    = "round"
            ctx.beginPath()
            ctx.moveTo(1, 5)
            ctx.lineTo(4.5, 8.5)
            ctx.lineTo(11, 1.5)
            ctx.stroke()
        }
        Component.onCompleted: requestPaint()
        Connections {
            target: root
            function onReadStatusChanged() { tick1.requestPaint() }
        }
    }

    // Second tick (only in delivered/read status)
    Canvas {
        id: tick2
        width:  14
        height: 10
        visible: root.readStatus >= 2 && root.readStatus !== 3
        onPaint: {
            const ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)
            ctx.strokeStyle = root.readStatus === 3
                              ? WAPageTheme.tickBlue
                              : WAPageTheme.tickGray
            ctx.lineWidth   = 1.5
            ctx.lineCap     = "round"
            ctx.lineJoin    = "round"
            ctx.beginPath()
            ctx.moveTo(1, 5)
            ctx.lineTo(4.5, 8.5)
            ctx.lineTo(11, 1.5)
            ctx.stroke()
        }
        Component.onCompleted: requestPaint()
        Connections {
            target: root
            function onReadStatusChanged() { tick2.requestPaint() }
        }
    }
}
