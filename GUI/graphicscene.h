/*
 * Esta clase crea la superficie sobre la cual se insertan todos
 * los objetos que se deben mostrar en la pantalla
 */


#ifndef GRAPHICSCENE
#define GRAPHICSCENE

#include <QGraphicsScene>

class GraphicScene: public QGraphicsScene {

public:
   GraphicScene();

private:
   QGraphicsScene *scene;
};



#endif // GRAPHICSCENE

