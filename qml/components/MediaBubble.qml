import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt5Compat.GraphicalEffects

// Image/video message bubble content
Item {
    id: root

    property string mediaPath:      ""
    property string mediaThumbnail: ""
    property string mediaDuration:  ""
    property string mediaType:      "image"   // "image" | "video"
    property string msgTime:        ""
    property string editedText:     ""
    property int    readStatus:     3
    property bool   isFromMe:       false

    implicitWidth:  240
    implicitHeight: 200

    Rectangle {
        anchors.fill: parent
        radius:       WAPageTheme.bubbleRadius
        color:        "#000000"
        clip:         true

        // Photo / Video thumbnail
        Item {
            anchors.fill: parent
            clip: true
            
            // For video - Thumbnail or placeholder
            Image {
                id: videoThumbnail
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
                asynchronous: true  // Load async - don't block scroll
                cache: true
                visible: root.mediaType === "video" && root.mediaThumbnail.length > 0
                source: root.mediaThumbnail.length > 0
                    ? ("file:///" + root.mediaThumbnail.replace(/\\/g, "/"))
                        : ""
            }
            
            // Video placeholder - will always be visible (if not thumbnail)
            Rectangle {
                id: videoPlaceholder
                anchors.fill: parent
                color: "#1C1C1C"
                visible: root.mediaType === "video" && root.mediaThumbnail.length === 0
                
                Column {
                    anchors.centerIn: parent
                    spacing: 8
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "🎬"
                        font.pixelSize: 40
                    }
                }
            }
            
            // Image component for an image
            Image {
                id: mediaImg
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
                asynchronous: true  // Load async - don't block scroll
                cache: true
                visible: root.mediaType === "image"
                source: root.mediaType === "image" && root.mediaPath.length > 0
                        ? ("file:///" + root.mediaPath.replace(/\\/g, "/"))
                        : ""
            }
        }

        // Loading indicator
        Item {
            id: mediaLoadingSpinner
            anchors.centerIn: parent
            width: 36
            height: 36

            readonly property bool imageLoading: root.mediaType === "image" && mediaImg.status === Image.Loading
            readonly property bool videoLoading: root.mediaType === "video" && root.mediaThumbnail.length > 0
                                                && videoThumbnail.status === Image.Loading

            visible: imageLoading || videoLoading

            Rectangle {
                anchors.fill: parent
                radius: width / 2
                color: "#55000000"
            }

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
                        running: mediaLoadingSpinner.visible
                        easing.type: Easing.Linear
                    }

                    Canvas {
                        id: mediaSpinnerArc
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

        // ── Placeholder if image not found ──────────────────────────
        Rectangle {
            anchors.fill: parent
            color:        "#2A2A2A"
            visible:      root.mediaType === "image" && mediaImg.status === Image.Error

            Column {
                anchors.centerIn: parent
                spacing: 6
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           "🖼"
                    font.pixelSize: 36
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           langManager.currentTranslations["image_not_found"]
                    color:          "#AAAAAA"
                    font.pixelSize: WAPageTheme.fontSizeMicro
                    font.family:    WAPageTheme.fontFamily
                }
            }
        }

        // ── Placeholder if video thumbnail not found ─────────────────
        Rectangle {
            anchors.fill: parent
            color:        "#2A2A2A"
            visible:      root.mediaType === "video" && videoThumbnail.status === Image.Error

            Column {
                anchors.centerIn: parent
                spacing: 6
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           "🎬"
                    font.pixelSize: 36
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:           langManager.currentTranslations["image_not_found"]
                    color:          "#AAAAAA"
                    font.pixelSize: WAPageTheme.fontSizeMicro
                    font.family:    WAPageTheme.fontFamily
                }
            }
        }

        // Video play button
        Rectangle {
            visible:          root.mediaType === "video"
            anchors.centerIn: parent
            width:            48
            height:           48
            radius:           24
            color:            "#8C000000"

            Image {
                id: videoPlayIcon
                anchors.centerIn: parent
                source:      "qrc:/assets/icon_play.svg"
                width:       24; height: 24
                sourceSize:  Qt.size(24, 24)
                visible:     false
            }

            ColorOverlay {
                anchors.fill: videoPlayIcon
                source:       videoPlayIcon
                color:        "#FFFFFF"
            }
        }

        // Video duration (bottom left)
        Rectangle {
            visible: root.mediaType === "video" && root.mediaDuration.length > 0
            anchors {
                left:         parent.left
                bottom:       parent.bottom
                leftMargin:   8
                bottomMargin: 6
            }
            color:  "#80000000"
            radius: 4
            width:  durationText.width + 10
            height: durationText.height + 4

            Text {
                id: durationText
                anchors.centerIn: parent
                text:           root.mediaDuration
                color:          "#FFFFFF"
                font.family:    WAPageTheme.fontFamily
                font.pixelSize: WAPageTheme.fontSizeMicro
            }
        }

        // ── Time + tick (bottom right, on semi-transparent background) ─────
        Rectangle {
            anchors {
                right:  parent.right
                bottom: parent.bottom
                left:   parent.left
            }
            height: 28
            color:  "#59000000"

            Row {
                anchors {
                    right:          parent.right
                    verticalCenter: parent.verticalCenter
                    rightMargin:    8
                }
                spacing: 3

                Text {
                    visible:        root.editedText !== ""
                    text:           root.editedText
                    color:          "#D9FFFFFF"
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                    font.italic:    true
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text:           root.msgTime
                    color:          "#D9FFFFFF"
                    font.family:    WAPageTheme.fontFamily
                    font.pixelSize: WAPageTheme.fontSizeMicro
                    anchors.verticalCenter: parent.verticalCenter
                }

                TickMark {
                    visible:    root.isFromMe
                    readStatus: root.readStatus
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }

        // ── Click — opens media viewer ─────────────────────────────
        TapHandler {
            cursorShape: Qt.PointingHandCursor
            enabled:     root.mediaPath.length > 0
            onTapped: {
                if (root.mediaPath.length > 0)
                    mediaViewer.open(root.mediaPath, root.mediaType, root.mediaThumbnail)
            }
        }
    }
}
