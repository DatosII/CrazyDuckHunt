#include "game.h"


/**
 * @brief Constructor de la la clase Game
 * Inicializa la variable Game::_running en false,esta variable se utiliza como condicion para el loop
 */
Game::Game(Facade *pFacade){
    this->_running = false;
    this->_probabilidades = new Probabilidades();
    this->cleanArray();
    this->_facade=pFacade;
}


/**
 * @brief Método que detiene el loop
 * Cambia la variable Game::_running (condición del loop) a false, provocando que se salga del loop
 */
void Game::stopGame(){
    this->_running = false;
    pthread_exit(NULL);
}


/**
 * @brief Método estatico que ejecutara el thread cuando es creado
 * Recibe un puntero void a una clase de tipo Game, el puntero es casteado de nuevo a tipo
 * Game para cambiar el valor de la variable Game::_running y llamar el método que ejecuta el loop
 *
 * @param argument Puntero de tipo void a una clase tipo Game
 * @return NULL
 */
void* Game::staticStart(void *argument){
    Game* _thisObject = static_cast<Game*>(argument);
    _thisObject->_running = true;
    _thisObject->run();
    return NULL;

}


/**
 * @brief Método que comienza la ejecución del loop
 * Crea el thread, el cual ejecutara el método estatico Game::staticStart() y enviando como parametro
 * un puntero tipo void a la objeto Game
 */
void Game::startGame(){
    pthread_create(&_thread, NULL, staticStart, (void*)this);
    pthread_join(_thread,NULL);
}



/**
 * @brief Método que inicializa los punteros del arreglo en nulo
 */
void Game::cleanArray(){
    for(int i = 0; i<20; i++){
        _ducks[i] = 0;
    }
}


/**
 * @brief Inserta objetos de tipo pato dentro del arreglo
 *
 * @param pDuck Puntero al objeto que se quiere insertar
 */
void Game::insertDuck(Duck *pDuck){
    if(_totalDucks != 20){
        for(int i = 0; i<20; i++){
            if(_ducks[i] == 0){
                _ducks[i] = pDuck;
                _totalDucks++;
                break;
            }
        }
    }
    else{
        this->stopGame();
    }
}



/**
 * @brief Método que recorre el de objetos de tipo pato y llama a su método Duck::update()
 */
void Game::updateDucks(){
    for(int i = 0; i<20; i++){
        if(_ducks[i] != 0){
            _ducks[i]->update();

        }
    }
}



/**
 * @brief Método que permite crear nuevos patos
 * Crea un nuevo pato de una especie aleatoria según sus probabilidades
 */
void Game::createNewDuck(){
    std::string _duckSpecie = _probabilidades->obtenerPato();
    Duck *_newDuck = new Duck(_counterID);
    _counterID++;
    _newDuck->setType(_duckSpecie);
    if(_duckSpecie == "salvaje") _newDuck->setLife(3.0, 1.0); _newDuck->setSpeed(10.0, 5.0);
    if(_duckSpecie == "Hawaii") _newDuck->setLife(5.0, 2.0);  _newDuck->setSpeed(8.0, 3.0);
    if(_duckSpecie == "colorado") _newDuck->setLife(10.0, 5.0); _newDuck->setSpeed(10.0, 3.0);
    if(_duckSpecie == "canelo") _newDuck->setLife(5.0, 2.0); _newDuck->setSpeed(3.0, 1.0);
    if(_duckSpecie == "yaguasa")  _newDuck->setLife(2.0, 1.0); _newDuck->setSpeed(12.0, 5.0);

    this->insertDuck(_newDuck);
}



/**
 * @brief Método en donde se ejecuta el loop principal del juego
 *
 */
void Game::run(){


    gettimeofday(&_timeNew1, NULL);
    this->_msDuckNewDuck1 = (long long) _timeNew1.tv_sec * 1000L + _timeNew1.tv_usec / 1000;

    gettimeofday(&_timeUpdate1, NULL);
    this->_msUpdate1 = (long long) _timeUpdate1.tv_sec * 1000L + _timeUpdate1.tv_usec / 1000;

    while(_running){
        gettimeofday(&_timeNew2, NULL);
        this->_msDuckNewDuck2 = (long long) _timeNew2.tv_sec * 1000L + _timeNew2.tv_usec / 1000;

        gettimeofday(&_timeUpdate2, NULL);
        this->_msUpdate2 = (long long) _timeUpdate2.tv_sec * 1000L + _timeUpdate2.tv_usec / 1000;

        if((_msDuckNewDuck2-_msDuckNewDuck1) > 1000){
            this->createNewDuck();
            gettimeofday(&_timeNew1, NULL);
            this->_msDuckNewDuck1 = (long long) _timeNew1.tv_sec * 1000L + _timeNew1.tv_usec / 1000;
        }

        if((_msUpdate2-_msUpdate1) > 500){
            this->updateDucks();
            gettimeofday(&_timeUpdate1, NULL);
            this->_msUpdate1 = (long long) _timeUpdate1.tv_sec * 1000L + _timeUpdate1.tv_usec / 1000;
        }

    }

    qDebug() << "FIN DEL JUEGO: HAY 20 PATOS EN PANTALLA";
}
/**
 * @brief Game::DeadDuck Metodo para eliminar patos muertos
 * @param pArray
 */
void Game::DeadDuck(int pArray[]){
    delete(_ducks[pArray[1]]);
    _ducks[pArray[1]]=0;
}
