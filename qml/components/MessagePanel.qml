import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

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
            onFirstMessageRequested: msgList.jumpToFirstMessage()
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
                              ? "qrc:/assets/wallpaper_dark.png"
                              : "qrc:/assets/wallpaper_light.png"
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
                    enabled: msgList.contentReady
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

    // Profile view overlay
    ProfileView {
        id: profileView
        anchors.fill: parent
        visible:      false
    }
}
