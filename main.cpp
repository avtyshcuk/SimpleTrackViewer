#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "trackmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TrackModel>("com.company.media", 1, 0, "TrackModel");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
