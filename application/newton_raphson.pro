#-------------------------------------------------
#
# Project created by QtCreator 2015-03-19T19:00:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newton_raphson
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    IntervalArithmetic.cpp \
    equation.cpp \
    equationia.cpp \
    equationpa.cpp

HEADERS  += mainwindow.h \
    IntervalArithmetic.h \
    equation.h \
    equationia.h \
    equationpa.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -Wextra -pedantic
LIBS += -lmpfr
