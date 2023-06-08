#pragma once
#include "MainMenu.h"
#include "Level.h"

struct Arguments {
    int hp;
    int coinGain;
    int waves;
    //add number and types of enemies
};

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
    std::vector<std::shared_ptr<sf::Texture>> loadTextures();
    std::vector<std::shared_ptr<sf::Texture>> vecTextures; // vector of textures
    std::vector<Arguments> vecArguments;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time elapsed;
    std::unique_ptr<Level> level;
    bool running = true;
public:
    MainMenu mm;
};