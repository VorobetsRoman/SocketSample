#-------------------------------------------------
#
# Project created by QtCreator 2018-09-07T21:31:53
#
#-------------------------------------------------

QT       += core gui widgets network sql

TARGET = SocketSample
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    socketwork.cpp \
    dbwork.cpp \
    dbworkwithlib.cpp \
    socketworkwithlib.cpp

HEADERS += \
        widget.h \
    socketwork.h \
    dbwork.h \
    dbworkwithlib.h \
    socketworkwithlib.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/../ProjectSample/AppSettings/release/ -lAppSettings

INCLUDEPATH += $$PWD/../ProjectSample/AppSettings
DEPENDPATH += $$PWD/../ProjectSample/AppSettings
