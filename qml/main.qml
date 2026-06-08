import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import WAPage 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width:   1280
    height:  720
    minimumWidth:  WAPageTheme.minWindowWidth
    minimumHeight: WAPageTheme.minWindowHeight
    title: "WAPage"
    color: WAPageTheme.chatBg

    // A reference to the currently playing voice message (so that only 1 voice works at a time)
    property var activeAudioPlayer: null
    
    // Drag & drop state
    property bool isDraggingZip: false

    // ── Main layout: left panel + right panel ──────────────────────
    Row {
        anchors.fill: parent
        spacing: 0

        // Left panel — chat list
        ChatListPanel {
            id: leftPanel
            width:  Math.round(appWindow.width * WAPageTheme.leftPanelRatio)
            height: parent.height
        }

        // Fine dividing line
        Rectangle {
            width:  1
            height: parent.height
            color:  WAPageTheme.divider
        }

        // Right panel — messages
        MessagePanel {
            id: rightPanel
            width:  appWindow.width - leftPanel.width - 1
            height: parent.height
        }
    }
    
    // ── Drag & Drop overlay for ZIP files ──────────────────────
    DropArea {
        id: dropArea
        anchors.fill: parent
        
        onEntered: function(drag) {
            // Check if dragged content contains files
            if (drag.hasUrls) {
                var urls = drag.urls
                // Check if any file is a ZIP
                for (var i = 0; i < urls.length; i++) {
                    var url = urls[i].toString()
                    if (url.toLowerCase().endsWith('.zip')) {
                        drag.accept(Qt.CopyAction)
                        appWindow.isDraggingZip = true
                        return
                    }
                }
            }
            drag.accepted = false
        }
        
        onExited: {
            appWindow.isDraggingZip = false
        }
        
        onDropped: function(drop) {
            appWindow.isDraggingZip = false
            
            if (drop.hasUrls) {
                var urls = drop.urls
                // Find first ZIP file
                for (var i = 0; i < urls.length; i++) {
                    var url = urls[i].toString()
                    if (url.toLowerCase().endsWith('.zip')) {
                        // Convert file URL to local path
                        var path = url
                        if (Qt.platform.os === "windows") {
                            path = path.replace("file:///", "")
                        } else {
                            path = path.replace("file://", "")
                        }
                        
                        // Skip step 1 (file selection) and go directly to step 2 (owner name)
                        importDlg.selectedZip = path
                        importDlg.step = 2
                        importDlg.visible = true
                        
                        drop.accept(Qt.CopyAction)
                        return
                    }
                }
            }
        }
    }
    
    // Visual feedback overlay when dragging ZIP
    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: appWindow.isDraggingZip ? 0.15 : 0.0
        visible: opacity > 0
        z: 100
        
        Behavior on opacity {
            NumberAnimation { duration: 150; easing.type: Easing.OutCubic }
        }
        
        // Prevent mouse events from passing through
        MouseArea {
            anchors.fill: parent
            enabled: appWindow.isDraggingZip
        }
    }

    // ── Media full screen view ───────────────────────────────
    MediaFullScreen {
        id: mediaFullScreen
        anchors.fill: parent
        visible: mediaViewer.visible
        mediaPath: mediaViewer.mediaPath
        mediaType: mediaViewer.mediaType
        onCloseRequested: mediaViewer.close()
    }

    // ── Import dialog ─────────────────────────────────────────
    ImportDialog {
        id: importDlg
        anchors.fill: parent
        visible: false
    }

    // Error notification
    ErrorToast {
        id: errorToast
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 24
    }

    // Signal connections
    Connections {
        target: mainWindow
        function onImportError(message) {
            errorToast.show(message)
        }
        function onImportSuccess(contactName, messageCount) {
            errorToast.showSuccess(
                langManager.currentTranslations["import_success"]
                .arg(contactName).arg(messageCount))
        }
    }

    // ── Global language selection dialog ─────────────────────────────
    // is a direct child of appWindow — always in the exact center of the screen
    Dialog {
        id: globalLangDialog
        anchors.centerIn: parent
        width: 300
        title: langManager.currentTranslations["select_language"]
        modal: true
        standardButtons: Dialog.NoButton

        contentItem: ListView {
            implicitHeight: 400
            implicitWidth: parent.width
            clip: true
            model: ["Azerbaijani", "Turkish", "English", "Spanish", "Portuguese",
                "Russian", "Ukrainian", "Polish", "Italian", "Arabic", "French", "German",
                "Chinese", "Korean", "Japanese", "Hindi", "Mongolian", "Uzbek"]
            delegate: ItemDelegate {
                width: globalLangDialog.availableWidth
                text: langManager.getLanguageName(modelData)
                highlighted: langManager.currentLanguage === modelData
                onClicked: {
                    globalLangDialog.close()
                    langChangeTimer.langToSet = modelData
                    langChangeTimer.start()
                }
            }
        }

        footer: DialogButtonBox {
            Button {
                text: langManager.currentTranslations["cancel"]
                      ? langManager.currentTranslations["cancel"]
                      : "Cancel"
                DialogButtonBox.buttonRole: DialogButtonBox.RejectRole
            }
            onRejected: globalLangDialog.close()
        }

        Timer {
            id: langChangeTimer
            interval: 250
            property string langToSet: ""
            onTriggered: langManager.currentLanguage = langToSet
        }
    }

    // Add openLangDialog signal from SettingsView
    Connections {
        target: leftPanel.settingsViewRef
        function onOpenLangDialog() { globalLangDialog.open() }
    }

    // Short keys
    Shortcut {
        sequence: "Ctrl+F"
        onActivated: searchCtrl.open()
    }
    Shortcut {
        sequence: "Escape"
        onActivated: {
            if (mediaViewer.visible)  mediaViewer.close()
            else if (searchCtrl.active) searchCtrl.close()
        }
    }
}
