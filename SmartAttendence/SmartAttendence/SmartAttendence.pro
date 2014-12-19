#-------------------------------------------------
#
# Project created by QtCreator 2014-01-23T08:47:24
#
#-------------------------------------------------

QT       += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartAttendence
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    retrive_window.cpp \
    checkleaves.cpp \
    advance.cpp \
    salary.cpp

HEADERS  += widget.h \
    Database.h \
    retrive_window.h \
    checkleaves.h \
    advance.h \
    salary.h

FORMS    += widget.ui \
    retrive_window.ui \
    checkleaves.ui \
    advance.ui \
    salary.ui
