import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 6.0
import Qt5Compat.GraphicalEffects

// Voice / PTT message player like WAPage
Item {
    id: root

    property string mediaPath: ""
    property string duration:  "0:00"
    property string waveform:  ""      // Real waveform (comma separated)
    property bool   isVoice:   true    // PTT = true, normal audio = false
    property bool   isFromMe:  false

    // Holds the waveform that arrived asynchronously from MainWindow::waveformReady.
    // When non-empty it overrides the synchronous fallback in waveformContainer.
    property string asyncWaveform: ""

    // Request the waveform on a background thread so the UI never blocks.
    // Called when mediaPath becomes available and the model has no precomputed
    // waveform attached (legacy / freshly imported audio).
    function _maybeRequestWaveform() {
        if (root.waveform && root.waveform.length > 0) return
        if (root.asyncWaveform.length > 0) return
        if (root.mediaPath.length === 0) return
        if (typeof mainWindow === "undefined") return
        mainWindow.requestWaveform(root.mediaPath)
    }

    Component.onCompleted: _maybeRequestWaveform()
    onMediaPathChanged: { asyncWaveform = ""; _maybeRequestWaveform() }

    Connections {
        target: typeof mainWindow !== "undefined" ? mainWindow : null
        function onWaveformReady(audioPath, waveformData) {
            if (audioPath === root.mediaPath && waveformData.length > 0) {
                root.asyncWaveform = waveformData
            }
        }
    }

    implicitWidth:  260
    implicitHeight: 48

    MediaPlayer {
        id: player
        source: root.mediaPath.length > 0 ? ("file:///" + root.mediaPath) : ""
        audioOutput: AudioOutput { id: audioOut }

        onPlaybackStateChanged: function() {
            if (player.playbackState === MediaPlayer.StoppedState) {
                root.smoothPosition = 0
                if (typeof appWindow !== "undefined" && appWindow.activeAudioPlayer === root)
                    appWindow.activeAudioPlayer = null
            } else if (player.playbackState === MediaPlayer.PlayingState) {
                root.smoothPosition = player.position
            } else if (player.playbackState === MediaPlayer.PausedState) {
                if (typeof appWindow !== "undefined" && appWindow.activeAudioPlayer === root)
                    appWindow.activeAudioPlayer = null
            }
        }
        onDurationChanged: function() {
            if (player.duration > 0)
                root.currentDuration = root.formatMs(player.duration)
        }
    }

    function play() {
        if (typeof appWindow !== "undefined") {
            if (appWindow.activeAudioPlayer && appWindow.activeAudioPlayer !== root) {
                appWindow.activeAudioPlayer.pause()
            }
            appWindow.activeAudioPlayer = root
        }
        player.play()
    }

    function pause() {
        if (typeof appWindow !== "undefined" && appWindow.activeAudioPlayer === root) {
            appWindow.activeAudioPlayer = null
        }
        player.pause()
    }

    property string currentDuration: root.duration
    property bool   playing: player.playbackState === MediaPlayer.PlayingState
    property real   smoothPosition: 0
    property string senderName: ""
    property string senderAvatarPath: ""  // Per-sender avatar for group chats
    
    // Vizual progress (0.0 - 1.0)
    readonly property real visualProgress: (player.duration > 0) ? (root.smoothPosition / player.duration) : 0.0

    // Waveform animation ('turns on' when playing)
    property real   waveAnim: playing ? 1.0 : 0.4
    Behavior on waveAnim { NumberAnimation { duration: 300; easing.type: Easing.OutBack } }

    function formatMs(ms) {
        const s = Math.floor(ms / 1000)
        return Math.floor(s / 60) + ":" + String(s % 60).padStart(2, "0")
    }

    Timer {
        id: playTimer
        interval: 16 // ~60fps
        // We stop the timer when the user grabs the slider
        running: root.playing && !seekerMouseArea.pressed
        repeat: true
        onTriggered: {
            if (player.duration > 0) {
                root.smoothPosition += 16
                if (Math.abs(root.smoothPosition - player.position) > 1000) {
                    root.smoothPosition = player.position
                }
                
                if (root.smoothPosition > player.duration) 
                    root.smoothPosition = player.duration
            }
        }
    }

    Item {
        anchors.fill: parent
        anchors.leftMargin: 8
        anchors.rightMargin: 8

        // Avatar + microphone icon
        Item {
            id: avatarWithMic
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: root.isFromMe ? parent.left : undefined
            anchors.right: root.isFromMe ? undefined : parent.right
            width: 44
            height: 44

            AvatarCircle {
                id: avatarIcon
                anchors.fill: parent
                size: 44

                avatarPath: root.isFromMe ? mainWindow.myAvatar
                                          : (root.senderAvatarPath.length > 0 ? root.senderAvatarPath
                                                                               : mainWindow.activeChatAvatar)
                avatarColor: root.isFromMe ? "#25D366" : mainWindow.activeChatColor

                initials: {
                    let name = root.senderName.trim()
                    if (name.length === 0) return "?"
                    let parts = name.split(" ")
                    if (parts.length >= 2) return (parts[0][0] + parts[1][0]).toUpperCase()
                    return name[0].toUpperCase()
                }
            }

            // Microphone icon — bottom-left (opposite) / bottom-right (mine) as in WAPage
            Image {
                id: micIcon
                source: "qrc:/assets/microphone.svg"
                width: 18
                height: 18
                sourceSize: Qt.size(18, 18)
                anchors.bottom: parent.bottom
                anchors.bottomMargin: -2
                anchors.left:  root.isFromMe ? undefined : parent.left
                anchors.right: root.isFromMe ? parent.right : undefined
                anchors.leftMargin:  root.isFromMe ? 0 : -2
                anchors.rightMargin: root.isFromMe ? -2 : 0
            }
        }

        // Play / Pause button
        Item {
            id: playBtnContainer
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: root.isFromMe ? avatarWithMic.right : parent.left
            anchors.leftMargin: root.isFromMe ? 10 : 0
            width:  44
            height: 44

            Rectangle {
                anchors.fill: parent
                radius: 22
                color: (playBtnArea.containsMouse || playBtnArea.pressed)
                       ? (WAPageTheme.dark ? Qt.rgba(1, 1, 1, 0.1) : Qt.rgba(0, 0, 0, 0.05))
                       : "transparent"

                Behavior on color { ColorAnimation { duration: 150 } }
            }

            Image {
                id: playIcon
                anchors.centerIn: parent
                anchors.horizontalCenterOffset: root.playing ? 0 : 2
                source:   root.playing
                          ? "qrc:/assets/icon_pause.svg"
                          : "qrc:/assets/icon_play.svg"
                width:    24
                height:   24
                sourceSize: Qt.size(24, 24)
                visible: false
            }

            ColorOverlay {
                anchors.fill: playIcon
                source: playIcon
                color: (root.isFromMe && WAPageTheme.dark) ? "#FFFFFF" : WAPageTheme.iconColor
            }

            MouseArea {
                id: playBtnArea
                anchors.fill: parent
                hoverEnabled: true
                cursorShape:  Qt.PointingHandCursor
                onClicked: {
                    if (root.playing) root.pause()
                    else              root.play()
                }
            }
        }

        // --- MANUAL SEEKER ---
        Item {
            id: seekerContainer
            anchors.verticalCenter: playBtnContainer.verticalCenter
            anchors.left: playBtnContainer.right
            anchors.right: root.isFromMe ? parent.right : avatarWithMic.left
            anchors.leftMargin: 10
            anchors.rightMargin: root.isFromMe ? 0 : 10
            height:    32

            // Waveform background (visual layer)
            Item {
                id: waveformContainer
                anchors.fill: parent
                enabled: false

                // Waveform data — never call into mainWindow synchronously here:
                // generateWaveform spawns ffmpeg and would freeze the UI thread.
                // Async results arrive via root.asyncWaveform (see Connections above).
                readonly property string realWaveform: {
                    if (root.waveform && root.waveform.length > 0) return root.waveform
                    if (root.asyncWaveform.length > 0) return root.asyncWaveform
                    return ""
                }

                readonly property var waveformPoints: {
                    let wf = realWaveform
                    if (wf && wf.length > 0) {
                        return wf.split(',')
                    }
                    return [10, 15, 20, 25, 30, 25, 20, 15, 10, 15, 20, 25, 30, 25, 20, 15, 10, 15, 20, 25, 30, 25, 20, 15, 10, 15, 20, 25, 30, 25, 20, 15, 10, 15, 10, 5]
                }

                // 1. Base Layer (Gray)
                Row {
                    id: inactiveRow
                    anchors.fill: parent
                    spacing: (width - (36 * 2)) / 35
                    
                    Repeater {
                        model: 36
                        Rectangle {
                            width: 2
                            height: {
                                let pts = waveformContainer.waveformPoints
                                let h = (pts && index < pts.length) ? 4 + (parseInt(pts[index]) * 18 / 100) : 4
                                return h * root.waveAnim
                            }
                            radius: 1
                            anchors.verticalCenter: parent.verticalCenter
                            color: WAPageTheme.dark ? "#40FFFFFF" : "#26000000"
                        }
                    }
                }

                // 2. Top Layer (Blue)
                Item {
                    id: clipper
                    width:  parent.width * root.visualProgress
                    height: parent.height
                    clip:   true
                    
                    Row {
                        width:   seekerContainer.width
                        height:  seekerContainer.height
                        spacing: (width - (36 * 2)) / 35
                        
                        Repeater {
                            model: 36
                            Rectangle {
                                width: 2
                                height: {
                                    let pts = waveformContainer.waveformPoints
                                    let h = (pts && index < pts.length) ? 4 + (parseInt(pts[index]) * 18 / 100) : 4
                                    return h * root.waveAnim
                                }
                                radius: 1
                                anchors.verticalCenter: parent.verticalCenter
                                color: "#53BDEB"
                            }
                        }
                    }
                }
            }

            // Handle (Yumru Daire)
            Rectangle {
                id: seekerHandle
                width: 12
                height: 12
                radius: 6
                color: (root.isFromMe && WAPageTheme.dark) ? "#FFFFFF" : "#53BDEB"
                anchors.verticalCenter: parent.verticalCenter
                // We calculate the position
                x: (root.visualProgress * (parent.width - width))
                z: 5
            }

            // --- MASTER CONTROLLER ---
            MouseArea {
                id: seekerMouseArea
                anchors.fill: parent
                preventStealing: true
                cursorShape: Qt.PointingHandCursor
                z: 100 // We ensure that it is at the top
                
                function updateSeek(mouse) {
                    let p = Math.max(0, Math.min(1, mouse.x / width))
                    if (player.duration > 0) {
                        player.position = p * player.duration
                        root.smoothPosition = player.position
                    }
                }

                onPressed: (mouse) => {
                    updateSeek(mouse)
                }
                onPositionChanged: (mouse) => {
                    if (pressed) {
                        updateSeek(mouse)
                    }
                }
            }
        }

        // Time information
        Text {
            anchors.left: seekerContainer.left
            anchors.top: seekerContainer.bottom
            anchors.topMargin: -4
            
            text: root.playing
                  ? root.formatMs(player.position)
                  : root.currentDuration
            color: (root.isFromMe && WAPageTheme.dark)
                   ? "#B3FFFFFF"
                   : WAPageTheme.chatListSubText
            font.family:    WAPageTheme.fontFamily
            font.pixelSize: WAPageTheme.fontSizeMicro + 1
        }
    }
}
