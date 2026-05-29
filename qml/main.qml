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
        standardButtons: Dialog.Cancel

        ListView {
            implicitHeight: 400
            width: parent.width
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
