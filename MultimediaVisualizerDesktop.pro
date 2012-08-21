# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

QT += network declarative

TARGET = MultimediaVisualizer
TEMPLATE = app

SOURCES += main.cpp \
    imagereciver.cpp \
    serverthread.cpp \
    imageserver.cpp \
    mainwindow.cpp

# Please do not modify the following two lines. Required for deployment.
include(QBonjourServer/bonjourserver.pri)

HEADERS += \
    imagereciver.h \
    serverthread.h \
    imageserver.h \
    mainwindow.h

FORMS +=

OTHER_FILES += \
    qml/MultimediaVisualizerDesktop/main.qml

RESOURCES += \
    resources.qrc


