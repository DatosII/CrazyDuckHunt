#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T17:23:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CrazyDuckHunt
TEMPLATE = app


SOURCES += main.cpp \
    GUI/graphicscene.cpp \
    GUI/myobject.cpp \
    GUI/graphicview.cpp

HEADERS  += \
    GUI/graphicscene.h \
    GUI/myobject.h \
    GUI/graphicview.h \
    Logic/Duck.h \
    Logic/Player.h \
    Logic/game.h

FORMS    +=
