QT           += network

HEADERS += \
    $$PWD/bonjourrecord.h \
    $$PWD/bonjourserviceregister.h \

SOURCES += \
    $$PWD/bonjourserviceregister.cpp \

INCLUDEPATH += $$PWD


win32 {
    LIBS+=-L"C:/Program Files/Bonjour SDK/Lib/Win32" \
        -ldnssd

    INCLUDEPATH += "C:/Program Files/Bonjour SDK/Include" \

} else {
    LIBS+=-ldns_sd
}
