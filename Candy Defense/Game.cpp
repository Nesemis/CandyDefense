#include "game.h"

Game::Game() :
vecTextures(loadTextures()), 
mm(vecTextures),    
window(sf::VideoMode(800, 600), "Candy defense"), 
running(true){
    window.setFramerateLimit(120);
};

//It's waay better to preload textures and then give a pointer to the assets objects 
//instead of loading a texture with every asset thats being created, that's why my concept shifted a little here
std::vector<std::unique_ptr<sf::Texture>> Game::loadTextures() {
    std::vector<std::unique_ptr<sf::Texture>> temp;
    std::unique_ptr<sf::Texture> level1 = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> level2 = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> level3 = std::make_unique<sf::Texture>();
    level1->loadFromFile("assets/1.png");
    level2->loadFromFile("assets/2.png");
    level3->loadFromFile("assets/3.png");
    temp.emplace_back(std::move(level1));
    temp.emplace_back(std::move(level2));
    temp.emplace_back(std::move(level3));
    return temp;
};

void Game::render() {
    window.clear(sf::Color::Black);
    window.display();

}

void Game::update() {
    sf::Event event;
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed)
        {
            running = false;
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            }
        }


    }

}

//Two methods here are for render & update mainMenu
//I found this divison of methods as neccesery , 
//becasue if we want to just have two methods in main loop, 
//that means we would need to check if the MainMenu exist or somehow,
//EVERY FRAME, so that would be unoptimal
//Istead, another while loop, just a bunch more lines of code, and it even adds more readibility
void Game::mainMenuRender() {
    window.clear(sf::Color::Black);
    mm.render(window);
    window.display();
};
void Game::mainMenuUpdate() {
    sf::Event event;
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
};
bool Game::isRunning() const {
    return running;
}
