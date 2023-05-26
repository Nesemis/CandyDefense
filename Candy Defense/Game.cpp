#include "game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Candy defense"), running(true) {
    window.setFramerateLimit(120);
}


void Game::render() {
    window.clear(sf::Color::Black);

    window.display();

}

void Game::update() {
    sf::Event event;
    sf::Time elapsed = clock.restart();

    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed)
            running = false;
        window.close();

    }

}

bool Game::isRunning() const {
    return running;
}
