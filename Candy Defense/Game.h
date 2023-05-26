#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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
    bool running; 
};