#include "ventanajugador.h"
#include <QString>

/**
 * @brief VentanaJugador::VentanaJugador
 * @param parent
 * Constructor que inicializa los threads de envio de datos y recepcion de datos.
 * A su vez seta las caraceristicas basicas de la ventana para su oportuna visualizacion.
 */
VentanaJugador::VentanaJugador(QWidget *parent)
    : QMainWindow(parent)
{
    this->iniciarThreadsCliente();
    this->mira = new QLabel(this);
    QPixmap mapa("/home/diego/Escritorio/CrazyDuckHunt/ClientePrincipal-ServidorSecundario/Mira.png");

    this->mira->setPixmap(mapa);
    this->mira->setGeometry(0,0,mapa.width(),mapa.height());
    this->mira->show();
    this->show();
}

/**
 * @brief VentanaJugador::setIP_Puerto
 * @param pIP es el ip obtenido por el usuario de la ventana anterior.
 * @param pPuerto es el puerto obtenido por el usuario de la ventana anterior
 * Metodo que setea los valores de ip y puerto de la clase para la comunicacion
 *  del cliente con el servidor
 */
void VentanaJugador::setIP_Puerto(char pIP, int pPuerto)
{
    this->IP = pIP;
    this->puerto = pPuerto;
}

/**
 * @brief VentanaJugador::iniciarThreadsCliente
 * Metodo que inicializa los threads que enviaran y recibiran los datos del servidor.
 */
void VentanaJugador::iniciarThreadsCliente(){
    pthread_create(&envio,NULL,envios,NULL);
    pthread_create(&recibo,NULL,recibidos,NULL);
}

/**
 * @brief VentanaJugador::envios
 * @param argument es un puntero de un struct con los datos necesarios para mandar
 *  informacion al servidor.
 * @return
 */
void* VentanaJugador::envios(void * argument){
    cout<<"Este es el thread para enviar informacion del Juego/n"<<endl;
}

/**
 * @brief VentanaJugador::recibidos
 * @param argument
 * @return
 */
void* VentanaJugador::recibidos(void * argument){
    cout<<"Este es el thread que recibe informacion del Juego/n"<<endl;
}

/**
 * @brief VentanaJugador::mouseMoveEvent
 * @param e
 */
void VentanaJugador::mouseMoveEvent(QMouseEvent* e){
    cout<< "X: "<< e->x()<<"Y: "<<e->y() <<endl;
    this->mira->setGeometry(e->x(),e->y(),mapa.width(),mapa.height());
    this->mira->show();
}

/**
 * @brief VentanaJugador::~VentanaJugador
 */
VentanaJugador::~VentanaJugador()
{

}
