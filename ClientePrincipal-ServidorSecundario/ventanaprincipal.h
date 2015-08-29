#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QWidget>
#include <QMainWindow>

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();
};

#endif // VENTANAPRINCIPAL_H
