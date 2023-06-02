#pragma once
#include "Asset.h"
class MainMenu{
public:
    MainMenu(std::vector<std::unique_ptr<sf::Texture>>& textures);
    void render(sf::RenderWindow& window);
    void update(sf::Vector2i mouse_pos);
    bool isRunning() const;
private:
    sf::Font kalam;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    Asset level1;
    Asset level2;
    Asset level3;
    int dif = 0;
    int level= 0;
    bool running = true;
};