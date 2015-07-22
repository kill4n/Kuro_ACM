#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T13:54:19
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = Socket_1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sockettest.cpp \
    csocket.cpp \
    cthread.cpp

HEADERS += \
    sockettest.h \
    csocket.h \
    cthread.h
