pragma Singleton
import QtQuick 2.15

QtObject {
    id: theme

    // ── Aktiv tema ──────────────────────────────────────────────
    property bool dark: mainWindow.isDarkTheme

    // Panel colors
    property color panelBg:         dark ? "#111B21" : "#FFFFFF"
    property color headerBg:        dark ? "#202C33" : "#008069"
    property color headerText:      "#FFFFFF"
    property color divider:         dark ? "#2A3942" : "#E9EDEF"

    // Chat background (right panel)
    property color chatBg:          dark ? "#0B141A" : "#EAE4D8"

    // ── Message bubbles 
    property color bubbleSent:      dark ? "#005C4B" : "#D9FDD3"
    property color bubbleReceived:  dark ? "#202C33" : "#FFFFFF"
    property color bubbleSentText:  dark ? "#E9EDF0" : "#111B21"
    property color bubbleRecvText:  dark ? "#E9EDF0" : "#111B21"

    // ── Metadata (vaxt, tik) ───────────────────────────────────
    property color metaTextSent:    dark ? "#E68696A0" : "#73000000"
    property color metaTextRecv:    dark ? "#E68696A0" : "#73000000"

    // Teak colors
    property color tickGray:        "#8696A0"
    property color tickBlue:        "#53BDEB"

    // Left panel chat list
    property color chatListBg:      dark ? "#111B21" : "#FFFFFF"
    property color chatListHover:   dark ? "#2A3942" : "#F5F6F6"
    property color chatListActive:  dark ? "#2A3942" : "#E9EDEF"
    property color chatListText:    dark ? "#E9EDF0" : "#111B21"
    property color chatListSubText: dark ? "#8696A0" : "#667781"
    property color chatListTime:    dark ? "#8696A0" : "#667781"

    // ── Date separator ──────────────────────
    property color dateSepBg:       dark ? "#182229" : "#E1F2FB"
    property color dateSepText:     dark ? "#8696A0" : "#54656F"

    // Search bar
    property color searchBg:        dark ? "#2A3942" : "#F0F2F5"
    property color searchText:      dark ? "#D1D7DB" : "#3B4A54"
    property color searchPlaceholder: dark ? "#8696A0" : "#8696A0"
    property color searchHighlight: "#FFC107"

    // Input area
    property color inputBg:         dark ? "#202C33" : "#FFFFFF"
    property color inputText:       dark ? "#D1D7DB" : "#3B4A54"

    // ── Media viewer ───────────────────────────────────────────
    property color mediaOverlay:    "#D9000000"
    property color mediaToolbar:    "#99000000"

    // ── Profile panel ───────────────────────────────────────────
    property color profileBg:       dark ? "#111B21" : "#F0F2F5"
    property color profileHeaderBg: dark ? "#202C33" : "#008069"

    // General
    property color accent:          "#00BFA5"
    property color accentGreen:     "#25D366"
    property color iconColor:       dark ? "#AEBAC1" : "#54656F"
    property color iconColorActive: "#FFFFFF"

    // ── Tipografiya ────────────────────────────────────────────
    property string fontFamily:     "Segoe UI"
    property int    fontSizeNormal: 14
    property int    fontSizeSmall:  12
    property int    fontSizeMicro:  11

    // Layout constants
    // WAPage Web ratio: left panel ~30%, right panel ~70%
    property real leftPanelRatio:   0.30
    property int  minWindowWidth:   900
    property int  minWindowHeight:  600

    property int  bubbleRadius:     8
    property int  bubbleMaxWidth:   480  // px (~65% of viewport)
    property int  bubblePaddingH:   9
    property int  bubblePaddingV:   6

    property int  avatarSize:       40
    property int  avatarSizeLarge:  200

    property int  headerHeight:     59
    property int  inputHeight:      62
}
