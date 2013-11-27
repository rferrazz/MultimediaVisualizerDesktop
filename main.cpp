#include "imagereciver.h"

#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ImageReciver>("ImageReciver", 1, 0, "ImageReciver");

    QQmlApplicationEngine appEngine(QUrl("qrc:/qml/main.qml"));

    return app.exec();
}
