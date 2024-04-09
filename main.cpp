#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QQmlContext>
#include "PieceArr.h"
#include "PieceColor.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<PieceArr>("PieceArr", 1, 0, "PieceArr");

    PieceArr whitePieces(PieceColor::white);
    //PieceArr blackPieces(PieceColor::black);
    QQmlApplicationEngine engine;
    //engine.rootContext()->setContextProperty("blackPieces", QVariant::fromValue(&blackPieces));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * white = engine.rootContext();
    white->setContextProperty("whitePieces", &whitePieces);

    return app.exec();
}
