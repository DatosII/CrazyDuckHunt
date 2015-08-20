#ifndef MYOBJECT
#define MYOBJECT

#include <QGraphicsRectItem>

class MyObject: public QGraphicsRectItem{

public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYOBJECT

