#include <QApplication>
#include "GUI/graphicview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraphicView *view = new GraphicView();





    /*
    GraphicScene *scene = new GraphicScene();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1366,768);
    view->show();
    */

    return a.exec();
}
