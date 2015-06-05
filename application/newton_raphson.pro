#-------------------------------------------------
#
# Project created by QtCreator 2015-03-19T19:00:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newton_raphson
TEMPLATE = app
INCLUDEPATH += -L/usr/lib/x86_64-linux-gnu/

SOURCES += main.cpp\
        mainwindow.cpp \
    IntervalArithmetic.cpp \
    equationia.cpp \
    equationpa.cpp

HEADERS  += mainwindow.h \
    IntervalArithmetic.h \
    equationia.h \
    equationpa.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -Wextra -pedantic

LIBS += -L/usr/lib/x86_64-linux-gnu/ -lmpfr -ldl
