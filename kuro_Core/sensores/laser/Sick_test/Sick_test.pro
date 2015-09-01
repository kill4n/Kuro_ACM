#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T10:52:44
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sick_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sick_test.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    sick_test.h \
    glwidget.h

FORMS    += mainwindow.ui
