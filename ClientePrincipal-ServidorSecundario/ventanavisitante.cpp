#include "ventanavisitante.h"

/**
 * @brief VentanaVisitante::VentanaVisitante
 * @param parent
 * Constructor de la ventana de visitante
 */
VentanaVisitante::VentanaVisitante(QWidget *parent)
    : QMainWindow(parent)
{
    this->show();
}

/**
 * @brief VentanaVisitante::setIP_Puerto
 * @param pIP el Ip obtenido por el usuario de la ventana Anterior
 * @param pPuerto es el puerto obtenido de la ventana anterior
 * Metodo que setea el ip y el puerto de la ventana precedida.
 */
void VentanaVisitante::setIP_Puerto(char pIP, int pPuerto)
{
    this->IP = pIP;
    this->puerto = pPuerto;
}

/**
 * @brief VentanaVisitante::~VentanaVisitante
 * Destructor por defecto de la clase VentanaVisitante
 */
VentanaVisitante::~VentanaVisitante()
{

}
