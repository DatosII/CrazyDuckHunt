#include "Duck.h"

Duck::Duck(char pType){
    _type=pType;
}

char Duck::getType(){
    return _type;
}

int Duck::getLife(){
    return _life;
}

int Duck::getPosX(){
    return _posX;
}

int Duck::getPosY(){
    return _posY;
}

int Duck::getSpeed(){
    return _speed;
}

void Duck::setLife(int pLife){
    _life=pLife;
}

void Duck::setPosX(int pPosX){
    _posX=pPosX;
}

void Duck::setPosY(int pPosY){
    _posY=pPosY;
}

void Duck::setSpeed(int pSpeed){
    _speed=pSpeed;
}

void Duck::move(int pPosX, int pPosY){
    _posX+=pPosX;
    _posY+=pPosY;
}

