#include "Game.h"

int main() {
    Game game;
    while (game.mm.isRunning())
    {
        game.mainMenuUpdate();
        game.mainMenuRender();
    }
    game.createLevel();
    while (game.isRunning())
    {
        game.update();
        game.render();
    }
    return 0;
}