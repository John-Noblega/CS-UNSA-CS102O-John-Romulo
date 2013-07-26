#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T09:43:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Confe
TEMPLATE = app

QMAKE_CXXFLAGS += -std=gnu++11
SOURCES += main.cpp\
        interface.cpp \
    operation.cpp \
    node.cpp \
    lexer.cpp \
    constant.cpp \
    cell.cpp

HEADERS  += interface.h \
    resources.h \
    operation.h \
    nodes.h \
    node.h \
    mastrize.h \
    lexer.h \
    inclusions.h \
    constant.h \
    cell.h

FORMS    += interface.ui
