#include "game.h"
#include "Duck.h"

/**
 * @brief Constructor de la la clase Game
 * Inicializa la variable Game::_running en false,esta variable se utiliza como condicion para el loop
 */
Game::Game(){
    this->_running = false;
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
 * @brief Método en donde se ejecuta el loop principal del juego
 *
 */
void Game::run(){

    Duck *pato = new Duck("ddd");

    gettimeofday(&_timeDuck1, NULL);
    this->_msDuck1 = (long long) _timeDuck1.tv_sec * 1000L + _timeDuck1.tv_usec / 1000;

    while(_running){
        gettimeofday(&_timeDuck2, NULL);
        this->_msDuck2 = (long long) _timeDuck2.tv_sec * 1000L + _timeDuck2.tv_usec / 1000;

        if((_msDuck2-_msDuck1)>500){

            pato->update();

            gettimeofday(&_timeDuck1, NULL);
            this->_msDuck1 = (long long) _timeDuck1.tv_sec * 1000L + _timeDuck1.tv_usec / 1000;
        }


    }
}
