import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import WAPage 1.0

// Media Browser - Modern full screen media viewer with theme support
Rectangle {
    id: mediaBrowserRoot
    
    visible: false
    anchors.fill: parent
    color: Qt.rgba(0, 0, 0, 0.7) // Semi-transparent overlay
    z: 1000
    
    // Theme colors - dynamically based on mainWindow.isDarkTheme
    readonly property color bgColor: mainWindow.isDarkTheme ? "#0B141A" : "#F0F2F5"
    readonly property color cardColor: mainWindow.isDarkTheme ? "#1F2C33" : "#FFFFFF"
    readonly property color headerColor: mainWindow.isDarkTheme ? "#202C33" : "#EDEDED"
    readonly property color textColor: mainWindow.isDarkTheme ? "#E9EDEF" : "#3B4A54"
    readonly property color subtextColor: mainWindow.isDarkTheme ? "#8696A0" : "#667781"
    readonly property color accentColor: "#00A884"
    readonly property color hoverColor: mainWindow.isDarkTheme ? "#2A3942" : "#F5F6F6"
    readonly property color borderColor: mainWindow.isDarkTheme ? "#2A3942" : "#E9EDEF"
    
    property string currentTab: "photos"
    
    MouseArea {
        anchors.fill: parent
        onClicked: mediaBrowserRoot.visible = false
    }
    
    // Main dialog container
    Rectangle {
        id: dialogContainer
        anchors.centerIn: parent
        width: parent.width * 0.92
        height: parent.height * 0.92
        radius: 0
        color: bgColor
        
        // Prevent click-through
        MouseArea {
            anchors.fill: parent
            onClicked: {} // Consume
        }
        
        ColumnLayout {
            anchors.fill: parent
            spacing: 0
            
            // Header
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 64
                color: headerColor
                radius: 0
                
                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: 24
                    anchors.rightMargin: 24
                    spacing: 16
                    
                    Text {
                        text: langManager.currentTranslations["media_browser"] || "Medialar"
                        color: textColor
                        font.pixelSize: 20
                        font.weight: Font.DemiBold
                        Layout.fillWidth: true
                    }
                    
                    // Close button
                    Rectangle {
                        width: 40
                        height: 40
                        radius: 20
                        color: closeMouseArea.pressed ? hoverColor : "transparent"
                        
                        Text {
                            anchors.centerIn: parent
                            text: "✕"
                            color: textColor
                            font.pixelSize: 20
                            font.weight: Font.Light
                        }
                        
                        MouseArea {
                            id: closeMouseArea
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: mediaBrowserRoot.visible = false
                        }
                    }
                }
            }
            
            // Tab bar
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 56
                color: headerColor
                
                ListView {
                    anchors.fill: parent
                    anchors.leftMargin: 16
                    anchors.rightMargin: 16
                    orientation: ListView.Horizontal
                    spacing: 4
                    clip: true
                    interactive: false
                    
                    model: ListModel {
                        ListElement { name: ""; type: "photos"; icon: "qrc:/assets/photo.svg" }
                        ListElement { name: ""; type: "videos"; icon: "qrc:/assets/video.svg" }
                        ListElement { name: ""; type: "documents"; icon: "qrc:/assets/file.svg" }
                        ListElement { name: ""; type: "links"; icon: "qrc:/assets/link.svg" }
                        ListElement { name: ""; type: "locations"; icon: "qrc:/assets/location.svg" }
                    }
                    
                    delegate: Rectangle {
                        width: 130
                        height: 48
                        radius: 24
                        color: mediaBrowserRoot.currentTab === model.type ? accentColor : "transparent"
                        
                        Behavior on color { ColorAnimation { duration: 200 } }
                        
                        RowLayout {
                            anchors.centerIn: parent
                            spacing: 6
                            
                            Item {
                                width: 18
                                height: 18
                                
                                Image {
                                    id: tabIcon
                                    anchors.fill: parent
                                    source: model.icon
                                    sourceSize: Qt.size(18, 18)
                                    visible: model.type !== "locations"
                                }
                                
                                // ColorOverlay for location icon (always black)
                                ColorOverlay {
                                    anchors.fill: parent
                                    source: Image {
                                        source: model.icon
                                        sourceSize: Qt.size(18, 18)
                                    }
                                    color: "#000000"
                                    visible: model.type === "locations"
                                }
                            }
                            
                            Text {
                                text: {
                                    if (model.type === "photos") return langManager.currentTranslations["media_browser_photos"] || "Şəkillər"
                                    if (model.type === "videos") return langManager.currentTranslations["media_browser_videos"] || "Videolar"
                                    if (model.type === "documents") return langManager.currentTranslations["media_browser_documents"] || "Fayllar"
                                    if (model.type === "links") return langManager.currentTranslations["media_browser_links"] || "Linklər"
                                    if (model.type === "locations") return langManager.currentTranslations["media_browser_locations"] || "Konumlar"
                                    return ""
                                }
                                color: mediaBrowserRoot.currentTab === model.type ? "#FFFFFF" : subtextColor
                                font.pixelSize: 14
                                font.weight: mediaBrowserRoot.currentTab === model.type ? Font.DemiBold : Font.Normal
                            }
                        }
                        
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: {
                                mediaBrowserRoot.currentTab = model.type
                                loadCurrentTab()
                            }
                        }
                    }
                }
            }
            
            // Content area
            StackLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                currentIndex: {
                    switch(mediaBrowserRoot.currentTab) {
                        case "photos": return 0
                        case "videos": return 1
                        case "documents": return 2
                        case "links": return 3
                        case "locations": return 4
                        default: return 0
                    }
                }
                
                // Photos grid
                Item {
                    // Empty state
                    Column {
                        anchors.centerIn: parent
                        spacing: 16
                        visible: photosModel.count === 0
                        
                        Image {
                            anchors.horizontalCenter: parent.horizontalCenter
                            source: "qrc:/assets/photo.svg"
                            width: 64
                            height: 64
                            sourceSize: Qt.size(64, 64)
                        }
                        
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: langManager.currentTranslations["no_photos_found"] || "Şəkil tapılmadı"
                            color: subtextColor
                            font.pixelSize: 16
                        }
                    }
                    
                    GridView {
                        id: photosGrid
                        anchors.fill: parent
                        anchors.margins: 16
                        cellWidth: 196
                        cellHeight: 196
                        clip: true
                        visible: photosModel.count > 0
                        interactive: true
                        flickableDirection: Flickable.VerticalFlick
                        boundsBehavior: Flickable.DragAndOvershootBounds
                        boundsMovement: Flickable.FollowBoundsBehavior
                        flickDeceleration: 600
                        maximumFlickVelocity: 8000
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOff
                        }
                        
                        model: ListModel { id: photosModel }
                            
                            delegate: Item {
                                width: 186
                                height: 186
                                
                                Rectangle {
                                    id: photoCard
                                    anchors.fill: parent
                                    radius: 12
                                    color: "transparent"
                                    clip: true
                                    
                                    Image {
                                        anchors.fill: parent
                                        anchors.margins: 4
                                        source: model.thumbnailPath || model.mediaPath
                                        fillMode: Image.PreserveAspectCrop
                                        asynchronous: true
                                        smooth: true
                                        cache: true
                                    }
                                    
                                    // Hover overlay (dark)
                                    Rectangle {
                                        anchors.fill: parent
                                        anchors.margins: 4
                                        radius: 8
                                        color: "#000000"
                                        opacity: photoMouseArea.containsMouse ? 0.15 : 0
                                        
                                        Behavior on opacity { 
                                            NumberAnimation { duration: 200; easing.type: Easing.InOutQuad } 
                                        }
                                    }
                                }
                                
                                MouseArea {
                                    id: photoMouseArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        // Use QUrl to properly extract local file path (cross-platform)
                                        var filePath = model.mediaPath
                                        if (filePath.indexOf("file://") === 0) {
                                            // Let Qt handle the conversion from file:// URL to local path
                                            filePath = filePath
                                        }
                                        var thumbnailPath = model.thumbnailPath || ""
                                        
                                        // Extract local paths for mediaViewer
                                        var localFile = filePath.replace(/^file:\/\/\//, "")
                                        var localThumb = thumbnailPath.replace(/^file:\/\/\//, "")
                                        
                                        mediaViewer.open(localFile, "image", localThumb)
                                    }
                                }
                            }
                        }
                    }
                
                // Videos grid
                Item {
                    // Empty state
                    Column {
                        anchors.centerIn: parent
                        spacing: 16
                        visible: videosModel.count === 0
                        
                        Image {
                            anchors.horizontalCenter: parent.horizontalCenter
                            source: "qrc:/assets/video.svg"
                            width: 64
                            height: 64
                            sourceSize: Qt.size(64, 64)
                        }
                        
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: langManager.currentTranslations["no_videos_found"] || "Video tapılmadı"
                            color: subtextColor
                            font.pixelSize: 16
                        }
                    }
                    
                    GridView {
                        id: videosGrid
                        anchors.fill: parent
                        anchors.margins: 16
                        cellWidth: 196
                        cellHeight: 196
                        clip: true
                        visible: videosModel.count > 0
                        interactive: true
                        flickableDirection: Flickable.VerticalFlick
                        boundsBehavior: Flickable.DragAndOvershootBounds
                        boundsMovement: Flickable.FollowBoundsBehavior
                        flickDeceleration: 600
                        maximumFlickVelocity: 8000
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOff
                        }
                        
                        model: ListModel { id: videosModel }
                            
                            delegate: Item {
                                width: 186
                                height: 186
                                
                                Rectangle {
                                    id: videoCard
                                    anchors.fill: parent
                                    radius: 12
                                    color: "transparent"
                                    clip: true
                                    
                                    Image {
                                        anchors.fill: parent
                                        anchors.margins: 4
                                        source: model.thumbnailPath || model.mediaPath
                                        fillMode: Image.PreserveAspectCrop
                                        asynchronous: true
                                        smooth: true
                                        cache: true
                                    }
                                    
                                    // Play button overlay
                                    Rectangle {
                                        anchors.centerIn: parent
                                        width: 48
                                        height: 48
                                        radius: 24
                                        color: Qt.rgba(0, 0, 0, 0.7)
                                        
                                        Text {
                                            anchors.centerIn: parent
                                            text: "▶"
                                            color: "white"
                                            font.pixelSize: 20
                                        }
                                    }
                                    
                                    // Hover overlay (dark)
                                    Rectangle {
                                        anchors.fill: parent
                                        anchors.margins: 4
                                        radius: 8
                                        color: "#000000"
                                        opacity: videoMouseArea.containsMouse ? 0.15 : 0
                                        
                                        Behavior on opacity { 
                                            NumberAnimation { duration: 200; easing.type: Easing.InOutQuad } 
                                        }
                                    }
                                }
                                
                                MouseArea {
                                    id: videoMouseArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        // Use QUrl to properly extract local file path (cross-platform)
                                        var filePath = model.mediaPath
                                        var thumbnailPath = model.thumbnailPath || ""
                                        
                                        // Extract local paths for mediaViewer
                                        var localFile = filePath.replace(/^file:\/\/\//, "")
                                        var localThumb = thumbnailPath.replace(/^file:\/\/\//, "")
                                        
                                        mediaViewer.open(localFile, "video", localThumb)
                                    }
                                }
                            }
                        }
                    }
                
                // Documents list
                Item {
                    // Empty state
                    Column {
                        anchors.centerIn: parent
                        spacing: 16
                        visible: documentsModel.count === 0
                        
                        Image {
                            anchors.horizontalCenter: parent.horizontalCenter
                            source: "qrc:/assets/file.svg"
                            width: 64
                            height: 64
                            sourceSize: Qt.size(64, 64)
                        }
                        
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: langManager.currentTranslations["no_documents_found"] || "Fayl tapılmadı"
                            color: subtextColor
                            font.pixelSize: 16
                        }
                    }
                    
                    ListView {
                        id: documentsListView
                        anchors.fill: parent
                        anchors.margins: 16
                        spacing: 8
                        clip: true
                        visible: documentsModel.count > 0
                        interactive: true
                        flickableDirection: Flickable.VerticalFlick
                        boundsBehavior: Flickable.DragAndOvershootBounds
                        boundsMovement: Flickable.FollowBoundsBehavior
                        flickDeceleration: 600
                        maximumFlickVelocity: 8000
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOff
                        }
                        
                        model: ListModel { id: documentsModel }
                            
                            delegate: Rectangle {
                                width: documentsListView.width
                                height: 72
                                radius: 12
                                color: docMouseArea.containsMouse ? hoverColor : cardColor
                                
                                Behavior on color { ColorAnimation { duration: 150 } }
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 16
                                    spacing: 16
                                    
                                    Image {
                                        source: "qrc:/assets/file.svg"
                                        width: 24
                                        height: 24
                                        sourceSize: Qt.size(24, 24)
                                    }
                                    
                                    ColumnLayout {
                                        Layout.fillWidth: true
                                        spacing: 4
                                        
                                        Text {
                                            text: model.content || "Document"
                                            color: textColor
                                            font.pixelSize: 15
                                            font.weight: Font.Medium
                                            elide: Text.ElideRight
                                            Layout.fillWidth: true
                                        }
                                        
                                        Text {
                                            text: Qt.formatDateTime(model.timestamp, "dd MMM yyyy, HH:mm")
                                            color: subtextColor
                                            font.pixelSize: 13
                                        }
                                    }
                                }
                                
                                MouseArea {
                                    id: docMouseArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        Qt.openUrlExternally(model.mediaPath)
                                    }
                                }
                            }
                        }
                    }
                
                // Links list
                Item {
                    // Empty state
                    Column {
                        anchors.centerIn: parent
                        spacing: 16
                        visible: linksModel.count === 0
                        
                        Image {
                            anchors.horizontalCenter: parent.horizontalCenter
                            source: "qrc:/assets/link.svg"
                            width: 64
                            height: 64
                            sourceSize: Qt.size(64, 64)
                        }
                        
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: langManager.currentTranslations["no_links_found"] || "Link tapılmadı"
                            color: subtextColor
                            font.pixelSize: 16
                        }
                    }
                    
                    ListView {
                        id: linksListView
                        anchors.fill: parent
                        anchors.margins: 16
                        spacing: 8
                        clip: true
                        visible: linksModel.count > 0
                        interactive: true
                        flickableDirection: Flickable.VerticalFlick
                        boundsBehavior: Flickable.DragAndOvershootBounds
                        boundsMovement: Flickable.FollowBoundsBehavior
                        flickDeceleration: 600
                        maximumFlickVelocity: 8000
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOff
                        }
                        
                        model: ListModel { id: linksModel }
                            
                            delegate: Rectangle {
                                width: linksListView.width
                                height: 60
                                radius: 12
                                color: linkMouseArea.containsMouse ? hoverColor : cardColor
                                
                                Behavior on color { ColorAnimation { duration: 150 } }
                                
                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 16
                                    spacing: 12
                                    
                                    Image {
                                        source: "qrc:/assets/link.svg"
                                        width: 24
                                        height: 24
                                        sourceSize: Qt.size(24, 24)
                                    }
                                    
                                    Text {
                                        text: model.url
                                        color: accentColor
                                        font.pixelSize: 14
                                        font.weight: Font.Medium
                                        elide: Text.ElideMiddle
                                        Layout.fillWidth: true
                                    }
                                }
                                
                                MouseArea {
                                    id: linkMouseArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        Qt.openUrlExternally(model.url)
                                    }
                                }
                            }
                        }
                    }
                
                // Locations grid (wrapping)
                Item {
                    // Empty state
                    Column {
                        anchors.centerIn: parent
                        spacing: 16
                        visible: locationsModel.count === 0
                        
                        Image {
                            anchors.horizontalCenter: parent.horizontalCenter
                            source: "qrc:/assets/location.svg"
                            width: 64
                            height: 64
                            sourceSize: Qt.size(64, 64)
                        }
                        
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: langManager.currentTranslations["no_locations_found"] || "Konum tapılmadı"
                            color: subtextColor
                            font.pixelSize: 16
                        }
                    }
                    
                    GridView {
                        id: locationsGrid
                        anchors.fill: parent
                        anchors.margins: 16
                        cellWidth: 250
                        cellHeight: 170
                        clip: true
                        visible: locationsModel.count > 0
                        interactive: true
                        flickableDirection: Flickable.VerticalFlick
                        boundsBehavior: Flickable.DragAndOvershootBounds
                        boundsMovement: Flickable.FollowBoundsBehavior
                        flickDeceleration: 600
                        maximumFlickVelocity: 8000
                        
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AlwaysOff
                        }
                        
                        model: ListModel { id: locationsModel }
                            
                            delegate: Item {
                                width: 240
                                height: 160

                                // Copy from MessageBubble locationComp - without tickmark
                                Rectangle {
                                    id: mapBg
                                    anchors { top: parent.top; left: parent.left; right: parent.right }
                                    height: 110
                                    color: "#4CAF93"
                                    radius: 8
                                    clip: true

                                    // Road lines (decorative)
                                    Rectangle { x: 20;  y: 40; width: parent.width; height: 2; color: "#ffffff"; opacity: 0.3 }
                                    Rectangle { x: 0;   y: 70; width: parent.width; height: 2; color: "#ffffff"; opacity: 0.3 }
                                    Rectangle { x: 60;  y: 0;  width: 2; height: parent.height; color: "#ffffff"; opacity: 0.3 }
                                    Rectangle { x: 160; y: 0;  width: 2; height: parent.height; color: "#ffffff"; opacity: 0.3 }

                                    // Location pin
                                    Image {
                                        anchors.centerIn: parent
                                        source: "qrc:/assets/location.svg"
                                        width: 48
                                        height: 48
                                        sourceSize: Qt.size(48, 48)
                                    }
                                }

                                // Bottom info row
                                Rectangle {
                                    anchors { top: mapBg.bottom; left: parent.left; right: parent.right; bottom: parent.bottom }
                                    color: cardColor
                                    radius: 8

                                    Row {
                                        anchors {
                                            left: parent.left; right: parent.right
                                            verticalCenter: parent.verticalCenter
                                            leftMargin: 10; rightMargin: 8
                                        }
                                        spacing: 6

                                        Image {
                                            source: "qrc:/assets/location.svg"
                                            width: 18
                                            height: 18
                                            sourceSize: Qt.size(18, 18)
                                            anchors.verticalCenter: parent.verticalCenter
                                        }
                                        Text {
                                            text: langManager.currentTranslations["location"] || "Məkan"
                                            color: textColor
                                            font.family: WAPageTheme.fontFamily
                                            font.pixelSize: 13
                                            font.weight: Font.DemiBold
                                            anchors.verticalCenter: parent.verticalCenter
                                        }

                                        Item { Layout.fillWidth: true; width: 1; height: 1 }

                                        // Time only (no tickmark)
                                        Text {
                                            text: Qt.formatDateTime(model.timestamp, "HH:mm")
                                            color: subtextColor
                                            font.family: WAPageTheme.fontFamily
                                            font.pixelSize: 11
                                            anchors.verticalCenter: parent.verticalCenter
                                        }
                                    }
                                }

                                // Click — Open Google Maps
                                MouseArea {
                                    id: locationMouseArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        var meta = model.mediaMeta || ""
                                        var url = ""
                                        
                                        // Check if mediaMeta has lat,lng format
                                        if (meta.match(/^-?\d+\.\d+,-?\d+\.\d+$/)) {
                                            url = "https://maps.google.com/?q=" + meta
                                        } else if (meta.length > 0 && meta.indexOf("http") === 0) {
                                            url = meta
                                        } else if (model.content && model.content.indexOf("http") === 0) {
                                            // Fallback to content if it's a URL
                                            url = model.content
                                        } else if (meta.length > 0) {
                                            url = "https://maps.google.com/?q=" + encodeURIComponent(meta)
                                        }
                                        
                                        if (url.length > 0) {
                                            Qt.openUrlExternally(url)
                                        }
                                    }
                                }
                                
                                // Hover effect
                                Rectangle {
                                    anchors.fill: parent
                                    radius: 8
                                    color: accentColor
                                    opacity: locationMouseArea.containsMouse ? 0.1 : 0
                                    Behavior on opacity { NumberAnimation { duration: 150 } }
                                }
                            }
                        }
                    }
            }
        }
    }
    
    // Load data when opened
    onVisibleChanged: {
        if (visible) {
            loadCurrentTab()
        }
    }
    
    function open() {
        visible = true
    }
    
    function loadCurrentTab() {
        if (!mainWindow) return
        
        switch(currentTab) {
            case "photos":
                photosModel.clear()
                var photos = mainWindow.getMediaForBrowser("image")
                for (var i = 0; i < photos.length; i++) {
                    photosModel.append(photos[i])
                }
                break
            case "videos":
                videosModel.clear()
                var videos = mainWindow.getMediaForBrowser("video")
                for (var i = 0; i < videos.length; i++) {
                    videosModel.append(videos[i])
                }
                break
            case "documents":
                documentsModel.clear()
                var docs = mainWindow.getMediaForBrowser("document")
                for (var i = 0; i < docs.length; i++) {
                    documentsModel.append(docs[i])
                }
                break
            case "links":
                linksModel.clear()
                var links = mainWindow.getLinksForBrowser()
                for (var i = 0; i < links.length; i++) {
                    linksModel.append(links[i])
                }
                break
            case "locations":
                locationsModel.clear()
                var locations = mainWindow.getLocationsForBrowser()
                for (var i = 0; i < locations.length; i++) {
                    locationsModel.append(locations[i])
                }
                break
        }
    }
}
