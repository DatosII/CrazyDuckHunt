#ifndef VENTANAIP_H
#define VENTANAIP_H

#include <QPushButton>
#include <QLineEdit>
#include <QFont>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <iostream>
#include "ClientePrincipal-ServidorSecundario/ventanacomandos.h"
#include "ClientePrincipal-ServidorSecundario/ventanavisitante.h"
#include "ClientePrincipal-ServidorSecundario/ventanajugador.h"
#include <string>
#include <string.h>

using namespace std;

/**
 * @brief The ventanaIP class
 * Ventana que solicita al usuario la direccion IP y
 * el numero de uerto por el que se va a conectar el usuario
 * por medio de dos QLineEdit.
 */
class ventanaIP : public QMainWindow{
    Q_OBJECT
private:
    int tipo;
    QLineEdit* pBarraIP = NULL;
    QLineEdit* pBarraPuerto = NULL;

public:
    ventanaIP(QWidget *parent = 0);
    ~ventanaIP();
    void setTipo(int i);

private slots:
    void newVentana();
};

#endif // VENTANAIP_H
