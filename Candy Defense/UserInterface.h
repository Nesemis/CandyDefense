#pragma once

#include "Asset.h"

class Button : public Asset {
public:
    Button(sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_, std::unique_ptr<sf::Font>&font_, std::string text);

    void Callback();
    void render(sf::RenderWindow& window);

private:
    sf::Text buttonText;
    std::function<void()> onClickCallback;
};


class UserInterface {
public:
    UserInterface(std::unique_ptr<sf::Texture>& texture_);
    void update(sf::Vector2i mouse_pos); // Update when the mouse is clicked
    void update(sf::Vector2i mouse_pos, int hp, int coins); // Update constant
    void render(sf::RenderWindow& window);
private:
    std::unique_ptr<sf::Font> font;
    std::vector<Button> buttons;
    bool placeModeOn =false;
    sf::RectangleShape placeRectangle;
    sf::RectangleShape background;
};
