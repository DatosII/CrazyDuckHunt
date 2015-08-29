#ifndef PROBABILIDADES_H
#define PROBABILIDADES_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Probabilidades{
private:

    /** Variables que permiten conocer la cantidad de patos por especie y su probabilidad */
    int _pSalvajeIni=0, _pSalvajeFin=81, _gHawaiiIni=82, _gHawaiiFin=91, _pColoradoIni=92, _pColoradoFin=96,
    _tCaneloIni=97, _tCaneloFin=98, _yPiquirrojoIni=99, _yPiquirrojoFin=99, _contadorPS=0, _contadorGH=0, _contadorPC=0,
    _contadorTC=0, _contadorYP=0;
    std::string _salvaje="salvaje", _Hawaii="Hawaii", _colorado="colorado", _canelo="canelo", _yaguasa="yaguasa";
public:

    Probabilidades();
    void actualizarValores();
    std::string obtenerPato();
    int obtenerNumero();
};

#endif // PROBABILIDADES_H
