cmake_minimum_required(VERSION 3.28)
project(WAPage VERSION 1.3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# ── Qt6 — all are in the MSVC package ──────────────────────────────────────
find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Qml
    Quick
    QuickControls2
    Sql
    Multimedia
    Concurrent
)
qt_standard_project_setup(REQUIRES 6.5)

# ── Source files ───────────────────────────────────────────────────────────
set(SOURCES
    src/main.cpp
    src/app/Application.cpp
    src/core/ChatParser.cpp
    src/core/ZipExtractor.cpp
    src/core/DatabaseManager.cpp
    src/core/MediaManager.cpp
    src/core/AudioSpeedProcessor.cpp
    src/core/LanguageManager.cpp
    src/core/models/ChatListModel.cpp
    src/core/models/MessageListModel.cpp
    src/ui/MainWindow.cpp
    src/ui/MediaViewer.cpp
    src/ui/StickerMovieItem.cpp
    src/ui/SearchController.cpp
    src/utils/Logger.cpp
    src/utils/EmojiHelper.cpp
    src/utils/WAPageTextFormatter.cpp
)

set(HEADERS
    src/app/Application.h
    src/core/ChatParser.h
    src/core/ZipExtractor.h
    src/core/DatabaseManager.h
    src/core/MediaManager.h
    src/core/AudioSpeedProcessor.h
    src/core/LanguageManager.h
    src/core/models/Chat.h
    src/core/models/Message.h
    src/core/models/Participant.h
    src/core/models/ChatListModel.h
    src/core/models/MessageListModel.h
    src/ui/MainWindow.h
    src/ui/MediaViewer.h
    src/ui/StickerMovieItem.h
    src/ui/SearchController.h
    src/utils/Logger.h
    src/utils/EmojiHelper.h
    src/utils/WAPageTextFormatter.h
)

# ── Executable ─────────────────────────────────────────────────────────────
qt_add_executable(WAPage ${SOURCES} ${HEADERS})

# ── Align QML files to module root ─────────────────────────────────────────
set_source_files_properties(qml/main.qml PROPERTIES QT_RESOURCE_ALIAS main.qml)
set_source_files_properties(qml/theme/WAPageTheme.qml PROPERTIES
    QT_RESOURCE_ALIAS WAPageTheme.qml
    QT_QML_SINGLETON_TYPE TRUE
)
set_source_files_properties(qml/components/AvatarCircle.qml     PROPERTIES QT_RESOURCE_ALIAS AvatarCircle.qml)
set_source_files_properties(qml/components/TickMark.qml          PROPERTIES QT_RESOURCE_ALIAS TickMark.qml)
set_source_files_properties(qml/components/ChatListPanel.qml     PROPERTIES QT_RESOURCE_ALIAS ChatListPanel.qml)
set_source_files_properties(qml/components/ChatListItem.qml      PROPERTIES QT_RESOURCE_ALIAS ChatListItem.qml)
set_source_files_properties(qml/components/ChatHeader.qml        PROPERTIES QT_RESOURCE_ALIAS ChatHeader.qml)
set_source_files_properties(qml/components/MessagePanel.qml      PROPERTIES QT_RESOURCE_ALIAS MessagePanel.qml)
set_source_files_properties(qml/components/MessageBubble.qml     PROPERTIES QT_RESOURCE_ALIAS MessageBubble.qml)
set_source_files_properties(qml/components/MediaBubble.qml       PROPERTIES QT_RESOURCE_ALIAS MediaBubble.qml)
set_source_files_properties(qml/components/AudioPlayer.qml       PROPERTIES QT_RESOURCE_ALIAS AudioPlayer.qml)
set_source_files_properties(qml/components/SearchBar.qml         PROPERTIES QT_RESOURCE_ALIAS SearchBar.qml)
set_source_files_properties(qml/components/ProfileView.qml       PROPERTIES QT_RESOURCE_ALIAS ProfileView.qml)
set_source_files_properties(qml/components/ImportDialog.qml      PROPERTIES QT_RESOURCE_ALIAS ImportDialog.qml)
set_source_files_properties(qml/components/OwnerNameDialog.qml   PROPERTIES QT_RESOURCE_ALIAS OwnerNameDialog.qml)
set_source_files_properties(qml/components/MediaFullScreen.qml   PROPERTIES QT_RESOURCE_ALIAS MediaFullScreen.qml)
set_source_files_properties(qml/components/SettingsView.qml      PROPERTIES QT_RESOURCE_ALIAS SettingsView.qml)
set_source_files_properties(qml/components/ErrorToast.qml        PROPERTIES QT_RESOURCE_ALIAS ErrorToast.qml)
set_source_files_properties(qml/components/MouseWheelHandler.qml PROPERTIES QT_RESOURCE_ALIAS MouseWheelHandler.qml)

# ── QML module ─────────────────────────────────────────────────────────────
qt_add_qml_module(WAPage
    URI WAPage
    VERSION 1.0
    RESOURCE_PREFIX /
    QML_FILES
        qml/main.qml
        qml/theme/WAPageTheme.qml
        qml/components/AvatarCircle.qml
        qml/components/TickMark.qml
        qml/components/ChatListPanel.qml
        qml/components/ChatListItem.qml
        qml/components/ChatHeader.qml
        qml/components/MessagePanel.qml
        qml/components/MessageBubble.qml
        qml/components/MediaBubble.qml
        qml/components/AudioPlayer.qml
        qml/components/SearchBar.qml
        qml/components/ProfileView.qml
        qml/components/SettingsView.qml
        qml/components/ImportDialog.qml
        qml/components/OwnerNameDialog.qml
        qml/components/MediaFullScreen.qml
        qml/components/ErrorToast.qml
        qml/components/MouseWheelHandler.qml
)

# ── Resources (assets, fonts, icons) — in the qrc:/assets/... path ────────
set_source_files_properties(resources/assets/wallpaper_light.png  PROPERTIES QT_RESOURCE_ALIAS assets/wallpaper_light.png)
set_source_files_properties(resources/assets/wallpaper_dark.png   PROPERTIES QT_RESOURCE_ALIAS assets/wallpaper_dark.png)
set_source_files_properties(resources/assets/icon_search.svg      PROPERTIES QT_RESOURCE_ALIAS assets/icon_search.svg)
set_source_files_properties(resources/assets/icon_play.svg        PROPERTIES QT_RESOURCE_ALIAS assets/icon_play.svg)
set_source_files_properties(resources/assets/icon_pause.svg       PROPERTIES QT_RESOURCE_ALIAS assets/icon_pause.svg)
set_source_files_properties(resources/assets/icon_close.svg       PROPERTIES QT_RESOURCE_ALIAS assets/icon_close.svg)
set_source_files_properties(resources/assets/add.svg              PROPERTIES QT_RESOURCE_ALIAS assets/add.svg)
set_source_files_properties(resources/assets/delete.svg           PROPERTIES QT_RESOURCE_ALIAS assets/delete.svg)
set_source_files_properties(resources/assets/icon_arrow_up.svg    PROPERTIES QT_RESOURCE_ALIAS assets/icon_arrow_up.svg)
set_source_files_properties(resources/assets/icon_arrow_down.svg  PROPERTIES QT_RESOURCE_ALIAS assets/icon_arrow_down.svg)
set_source_files_properties(resources/assets/icon_arrow_left.svg  PROPERTIES QT_RESOURCE_ALIAS assets/icon_arrow_left.svg)
set_source_files_properties(resources/assets/icon_blocked.svg     PROPERTIES QT_RESOURCE_ALIAS assets/icon_blocked.svg)
set_source_files_properties(resources/assets/icon_open_external.svg PROPERTIES QT_RESOURCE_ALIAS assets/icon_open_external.svg)
set_source_files_properties(resources/assets/icon_zip.svg         PROPERTIES QT_RESOURCE_ALIAS assets/icon_zip.svg)
set_source_files_properties(resources/assets/icon_message.svg     PROPERTIES QT_RESOURCE_ALIAS assets/icon_message.svg)
set_source_files_properties(resources/assets/icon_calendar.svg    PROPERTIES QT_RESOURCE_ALIAS assets/icon_calendar.svg)
set_source_files_properties(resources/assets/language.svg         PROPERTIES QT_RESOURCE_ALIAS assets/language.svg)
set_source_files_properties(resources/assets/icon_sun.svg         PROPERTIES QT_RESOURCE_ALIAS assets/icon_sun.svg)
set_source_files_properties(resources/assets/icon_moon.svg        PROPERTIES QT_RESOURCE_ALIAS assets/icon_moon.svg)
set_source_files_properties(resources/assets/read.svg              PROPERTIES QT_RESOURCE_ALIAS assets/read.svg)
set_source_files_properties(resources/assets/first.svg             PROPERTIES QT_RESOURCE_ALIAS assets/first.svg)
set_source_files_properties(resources/assets/microphone.svg        PROPERTIES QT_RESOURCE_ALIAS assets/microphone.svg)
set_source_files_properties(resources/assets/dots.svg              PROPERTIES QT_RESOURCE_ALIAS assets/dots.svg)
set_source_files_properties(resources/assets/blue_avatar.svg       PROPERTIES QT_RESOURCE_ALIAS assets/blue_avatar.svg)
set_source_files_properties(resources/assets/green_avatar.svg      PROPERTIES QT_RESOURCE_ALIAS assets/green_avatar.svg)
set_source_files_properties(resources/assets/lightblue_avatar.svg  PROPERTIES QT_RESOURCE_ALIAS assets/lightblue_avatar.svg)
set_source_files_properties(resources/assets/lightgreen_avatar.svg PROPERTIES QT_RESOURCE_ALIAS assets/lightgreen_avatar.svg)
set_source_files_properties(resources/assets/lightred_avatar.svg   PROPERTIES QT_RESOURCE_ALIAS assets/lightred_avatar.svg)
set_source_files_properties(resources/assets/purple_avatar.svg     PROPERTIES QT_RESOURCE_ALIAS assets/purple_avatar.svg)
set_source_files_properties(resources/assets/red_avatar.svg        PROPERTIES QT_RESOURCE_ALIAS assets/red_avatar.svg)
set_source_files_properties(resources/assets/yellow_groupavatar.svg PROPERTIES QT_RESOURCE_ALIAS assets/yellow_groupavatar.svg)
set_source_files_properties(resources/assets/red_groupavatar.svg    PROPERTIES QT_RESOURCE_ALIAS assets/red_groupavatar.svg)
set_source_files_properties(resources/assets/orange_groupavatar.svg PROPERTIES QT_RESOURCE_ALIAS assets/orange_groupavatar.svg)
set_source_files_properties(resources/assets/blue_groupavatar.svg   PROPERTIES QT_RESOURCE_ALIAS assets/blue_groupavatar.svg)
set_source_files_properties(resources/assets/purple_groupavatar.svg PROPERTIES QT_RESOURCE_ALIAS assets/purple_groupavatar.svg)
set_source_files_properties(resources/fonts/NotoColorEmoji.ttf    PROPERTIES QT_RESOURCE_ALIAS fonts/NotoColorEmoji.ttf)
set_source_files_properties(resources/icons/wapage.ico          PROPERTIES QT_RESOURCE_ALIAS icons/wapage.ico)

qt_add_resources(WAPage "app_resources"
    PREFIX "/"
    FILES
        resources/assets/wallpaper_light.png
        resources/assets/wallpaper_dark.png
        resources/assets/icon_search.svg
        resources/assets/icon_play.svg
        resources/assets/icon_pause.svg
        resources/assets/icon_close.svg
        resources/assets/add.svg
        resources/assets/delete.svg
        resources/assets/icon_arrow_up.svg
        resources/assets/icon_arrow_down.svg
        resources/assets/icon_arrow_left.svg
        resources/assets/icon_blocked.svg
        resources/assets/icon_open_external.svg
        resources/assets/icon_zip.svg
        resources/assets/icon_message.svg
        resources/assets/icon_calendar.svg
        resources/assets/language.svg
        resources/assets/icon_sun.svg
        resources/assets/icon_moon.svg
        resources/assets/read.svg
        resources/assets/first.svg
        resources/assets/microphone.svg
        resources/assets/dots.svg
        resources/assets/blue_avatar.svg
        resources/assets/green_avatar.svg
        resources/assets/lightblue_avatar.svg
        resources/assets/lightgreen_avatar.svg
        resources/assets/lightred_avatar.svg
        resources/assets/purple_avatar.svg
        resources/assets/red_avatar.svg
        resources/assets/yellow_groupavatar.svg
        resources/assets/red_groupavatar.svg
        resources/assets/orange_groupavatar.svg
        resources/assets/blue_groupavatar.svg
        resources/assets/purple_groupavatar.svg
        resources/fonts/NotoColorEmoji.ttf
        resources/icons/wapage.ico
)

target_include_directories(WAPage PRIVATE src)

# ── Link — Qt6 only, no 3rd party ─────────────────────────────────────────
target_link_libraries(WAPage PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Sql
    Qt6::Multimedia
    Qt6::Concurrent
)

# ── Windows ────────────────────────────────────────────────────────────────
if(WIN32)
    target_sources(WAPage PRIVATE resources/icons/app.rc)
    set_target_properties(WAPage PROPERTIES WIN32_EXECUTABLE TRUE)

    # Qt bin path used by post-build deployment steps.
    set(QT_BIN_DIR "${Qt6_DIR}/../../../bin")

    # Portable extra/runtime source directory.
    # Keep app-specific extras and fixed CRT DLLs here so build output does not
    # depend on host System32 / toolchain redistributable lookup.
    set(PORTABLE_BIN_DIR "${CMAKE_SOURCE_DIR}/resources/executable")
    set(PORTABLE_RUNTIME_FILES
        vcruntime140.dll
        vcruntime140_1.dll
        msvcp140.dll
        msvcp140_1.dll
        msvcp140_2.dll
        concrt140.dll
    )
    
    foreach(RUNTIME_FILE IN LISTS PORTABLE_RUNTIME_FILES)
        if(EXISTS "${PORTABLE_BIN_DIR}/${RUNTIME_FILE}")
            add_custom_command(TARGET WAPage POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${PORTABLE_BIN_DIR}/${RUNTIME_FILE}"
                    "$<TARGET_FILE_DIR:WAPage>/${RUNTIME_FILE}"
                COMMENT "${RUNTIME_FILE} copying from resources/executable..."
                VERBATIM
            )
        else()
            message(WARNING "Portable runtime file is missing in resources/executable: ${RUNTIME_FILE}")
        endif()
    endforeach()

    # Explicitly keep Qt6Concurrent app-local from resources/executable.
    if(EXISTS "${PORTABLE_BIN_DIR}/Qt6Concurrent.dll")
        add_custom_command(TARGET WAPage POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${PORTABLE_BIN_DIR}/Qt6Concurrent.dll"
                "$<TARGET_FILE_DIR:WAPage>/Qt6Concurrent.dll"
            COMMENT "Qt6Concurrent.dll copying from resources/executable..."
            VERBATIM
        )
    else()
        message(WARNING "Portable runtime file is missing in resources/executable: Qt6Concurrent.dll")
    endif()

    # UCRT (Universal C Runtime) — for older versions of Windows 10.
    # Makes ucrtbase.dll + api-ms-win-crt-*.dll files app-local,
    # thus reducing the additional runtime installer dependency.
    set(UCRT_DIR "${CMAKE_SOURCE_DIR}/resources/executable/ucrt")
    if(EXISTS "${UCRT_DIR}")
        file(GLOB UCRT_DLLS "${UCRT_DIR}/*.dll")
        foreach(UCRT_DLL IN LISTS UCRT_DLLS)
            get_filename_component(UCRT_DLL_NAME "${UCRT_DLL}" NAME)
            add_custom_command(TARGET WAPage POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${UCRT_DLL}"
                    "$<TARGET_FILE_DIR:WAPage>/${UCRT_DLL_NAME}"
                VERBATIM
            )
        endforeach()
        message(STATUS "UCRT DLLs will be copied from resources/executable/ucrt (${CMAKE_SOURCE_DIR})")
    else()
        message(WARNING "UCRT directory not found: ${UCRT_DIR} — older Windows 10 may require UCRT/VC++ runtime")
    endif()
    
    add_custom_command(TARGET WAPage POST_BUILD
        COMMAND "${QT_BIN_DIR}/windeployqt.exe"
            --qmldir "${CMAKE_SOURCE_DIR}/qml"
            --no-translations
            --no-system-d3d-compiler
            --no-opengl-sw
            --no-compiler-runtime
            "$<TARGET_FILE:WAPage>"
        COMMENT "windeployqt - Qt DLLs are copying..."
        VERBATIM
    )
endif()
