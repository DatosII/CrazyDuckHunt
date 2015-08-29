#ifndef DUCK
#define DUCK

#include <pthread.h>
#include <iostream>
#include <QMainWindow>



class Duck{
  private:
    std::default_random_engine generator;
    std::string _type;
    int _id;
    int _posX, _posY, _moveX, _moveY, _life;
    double _media, _desviacion;

    int generateRandomPos(int pMax);

public:
    Duck(int pID);
    ~Duck();

    int generateDistribution(double pMedia, double pDesviacion, bool pSign);
    void update();
    void setLife(double pMedia, double pDesv);
    void setSpeed(double pMedia, double pDesv);
    void setType(std::string pType);
    int getPosX();
    int getPosY();
    int getID();

};

#endif // DUCK
