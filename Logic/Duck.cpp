#include "Duck.h"
#include <QDebug>

/**
 * @brief Constructor
 * Establece el id del objeto con el parametro enviado y generado
 * una posición aleatoria para el eje X y Y
 *
 * @param pID ID del objeto
 */
Duck::Duck(std::string pID){
    this->_id = pID;
    this->_posX = this->generateRandomPos(1300);
    this->_posY = this->generateRandomPos(500);
    this->_moveX = this->generateDistribution(2.0, 3.0);
    this->_moveY = this->generateDistribution(2.0, 3.0);

}



/**
 * @brief Obtener vida aleatoria
 * Método que obtiene una vida aleatoria mediante una distribución normal (Para el Pato Canelo)
 *
 * @param pMedia Media
 * @param pDesviacion Desviacion estandar
 *
 * @return Vida aleatoria generada
 */
int Duck::generateDistribution(double pMedia, double pDesviacion){
    std::normal_distribution<double> distribution(pMedia,pDesviacion);
    double number = distribution(this->generator);
    return number;
}



/**
 * @brief Generar posición aleatoria
 * Método que genera una posición aleatoria en el intervalo
 * de 100 a pMax
 * @param pMax Limite superior del intervalo
 * @return Posición aleatoria
 */
int Duck::generateRandomPos(int pMax){
    int number = 1+(rand()%(pMax));
    return number;
}


/**
 * @brief Obtener posición en el eje X
 *
 * @return Posición en el eje X
 */
int Duck::getPosX(){
    return this->_posX;
}


/**
 * @brief Obtener posición en el eje Y
 *
 * @return Posición en el eje Y
 */
int Duck::getPosY(){
    return this->_posY;
}


/**
 * @brief Obtener el id del objeto
 *
 * @return ID del objeto
 */
std::string Duck::getID(){
    return this->_id;
}


/**
 * @brief Actualiza el estado del objeto
 * Comprueba que la posición del objeto no se encuentre fuera del tamaño del area de juego
 * Si el pato se encuentra en el limite del eje X o Y se cambia la dirección de su movimiento
 */
void Duck::update(){

    if((this->_posX)+64 >= 1366 || this->_posX<=0){
        this->_moveX = this->generateDistribution(2.0,3.0);
    }

    if((this->_posY) <= 0 || (this->_posY)+64 >= 576){
        this->_moveY = this->generateDistribution(2.0,3.0);
    }

    this->_posX+=_moveX;
    this->_posY+=_moveY;

    qDebug()<<"POS X: " << _posX << " POS Y: " << _posY << "\n";

}


/**
 * @brief Destructor
 */
Duck::~Duck(){

}

