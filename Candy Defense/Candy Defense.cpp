#include "Game.h"

int main() {
    Game game;
    while (game.mm.isRunning())
    {
        game.mainMenuUpdate();
        game.mainMenuRender();
    }
    while (game.isRunning())
    {
        game.createLevel();
        game.update();
        game.render();
    }
    return 0;
}