#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <memory>
class Asset : public sf::Sprite
{
public:
    Asset();
    Asset(sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_);

    virtual ~Asset() {};
protected:

    void draw(sf::RenderWindow& window);
};
