#ifndef DUCK
#define DUCK

#include <pthread.h>
#include <iostream>
#include <QMainWindow>



class Duck{
  private:
    std::default_random_engine generator;
    std::string _type, _id;
    int _posX, _posY, _moveX, _moveY, _life;

    int generateRandomPos(int pMax);

public:
    Duck(std::string pID);
    ~Duck();

    int generateDistribution(double pMedia, double pDesviacion);
    void update();
    int getPosX();
    int getPosY();
    std::string getID();

};

#endif // DUCK
