#ifndef PLAYER_H
#define PLAYER_H

class Player{
private:
    int _id, _points;
public:
    Player();
    int getId();
    int getPoints();
    void setId(int pID);
    void setPoints(int pPoint);
};

#endif // PLAYER_H
