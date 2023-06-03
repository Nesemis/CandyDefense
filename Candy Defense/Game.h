#pragma once
#include "MainMenu.h"
#include "Level.h"


class Game {
public:
    Game();
    void createLevel();
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
    std::unique_ptr<Level> level;
    bool running = true;
public:
    MainMenu mm;
};