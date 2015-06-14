#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T10:26:34
#
#-------------------------------------------------

QT       -= core gui

TARGET = newrap
TEMPLATE = lib

DEFINES += NEWRAP_LIBRARY

SOURCES += newrap.cpp \
    IntervalArithmetic.cpp

HEADERS += newrap.h \
    IntervalArithmetic.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
