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
    qml/MultimediaVisualizerDesktop/main.qml \
    MultimediaVisualizer.desktop

RESOURCES += \
    resources.qrc

unix {
    target.path = /usr/bin
    data.path = /usr/share/${TARGET}/data
    data.files = data/*
    desktopfile.files += data/${TARGET}.desktop
    desktopfile.path = /usr/share/applications/
    icon.files += ${TARGET}.svg
    icon.path = /usr/share/${TARGET}/icon
    INSTALLS += data
    INSTALLS += target
    INSTALLS += desktopfile
    INSTALLS += icon
}


