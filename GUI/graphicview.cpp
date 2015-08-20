#include "GUI/graphicview.h"
#include "GUI/graphicscene.h"


GraphicView::GraphicView() {

    //Se elimina el scroll horizontal y vertical de la ventana
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Se establece el tamaño de la ventana
    this->setFixedSize(1366,768);


    GraphicScene *scene = new GraphicScene();
    this->setScene(scene);

    this->show();

}
