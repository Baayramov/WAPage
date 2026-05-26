import QtQuick 2.15

// Mouse Wheel Bounce (overshoot) simulator for black (ListView/Flickable).
// The "rubber" effect that is missing in desktop engines is provided here for the wheel.
Item {
    id: root

    property Flickable target: null
    property real overshootAmount: 40 // Maximum jump in pixels
    property bool enabled: true       // disabled until contentReady
    
    // The offset to be bound (bind) by the governor
    property real yOffset: 0

    // Spring effect (Spring) - Return action
    Behavior on yOffset {
        SpringAnimation {
            spring: 3.5
            damping: 0.3
            epsilon: 0.5
        }
    }

    // Reset offset when enabled changes
    onEnabledChanged: {
        if (!enabled) {
            yOffset = 0
            returnTimer.stop()
        }
    }

    // MouseArea to track wheel events (without blocking the scroll)
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.NoButton // It does not accept clicks, only the wheel works
        propagateComposedEvents: true
        onWheel: (wheel) => {
            if (!root.target || !root.enabled) {
                wheel.accepted = false
                return
            }
            
            let delta = Math.sign(wheel.angleDelta.y) * 15;

            // If it is at the top and is rotated up (up)
            if (root.target.atYBeginning && delta > 0) {
                root.yOffset = Math.min(root.overshootAmount, root.yOffset + delta);
                returnTimer.restart();
            } 
            // If it is at the bottom and scrolls down (down)
            else if (root.target.atYEnd && delta < 0) {
                root.yOffset = Math.max(-root.overshootAmount, root.yOffset + delta);
                returnTimer.restart();
            }

            wheel.accepted = false; 
        }
    }

    Timer {
        id: returnTimer
        interval: 150
        onTriggered: root.yOffset = 0
    }
}
