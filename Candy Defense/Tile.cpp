#include "Tile.h"
Tile::Tile(sf::Vector2f pos, int type, std::unique_ptr<sf::Texture>& texture_)
    : Asset(pos, texture_), type(type)
{
    this->setTextureRect(sf::IntRect(112, 48, 31, 31));
    this->setScale(TILE_SIZE / this->getGlobalBounds().height, TILE_SIZE / this->getGlobalBounds().width);
}


sf::Vector2f Tile::_getPosition() const
{
    return this->getPosition();
}
