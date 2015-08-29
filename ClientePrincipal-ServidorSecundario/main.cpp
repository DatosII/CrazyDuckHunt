#include <QApplication>
#include <QWidget>
#include "mainwindow.h"

 int main(int argc, char *argv[])
 {
     QApplication aplicacion(argc, argv);
     MainWindow* principal = new MainWindow();
     principal->show();

    return aplicacion.exec();
 }

