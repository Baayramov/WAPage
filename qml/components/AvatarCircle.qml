import QtQuick 2.15
import Qt5Compat.GraphicalEffects

// Round avatar like in WAPage
// If there is a picture, it shows the picture, otherwise it shows a colored circle + initials
Item {
    id: root

    property string avatarPath:  ""
    property string initials:    "?"
    property string avatarColor: "#00BFA5"
    property int    size:        WAPageTheme.avatarSize

    width:  size
    height: size

    // Background circle
    Rectangle {
        anchors.fill: parent
        radius:       width / 2
        color:        root.avatarPath.length > 0 ? "transparent" : root.avatarColor
        clip:         true

        // Image to be masked
        Image {
            id: avatarImg
            anchors.fill: parent
            source:       root.avatarPath.length > 0
                          ? (root.avatarPath.startsWith("qrc:") ? root.avatarPath : ("file:///" + root.avatarPath)) : ""
            // Guard against zero size during initial WAPageTheme evaluation.
            // Multiplied by 2 for crisp rendering on HiDPI screens.
            sourceSize.width:  Math.max(48, root.size) * 2
            sourceSize.height: Math.max(48, root.size) * 2
            // SVG/qrc avatars (default coloured icons) should fit without cropping.
            // User-supplied raster photos use Crop to fill the circle neatly.
            fillMode: root.avatarPath.startsWith("qrc:") ? Image.PreserveAspectFit
                                                         : Image.PreserveAspectCrop
            visible:      false // OpacityMask will show
        }
        
        // Circular cut effect
        OpacityMask {
            anchors.fill: avatarImg
            source: avatarImg
            maskSource: Rectangle {
                width: avatarImg.width
                height: avatarImg.height
                radius: avatarImg.width / 2
            }
            visible: root.avatarPath.length > 0
        }

        // Initials if there is no image
        Text {
            anchors.centerIn: parent
            text:             root.initials
            color:            "#FFFFFF"
            font.family:      WAPageTheme.fontFamily
            font.pixelSize:   Math.round(root.size * 0.38)
            font.weight:      Font.Medium
            visible:          root.avatarPath.length === 0
        }
    }
}
