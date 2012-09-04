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

unix {
    target.path = /usr/bin
    data.path = /usr/share/multimediavisualizer/data
    data.files = data/*
    INSTALLS += data
    INSTALLS += target
}


