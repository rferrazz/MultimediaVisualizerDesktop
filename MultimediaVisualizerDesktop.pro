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
#VARIABLES
    isEmpty(PREFIX) {
        PREFIX = /usr
    }
    BINDIR = $$PREFIX/bin
    DATADIR =$$PREFIX/share
    DEFINES += DATADIR=\\\"$$DATADIR\\\" PKGDATADIR=\\\"$$PKGDATADIR\\\"
    INSTALLS += data target desktopfile icon
    target.path = $$BINDIR
    data.path = $$DATADIR/${TARGET}/data
    data.files = data/*
    desktopfile.files += ${TARGET}.desktop
    desktopfile.path = $$DATADIR/applications/
    icon.files += ${TARGET}.svg
    icon.path = $$DATADIR/${TARGET}/icon
}


