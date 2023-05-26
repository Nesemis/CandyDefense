#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Candy Defense");

    window.setFramerateLimit(120);
   
    sf::Clock clock;

    while (window.isOpen()) {

        sf::Event event;
        sf::Time elapsed = clock.restart();

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}