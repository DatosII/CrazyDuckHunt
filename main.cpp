#include <QApplication>
#include "GUI/graphicview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraphicView *view = new GraphicView();


    return a.exec();
}
