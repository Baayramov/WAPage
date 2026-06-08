cmake_minimum_required(VERSION 3.28)
project(WAPage VERSION 1.4.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# ── Qt6 ────────────────────────────────────────────────────────────────────
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
    Svg
    OpenGL
)
if(NOT WIN32)
    qt_policy(SET QTP0004 NEW)
endif()
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

if(WIN32)
    set(BIN_NAME "WAPage")
else()
    set(BIN_NAME "wapage")
endif()

qt_add_executable(${BIN_NAME} ${SOURCES} ${HEADERS})

# ── QML Aliases ────────────────────────────────────────────────────────────
set_source_files_properties(qml/main.qml PROPERTIES QT_RESOURCE_ALIAS main.qml)
set_source_files_properties(qml/theme/WAPageTheme.qml PROPERTIES 
    QT_RESOURCE_ALIAS WAPageTheme.qml
    QT_QML_SINGLETON_TYPE TRUE
)
set_source_files_properties(qml/components/AvatarCircle.qml PROPERTIES QT_RESOURCE_ALIAS components/AvatarCircle.qml)
set_source_files_properties(qml/components/TickMark.qml PROPERTIES QT_RESOURCE_ALIAS components/TickMark.qml)
set_source_files_properties(qml/components/ChatListPanel.qml PROPERTIES QT_RESOURCE_ALIAS components/ChatListPanel.qml)
set_source_files_properties(qml/components/FavoritesPanel.qml PROPERTIES QT_RESOURCE_ALIAS components/FavoritesPanel.qml)
set_source_files_properties(qml/components/ChatListItem.qml PROPERTIES QT_RESOURCE_ALIAS components/ChatListItem.qml)
set_source_files_properties(qml/components/ChatHeader.qml PROPERTIES QT_RESOURCE_ALIAS components/ChatHeader.qml)
set_source_files_properties(qml/components/MessagePanel.qml PROPERTIES QT_RESOURCE_ALIAS components/MessagePanel.qml)
set_source_files_properties(qml/components/MessageBubble.qml PROPERTIES QT_RESOURCE_ALIAS components/MessageBubble.qml)
set_source_files_properties(qml/components/MediaBubble.qml PROPERTIES QT_RESOURCE_ALIAS components/MediaBubble.qml)
set_source_files_properties(qml/components/AudioPlayer.qml PROPERTIES QT_RESOURCE_ALIAS components/AudioPlayer.qml)
set_source_files_properties(qml/components/SearchBar.qml PROPERTIES QT_RESOURCE_ALIAS components/SearchBar.qml)
set_source_files_properties(qml/components/ProfileView.qml PROPERTIES QT_RESOURCE_ALIAS components/ProfileView.qml)
set_source_files_properties(qml/components/SettingsView.qml PROPERTIES QT_RESOURCE_ALIAS components/SettingsView.qml)
set_source_files_properties(qml/components/ImportDialog.qml PROPERTIES QT_RESOURCE_ALIAS components/ImportDialog.qml)
set_source_files_properties(qml/components/OwnerNameDialog.qml PROPERTIES QT_RESOURCE_ALIAS components/OwnerNameDialog.qml)
set_source_files_properties(qml/components/MediaFullScreen.qml PROPERTIES QT_RESOURCE_ALIAS components/MediaFullScreen.qml)
set_source_files_properties(qml/components/MediaBrowser.qml PROPERTIES QT_RESOURCE_ALIAS components/MediaBrowser.qml)
set_source_files_properties(qml/components/ErrorToast.qml PROPERTIES QT_RESOURCE_ALIAS components/ErrorToast.qml)
set_source_files_properties(qml/components/MouseWheelHandler.qml PROPERTIES QT_RESOURCE_ALIAS components/MouseWheelHandler.qml)
set_source_files_properties(qml/components/CalendarDialog.qml PROPERTIES QT_RESOURCE_ALIAS components/CalendarDialog.qml)

set(WAPAGE_QML_MODULE_ARGS)
if(WIN32)
    list(APPEND WAPAGE_QML_MODULE_ARGS NO_IMPORT_SCAN)
endif()

# Keep QML module output away from the binary name to avoid case-only clashes.
set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml_modules")

qt_add_qml_module(${BIN_NAME}
    URI WAPage
    VERSION 1.0
    RESOURCE_PREFIX /
    QML_FILES
        qml/main.qml
        qml/theme/WAPageTheme.qml
        qml/components/AvatarCircle.qml
        qml/components/TickMark.qml
        qml/components/ChatListPanel.qml
        qml/components/FavoritesPanel.qml
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
        qml/components/MediaBrowser.qml
        qml/components/ErrorToast.qml
        qml/components/MouseWheelHandler.qml
        qml/components/CalendarDialog.qml
    ${WAPAGE_QML_MODULE_ARGS}
)

# ── Assets Aliases ─────────────────────────────────────────────────────────
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
set_source_files_properties(resources/assets/edit.svg             PROPERTIES QT_RESOURCE_ALIAS assets/edit.svg)
set_source_files_properties(resources/assets/language.svg         PROPERTIES QT_RESOURCE_ALIAS assets/language.svg)
set_source_files_properties(resources/assets/settings.svg         PROPERTIES QT_RESOURCE_ALIAS assets/settings.svg)
set_source_files_properties(resources/assets/icon_sun.svg         PROPERTIES QT_RESOURCE_ALIAS assets/icon_sun.svg)
set_source_files_properties(resources/assets/icon_moon.svg        PROPERTIES QT_RESOURCE_ALIAS assets/icon_moon.svg)
set_source_files_properties(resources/assets/star.svg             PROPERTIES QT_RESOURCE_ALIAS assets/star.svg)
set_source_files_properties(resources/assets/read.svg              PROPERTIES QT_RESOURCE_ALIAS assets/read.svg)
set_source_files_properties(resources/assets/first.svg             PROPERTIES QT_RESOURCE_ALIAS assets/first.svg)
set_source_files_properties(resources/assets/last.svg              PROPERTIES QT_RESOURCE_ALIAS assets/last.svg)
set_source_files_properties(resources/assets/microphone.svg        PROPERTIES QT_RESOURCE_ALIAS assets/microphone.svg)
set_source_files_properties(resources/assets/dots.svg              PROPERTIES QT_RESOURCE_ALIAS assets/dots.svg)
set_source_files_properties(resources/assets/sticker.svg           PROPERTIES QT_RESOURCE_ALIAS assets/sticker.svg)
set_source_files_properties(resources/assets/photo.svg             PROPERTIES QT_RESOURCE_ALIAS assets/photo.svg)
set_source_files_properties(resources/assets/video.svg             PROPERTIES QT_RESOURCE_ALIAS assets/video.svg)
set_source_files_properties(resources/assets/file.svg              PROPERTIES QT_RESOURCE_ALIAS assets/file.svg)
set_source_files_properties(resources/assets/link.svg              PROPERTIES QT_RESOURCE_ALIAS assets/link.svg)
set_source_files_properties(resources/assets/location.svg          PROPERTIES QT_RESOURCE_ALIAS assets/location.svg)
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
set_source_files_properties(resources/assets/wapage.png          PROPERTIES QT_RESOURCE_ALIAS assets/wapage.png)
set_source_files_properties(resources/icons/wapage.ico           PROPERTIES QT_RESOURCE_ALIAS icons/wapage.ico)

qt_add_resources(${BIN_NAME} "app_resources"
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
        resources/assets/edit.svg
        resources/assets/language.svg
        resources/assets/settings.svg
        resources/assets/icon_sun.svg
        resources/assets/icon_moon.svg
        resources/assets/star.svg
        resources/assets/read.svg
        resources/assets/first.svg
        resources/assets/last.svg
        resources/assets/microphone.svg
        resources/assets/dots.svg
        resources/assets/sticker.svg
        resources/assets/photo.svg
        resources/assets/video.svg
        resources/assets/file.svg
        resources/assets/link.svg
        resources/assets/location.svg
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
        resources/assets/wapage.png
        resources/icons/wapage.ico
)

target_include_directories(${BIN_NAME} PRIVATE src)

target_link_libraries(${BIN_NAME} PRIVATE
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

# ── Development Resources Copy ─────────────────────────────────────────────
set(DEV_ASSETS_DIR "${CMAKE_BINARY_DIR}/dev_assets")
add_custom_target(copy_dev_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${DEV_ASSETS_DIR}/resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/qml ${DEV_ASSETS_DIR}/qml
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/.env ${CMAKE_BINARY_DIR}/.env
    COMMENT "Copying additional resources for development build..."
)
add_dependencies(${BIN_NAME} copy_dev_resources)

# ── Windows Deployment ─────────────────────────────────────────────────────
if(WIN32)
    target_sources(${BIN_NAME} PRIVATE resources/icons/app.rc)
    set_target_properties(${BIN_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
    set(QT_BIN_DIR "${Qt6_DIR}/../../../bin")

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
            add_custom_command(TARGET ${BIN_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${PORTABLE_BIN_DIR}/${RUNTIME_FILE}"
                    "$<TARGET_FILE_DIR:${BIN_NAME}>/${RUNTIME_FILE}"
                COMMENT "${RUNTIME_FILE} copying from resources/executable..."
                VERBATIM
            )
        else()
            message(WARNING "Portable runtime file is missing in resources/executable: ${RUNTIME_FILE}")
        endif()
    endforeach()

    if(EXISTS "${PORTABLE_BIN_DIR}/Qt6Concurrent.dll")
        add_custom_command(TARGET ${BIN_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${PORTABLE_BIN_DIR}/Qt6Concurrent.dll"
                "$<TARGET_FILE_DIR:${BIN_NAME}>/Qt6Concurrent.dll"
            COMMENT "Qt6Concurrent.dll copying from resources/executable..."
            VERBATIM
        )
    else()
        message(WARNING "Portable runtime file is missing in resources/executable: Qt6Concurrent.dll")
    endif()

    set(UCRT_DIR "${CMAKE_SOURCE_DIR}/resources/executable/ucrt")
    if(EXISTS "${UCRT_DIR}")
        file(GLOB UCRT_DLLS "${UCRT_DIR}/*.dll")
        foreach(UCRT_DLL IN LISTS UCRT_DLLS)
            get_filename_component(UCRT_DLL_NAME "${UCRT_DLL}" NAME)
            add_custom_command(TARGET ${BIN_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${UCRT_DLL}"
                    "$<TARGET_FILE_DIR:${BIN_NAME}>/${UCRT_DLL_NAME}"
                VERBATIM
            )
        endforeach()
        message(STATUS "UCRT DLLs will be copied from resources/executable/ucrt (${CMAKE_SOURCE_DIR})")
    else()
        message(WARNING "UCRT directory not found: ${UCRT_DIR} - older Windows 10 may require UCRT/VC++ runtime")
    endif()

    add_custom_command(TARGET ${BIN_NAME} POST_BUILD
        COMMAND "${QT_BIN_DIR}/windeployqt.exe"
            --qmldir "${CMAKE_SOURCE_DIR}/qml"
            --no-translations
            --no-system-d3d-compiler
            --no-opengl-sw
            --no-compiler-runtime
            "$<TARGET_FILE:${BIN_NAME}>"
        COMMENT "windeployqt - Qt DLLs are copying..."
        VERBATIM
    )
endif()

# ── Linux Deployment ───────────────────────────────────────────────────────
if(UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    install(TARGETS ${BIN_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    install(FILES "${CMAKE_SOURCE_DIR}/resources/linux/wapage.desktop" DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications)
    install(FILES "${CMAKE_SOURCE_DIR}/resources/assets/wapage.png" DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/256x256/apps RENAME wapage.png)
endif()
