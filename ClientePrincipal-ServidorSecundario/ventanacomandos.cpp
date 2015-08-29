#include "ventanacomandos.h"

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief VentanaComandos::VentanaComandos
 * @param parent
 */
VentanaComandos::VentanaComandos(QWidget *parent)
    : QMainWindow(parent)
{
//    Instanciamos los objetos de la GUI de la ventana de comandos.
    QLabel* fondo = new QLabel(this);
    QPixmap imagenFondo("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/FondoPrincipal.jpg");
    QPixmap imagenButton("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/buttonSolicitarPeticion.png");
    QIcon iconoComandos(imagenButton);
    QPushButton* enviarPeticion = new QPushButton(this);
    barraComando = new QLineEdit("Escriba su codigo", this);

//    Definimos caracteristicas de los objetos de la GUI

    this->resize(imagenFondo.width(),imagenFondo.height());

    fondo->setGeometry(0,0,imagenFondo.width(),imagenFondo.height());
    fondo->setPixmap(imagenFondo);

    barraComando->setGeometry(100, 100, 300, 50);

    enviarPeticion->setFont(QFont("Times", 18, QFont::Bold));
    enviarPeticion->setGeometry(250,150,imagenButton.width(),imagenButton.height());
    enviarPeticion->setIcon(iconoComandos);
    enviarPeticion->setIconSize(imagenButton.rect().size());

    clientecomando = new clienteComandos();

    QObject::connect(enviarPeticion, SIGNAL(clicked()), this, SLOT(conectarConServidor()));

    this->show();
}

/**
 * @brief VentanaComandos::setIP_Puerto
 * @param pIP es el ip que nos da el usuario al digitarlo en el
 * QLineEdit de la ventanaip
 * @param pPuerto es el puerto que nos da el usurio en el QLineEdit.
 * de la ventanaip
 */
void VentanaComandos::setIP_Puerto(const char* pIP, int pPuerto)
{
    this->IP = pIP;
    this->puerto = pPuerto;
}

/**
 * @brief VentanaComandos::conectarConServidor
 * El metodo basicamente invoca al objeto clienteComando para que este se encargue de enviar un
 * mensaje al servidor por medio de un thread que el mismo inicializa.
 */
void VentanaComandos::conectarConServidor(){

    clientecomando->enviar_y_recibir(this->IP, this->puerto, barraComando->text().toStdString());
}

/**
 * @brief VentanaComandos::~VentanaComandos
 * Destructor por defecto de la clase.
 */
VentanaComandos::~VentanaComandos()
{

}
