#include "Duck.h"
#include <QDebug>

/**
 * @brief Constructor
 * Establece el id del objeto con el parametro enviado y generado
 * una posición aleatoria para el eje X y Y
 *
 * @param pID ID del objeto
 */
Duck::Duck(int pID){
    this->_id = pID;
    this->_posX = this->generateRandomPos(1300);
    this->_posY = this->generateRandomPos(500);
    this->_moveX = this->generateDistribution(4.0, 2.0, true);
    this->_moveY = this->generateDistribution(4.0, 2.0, true);
}



/**
 * @brief Obtener vida aleatoria
 * Método que obtiene una vida aleatoria mediante una distribución normal
 * Mediante una variable booleana se determina si se desea que el número generado
 * sea positivo(true) o negativo(false)
 *
 * @param pMedia Media
 * @param pDesviacion Desviacion estandar
 * @param pSign Signo del número generado(Positivo o negativo)
 *
 * @return Número generado
 */
int Duck::generateDistribution(double pMedia, double pDesviacion, bool pSign){
    std::normal_distribution<double> distribution(pMedia,pDesviacion);
    double number = distribution(this->generator);
    if(pSign){
        if(number<0) number+=(number*2*-1);
    }
    else if(number == 0){
        number++;
    }
    else{
        if(number>0) number-= (number*2);
    }
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
int Duck::getID(){
    return this->_id;
}


/**
 * @brief Método que establece la vida del pato
 * Genera la vida mediante un número random de distribución normal
 * con la media y desviación enviadas como parametro
 *
 * @param pMedia Media de la distribución
 * @param pDesv Desviación estandar
 */
void Duck::setLife(double pMedia, double pDesv){
    this->_life = this->generateDistribution(pMedia, pDesv, true);
}


/**
 * @brief Método que establece la velocidad del pato
 * La velocidad del pato se calcula de acuerdo a una distribución normal
 * con los parametros de media y desviación
 *
 * @param pMedia Media de la distribución
 * @param pDesv Desviación estandar
 */
void Duck::setSpeed(double pMedia, double pDesv){
    this->_media = pMedia;
    this->_desviacion = pDesv;
}



/**
 * @brief Establece el tipo de pato
 *
 * @param pType Tipo de pato
 */
void Duck::setType(std::string pType){
    this->_type = pType;
}


/**
 * @brief Actualiza el estado del objeto
 * Comprueba que la posición del objeto no se encuentre fuera del tamaño del area de juego
 * Si el pato se encuentra en el limite del eje X o Y se cambia la dirección de su movimiento
 */
void Duck::update(){

    if((this->getPosX())+64 > 1366){
        this->_moveX = this->generateDistribution(_media, _desviacion, false);
    }
    if(this->_posX < 0){
        this->_moveX = this->generateDistribution(_media, _desviacion, true);
    }
    if(this->_posY < 0){
        this->_moveY = this->generateDistribution(_media, _desviacion, true);
    }
    if((this->_posY)+64 > 576){
        this->_moveY = this->generateDistribution(_media, _desviacion, false);
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

