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
    solver.cpp \
    IntervalArithmetic.cpp \
    funct.cpp

HEADERS  += mainwindow.h \
    solver.h \
    IntervalArithmetic.h \
    funct.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -Wextra -pedantic
LIBS += -lmpfr
