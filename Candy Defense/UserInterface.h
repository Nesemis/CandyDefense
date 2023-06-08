#pragma once
#include "Asset.h"
#include "Tower.h"


class Button : public Asset {
public:
    Button(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::unique_ptr<sf::Font>&font_, std::string text, TowerType tt);
    void render(sf::RenderWindow& window);
    TowerType getTowerType();
private:
    sf::Text buttonText;
    TowerType towerType;
};


class UserInterface {
public:
    UserInterface(std::shared_ptr<sf::Texture>& texture_);
    void update(sf::Vector2i mouse_pos); // Update when the mouse is clicked
    void update(sf::Vector2i mouse_pos, int& hp, int& coins); // Update constant
    void render(sf::RenderWindow& window);
    bool getPlaceMode();
    sf::RectangleShape placeRectangle;
    TowerType selectedTower;
private:
    std::unique_ptr<sf::Font> font;
    std::vector<std::unique_ptr<sf::Text>> UItext;
    std::vector<Button> buttons;
    bool placeModeOn =false;
    sf::RectangleShape background;
};
