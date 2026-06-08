import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 6.0
import WAPage 1.0
import Qt5Compat.GraphicalEffects

// Voice / PTT message player like WAPage
Item {
    id: root

    property string mediaPath: ""
    property string duration:  "0:00"
    property string waveform:  ""      // Real waveform (comma separated)
    property bool   isVoice:   true    // PTT = true, normal audio = false
    property bool   isFromMe:  false

    // Signal emitted when playback finishes (reaches end)
    signal playbackFinished()

    // ── Playback speed cycling (WhatsApp-like) ──────────────────────────
    // User taps the avatar inside an audio bubble to cycle 1x -> 1.5x -> 2x -> 1x.
    // Once activated (first tap) the avatar fades out and a speed badge takes its place.
    // The badge stays (even back at 1x) until the chat is switched or the app restarts.
    // Persistence across ListView delegate recycling is achieved via `speedStore`
    // (a JS object keyed by msgId) owned by MessagePanel, which clears it on
    // activeChatChanged. App restart resets naturally (QML state is not saved).
    property int  msgId:           -1     // Stable id from MessageListModel.IdRole
    property var  speedStore:      null   // External map: { [msgId]: rate }
    property real playbackRate:    1.0    // Logical rate (1.0/1.5/2.0)
    property bool speedActivated:  false  // true once user has tapped at least once

    // Path to a pre-stretched WAV (built by C++ AudioSpeedProcessor) for the
    // current rate. When non-empty AND playbackRate != 1.0, MediaPlayer.source
    // points to this file and plays at native 1.0 rate — so speed is achieved
    // *without* changing pitch (no helium effect). Empty means "use original";
    // either rate is 1.0 or the cache is still being generated.
    property string _activeCachedPath: ""
    // Rate at which the CURRENTLY-LOADED source was rendered (1.0 / 1.5 / 2.0).
    // Distinct from `playbackRate` which is updated synchronously on click.
    // Used to convert player.position into rate-independent "audio time" so
    // that swapping between sources preserves the user's place exactly.
    property real   _currentSourceRate: 1.0
    // Target position in NEW source's timeline (ms). Applied after the
    // player has loaded the new source. -1 = no pending seek.
    property real   _pendingSeekMs:    -1
    // Same target, kept around past the first apply so we can re-seek once
    // the player actually transitions to PlayingState — Qt 6 FFmpeg backend
    // often drops setPosition() calls made before audio decoding starts.
    property real   _stickyTargetMs:   -1
    // If true, play() is invoked once the new source has loaded.
    property bool   _playWhenReady:    false
    // Cached duration of the ORIGINAL recording (ms). Captured the first
    // time MediaPlayer reports a duration; back-calculated from a stretched
    // WAV if the user activates speed before original ever played. Used
    // only for the visible "0:28" label so it stays stable across swaps.
    property real   _originalDurationMs: 0

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

    Component.onCompleted: {
        _maybeRequestWaveform()
        if (root.speedStore && root.msgId >= 0) {
            const saved = root.speedStore[root.msgId]
            if (typeof saved === "number") {
                root.playbackRate = saved
                root.speedActivated = true
                if (saved !== 1.0 && typeof mainWindow !== "undefined") {
                    const cached = mainWindow.audioSpeedCachedPath(root.mediaPath, saved)
                    if (cached.length > 0) {
                        root._currentSourceRate = saved
                        root._activeCachedPath  = cached
                    } else {
                        mainWindow.requestAudioSpeed(root.mediaPath, saved)
                    }
                }
            }
        }
        // on_ResolvedSourceChanged fires only on changes, not for the
        // initial value — apply it explicitly here.
        _applySourceUrl(_resolvedSource)
    }
    onMediaPathChanged: { asyncWaveform = ""; _maybeRequestWaveform() }
    
    // Auto-swap to cached file when playbackRate changes (for auto-play feature)
    onPlaybackRateChanged: {
        console.log("🔄 AudioPlayer.onPlaybackRateChanged: " + playbackRate + " speedActivated=" + speedActivated)
        
        if (!speedActivated) {
            console.log("  ⏭️  Speed not activated yet, skipping")
            return
        }
        
        if (playbackRate === 1.0) {
            // Reset to original file
            if (root._activeCachedPath.length > 0) {
                console.log("  ↩️  Resetting to original file (1x)")
                const wasPlaying = root.playing
                const posMs = (root.smoothPosition > 0) ? root.smoothPosition : player.position
                const audioTimeMs = posMs * root._currentSourceRate
                
                root._pendingSeekMs = audioTimeMs
                root._stickyTargetMs = audioTimeMs
                root._playWhenReady = wasPlaying
                root._currentSourceRate = 1.0
                root._activeCachedPath = "" // This triggers source swap to original
            }
        } else {
            // Try to swap to cached file for 1.5x or 2x
            if (typeof mainWindow === "undefined") {
                console.log("  ❌ mainWindow undefined")
                return
            }
            
            const cached = mainWindow.audioSpeedCachedPath(root.mediaPath, playbackRate)
            console.log("  🔍 Checking cache for rate=" + playbackRate + ": " + (cached ? "FOUND" : "NOT FOUND"))
            
            if (cached.length > 0 && cached !== root._activeCachedPath) {
                // Cache exists and different from current - swap to it
                console.log("  ✅ Cache found, swapping to cached file")
                const wasPlaying = root.playing
                const posMs = (root.smoothPosition > 0) ? root.smoothPosition : player.position
                const audioTimeMs = posMs * root._currentSourceRate
                
                root._pendingSeekMs = audioTimeMs / playbackRate
                root._stickyTargetMs = root._pendingSeekMs
                root._playWhenReady = wasPlaying
                root._currentSourceRate = playbackRate
                root._activeCachedPath = cached
                console.log("  📍 Pending seek=" + root._pendingSeekMs + "ms, playWhenReady=" + wasPlaying)
            } else if (cached.length === 0) {
                // Cache not ready - request it
                console.log("  ⚠️  Cache not ready, requesting generation")
                mainWindow.requestAudioSpeed(root.mediaPath, playbackRate)
            } else {
                console.log("  ℹ️  Already using this cached file")
            }
        }
    }

    // Cycle: not-activated -> 1.5x -> 2x -> 1x -> 1.5x -> ...
    //
    // Position preservation across the swap uses rate-independent "audio
    // time" (ms in the original recording's timeline):
    //   audioTimeMs = player.position * _currentSourceRate
    //   newWavMs    = audioTimeMs / newSourceRate
    // This is exact regardless of small differences between the original
    // and stretched-WAV durations.
    function _cycleSpeed() {
        let nextRate
        if (!root.speedActivated)            nextRate = 1.5
        else if (root.playbackRate === 1.5)  nextRate = 2.0
        else if (root.playbackRate === 2.0)  nextRate = 1.0
        else                                  nextRate = 1.5

        root.speedActivated = true
        if (root.speedStore && root.msgId >= 0) {
            root.speedStore[root.msgId] = nextRate
        }

        const wasPlaying  = root.playing
        // Use smoothPosition as primary source (more reliable during swaps),
        // fall back to player.position only if smoothPosition is 0.
        const posMs       = (root.smoothPosition > 0) ? root.smoothPosition
                                                       : player.position
        const audioTimeMs = posMs * root._currentSourceRate

        root.playbackRate = nextRate

        // Decide which file the new rate should play from.
        let newPath       = ""
        let newSourceRate = 1.0
        if (nextRate !== 1.0) {
            if (typeof mainWindow === "undefined") return
            const cached = mainWindow.audioSpeedCachedPath(root.mediaPath, nextRate)
            if (cached.length > 0) {
                newPath       = cached
                newSourceRate = nextRate
            } else {
                // Cache not ready — keep the current source playing and
                // generate the WAV in the background. onAudioSpeedReady will
                // perform the swap when it lands on disk.
                mainWindow.requestAudioSpeed(root.mediaPath, nextRate)
                return
            }
        }

        // No-op if we're already on the requested source.
        if (newPath === root._activeCachedPath) return

        root._pendingSeekMs     = audioTimeMs / newSourceRate
        root._stickyTargetMs    = root._pendingSeekMs
        root._playWhenReady     = wasPlaying
        root._currentSourceRate = newSourceRate
        root._activeCachedPath  = newPath   // triggers MediaPlayer.source binding
    }

    Connections {
        target: typeof mainWindow !== "undefined" ? mainWindow : null
        function onWaveformReady(audioPath, waveformData) {
            if (audioPath === root.mediaPath && waveformData.length > 0) {
                root.asyncWaveform = waveformData
            }
        }
        // Cached pitch-preserving WAV is ready. Swap source if user is still
        // on the rate that matches this result; otherwise (user cycled past)
        // we silently keep the file on disk for next time.
        function onAudioSpeedReady(audioPath, rate, cachedPath) {
            if (audioPath !== root.mediaPath) return
            if (!root.speedActivated) return
            if (root.playbackRate !== rate) return
            if (cachedPath === root._activeCachedPath) return
            const wasPlaying  = root.playing
            // Use smoothPosition as primary source (more reliable during swaps),
            // fall back to player.position only if smoothPosition is 0.
            const posMs       = (root.smoothPosition > 0) ? root.smoothPosition
                                                           : player.position
            const audioTimeMs = posMs * root._currentSourceRate
            root._pendingSeekMs     = audioTimeMs / rate
            root._stickyTargetMs    = root._pendingSeekMs
            root._playWhenReady     = wasPlaying
            root._currentSourceRate = rate
            root._activeCachedPath  = cachedPath
        }
    }

    implicitWidth:  260
    implicitHeight: 48

    // The URL we want MediaPlayer to play. Computed declaratively so any
    // change to mediaPath / _activeCachedPath / playbackRate triggers the
    // imperative reset below. We don't bind it directly to MediaPlayer.source
    // because Qt 6 FFmpeg backend retains decoder state from the previous
    // source — including EndOfMedia — and that breaks subsequent seeks. The
    // imperative reset (stop → source="" → source=newPath) discards that
    // state cleanly on every swap.
    readonly property string _resolvedSource: {
        if (root.mediaPath.length === 0) return ""
        if (root.playbackRate !== 1.0 && root._activeCachedPath.length > 0)
            return "file:///" + root._activeCachedPath
        return "file:///" + root.mediaPath
    }
    on_ResolvedSourceChanged: _applySourceUrl(_resolvedSource)

    function _applySourceUrl(newUrl) {
        if (newUrl.length === 0) {
            player.stop()
            player.source = ""
            return
        }
        // Full reset: stop, null out, then assign. This is the workaround
        // for Qt 6 FFmpeg's decoder-state leak between successive sources.
        player.stop()
        player.source = ""
        player.source = newUrl
    }

    MediaPlayer {
        id: player
        // source is set imperatively by _applySourceUrl()
        audioOutput: AudioOutput { id: audioOut }
        playbackRate: 1.0   // pitch preserved — speed comes from the WAV itself

        onPlaybackStateChanged: function() {
            if (player.playbackState === MediaPlayer.StoppedState) {
                // Suppress the auto-zero of the seeker while a swap is in
                // progress — we want the visual position to carry over to
                // the resumed point, not flicker to 0 first.
                if (root._pendingSeekMs < 0 && root._stickyTargetMs < 0) {
                    root.smoothPosition = 0
                }
                if (typeof appWindow !== "undefined" && appWindow.activeAudioPlayer === root)
                    appWindow.activeAudioPlayer = null
            } else if (player.playbackState === MediaPlayer.PlayingState) {
                // While a swap is still negotiating, keep the visual seeker
                // glued to the target so the user doesn't see a 0→target
                // jump or a backward snap.
                if (root._stickyTargetMs >= 0) {
                    root.smoothPosition = root._stickyTargetMs
                } else {
                    root.smoothPosition = player.position
                }
            } else if (player.playbackState === MediaPlayer.PausedState) {
                if (typeof appWindow !== "undefined" && appWindow.activeAudioPlayer === root)
                    appWindow.activeAudioPlayer = null
            }
        }
        onDurationChanged: function() {
            if (player.duration <= 0) return
            // Capture the ORIGINAL recording's duration so the visible
            // "0:28" label stays stable regardless of which file is
            // currently loaded (original / 1.5x WAV / 2x WAV).
            if (root._currentSourceRate === 1.0) {
                root._originalDurationMs = player.duration
            } else if (root._originalDurationMs <= 0) {
                // Stretched WAV loaded before original ever played —
                // recover original duration from the stretch ratio.
                root._originalDurationMs = player.duration * root._currentSourceRate
            }
        }
        // Either LoadedMedia or BufferedMedia indicates the new source is
        // ready to seek/play. Qt 6 FFmpeg sometimes goes straight to
        // BufferedMedia for short files, skipping LoadedMedia — listening
        // to both ensures we always trigger _applyPendingSeek. The
        // _pendingSeekMs<0 guard inside that function makes it a no-op
        // during normal playback re-buffers.
        onMediaStatusChanged: function() {
            console.log("⚡ MediaPlayer.onMediaStatusChanged: status=" + player.mediaStatus + " (" + 
                       (player.mediaStatus === MediaPlayer.NoMedia ? "NoMedia" :
                        player.mediaStatus === MediaPlayer.LoadingMedia ? "LoadingMedia" :
                        player.mediaStatus === MediaPlayer.LoadedMedia ? "LoadedMedia" :
                        player.mediaStatus === MediaPlayer.StalledMedia ? "StalledMedia" :
                        player.mediaStatus === MediaPlayer.BufferingMedia ? "BufferingMedia" :
                        player.mediaStatus === MediaPlayer.BufferedMedia ? "BufferedMedia" :
                        player.mediaStatus === MediaPlayer.EndOfMedia ? "EndOfMedia" :
                        player.mediaStatus === MediaPlayer.InvalidMedia ? "InvalidMedia" : "Unknown") + ")")
            console.log("    source=" + player.source)
            console.log("    playbackState=" + player.playbackState)
            console.log("    _pendingSeekMs=" + root._pendingSeekMs)
            console.log("    _playWhenReady=" + root._playWhenReady)
            
            if (player.mediaStatus === MediaPlayer.LoadedMedia ||
                player.mediaStatus === MediaPlayer.BufferedMedia) {
                console.log("    → Media is ready, calling _applyPendingSeek()")
                root._applyPendingSeek()
            }
            // Detect when playback finishes
            if (player.mediaStatus === MediaPlayer.EndOfMedia) {
                console.log("    → EndOfMedia detected, emitting playbackFinished()")
                root.playbackFinished()
            }
        }
    }

    // Apply the pending position carry-over after a source swap. Called
    // from onMediaStatusChanged(LoadedMedia). Sequence:
    //   1) setPosition(target) — works in LoadedMedia for non-stale players
    //   2) play() (or stay paused if user wasn't playing)
    //   3) After 250 ms, if position is still near 0 (Qt FFmpeg dropped
    //      the seek), retry once.
    // No tight loop — the decoder is allowed to actually start producing
    // audio between attempts.
    function _applyPendingSeek() {
        console.log("🎯 AudioPlayer._applyPendingSeek() called")
        console.log("    _pendingSeekMs=" + root._pendingSeekMs)
        console.log("    _playWhenReady=" + root._playWhenReady)
        console.log("    player.duration=" + player.duration)
        
        if (root._pendingSeekMs < 0) {
            console.log("    → No pending seek, returning")
            return
        }
        
        if (player.duration <= 0) {
            console.log("    → Duration not ready yet, returning")
            return
        }
        
        const target = Math.max(0, Math.min(root._pendingSeekMs,
                                             player.duration - 1))
        console.log("    → Setting player.position=" + target)
        player.position    = target
        root.smoothPosition = target
        root._pendingSeekMs = -1

        if (root._playWhenReady) {
            root._playWhenReady = false
            console.log("    → _playWhenReady was true, calling play() after Qt.callLater")
            // Defer play() to the next event-loop tick. Calling it
            // synchronously inside the mediaStatusChanged handler is
            // unreliable on Qt 6 FFmpeg — the player is still mid-
            // transition out of LoadingMedia and silently drops the
            // command, leaving the bubble in a paused state. By the next
            // tick the player has fully settled and play() takes effect.
            Qt.callLater(root.play)
        } else {
            console.log("    → _playWhenReady was false, not calling play()")
        }

        // Schedule a single fallback retry in case the seek didn't take.
        fallbackSeekTimer.targetMs = target
        fallbackSeekTimer.restart()
    }

    Timer {
        id: fallbackSeekTimer
        interval: 250
        repeat: false
        property real targetMs: 0
        onTriggered: {
            if (player.duration <= 0) {
                root._stickyTargetMs = -1
                return
            }
            // Only retry if the seek clearly missed — otherwise leave the
            // (now-correct) position alone so we don't hiccup audio.
            if (Math.abs(player.position - targetMs) > 500) {
                player.position = targetMs
            }
            root._stickyTargetMs = -1
        }
    }

    function play() {
        console.log("▶▶▶ AudioPlayer.play() CALLED for mediaPath=" + root.mediaPath)
        console.log("    playbackRate=" + root.playbackRate)
        console.log("    speedActivated=" + root.speedActivated)
        console.log("    _currentSourceRate=" + root._currentSourceRate)
        console.log("    _activeCachedPath=" + root._activeCachedPath)
        console.log("    _playWhenReady=" + root._playWhenReady)
        console.log("    player.source=" + player.source)
        console.log("    player.playbackState=" + player.playbackState)
        console.log("    player.mediaStatus=" + player.mediaStatus)
        
        if (typeof appWindow !== "undefined") {
            if (appWindow.activeAudioPlayer && appWindow.activeAudioPlayer !== root) {
                console.log("    Pausing other active player first")
                appWindow.activeAudioPlayer.pause()
            }
            appWindow.activeAudioPlayer = root
        }
        console.log("    Calling player.play()...")
        player.play()
        console.log("    player.play() returned, state=" + player.playbackState)
    }

    function pause() {
        if (typeof appWindow !== "undefined" && appWindow.activeAudioPlayer === root) {
            appWindow.activeAudioPlayer = null
        }
        player.pause()
    }

    // Visible label — ALWAYS the original recording's duration. Even when
    // we swap MediaPlayer.source to a stretched WAV (shorter), this stays
    // unchanged so the user never sees the timestamp "jump". Prefers the
    // cached value captured from MediaPlayer (most accurate); falls back
    // to the parent-supplied `duration` string if MediaPlayer hasn't yet
    // reported a duration.
    readonly property string currentDuration: (root._originalDurationMs > 0)
                                               ? root.formatMs(root._originalDurationMs)
                                               : root.duration
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
                // MediaPlayer always runs at native rate (the WAV itself is
                // pre-stretched), so the seeker advances at 16ms per tick.
                root.smoothPosition += 16
                // Resync only when the player is clearly decoding audio
                // (position > a small threshold). Right after a source
                // swap Qt FFmpeg can hold position at 0 for a few hundred
                // ms even though playbackState is Playing — snapping the
                // seeker to 0 in that window produced the "loop every
                // second" bug. Also require the sticky target to have
                // cleared.
                if (root._stickyTargetMs < 0 &&
                    player.position > 200 &&
                    Math.abs(root.smoothPosition - player.position) > 1000) {
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

        // Avatar + microphone icon — tap to cycle playback speed.
        // When speed is activated the whole avatar layer fades out and a circular
        // speed badge (1.5×/2×/1×) cross-fades in at the same position.
        Item {
            id: avatarWithMic
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: root.isFromMe ? parent.left : undefined
            anchors.right: root.isFromMe ? undefined : parent.right
            width: 44
            height: 44

            // ── Avatar layer (default) ──────────────────────────────────
            Item {
                id: avatarLayer
                anchors.fill: parent
                opacity: root.playing ? 0.0 : 1.0
                visible: opacity > 0.01
                Behavior on opacity { NumberAnimation { duration: 220; easing.type: Easing.OutCubic } }

                AvatarCircle {
                    id: avatarIcon
                    anchors.fill: parent
                    size: 44

                    // Use senderAvatarPath for both owner and other participants
                    // This ensures that each chat displays the avatar that was active when that chat was imported
                    avatarPath: (root.senderAvatarPath.length > 0) 
                              ? root.senderAvatarPath
                              : (root.isFromMe ? mainWindow.myAvatar : mainWindow.activeChatAvatar)
                    avatarColor: root.isFromMe ? "#25D366" : mainWindow.activeChatColor

                    initials: {
                        let name = root.senderName.trim()
                        // Strip tilde prefix for initials calculation (iOS/Android compatibility)
                        if (name.startsWith("~ ")) {
                            name = name.substring(2).trim()
                        } else if (name.startsWith("~")) {
                            name = name.substring(1).trim()
                        }
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

            // ── Speed badge layer (shown when playing) ─────────────────────
            Rectangle {
                id: speedBadge
                anchors.centerIn: parent
                width:  40
                height: 40
                radius: 20
                color: root.isFromMe
                       ? (WAPageTheme.dark ? "#1F2C33" : "#1A5C4A")
                       : (WAPageTheme.dark ? "#2A3942" : "#E5E5E5")
                opacity: root.playing ? 1.0 : 0.0
                visible: opacity > 0.01
                scale:   root.playing ? 1.0 : 0.6
                Behavior on opacity { NumberAnimation { duration: 220; easing.type: Easing.OutCubic } }
                Behavior on scale   { NumberAnimation { duration: 260; easing.type: Easing.OutBack } }

                Text {
                    anchors.centerIn: parent
                    text: root.playbackRate === 1.5 ? "1.5×"
                        : root.playbackRate === 2.0 ? "2×"
                        :                              "1×"
                    color: root.isFromMe
                           ? "#FFFFFF"
                           : (WAPageTheme.dark ? "#FFFFFF" : WAPageTheme.iconColor)
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: 13
                    font.bold:      true
                }
            }

            // ── Tap handler — covers both avatar and speed badge ───────
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                cursorShape:  Qt.PointingHandCursor
                onClicked:    root._cycleSpeed()
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
