#include "probabilidades.h"

probabilidades::probabilidades(){

}

void probabilidades::actualizarValores()
{
    _pSalvajeFin-=4;
    _gHawaiiIni-=4;
    _gHawaiiFin-=3;
    _pColoradoIni-=3;
    _pColoradoFin-=2;
    _tCaneloIni-=2;
    _tCaneloFin-=1;
    _yPiquirrojoIni-=1;
}



std::string probabilidades::obtenerPato(){
    int pTipo=obtenerNumero();
    if(pTipo>=_pSalvajeIni && pTipo<=_pSalvajeFin && (_contadorPS<(_pSalvajeFin-_pSalvajeIni))){
            _contadorPS++;
            return _salvaje;
    }
    else if(pTipo>=_gHawaiiIni && pTipo<=_gHawaiiFin && (_contadorGH<(_gHawaiiFin-_gHawaiiIni))){
        _contadorGH++;
        return _Hawaii;
    }
    else if(pTipo>=_pColoradoIni && pTipo<=_pColoradoFin && (_contadorPC<(_pColoradoFin-_pColoradoIni))){
        _contadorPC++;
        return _colorado;
    }
    else if(pTipo>=_tCaneloIni && pTipo<=_tCaneloFin && (_contadorTC<(_tCaneloFin - _tCaneloIni))){
        _contadorTC++;
        return _canelo;
    }
    else if (pTipo>=_yPiquirrojoIni && pTipo<=_yPiquirrojoFin && (_contadorYP<(_yPiquirrojoFin-_yPiquirrojoIni))){
        _contadorYP++;
        return _yaguasa;
    }
    else
        return obtenerPato();
}

int probabilidades::obtenerNumero(){
    return (rand()%(100));
}
