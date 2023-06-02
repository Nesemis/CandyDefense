#pragma once
#include "MainMenu.h"


class Game {
public:
    Game();
    void render();
    void update();
    void mainMenuRender();
    void mainMenuUpdate();
    bool isRunning() const;
    
private:
    std::vector<std::unique_ptr<sf::Texture>> loadTextures();
   
    std::vector<std::unique_ptr<sf::Texture>> vecTextures;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time elapsed;
    bool running = true;
public:
    MainMenu mm;
};