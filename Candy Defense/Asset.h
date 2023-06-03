#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
class Asset : public sf::Sprite
{
public:
    Asset(sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_);
    virtual void update(sf::Time& elapsed) {};
    virtual ~Asset() {};
protected:
    void draw(sf::RenderWindow& window);
    
};
