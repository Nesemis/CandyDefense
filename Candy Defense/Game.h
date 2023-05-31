#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include <iostream>

class Game {
public:
    Game();
    void render();
    void update();

    bool isRunning() const;
    
private:
    sf::RenderWindow window;
    sf::Clock clock;
    bool running = true;
    sf::Event event;
    sf::Time elapsed;
    MainMenu mm;
};