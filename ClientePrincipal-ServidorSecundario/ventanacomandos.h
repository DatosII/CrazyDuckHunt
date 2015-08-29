#ifndef VENTANACOMANDOS_H
#define VENTANACOMANDOS_H

#include <QPushButton>
#include <QLineEdit>
#include <QFont>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <iostream>
#include <pthread.h>
#include <clientecomandos.h>

using namespace std;

/**
  * @brief The VentanaComandos class
  * Ventana que hereda de QMainWindow y que nos permite escribir una peticion
  * en el QLineEdit y recibir una respuesta por parte del servidor.
  */
 class VentanaComandos : public QMainWindow
{
    Q_OBJECT
 private:
     const char* IP;
     int puerto;
     clienteComandos* clientecomando = NULL;
     QLineEdit* barraComando;

 public:
    VentanaComandos(QWidget *parent = 0);
    ~VentanaComandos();
     void setIP_Puerto(const char *pIP, int pPuerto);
 private slots:
     void conectarConServidor();
 };
#endif // VENTANACOMANDOS_H
