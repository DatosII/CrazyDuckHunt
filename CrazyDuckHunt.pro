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
    GUI/graphicview.cpp \
    Logic/Player.cpp \
    Logic/Duck.cpp \
    Logic/Probabilidades.cpp \
    Logic/game.cpp \
    ClientePrincipal-ServidorSecundario/clientecomandos.cpp \
    ClientePrincipal-ServidorSecundario/main.cpp \
    ClientePrincipal-ServidorSecundario/mainwindow.cpp \
    ClientePrincipal-ServidorSecundario/ventanacomandos.cpp \
    ClientePrincipal-ServidorSecundario/ventanaip.cpp \
    ClientePrincipal-ServidorSecundario/ventanajugador.cpp \
    ClientePrincipal-ServidorSecundario/ventanaprincipal.cpp \
    ClientePrincipal-ServidorSecundario/ventanavisitante.cpp \
    ServidorPrincipal/logica.cpp \
    ServidorPrincipal/main.cpp \
    ServidorPrincipal/servidor.cpp

HEADERS  += \
    GUI/graphicscene.h \
    GUI/myobject.h \
    GUI/graphicview.h \
    Logic/Duck.h \
    Logic/Player.h \
    Logic/game.h \
    Logic/Probabilidades.h \
    ClientePrincipal-ServidorSecundario/clientecomandos.h \
    ClientePrincipal-ServidorSecundario/mainwindow.h \
    ClientePrincipal-ServidorSecundario/ventanacomandos.h \
    ClientePrincipal-ServidorSecundario/ventanaip.h \
    ClientePrincipal-ServidorSecundario/ventanajugador.h \
    ClientePrincipal-ServidorSecundario/ventanaprincipal.h \
    ClientePrincipal-ServidorSecundario/ventanavisitante.h \
    ServidorPrincipal/logica.h \
    ServidorPrincipal/servidor.h

FORMS    +=
