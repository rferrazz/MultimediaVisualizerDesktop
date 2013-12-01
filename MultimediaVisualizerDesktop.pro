QT += core quick network

TARGET = MultimediaViasualizer
TEMPLATE = app

include(QBonjourServer/bonjourserver.pri)

SOURCES += main.cpp \
    imageserver.cpp \
    imagereciver.cpp

HEADERS += \
    imageserver.h \
    imagereciver.h

RESOURCES += \
    qml.qrc

OTHER_FILES += \
    qml/MultimediaVisualizer/main.qml

