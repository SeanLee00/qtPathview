#include <QGuiApplication>
#include <QQmlApplicationEngine>

//int main(int argc, char *argv[])
//{
//#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();
//}

#include "send.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //
    qmlRegisterType ("Send", 1,0, "SendClass");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //
    Viewer viewer(app.focusObject());
    SEND send(app.focusObject());
    engine.rootContext()->setContextProperty("send", &send);
    return app.exec();
}
