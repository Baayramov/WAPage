import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import WAPage 1.0

// Right panel — header + messages + search panel
Rectangle {
    id: root
    color: WAPageTheme.chatBg

    // Splash screen if conversation is not selected
    Item {
        anchors.fill: parent
        visible:      mainWindow.activeChatId < 0

        Column {
            anchors.centerIn: parent
            spacing: 16

            // WAPage icon (text-based)
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text:     "💬"
                font.pixelSize: 64
                opacity:  0.15
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text:           "WAPage"
                color:          WAPageTheme.chatListSubText
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: 22
                font.weight:    Font.Light
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text:           langManager.currentTranslations["empty_chat_hint"]
                color:          WAPageTheme.chatListSubText
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeSmall
                opacity:        0.7
            }
        }
    }



    // Actual content if conversation is selected
    ColumnLayout {
        anchors.fill: parent
        spacing:      0
        visible:      mainWindow.activeChatId >= 0

        // ── Header ────────────────────────────────────────────
        ChatHeader {
            Layout.fillWidth: true
            onProfileClicked: profileView.open()
            onSearchClicked:  searchCtrl.open()
            onCalendarClicked: calendarDialog.open()
            onFirstMessageRequested: msgList.jumpToFirstMessage()
            onLastMessageRequested: msgList.jumpToLastMessage()
            onDeleteRequested: {
                if (mainWindow.activeChatId >= 0)
                    mainWindow.deleteChat(mainWindow.activeChatId)
            }
        }

        // ── Search bar (visible when open) ──────────────
        SearchBar {
            Layout.fillWidth: true
            Layout.preferredHeight: searchCtrl.active ? 48 : 0
            visible:          searchCtrl.active || Layout.preferredHeight > 0
            z: 1
            clip: true

            Behavior on Layout.preferredHeight { NumberAnimation { duration: 180 } }
        }

        // ── Message list (wallpaper background) ──────────────────────
        // ── Message list (wallpaper background) ──────────────────────
        // ListView and Wallpaper are directly in the fillHeight element of the ColumnLayout
        Item {
            Layout.fillWidth:  true
            Layout.fillHeight: true
            clip: true // Clip for the general border

            // Arxa plan — WAPage wallpaper
            Image {
                id: wallpaper
                anchors.fill: parent
                source:       WAPageTheme.dark
                              ? "qrc:/assets/wallpaper_dark.svg"
                              : "qrc:/assets/wallpaper_light.svg"
                fillMode:     Image.Tile
                z: -1
            }

            // ── WAPage style Chat Loading screen ──────────────
            // When Chat is selected, the data is displayed until it is loaded
            Rectangle {
                id: chatLoadingOverlay
                anchors.fill: parent
                color:        WAPageTheme.dark ? "#0D1418" : "#F0F2F5"
                z:            20
                visible:      mainWindow.isChatLoading
                opacity:      mainWindow.isChatLoading ? 1.0 : 0.0

                Behavior on opacity {
                    NumberAnimation { duration: 120; easing.type: Easing.OutQuad }
                }

                // "Loading messages..." text — below the spinner
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter:   parent.verticalCenter
                    anchors.verticalCenterOffset: 48
                    text:           langManager.currentTranslations["loading_messages"]
                                    || "Mesajlar yüklənir..."
                    color:          WAPageTheme.dark ? "#8696A0" : "#667781"
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeSmall
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            // Spinner — separate from overlay, not affected by opacity animation
            Item {
                id: spinnerRoot
                anchors.centerIn: parent
                width:  60
                height: 60
                z:      21
                visible: mainWindow.isChatLoading

                // Gray track circle (fixed, not rotating)
                Rectangle {
                    anchors.fill: parent
                    radius:       width / 2
                    color:        "transparent"
                    border.width: 4
                    border.color: "#8696A0"
                }

                // Rotating green arc (Canvas) — without mask rectangle
                Item {
                    id: arcLayer
                    anchors.fill: parent
                    transformOrigin: Item.Center

                    RotationAnimator on rotation {
                        from:        0
                        to:          360
                        duration:    900
                        loops:       Animation.Infinite
                        running:     mainWindow.isChatLoading
                        easing.type: Easing.Linear
                    }

                    Canvas {
                        id: arcCanvas
                        anchors.fill: parent
                        antialiasing: true

                        property color arcColor: WAPageTheme.dark ? "#00D4A8" : "#00C060"

                        onArcColorChanged: requestPaint()
                        onWidthChanged: requestPaint()
                        onHeightChanged: requestPaint()

                        onPaint: {
                            const ctx = getContext("2d")
                            ctx.clearRect(0, 0, width, height)

                            const lineW = 4
                            const cx = width / 2
                            const cy = height / 2
                            const r = Math.max(0, Math.min(width, height) / 2 - lineW / 2)

                            ctx.beginPath()
                            ctx.lineWidth = lineW
                            ctx.lineCap = "round"
                            ctx.strokeStyle = arcColor
                            ctx.arc(cx, cy, r, -Math.PI * 0.78, Math.PI * 0.18, false)
                            ctx.stroke()
                        }

                        Component.onCompleted: requestPaint()
                    }
                }

                // Emoji in the center
                Text {
                    anchors.centerIn: parent
                    text:             "💬"
                    font.pixelSize:   22
                    opacity:          0.85
                }
            }

            ListView {
                id: msgList
                anchors.fill:        parent
                model:               mainWindow.messageModel
                clip:                false 
                spacing:             0
                z: 0
                focus:               false
                highlightFollowsCurrentItem: false
                highlight:           null
                highlightMoveDuration: 0
                highlightMoveVelocity: -1
                currentIndex:        -1

                interactive:        true
                flickableDirection: Flickable.VerticalFlick
                boundsBehavior:     Flickable.DragAndOvershootBounds
                boundsMovement:     Flickable.FollowBoundsBehavior 
                flickDeceleration:  600  
                maximumFlickVelocity: 8000 
                pressDelay:         0
                pixelAligned:       true 
                cacheBuffer:        800
                smooth:             true

                // ── Header: simple top padding spacer ──────────────────
                // Note: rubber band fix based on estimatedTotalHeight
                // created a binding loop because height
                // was removing itself from contentHeight. 
                header: Item {
                    id: topSpacer
                    width: msgList.width
                    height: 40
                }
                footer: Item { height: 40; width: msgList.width }

                // ── Scroll state ──────────────────────────────────────
                // contentReady: for bounce — false until the chat is scrolled to the end
                property bool contentReady:    false
                property real lastStableH:     0
                property int  stabilizeCount:  0
                // isNewChat: a new chat is selected, scrolling to the end is enabled
                property bool isNewChat:       false
                // isLoadingMore: old message is loading, trigger block
                property bool isLoadingMore:   false
                // Last contentY value — to track the scroll direction
                property real lastContentY:    0
                // Trigger debounce interval (ms)
                property int loadDebounceMs:   90
                // Snapshot to accurately restore viewport after old message insert
                property bool restorePending:  false
                property real restoreBaseY:    0
                property real restoreBaseH:    0
                property real restoreFallbackY: 0
                property int  restoreRetryCount: 0
                property int  restoreBaseCount: 0
                property int  restoreAnchorIndex: -1
                property real restoreAnchorOffset: 0
                property int  restoreInsertedCount: 0
                // ── Audio playback-speed persistence (per chat session) ──────
                // Map of msgId -> selected playback rate (1.5 / 2.0 / 1.0).
                // AudioPlayer instances read/write this through MessageBubble.
                // Cleared in the activeChatChanged handler below so every fresh
                // chat starts with avatars (not speed badges) visible.
                property var  audioSpeedMap: ({})
                // [SCROLL-RESTORE] Track ListView's originY snapshot so we can detect coordinate-system shifts caused by front-insert.
                property real restoreBaseOriginY: 0

                function topLoadThreshold() {
                    return Math.max(220, msgList.height * 0.25)
                }

                // [SCROLL-RESTORE] Helper: print one-line state snapshot for any phase
                // Routes through mainWindow.debugLog so it lands in app.log AND Application Output reliably.
                function _srLog(tag, extra) {
                    var s = "[SCROLL-RESTORE] " + tag
                            + " chat=" + mainWindow.activeChatId
                            + " cnt=" + mainWindow.messageModel.count
                            + "/" + mainWindow.messageModel.totalCount
                            + " cY=" + msgList.contentY.toFixed(1)
                            + " oY=" + msgList.originY.toFixed(1)
                            + " cH=" + msgList.contentHeight.toFixed(1)
                            + " h=" + msgList.height.toFixed(0)
                            + " atBeg=" + msgList.atYBeginning
                            + " atEnd=" + msgList.atYEnd
                            + " drag=" + msgList.dragging
                            + " flick=" + msgList.flicking
                            + " loading=" + mainWindow.messageModel.loading
                            + " loadingMore=" + msgList.isLoadingMore
                            + " newChat=" + msgList.isNewChat
                            + " ready=" + msgList.contentReady
                            + " pending=" + msgList.restorePending
                    if (extra) s += " | " + extra
                    console.log(s)
                    if (mainWindow && mainWindow.debugLog) mainWindow.debugLog(s)
                }

                function jumpToFirstMessage() {
                    if (mainWindow.activeChatId < 0) return
                    if (mainWindow.messageModel.loading) return

                    _srLog("jumpToFirstMessage:enter")
                    loadMoreDebounce.stop()
                    restoreApplyTimer.stop()
                    restorePending = false
                    isLoadingMore = false
                    isNewChat = false

                    mainWindow.messageModel.ensureAllLoaded()
                    contentReady = true

                    Qt.callLater(function() {
                        if (mainWindow.messageModel.count <= 0) return
                        msgList.positionViewAtBeginning()
                        msgList.lastContentY = msgList.contentY
                        _srLog("jumpToFirstMessage:done")
                    })
                }

                function jumpToLastMessage() {
                    if (mainWindow.activeChatId < 0) return
                    if (mainWindow.messageModel.loading) return

                    _srLog("jumpToLastMessage:enter")
                    loadMoreDebounce.stop()
                    restoreApplyTimer.stop()
                    restorePending = false
                    isLoadingMore = false
                    isNewChat = false

                    mainWindow.messageModel.ensureAllLoaded()
                    contentReady = true

                    Qt.callLater(function() {
                        if (mainWindow.messageModel.count <= 0) return
                        msgList.positionViewAtEnd()
                        msgList.lastContentY = msgList.contentY
                        _srLog("jumpToLastMessage:done")
                    })
                }

                function requestOlderMessages() {
                    if (!contentReady)                              { _srLog("requestOlder:SKIP", "reason=notReady"); return }
                    if (mainWindow.messageModel.loading)            { _srLog("requestOlder:SKIP", "reason=loading"); return }
                    if (isLoadingMore || isNewChat)                 { _srLog("requestOlder:SKIP", "reason=isLoadingMore|isNewChat"); return }
                    if (mainWindow.messageModel.totalCount <= mainWindow.messageModel.count) { _srLog("requestOlder:SKIP", "reason=allLoaded"); return }

                    _srLog("requestOlder:enter")

                    restorePending   = true
                    restoreBaseY     = msgList.contentY
                    restoreBaseH     = msgList.contentHeight
                    restoreBaseOriginY = msgList.originY
                    restoreFallbackY = msgList.contentY
                    restoreRetryCount = 0
                    restoreBaseCount = mainWindow.messageModel.count
                    restoreInsertedCount = 0
                    captureRestoreAnchor()

                    _srLog("requestOlder:snapshot",
                           "baseY=" + restoreBaseY.toFixed(1)
                           + " baseH=" + restoreBaseH.toFixed(1)
                           + " baseOriginY=" + restoreBaseOriginY.toFixed(1)
                           + " baseCount=" + restoreBaseCount
                           + " anchorIdx=" + restoreAnchorIndex
                           + " anchorOff=" + restoreAnchorOffset.toFixed(1))

                    isLoadingMore = true
                    const accepted = mainWindow.messageModel.loadMoreOlderMessages(
                        msgList.contentY,
                        msgList.contentHeight
                    )
                    _srLog("requestOlder:cppCall", "accepted=" + accepted)

                    // Because of C++ guards, if it returns false immediately, don't set the flag
                    if (!accepted) {
                        _srLog("requestOlder:REJECTED", "resetting all flags")
                        restorePending = false
                        restoreRetryCount = 0
                        restoreAnchorIndex = -1
                        restoreAnchorOffset = 0
                        restoreInsertedCount = 0
                        isLoadingMore = false
                    }
                }

                function captureRestoreAnchor() {
                    restoreAnchorIndex = -1
                    restoreAnchorOffset = 0

                    const probeX = Math.max(12, msgList.width * 0.5)
                    // [SCROLL-RESTORE] Probe across the REAL visible viewport in content coords.
                    // ListView.indexAt() accepts negative y when originY is negative (which
                    // happens in chats where item heights vary enough for QtQuick to shift origin).
                    // Previously we clamped startY to >=0 which made every probe land OUTSIDE the
                    // current viewport, returning -1 for all probes -> anchor lost -> fallback
                    // produced wrong target after originY post-insert recalc, scrolling user away.
                    const startY = msgList.contentY + 8
                    const endY = startY + Math.max(48, msgList.height - 8)

                    var probes = 0
                    var noIdxHits = 0
                    var noItemHits = 0
                    for (let y = startY; y <= endY; y += 28) {
                        probes++
                        const idx = msgList.indexAt(probeX, y)
                        if (idx < 0) { noIdxHits++; continue }

                        const item = msgList.itemAtIndex(idx)
                        if (!item) { noItemHits++; continue }

                        restoreAnchorIndex = idx
                        restoreAnchorOffset = msgList.contentY - item.y
                        _srLog("anchor:FOUND",
                               "probes=" + probes
                               + " idx=" + idx
                               + " item.y=" + item.y.toFixed(1)
                               + " item.h=" + item.height.toFixed(1)
                               + " off=" + restoreAnchorOffset.toFixed(1))
                        return
                    }
                    _srLog("anchor:NOT_FOUND",
                           "probes=" + probes
                           + " noIdx=" + noIdxHits
                           + " noItem=" + noItemHits
                           + " probeX=" + probeX.toFixed(1)
                           + " startY=" + startY.toFixed(1)
                           + " endY=" + endY.toFixed(1))
                }

                // Handle voice message finished - auto-play next voice if enabled
                function handleVoiceFinished(finishedMsgId, playbackRate) {
                    debugOverlay.lastEvent = "handleVoiceFinished called"
                    debugOverlay.lastMsgId = finishedMsgId.toString()
                    debugOverlay.lastRate = playbackRate.toString()
                    debugOverlay.lastNextIndex = ""
                    debugOverlay.lastStatus = "Starting..."
                    
                    console.log("handleVoiceFinished: msgId=" + finishedMsgId + " rate=" + playbackRate + " enabled=" + mainWindow.autoPlayNextVoice)
                    
                    // Check if auto-play is enabled
                    if (!mainWindow.autoPlayNextVoice) {
                        debugOverlay.lastStatus = "DISABLED - checkbox off"
                        return
                    }
                    
                    // Find the current message index
                    let currentIndex = -1
                    for (let i = 0; i < mainWindow.messageModel.count; i++) {
                        if (mainWindow.messageModel.data(mainWindow.messageModel.index(i, 0), 256) === finishedMsgId) { // 256 = IdRole
                            currentIndex = i
                            break
                        }
                    }
                    
                    console.log("handleVoiceFinished: currentIndex=" + currentIndex)
                    
                    if (currentIndex < 0) {
                        debugOverlay.lastStatus = "ERROR - current msg not found"
                        return
                    }
                    
                    debugOverlay.lastStatus = "Found current at index " + currentIndex
                    
                    // Look for the next voice message (PTT)
                    for (let i = currentIndex + 1; i < mainWindow.messageModel.count; i++) {
                        const msgType = mainWindow.messageModel.data(mainWindow.messageModel.index(i, 0), 260) // 260 = MsgTypeRole
                        console.log("handleVoiceFinished: checking index=" + i + " msgType=" + msgType)
                        
                        if (msgType === "ptt") {
                            // Found next voice message - get its details
                            const nextMsgId = mainWindow.messageModel.data(mainWindow.messageModel.index(i, 0), 256) // IdRole
                            
                            debugOverlay.lastNextIndex = i.toString() + " (msgId:" + nextMsgId + ")"
                            debugOverlay.lastStatus = "Found next PTT, triggering..."
                            
                            console.log("handleVoiceFinished: found next PTT at index=" + i + " msgId=" + nextMsgId)
                            
                            // Set the playback rate for the next message to maintain speed
                            if (msgList.audioSpeedMap && nextMsgId >= 0) {
                                msgList.audioSpeedMap[nextMsgId] = playbackRate
                                console.log("handleVoiceFinished: set speed=" + playbackRate + " for msgId=" + nextMsgId)
                            }
                            
                            // Trigger play by accessing the delegate and calling triggerPlay()
                            Qt.callLater(function() {
                                const item = msgList.itemAtIndex(i)
                                if (!item) {
                                    debugOverlay.lastStatus = "ERROR - item not found"
                                    console.log("handleVoiceFinished: item not found at index=" + i)
                                    return
                                }
                                
                                if (item.children.length === 0) {
                                    debugOverlay.lastStatus = "ERROR - item has no children"
                                    console.log("handleVoiceFinished: item has no children")
                                    return
                                }
                                
                                const bubble = item.children[0] // MessageBubble is first child of delegateRoot
                                if (!bubble) {
                                    debugOverlay.lastStatus = "ERROR - bubble not found"
                                    console.log("handleVoiceFinished: bubble not found")
                                    return
                                }
                                
                                if (typeof bubble.triggerPlay !== "function") {
                                    debugOverlay.lastStatus = "ERROR - triggerPlay() not found"
                                    console.log("handleVoiceFinished: triggerPlay not found on bubble")
                                    return
                                }
                                
                                debugOverlay.lastStatus = "SUCCESS - calling triggerPlay()"
                                console.log("handleVoiceFinished: calling triggerPlay() on bubble")
                                bubble.triggerPlay()
                            })
                            return // Found and triggered, stop searching
                        } else if (msgType !== "system") {
                            // If we encounter a non-system, non-voice message, stop
                            debugOverlay.lastStatus = "STOPPED - non-voice msg at " + i
                            console.log("handleVoiceFinished: stopping at non-voice message, index=" + i + " msgType=" + msgType)
                            return
                        }
                    }
                    
                    debugOverlay.lastStatus = "END - no more PTT found"
                    console.log("handleVoiceFinished: no more PTT messages found")
                }
                
                // NEW: Handle voice finished by index (more reliable)
                function handleVoiceFinishedByIndex(currentIndex, playbackRate) {
                    console.log("🎯 handleVoiceFinishedByIndex: index=" + currentIndex + " rate=" + playbackRate + " enabled=" + mainWindow.autoPlayNextVoice)
                    
                    // Check if auto-play is enabled
                    if (!mainWindow.autoPlayNextVoice) {
                        console.log("  ❌ Auto-play disabled")
                        return
                    }
                    
                    if (currentIndex < 0 || currentIndex >= mainWindow.messageModel.count) {
                        console.log("  ❌ Invalid index")
                        return
                    }
                    
                    // Look for the IMMEDIATE next item (currentIndex + 1)
                    const nextIndex = currentIndex + 1
                    if (nextIndex >= mainWindow.messageModel.count) {
                        console.log("  ⛔ No more messages after index " + currentIndex)
                        return
                    }
                    
                    // Check if the next item is PTT
                    const nextMsgType = mainWindow.messageModel.data(mainWindow.messageModel.index(nextIndex, 0), 265) // 265 = MessageTypeRole
                    console.log("  ➡️  Next index=" + nextIndex + " msgType=" + nextMsgType)
                    
                    if (nextMsgType === "ptt") {
                        // Next message is voice - play it!
                        const nextMsgId = mainWindow.messageModel.data(mainWindow.messageModel.index(nextIndex, 0), 257) // 257 = IdRole
                        
                        console.log("  ✅ Next is PTT at index=" + nextIndex + " msgId=" + nextMsgId + " setting speed=" + playbackRate)
                        
                        // Set the playback rate for the next message to maintain speed
                        // This must be done BEFORE the AudioPlayer is created/initialized
                        if (msgList.audioSpeedMap && nextMsgId >= 0) {
                            msgList.audioSpeedMap[nextMsgId] = playbackRate
                            console.log("  📊 audioSpeedMap[" + nextMsgId + "] = " + playbackRate)
                        }
                        
                        // Wait 500ms before playing next voice message
                        console.log("  ⏳ Starting 500ms delay timer...")
                        
                        autoPlayDelayTimer.nextIndex = nextIndex
                        autoPlayDelayTimer.playbackRate = playbackRate
                        autoPlayDelayTimer.restart()
                    } else {
                        // Next item is NOT a voice message - stop auto-play
                        console.log("  ⛔ Next item is not PTT (type=" + nextMsgType + ") - stopping auto-play")
                    }
                }

                function scheduleScrollRestore() {
                    if (!restorePending) { _srLog("schedule:SKIP", "reason=notPending"); return }
                    _srLog("schedule:scheduled")
                    restoreRetryCount = 0
                    restoreApplyTimer.restart()
                }

                function applyPendingScrollRestore() {
                    if (!restorePending) { _srLog("apply:SKIP", "reason=notPending"); return }

                    if (mainWindow.messageModel.loading) {
                        _srLog("apply:WAIT_LOADING", "retry=" + restoreRetryCount)
                        restoreApplyTimer.restart()
                        return
                    }

                    let targetY = restoreFallbackY
                    let anchored = false

                    const currentCount = mainWindow.messageModel.count
                    let insertedCount = restoreInsertedCount
                    if (insertedCount <= 0) {
                        insertedCount = currentCount - restoreBaseCount
                    }

                    _srLog("apply:enter",
                           "retry=" + restoreRetryCount
                           + " anchorIdx=" + restoreAnchorIndex
                           + " anchorOff=" + restoreAnchorOffset.toFixed(1)
                           + " insertedCount=" + insertedCount
                           + " baseCount=" + restoreBaseCount
                           + " baseY=" + restoreBaseY.toFixed(1)
                           + " baseH=" + restoreBaseH.toFixed(1)
                           + " baseOriginY=" + restoreBaseOriginY.toFixed(1)
                           + " deltaOriginY=" + (msgList.originY - restoreBaseOriginY).toFixed(1)
                           + " fallbackY=" + restoreFallbackY.toFixed(1))

                    if (restoreAnchorIndex >= 0 && insertedCount > 0) {
                        const targetIndex = restoreAnchorIndex + insertedCount
                        if (targetIndex >= 0 && targetIndex < currentCount) {
                            msgList.positionViewAtIndex(targetIndex, ListView.Beginning)
                            const anchoredItem = msgList.itemAtIndex(targetIndex)
                            if (anchoredItem) {
                                targetY = anchoredItem.y + restoreAnchorOffset
                                anchored = true
                                _srLog("apply:ANCHOR_OK",
                                       "targetIdx=" + targetIndex
                                       + " item.y=" + anchoredItem.y.toFixed(1)
                                       + " item.h=" + anchoredItem.height.toFixed(1)
                                       + " -> targetY=" + targetY.toFixed(1))
                            } else if (restoreRetryCount < 6) {
                                restoreRetryCount++
                                _srLog("apply:ANCHOR_RETRY",
                                       "targetIdx=" + targetIndex
                                       + " retry=" + restoreRetryCount
                                       + " itemNotYetCreated")
                                restoreApplyTimer.restart()
                                return
                            } else {
                                _srLog("apply:ANCHOR_GIVEUP",
                                       "targetIdx=" + targetIndex
                                       + " retry exhausted, falling back to deltaH")
                            }
                        } else {
                            _srLog("apply:ANCHOR_OOR",
                                   "targetIdx=" + targetIndex
                                   + " currentCount=" + currentCount
                                   + " -> falling back")
                        }
                    } else {
                        _srLog("apply:ANCHOR_SKIP",
                               "reason=" + (restoreAnchorIndex < 0 ? "noAnchor" : "insertedCount<=0"))
                    }

                    if (!anchored) {
                        const deltaH = msgList.contentHeight - restoreBaseH
                        // [SCROLL-RESTORE] originY may shift on front-insert; account for it in the fallback.
                        const deltaOrigin = msgList.originY - restoreBaseOriginY
                        if (deltaH <= 0.5 && restoreRetryCount < 6) {
                            restoreRetryCount++
                            _srLog("apply:DELTAH_RETRY",
                                   "deltaH=" + deltaH.toFixed(2)
                                   + " deltaOrigin=" + deltaOrigin.toFixed(2)
                                   + " retry=" + restoreRetryCount
                                   + " cH=" + msgList.contentHeight.toFixed(1)
                                   + " baseH=" + restoreBaseH.toFixed(1))
                            restoreApplyTimer.restart()
                            return
                        }
                        if (deltaH > 0.5) {
                            targetY = restoreBaseY + deltaH + deltaOrigin
                            _srLog("apply:DELTAH_OK",
                                   "deltaH=" + deltaH.toFixed(2)
                                   + " deltaOrigin=" + deltaOrigin.toFixed(2)
                                   + " -> targetY=" + targetY.toFixed(1))
                        } else {
                            _srLog("apply:DELTAH_GIVEUP",
                                   "deltaH=" + deltaH.toFixed(2)
                                   + " deltaOrigin=" + deltaOrigin.toFixed(2)
                                   + " using cppFallbackY=" + restoreFallbackY.toFixed(1))
                        }
                    }

                    // [SCROLL-RESTORE] maxY in originY-aware coordinates. ListView contentY range is [originY, originY + contentHeight - height].
                    const minY = msgList.originY
                    const maxY = Math.max(minY, msgList.originY + msgList.contentHeight - msgList.height)
                    if (targetY !== targetY) {
                        _srLog("apply:NaN_GUARD", "targetY was NaN, using baseY=" + restoreBaseY.toFixed(1))
                        targetY = restoreBaseY
                    }
                    const preClamp = targetY
                    targetY = Math.max(minY, Math.min(maxY, targetY))
                    if (preClamp !== targetY) {
                        _srLog("apply:CLAMPED",
                               "pre=" + preClamp.toFixed(1)
                               + " -> post=" + targetY.toFixed(1)
                               + " minY=" + minY.toFixed(1)
                               + " maxY=" + maxY.toFixed(1)
                               + " cH=" + msgList.contentHeight.toFixed(1)
                               + " h=" + msgList.height.toFixed(0))
                    }

                    msgList.contentY = targetY
                    msgList.lastContentY = targetY
                    msgList.restorePending = false
                    msgList.restoreRetryCount = 0
                    msgList.restoreAnchorIndex = -1
                    msgList.restoreAnchorOffset = 0
                    msgList.restoreInsertedCount = 0
                    msgList.isLoadingMore = false
                    _srLog("apply:DONE",
                           "finalY=" + targetY.toFixed(1)
                           + " anchored=" + anchored
                           + " atEnd=" + msgList.atYEnd
                           + " atBeg=" + msgList.atYBeginning)
                }

                Timer {
                    id: loadMoreDebounce
                    interval: msgList.loadDebounceMs
                    repeat: false
                    onTriggered: msgList.requestOlderMessages()
                }
                
                // Timer for auto-play delay (500ms pause between voice messages)
                Timer {
                    id: autoPlayDelayTimer
                    interval: 500
                    repeat: false
                    
                    property int nextIndex: -1
                    property real playbackRate: 1.0
                    
                    onTriggered: {
                        console.log("⏰ autoPlayDelayTimer.onTriggered: nextIndex=" + nextIndex + " rate=" + playbackRate)
                        
                        const item = msgList.itemAtIndex(nextIndex)
                        if (!item) {
                            console.log("  ❌ Item not found at index " + nextIndex)
                            return
                        }
                        
                        if (item.children.length === 0) {
                            console.log("  ❌ Item has no children")
                            return
                        }
                        
                        const bubble = item.children[0] // MessageBubble is first child of delegateRoot
                        if (!bubble) {
                            console.log("  ❌ Bubble not found")
                            return
                        }
                        
                        if (typeof bubble.triggerPlay !== "function") {
                            console.log("  ❌ triggerPlay() not found on bubble")
                            return
                        }
                        
                        console.log("  ▶️  Calling bubble.triggerPlay(" + playbackRate + ")")
                        bubble.triggerPlay(playbackRate)
                    }
                }

                Timer {
                    id: restoreApplyTimer
                    interval: 16
                    repeat: false
                    onTriggered: msgList.applyPendingScrollRestore()
                }

                // ContentHeight stable events may be rare in large chats.
                // This fallback timer prevents the isNewChat/contentReady flags from getting stuck.
                Timer {
                    id: newChatSafetyTimer
                    interval: 1200
                    repeat: false
                    onTriggered: {
                        if (!msgList.isNewChat) return
                        Qt.callLater(function() {
                            if (msgList.count > 0 && !msgList.dragging && !msgList.flicking) {
                                msgList.positionViewAtEnd()
                            }
                            msgList.isNewChat = false
                            msgList.contentReady = true
                            msgList.lastStableH = msgList.contentHeight
                            msgList.lastContentY = msgList.contentY
                            msgList.stabilizeCount = 0
                        })
                    }
                }

                // Mouse Wheel Bounce
                transform: Translate { y: wheelBounce.yOffset }
                MouseWheelHandler {
                    id: wheelBounce
                    target: msgList
                    anchors.fill: parent
                    overshootAmount: 60
                    handlerEnabled: msgList.contentReady
                }

                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AlwaysOff
                    interactive: false
                }

                // ── New chat selected ─────────────────────────────────
                Connections {
                    target: mainWindow
                    function onActiveChatChanged() {
                        msgList.contentReady   = false
                        msgList.stabilizeCount = 0
                        msgList.lastStableH    = 0
                        msgList.isNewChat      = true
                        msgList.isLoadingMore  = false
                        msgList.lastContentY   = 0
                        msgList.restorePending = false
                        msgList.restoreRetryCount = 0
                        msgList.restoreAnchorIndex = -1
                        msgList.restoreAnchorOffset = 0
                        msgList.restoreInsertedCount = 0
                        // Reset per-message audio playback-rate state so the avatar
                        // (not the speed badge) is shown again in the new chat.
                        msgList.audioSpeedMap = ({})
                        loadMoreDebounce.stop()
                        restoreApplyTimer.stop()
                        newChatSafetyTimer.restart()
                        msgList._srLog("chatChanged:reset")
                    }
                    function onJumpToDateIndex(messageIndex) {
                        if (messageIndex < 0) return
                        // Ensure all messages are loaded first
                        mainWindow.messageModel.ensureAllLoaded()
                        Qt.callLater(function() {
                            if (messageIndex < mainWindow.messageModel.count) {
                                msgList.positionViewAtIndex(messageIndex, ListView.Beginning)
                                msgList.lastContentY = msgList.contentY
                            }
                        })
                    }
                }

                // ── For new chat: end when count arrives ───────────
                onCountChanged: {
                    if (!isNewChat) return
                    Qt.callLater(function() { msgList.positionViewAtEnd() })
                    newChatSafetyTimer.restart()
                }

                // ── contentHeight: new chat stabilization ─────────
                onContentHeightChanged: {
                    if (!isNewChat || contentReady) return
                    if (contentHeight <= 0 || dragging || flicking) return
                    if (Math.abs(contentHeight - lastStableH) < 5) {
                        stabilizeCount++
                        if (stabilizeCount >= 3) {
                            Qt.callLater(function() {
                                msgList.positionViewAtEnd()
                                msgList.isNewChat     = false
                                msgList.contentReady  = true
                                msgList.lastStableH   = msgList.contentHeight
                                msgList.lastContentY  = msgList.contentY
                                msgList.stabilizeCount = 0
                                newChatSafetyTimer.stop()
                            })
                        }
                    } else {
                        stabilizeCount = 0
                        lastStableH    = contentHeight
                        if (count <= 60) {
                            Qt.callLater(function() {
                                if (!dragging && !flicking) msgList.positionViewAtEnd()
                            })
                        }
                    }
                }

                verticalLayoutDirection: ListView.TopToBottom

                // ── Scroll up: load old message ──────────────────
                onContentYChanged: {
                    if (!contentReady) {
                        lastContentY = contentY
                        return
                    }

                    const movingUp = contentY < (lastContentY - 0.5)
                    lastContentY = contentY

                    if (mainWindow.messageModel.loading) return
                    if (isLoadingMore || isNewChat)      return
                    if (mainWindow.messageModel.totalCount <= mainWindow.messageModel.count) return

                    const threshold = topLoadThreshold()
                    if ((movingUp && contentY <= threshold) || (atYBeginning && contentY <= (threshold + 40))) {
                        _srLog("trigger:contentY",
                               "movingUp=" + movingUp
                               + " atBeg=" + atYBeginning
                               + " threshold=" + threshold.toFixed(0))
                        loadMoreDebounce.restart()
                    }
                }

                onMovementEnded: {
                    if (!contentReady) return
                    if (mainWindow.messageModel.loading) return
                    if (isLoadingMore || isNewChat) return
                    if (mainWindow.messageModel.totalCount <= mainWindow.messageModel.count) return

                    if (atYBeginning) {
                        _srLog("trigger:movementEnded", "atBeg=true")
                        loadMoreDebounce.restart()
                    }
                }

                // ── C++ scroll recovery signal ─────────────────────────
                Connections {
                    target: mainWindow.messageModel
                    function onScrollRestoreNeeded(newContentY, insertedCount) {
                        // C++ save value as fallback, exact recovery in QML
                        // is done with the real contentHeight difference.
                        msgList.restoreFallbackY = newContentY
                        msgList.restoreInsertedCount = insertedCount
                        msgList._srLog("signal:scrollRestoreNeeded",
                                       "newY=" + newContentY.toFixed(1)
                                       + " inserted=" + insertedCount)
                        msgList.scheduleScrollRestore()
                    }
                    function onLoadingChanged() {
                        msgList._srLog("signal:loadingChanged",
                                       "loading=" + mainWindow.messageModel.loading)
                        // scrollRestoreNeeded failed (null result) — reset flag
                        if (!mainWindow.messageModel.loading && msgList.isLoadingMore) {
                            if (msgList.restorePending) {
                                msgList._srLog("signal:loadingChanged:reschedule")
                                msgList.scheduleScrollRestore()
                            } else {
                                msgList._srLog("signal:loadingChanged:clearFlag")
                                msgList.isLoadingMore = false
                            }
                        }
                    }
                }

                delegate: Item {
                    id: delegateRoot
                    width:  msgList.width
                    height: bubbleItem.height
                    
                    property int delegateIndex: index  // Store the model index

                    MessageBubble {
                        id: bubbleItem
                        width:            parent.width
                        isGroupChat:      mainWindow.activeChatIsGroup
                        msgId:            model.msgId
                        audioSpeedStore:  msgList.audioSpeedMap
                        isFromMe:         model.isFromMe
                        formattedContent: model.formattedContent
                        msgTime:          model.msgTime
                        sender:           model.sender 
                        senderAvatarPath: model.senderAvatar
                        msgDate:          model.msgDate
                        readStatus:       model.readStatus
                        isFirstInGroup:   model.isFirstInGroup
                        isLastInGroup:    model.isLastInGroup
                        msgType:          model.msgType
                        mediaPath:        model.mediaPath
                        mediaThumbnail:   model.mediaThumbnail
                        mediaDuration:    model.mediaDuration
                        mediaMeta:        model.mediaMeta
                        waveform:         model.waveform
                        editedText:       model.editedText === "1"
                                          ? (langManager.currentTranslations["edited"] || "Edited")
                                          : model.editedText !== "" && model.editedText !== "0"
                                            ? (langManager.currentTranslations["edited"] || model.editedText)
                                            : ""
                        showDate:         model.showDateSeparator && model.msgType !== "system"
                        
                        // Handle voice message finished - pass the delegate index instead of msgId
                        onVoiceMessageFinished: function(messageId, playbackRate) {
                            msgList.handleVoiceFinishedByIndex(delegateRoot.delegateIndex, playbackRate)
                        }
                    }
                }

                // Scroll to search result
                Connections {
                    target: searchCtrl
                    function onScrollToIndex(idx) {
                        msgList.positionViewAtIndex(idx, ListView.Center)
                    }
                }

                // ── Loading indicator above ───────────────────────
                Item {
                    id: loadingIndicator
                    visible: mainWindow.messageModel.loading
                    anchors {
                        top:              parent.top
                        horizontalCenter: parent.horizontalCenter
                        topMargin:        8
                    }
                    width:  42
                    height: 42
                    z:      10

                    Rectangle {
                        anchors.fill: parent
                        radius: width / 2
                        color:  WAPageTheme.dateSepBg
                        opacity: 0.9

                        Item {
                            anchors.centerIn: parent
                            width: 24
                            height: 24

                            Rectangle {
                                anchors.fill: parent
                                radius: width / 2
                                color: "transparent"
                                border.width: 2
                                border.color: "#8696A0"
                            }

                            Item {
                                anchors.fill: parent
                                transformOrigin: Item.Center

                                RotationAnimator on rotation {
                                    from: 0
                                    to: 360
                                    duration: 900
                                    loops: Animation.Infinite
                                    running: mainWindow.messageModel.loading
                                    easing.type: Easing.Linear
                                }

                                Canvas {
                                    id: loadingIndicatorArc
                                    anchors.fill: parent
                                    antialiasing: true

                                    property color arcColor: WAPageTheme.dark ? "#00D4A8" : "#00C060"

                                    onArcColorChanged: requestPaint()
                                    onWidthChanged: requestPaint()
                                    onHeightChanged: requestPaint()

                                    onPaint: {
                                        const ctx = getContext("2d")
                                        ctx.clearRect(0, 0, width, height)

                                        const lineW = 2
                                        const cx = width / 2
                                        const cy = height / 2
                                        const r = Math.max(0, Math.min(width, height) / 2 - lineW / 2)

                                        ctx.beginPath()
                                        ctx.lineWidth = lineW
                                        ctx.lineCap = "round"
                                        ctx.strokeStyle = arcColor
                                        ctx.arc(cx, cy, r, -Math.PI * 0.78, Math.PI * 0.18, false)
                                        ctx.stroke()
                                    }

                                    Component.onCompleted: requestPaint()
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Calendar overlay - dim background, click to close
    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: calendarDialog.visible ? 0.3 : 0
        visible: opacity > 0
        z: 999

        Behavior on opacity {
            NumberAnimation { duration: 150 }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: calendarDialog.close()
        }
    }

    // Calendar dialog for date navigation
    CalendarDialog {
        id: calendarDialog
        anchors.centerIn: parent
        onDateSelected: function(date) {
            mainWindow.jumpToDate(date)
        }
    }

    // Profile view overlay
    ProfileView {
        id: profileView
        anchors.fill: parent
        visible:      false
    }
}
