#include <QApplication>
#include "GUI/graphicview.h"
#include "Logic/game.h"

int main(int argc, char *argv[]){
   // QApplication a(argc, argv);

   // GraphicView *view = new GraphicView();


    Game *game = new Game();
    game->startGame();


    return 0;
}
