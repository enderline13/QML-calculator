#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calcsystem.h"
#include <qqml.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<CalcSystem>("CustomComponent", 1, 0, "CalcSystem");
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Calculator/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
