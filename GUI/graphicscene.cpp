#include "GUI/graphicscene.h"
#include "GUI/myobject.h"

GraphicScene::GraphicScene(){

    //Establece el tamaño de la superficie
    this->setSceneRect(0,0,1366,768);

    MyObject *object = new MyObject();
    object->setRect(0,0,10,10);

    this->addItem(object);

    object->setFlag(QGraphicsItem::ItemIsFocusable);
    object->setFocus();

}
