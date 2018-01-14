TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    trackmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    trackstorage.h \
    trackmodel.h \
    tracks/basetrack.h \
    tracks/usbtrack.h \
    tracks/track.h \
    tracks/btatrack.h \
    trackfactory.h
