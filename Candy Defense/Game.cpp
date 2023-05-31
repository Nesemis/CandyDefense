#include "game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Candy defense"), running(true) {
    window.setFramerateLimit(120);
}


void Game::render() {

    window.clear(sf::Color::Black);
    mm.render(window);
    window.display();

}

void Game::update() {

    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed)
        {
            running = false;
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                mm.update(mouse_pos);
            }
        }
        

    }

}

bool Game::isRunning() const {
    return running;
}
