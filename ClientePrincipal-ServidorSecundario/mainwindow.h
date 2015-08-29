#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QMainWindow>
#include <QPixmap>
#include <QtGui>
#include <iostream>
#include <ventanaip.h>

using namespace std;

/**
 * @brief The MainWindow class
 * Clase que hereda de QMainWindow. Basicamente almacena botones que al
 * presionarlos nos enviara a la solicitud de conexion pertinente.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void newVentanaIP1();
    void newVentanaIP2();
    void newVentanaIP3();
};

#endif // MAINWINDOW_H
