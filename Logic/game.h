#ifndef GAME_H
#define GAME_H

#include <pthread.h>
#include <iostream>
#include <sys/time.h>



class Game{

private:
    struct timeval _timeDuck1, _timeDuck2;
    long long _msDuck1, _msDuck2;
    bool _running; /** Condición del loop */
    pthread_t _thread, _thread2; /** Thread que ejecuta el loop */
    static void* staticStart(void*argument); /** Métdo estatico para el thread */
    void run(); /** Método que ejecuta el loop */


public:
    Game(); /** Constructor */
    void startGame(); /** Método para iniciar el loop */
    void stopGame(); /** Método para finalizar el loop */
};

#endif // GAME_H
