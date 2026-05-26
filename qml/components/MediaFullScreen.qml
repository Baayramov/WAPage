import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 6.0
import Qt5Compat.GraphicalEffects

// Full screen media view — for image / video
Rectangle {
    id: root
    color: WAPageTheme.mediaOverlay

    property string mediaPath: ""
    property string mediaType: ""
    property real   smoothPosition: 0

    signal closeRequested()

    // Image view
    Flickable {
        id: flick
        anchors {
            fill:            parent
            topMargin:       toolBar.height
            bottomMargin:    16
        }
        visible:         root.mediaType === "image"
        contentWidth:    bigImg.width * bigImg.scale
        contentHeight:   bigImg.height * bigImg.scale
        clip:            true

        Image {
            id: bigImg
            anchors.centerIn: parent
            // Only upload image files — never upload a video file to Image
            // (Qt FFmpeg plugin crashes with assert when trying to open video file as Image)
            source: {
                // Guard: never pass a video file to Image (causes Qt FFmpeg assert/WARN)
                var videoExts = [".mp4", ".mov", ".avi", ".mkv", ".webm"]
                var lp = root.mediaPath.toLowerCase()
                var isVideoFile = videoExts.some(function(e){ return lp.endsWith(e) })
                return (root.mediaType === "image" && root.mediaPath.length > 0 && !isVideoFile)
                    ? ("file:///" + root.mediaPath) : ""
            }
            fillMode: Image.PreserveAspectFit
            width:    flick.width
            height:   flick.height

            property real minScale: 1.0
            property real maxScale: 4.0
            scale: minScale

            // Pinch zoom
            PinchHandler {
                target: bigImg
                minimumScale: bigImg.minScale
                maximumScale: bigImg.maxScale
            }

            // Double-click reset
            MouseArea {
                anchors.fill: parent
                onDoubleClicked: bigImg.scale = bigImg.minScale
            }
        }
    }

    // video player
    Item {
        id: videoContainer
        anchors {
            fill:         parent
            topMargin:    toolBar.height
            bottomMargin: videoControls.height + 16
        }
        visible: root.mediaType === "video"

        MediaPlayer {
            id: vidPlayer
            source: (root.mediaType === "video" && root.mediaPath.length > 0 && root.visible)
                    ? ("file:///" + root.mediaPath) : ""
            videoOutput: vidOutput
            audioOutput: AudioOutput {}
            
            // To make the first frame appear loaded:
            autoPlay: false

            onErrorOccurred: function(error, errorString) {
                console.warn("Video player error:", errorString)
            }
            
            onPlaybackStateChanged: function() {
                if (vidPlayer.playbackState === MediaPlayer.StoppedState) {
                    root.smoothPosition = 0
                    vidSlider.value = 0
                } else if (vidPlayer.playbackState === MediaPlayer.PlayingState) {
                    root.smoothPosition = vidPlayer.position
                    if (vidPlayer.duration > 0 && !vidSlider.pressed)
                        vidSlider.value = vidPlayer.position
                }
            }
        }

        VideoOutput {
            id: vidOutput
            anchors.fill: parent
        }

        // Thumbnail indicator — appears when the video first starts (or ends).
        // For a smooth transition, we save the thumbnail until the first 150ms of the video so that the black screen does not "flicker".
        Image {
            id: videoThumbnail
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: mediaViewer.mediaThumbnail.length > 0 ? ("file:///" + mediaViewer.mediaThumbnail.replace(/\\/g, "/")) : ""
            asynchronous: true
            opacity: (vidPlayer.playbackState === MediaPlayer.StoppedState || vidPlayer.position <= 150) ? 1 : 0
            visible: opacity > 0
            Behavior on opacity { NumberAnimation { duration: 100 } }
        }

        // Click on the entire video — to Play/Pause
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (vidPlayer.playbackState === MediaPlayer.PlayingState) {
                    vidPlayer.pause()
                } else {
                    vidPlayer.play()
                }
            }
        }

        // Large Play indicator in the middle (Only visible when the video is stopped)
        Rectangle {
            id: centerPlayBtn
            anchors.centerIn: parent
            visible: vidPlayer.playbackState !== MediaPlayer.PlayingState
            width:  120; height: 120; radius: 60
            color:  (centerPlayMouse.containsMouse || centerPlayMouse.pressed)
                    ? Qt.rgba(0.5, 0.5, 0.5, 0.25)
                    : "transparent"
            
            Behavior on color { ColorAnimation { duration: 150 } }
            
            Image {
                id: bigPlayIcon
                anchors.centerIn: parent
                anchors.horizontalCenterOffset: 4 // Optical centering for the Play icon
                source: "qrc:/assets/icon_play.svg"
                width:   80; height: 80
                sourceSize: Qt.size(80, 80)
                visible: false
                opacity: centerPlayMouse.containsMouse ? 1.0 : 0.85
                Behavior on opacity { NumberAnimation { duration: 150 } }
            }

            ColorOverlay {
                anchors.fill: bigPlayIcon
                source: bigPlayIcon
                color: "#FFFFFF"
                opacity: bigPlayIcon.opacity
            }

            MouseArea {
                id: centerPlayMouse
                anchors.fill: parent
                hoverEnabled: true
                cursorShape:  Qt.PointingHandCursor
                onClicked: {
                    if (vidPlayer.playbackState === MediaPlayer.PlayingState) vidPlayer.pause()
                    else vidPlayer.play()
                }
            }
        }
    }

    // Video control panel
    Rectangle {
        id: videoControls
        visible: root.mediaType === "video"
        anchors { left: parent.left; right: parent.right; bottom: parent.bottom }
        height:  56
        color:   WAPageTheme.mediaToolbar

        Row {
            anchors { fill: parent; leftMargin: 16; rightMargin: 16 }
            spacing: 12

            // Bottom Play/Pause - Aesthetic Style
            Rectangle {
                width: 40; height: 40; radius: 20
                color: bottomPlayMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.15) : "transparent"
                anchors.verticalCenter: parent.verticalCenter
                Behavior on color { ColorAnimation { duration: 150 } }

                Image {
                    id: bottomPlayIcon
                    anchors.centerIn: parent
                    source: vidPlayer.playbackState === MediaPlayer.PlayingState
                                 ? "qrc:/assets/icon_pause.svg"
                                 : "qrc:/assets/icon_play.svg"
                    width: 24; height: 24
                    sourceSize: Qt.size(24, 24)
                    visible: false
                }
                ColorOverlay {
                    anchors.fill: bottomPlayIcon
                    source: bottomPlayIcon
                    color: "#FFFFFF"
                }
                MouseArea {
                    id: bottomPlayMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        if (vidPlayer.playbackState === MediaPlayer.PlayingState) vidPlayer.pause()
                        else vidPlayer.play()
                    }
                }
            }

            // Timeline / Progress Bar
            Slider {
                id: vidSlider
                anchors.verticalCenter: parent.verticalCenter
                width:  parent.width - 150 // We allocate a space for time writing
                from:   0
                to:     vidPlayer.duration > 0 ? vidPlayer.duration : 1
                
                // Handle changing position manually
                onMoved: {
                    vidPlayer.position = value
                    root.smoothPosition = value
                }

                Timer {
                    interval: 16 // ~60fps
                    running: vidPlayer.playbackState === MediaPlayer.PlayingState && !vidSlider.pressed
                    repeat: true
                    onTriggered: {
                        if (vidPlayer.duration > 0) {
                            root.smoothPosition += 16
                            if (Math.abs(root.smoothPosition - vidPlayer.position) > 1000) {
                                root.smoothPosition = vidPlayer.position
                            }
                            if (root.smoothPosition > vidPlayer.duration)
                                root.smoothPosition = vidPlayer.duration
                            vidSlider.value = root.smoothPosition
                        }
                    }
                }
                
                background: Rectangle {
                    x: parent.leftPadding; y: parent.topPadding + parent.availableHeight/2 - height/2
                    width: parent.availableWidth; height: 4; radius: 2 // Stay a while
                    color: "#4DFFFFFF"
                    
                    Rectangle {
                        width: parent.parent.visualPosition * parent.width
                        height: parent.height; radius: parent.radius
                        color: WAPageTheme.accentGreen // WAPage green progress color
                    }
                }
                handle: Rectangle {
                    x: parent.leftPadding + parent.visualPosition*(parent.availableWidth-width)
                    y: parent.topPadding + parent.availableHeight/2 - height/2
                    width: 16; height: 16; radius: 8; color: WAPageTheme.accentGreen // Green handle
                }
            }

            // Beautifully Formatted Time
            Text {
                anchors.verticalCenter: parent.verticalCenter
                color: "#FFFFFF"
                font.family: WAPageTheme.fontFamily
                font.pixelSize: 12
                text: {
                    function formatTime(ms) {
                        var totalSeconds = Math.floor(ms / 1000)
                        var minutes = Math.floor(totalSeconds / 60)
                        var seconds = totalSeconds % 60
                        return (minutes < 10 ? "0" : "") + minutes + ":" + (seconds < 10 ? "0" : "") + seconds
                    }
                    var cur = formatTime(vidPlayer.position)
                    var tot = formatTime(vidPlayer.duration > 0 ? vidPlayer.duration : 0)
                    return cur + " / " + tot
                }
            }
        }
    }

    // Top toolbar
    Rectangle {
        id: toolBar
        anchors { left: parent.left; right: parent.right; top: parent.top }
        height: 56
        color:  WAPageTheme.mediaToolbar

        Row {
            anchors { fill: parent; leftMargin: 8; rightMargin: 8 }
            spacing: 8

            // Close Button - Aesthetic Style
            Rectangle {
                width: 40; height: 40; radius: 20
                color: closeBtnMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.15) : "transparent"
                anchors.verticalCenter: parent.verticalCenter
                Behavior on color { ColorAnimation { duration: 150 } }

                Image {
                    id: closeIcon
                    anchors.centerIn: parent
                    source: "qrc:/assets/icon_close.svg"
                    width: 24; height: 24
                    sourceSize: Qt.size(24, 24)
                    visible: false
                }
                ColorOverlay {
                    anchors.fill: closeIcon
                    source: closeIcon
                    color: "#FFFFFF"
                }
                MouseArea {
                    id: closeBtnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: root.closeRequested()
                }
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text:           root.mediaType === "video" ? langManager.currentTranslations["video"] : mediaViewer.fileName
                color:          "#FFFFFF"
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeNormal
                elide:          Text.ElideMiddle
                width:          parent.width - 120
            }

            // Open External - Aesthetic Style
            Rectangle {
                width: 40; height: 40; radius: 20
                color: openExtMouse.containsMouse ? Qt.rgba(1, 1, 1, 0.15) : "transparent"
                anchors.verticalCenter: parent.verticalCenter
                Behavior on color { ColorAnimation { duration: 150 } }

                Image {
                    id: openExtIcon
                    anchors.centerIn: parent
                    source: "qrc:/assets/icon_open_external.svg"
                    width: 24; height: 24
                    sourceSize: Qt.size(24, 24)
                    visible: false
                }
                ColorOverlay {
                    anchors.fill: openExtIcon
                    source: openExtIcon
                    color: "#FFFFFF"
                }
                MouseArea {
                    id: openExtMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: mediaViewer.openWithSystem(root.mediaPath)
                }
                ToolTip {
                    visible: openExtMouse.containsMouse
                    text:    langManager.currentTranslations["open_system"]
                    delay:   500
                }
            }
        }
    }

    // Close by clicking (empty area on the image)
    MouseArea {
        anchors.fill:    parent
        z:               -1
        onClicked:       root.closeRequested()
    }

    onVisibleChanged: {
        if (!visible && vidPlayer.playbackState === MediaPlayer.PlayingState)
            vidPlayer.stop()
    }
}
