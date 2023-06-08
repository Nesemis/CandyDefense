#pragma once
#include "Asset.h"
class MainMenu{
public:
    MainMenu(std::vector<std::shared_ptr<sf::Texture>>& textures);
    void render(sf::RenderWindow& window);
    void update(sf::Vector2i mouse_pos);
    bool isRunning() const;
    int getLevel() const;
    int getDif() const;
private:
    sf::Font kalam;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    std::unique_ptr<Asset> level1;
    std::unique_ptr<Asset> level2;
    std::unique_ptr<Asset> level3;
    int dif = 0;
    int level= 1;
    bool running = true;
};