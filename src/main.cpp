#include "app/Application.h"
#include "ui/MainWindow.h"
#include "ui/SearchController.h"
#include "ui/MediaViewer.h"
#include "ui/StickerMovieItem.h"
#include "core/LanguageManager.h"
#include "utils/Logger.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QImageReader>
#include <QQuickStyle>
#include <QIcon>
#include <QFontDatabase>
#include <QProcessEnvironment>
#include <QStringList>
#include <qqml.h>

int main(int argc, char* argv[])
{
    // Avoid D3D11 hardware acceleration error (use software decode)
    // "Failed setup for format d3d11: hwaccel initialisation returned error"
    qputenv("QT_MEDIA_BACKEND", "ffmpeg");
    qputenv("LIBAV_HWACCEL_DISABLE", "1");

    // In Qt6, HiDPI is enabled by default, no additional setAttribute is needed

    Application app(argc, argv);

    // Start Logger
    Logger::init(app.dataDir().toStdString(), app.logLevel().toStdString());

    // WAPage icon
    app.setWindowIcon(QIcon(":/icons/wapage.ico"));

    // Qt Quick Controls 2 Basic style (for custom theme)
    QQuickStyle::setStyle("Basic");

    // Create C++ objects
    MainWindow      mainWindow(app.dataDir());
    SearchController searchCtrl;
    MediaViewer      mediaViewer;
    LanguageManager  langManager;
    mainWindow.setLanguageManager(&langManager);

    // Combine search signals
    QObject::connect(&searchCtrl, &SearchController::requestSearch,
                     &mainWindow, &MainWindow::searchInChat);
    QObject::connect(&searchCtrl, &SearchController::requestClear,
                     &mainWindow, &MainWindow::clearSearch);
    QObject::connect(&mainWindow, &MainWindow::searchResultReady,
                     &searchCtrl, &SearchController::onResultReady);
    QObject::connect(&searchCtrl, &SearchController::requestScrollToResult,
                     &mainWindow, &MainWindow::scrollToSearchResult);
    QObject::connect(&mainWindow, &MainWindow::scrollIndexReady,
                     &searchCtrl, &SearchController::onScrollIndexReady);

    // Load existing data
    mainWindow.loadAll();

    // QML engine
    QQmlApplicationEngine engine;

    qmlRegisterType<StickerMovieItem>("WAPage", 1, 0, "StickerMovieItem");

    QStringList formatNames;
    bool webpSupported = false;
    const QList<QByteArray> formats = QImageReader::supportedImageFormats();
    for (const QByteArray& format : formats) {
        const QString lower = QString::fromLatin1(format).toLower();
        formatNames << lower;
        if (lower == "webp") {
            webpSupported = true;
        }
    }

    // Open C++ objects to QML
    engine.rootContext()->setContextProperty("mainWindow",    &mainWindow);
    engine.rootContext()->setContextProperty("searchCtrl",    &searchCtrl);
    engine.rootContext()->setContextProperty("mediaViewer",   &mediaViewer);
    engine.rootContext()->setContextProperty("langManager",   &langManager);

    engine.load(QUrl("qrc:/WAPage/main.qml"));

    if (engine.rootObjects().isEmpty()) {
        Logger::critical("Failed to load QML.");
        return -1;
    }

    const int ret = app.exec();
    Logger::shutdown();
    return ret;
}
