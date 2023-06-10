#include "game.h"

Game::Game() :
vecTextures(loadTextures()), 
mm(vecTextures),    
window(sf::VideoMode(1600, 900), "Candy defense"), 
running(true){
    window.setFramerateLimit(120);
    srand(time(NULL));
};

//It's waay better to preload textures and then give a pointer to the assets objects 
//instead of loading a texture with every asset thats being created, that's why my concept shifted a little here
//
//And also, I initially wanted to use one texture for all tiles, 
//but I couldn't find the ones that inerested me the most,
//so I got to work with what I've got
std::vector<std::shared_ptr<sf::Texture>> Game::loadTextures() {
    std::vector<std::shared_ptr<sf::Texture>> temp;
    std::shared_ptr<sf::Texture> level1 = std::make_unique<sf::Texture>();
    std::shared_ptr<sf::Texture> level2 = std::make_unique<sf::Texture>();
    std::shared_ptr<sf::Texture> level3 = std::make_unique<sf::Texture>();
    std::shared_ptr<sf::Texture> white = std::make_unique<sf::Texture>();// REMEMBER TO MENTION THE AUTHOR!!!: https://uchimama.itch.io/  
    std::shared_ptr<sf::Texture> milk = std::make_unique<sf::Texture>();// REMEMBER TO MENTION THE AUTHOR!!!: https://uchimama.itch.io/  
    std::shared_ptr<sf::Texture> strawberry = std::make_unique<sf::Texture>(); //REMEMBER TO MENTION THE AUTHOR!!!: https://uchimama.itch.io/  
    std::shared_ptr<sf::Texture> enemies = std::make_unique<sf::Texture>();
    std::shared_ptr<sf::Texture> towers = std::make_unique<sf::Texture>();
    std::shared_ptr<sf::Texture> scenery = std::make_unique<sf::Texture>();
    
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
    if (!towers->loadFromFile("assets/towers.png"))
    {
        std::cout << "Error loading asset!\n Make sure theres assets file in the same file as Candy Defense.cpp and theres that asset in it!" << std::endl;
    }
    if (!scenery->loadFromFile("assets/scenery.png"))
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
    temp.emplace_back(std::move(scenery));
    return temp;
};
void Game::makeWS()
{
    sf::Clock WSClock;
    sf::Text WSText;
    sf::Font kalam;
    if (!kalam.loadFromFile("fonts/Kalam-Regular.ttf"))//checking if we loaded the font
    {
        std::cout << "Error loading Kalam Font!\n Make sure theres fonts file in the same file as main.cpp and theres Kalam-Regular.ttf in it!" << std::endl;
    }
    WSText.setPosition(sf::Vector2f(650, 300));
    WSText.setFont(kalam);
    WSText.setString("YOU WIN!");
    WSText.setOutlineColor(sf::Color::White);
    WSText.setCharacterSize(70);
    WSText.setOutlineThickness(1);
    WSClock.restart();
    while (WSClock.getElapsedTime().asSeconds() < 2)
    {
        window.clear(sf::Color::Black);
        window.draw(WSText);
        window.display();
    }
    level.reset();
    mm.setIsRunning(true);
}
void Game::makeLS()
{
    sf::Clock LSClock;
    sf::Text LSText;
    sf::Font kalam;
    if (!kalam.loadFromFile("fonts/Kalam-Regular.ttf"))//checking if we loaded the font
    {
        std::cout << "Error loading Kalam Font!\n Make sure theres fonts file in the same file as main.cpp and theres Kalam-Regular.ttf in it!" << std::endl;
    }
    LSText.setPosition(sf::Vector2f(650, 300));
    LSText.setFont(kalam);
    LSText.setString("GAME OVER");
    LSText.setOutlineColor(sf::Color::White);
    LSText.setCharacterSize(70);
    LSText.setOutlineThickness(1);
    LSClock.restart();
    while (LSClock.getElapsedTime().asSeconds() < 2)
    {
        window.clear(sf::Color::Black);
        window.draw(LSText);
        window.display();
    }
    level.reset();
    mm.setIsRunning(true);
}
void Game::createLevel() {
    level = std::make_unique<Level>(vecTextures,mm.getLevel(),mm.getDif());
};

void Game::render() {
    window.clear(sf::Color::Black);
    if (mm.isRunning())
    {
        mainMenuRender();
    }
    else if(level != nullptr)
    {
        level.get()->render(window);
    }
    window.display();
}

void Game::update() {
    if (!mm.isRunning() && level!=nullptr)
    {
        elapsed = clock.restart();
        sf::Event event;
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Keyboard::Key key;
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
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::C) {
                    key = sf::Keyboard::C;
                    level.get()->update(key, vecTextures);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::B) {
                    key = sf::Keyboard::B;
                    level.get()->update(key, vecTextures);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::T) {
                    key = sf::Keyboard::T;
                    level.get()->update(key, vecTextures);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::E) {
                    key = sf::Keyboard::E;
                    level.get()->update(key, vecTextures);
                }
            }
            


        }
        level.get()->update(elapsed, vecTextures, mouse_pos); 
        if (level.get()->getHasWon())
        {
            makeWS();
        }
        if (level !=nullptr&&level.get()->getHasLost())
        {
            makeLS();
        }
    }
    else if (level == nullptr&&mm.isRunning())
    {
        mainMenuUpdate();
    }
    else {
        createLevel();
    }
   
}

// I dont know how else could I check, and yet I want to the game to return to main menu
// So I did it the way i didn't itend to
void Game::mainMenuRender() {
    window.clear(sf::Color::Black);
    mm.render(window);
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


