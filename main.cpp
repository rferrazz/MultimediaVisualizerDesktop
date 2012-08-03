#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include <QtDeclarative/QtDeclarative>
#include "qmlapplicationviewer.h"
#include "imagereciver.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<ImageReciver>("QmlSharing", 1, 0, "ImageSharingClient");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/MultimediaVisualizerDesktop/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
