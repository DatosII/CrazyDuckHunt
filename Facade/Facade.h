#ifndef FACADE
#define FACADE

class Facade{
public:
    Facade();
    void send(int pType, int pIndex, int pId, int pPosX, int pPosY);
    int *receive(int  pArray[]);
};

#endif // FACADE

