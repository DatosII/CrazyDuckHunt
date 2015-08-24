#ifndef DUCK
#define DUCK


class Duck{
private:
    char _type;
    int _posX, _posY, _speed, _life;

public:
    Duck(char pType);
    void setPosX(int pPosX);
    void setPosY(int pPosY);
    void setLife(int pLife);
    void setSpeed(int pSpeed);
    int getPosX();
    int getPosY();
    int getLife();
    int getSpeed();
    char getType();    
    void move(int pPosX, int pPosY);
};

#endif // DUCK
