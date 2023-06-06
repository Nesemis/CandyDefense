#include "game.h"

Game::Game() :
vecTextures(loadTextures()), 
mm(vecTextures),    
window(sf::VideoMode(1600, 900), "Candy defense"), 
running(true){
    window.setFramerateLimit(120);
};

//It's waay better to preload textures and then give a pointer to the assets objects 
//instead of loading a texture with every asset thats being created, that's why my concept shifted a little here
//
//And also, I initially wanted to use one texture for all tiles, 
//but I couldn't find the ones that inerested me the most,
//so I got to work with what I've got
std::vector<std::unique_ptr<sf::Texture>> Game::loadTextures() {
    std::vector<std::unique_ptr<sf::Texture>> temp;
    std::unique_ptr<sf::Texture> level1 = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> level2 = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> level3 = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> white = std::make_unique<sf::Texture>();// REMEMBER TO MENTION THE AUTHOR!!!: https://uchimama.itch.io/  
    std::unique_ptr<sf::Texture> milk = std::make_unique<sf::Texture>();// REMEMBER TO MENTION THE AUTHOR!!!: https://uchimama.itch.io/  
    std::unique_ptr<sf::Texture> strawberry = std::make_unique<sf::Texture>(); //REMEMBER TO MENTION THE AUTHOR!!!: https://uchimama.itch.io/  
    std::unique_ptr<sf::Texture> enemies = std::make_unique<sf::Texture>();
    std::unique_ptr<sf::Texture> towers = std::make_unique<sf::Texture>();
    
    if (!level1->loadFromFile("assets/1.png"))//checking if we loaded the assets
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!level2->loadFromFile("assets/2.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!level3->loadFromFile("assets/3.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!white->loadFromFile("assets/White Choco A.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!milk->loadFromFile("assets/Milk Choco A.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!strawberry->loadFromFile("assets/Strawberry Choco A.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!enemies->loadFromFile("assets/enemies.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!towers->loadFromFile("assets/enemies.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    temp.emplace_back(std::move(level1));
    temp.emplace_back(std::move(level2));
    temp.emplace_back(std::move(level3));
    temp.emplace_back(std::move(white));
    temp.emplace_back(std::move(milk));
    temp.emplace_back(std::move(strawberry));
    temp.emplace_back(std::move(enemies));
    temp.emplace_back(std::move(towers));
    return temp;
};
void Game::createLevel() {
    level = std::make_unique<Level>(vecTextures,mm.getLevel(),mm.getDif());
};

void Game::render() {
    window.clear(sf::Color::Black);
    level.get()->render(window);
    window.display();
}

void Game::update() {
    elapsed = clock.restart();
    sf::Event event;
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed)
        {
            running = false;
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                mouse_pos = sf::Mouse::getPosition(window);
                level.get()->update(mouse_pos, vecTextures);
            }
        }


    }
    level.get()->update(elapsed, vecTextures,mouse_pos);
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


