#-------------------------------------------------
#
# Project created by QtCreator 2015-03-20T09:22:03
#
#-------------------------------------------------

QT       -= gui

TARGET = lib_newton_raphson
TEMPLATE = lib

DEFINES += LIB_NEWTON_RAPHSON_LIBRARY

SOURCES += lib_newton_raphson.cpp

HEADERS += lib_newton_raphson.h\
        lib_newton_raphson_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
