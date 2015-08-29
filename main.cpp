#include <QApplication>
#include "GUI/graphicview.h"
#include "Logic/game.h"
#include "Facade/Facade.h"

int main(int argc, char *argv[]){
   // QApplication a(argc, argv);

   // GraphicView *view = new GraphicView();

    Facade *facade = new Facade();
    Game *game = new Game(facade);
    game->startGame();


    return 0;
}
