#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include <QtDeclarative/QtDeclarative>
#include "mainwindow.h"
#include "imagereciver.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication *app = new QApplication(argc, argv);

    qmlRegisterType<ImageReciver>("QmlSharing", 1, 0, "ImageSharingClient");

    MainWindow win(QUrl("qrc:/qml/main.qml"));
    win.show();

    return app->exec();
}
