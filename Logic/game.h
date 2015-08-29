#ifndef GAME_H
#define GAME_H

#include <pthread.h>
#include <iostream>
#include <sys/time.h>
#include "Probabilidades.h"
#include "Duck.h"
#include <QDebug>
#include "Facade/Facade.h"


class Game{

private:
    struct timeval _timeNew1, _timeNew2, _timeUpdate1, _timeUpdate2;
    Probabilidades *_probabilidades;
    Duck *_ducks[20];
    long long _msDuckNewDuck1, _msDuckNewDuck2, _msUpdate1, _msUpdate2;
    bool _running;                              /** Condición del loop */
    pthread_t _thread, _thread2;                /** Thread que ejecuta el loop */
    int _counterID;
    int _totalDucks=0;

    static void* staticStart(void*argument);    /** Métdo estatico para el thread */
    void run();                                 /** Método que ejecuta el loop */
    void createNewDuck();                       /** Método que crea un nuevo pato */
    void cleanArray();
    void insertDuck(Duck *pDuck);
    void deleteDuck(int pID);
    void updateDucks();
    Facade *_facade;


public:
    Game(); /** Constructor */
    void startGame(); /** Método para iniciar el loop */
    void stopGame(); /** Método para finalizar el loop */
    void DeadDuck(int pArray[]);
};

#endif // GAME_H
