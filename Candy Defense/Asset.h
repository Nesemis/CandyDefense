#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <functional>
class Asset : public sf::Sprite
{
public:
    Asset(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_);
    virtual void update(sf::Time& elapsed) {};
    void draw(sf::RenderWindow& window);
    virtual ~Asset() {};

    
};
