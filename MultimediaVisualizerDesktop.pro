QT += core quick

# Add more folders to ship with the application, here
folder_01.source = qml/MultimediaVisualizer
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Installation path
# target.path =

include(QBonjourServer/bonjourserver.pri)

SOURCES += main.cpp \
    serverthread.cpp \
    imageserver.cpp \
    imagereciver.cpp

HEADERS += \
    serverthread.h \
    imageserver.h \
    imagereciver.h

RESOURCES += \
    qml.qrc

OTHER_FILES += \
    qml/MultimediaVisualizer/main.qml

