QT           += network

HEADERS += \
    $$PWD/bonjourrecord.h \
    $$PWD/bonjourserviceregister.h \

SOURCES += \
    $$PWD/bonjourserviceregister.cpp \

INCLUDEPATH += $$PWD


win32 {
    LIBS+=-ldnssd
    # Add your path to bonjour here.
    LIBPATH = C:/Temp/mDNSResponder-107.6/mDNSWindows/DLL/Debug
    INCLUDEPATH += c:/Temp/mDNSResponder-107.6/mDNSShared
} else {
    LIBS+=-ldns_sd
}
