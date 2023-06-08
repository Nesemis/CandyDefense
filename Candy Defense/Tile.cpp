#include "Tile.h"
void Tile::update(sf::Time& elapsed)
{

}
Tile::Tile(sf::Vector2f pos, int type, std::shared_ptr<sf::Texture>& texture_)
    : Asset(pos, texture_), type(type)
{
    this->setTextureRect(sf::IntRect(112, 48, 31, 31));
    this->setScale(TILE_SIZE / this->getGlobalBounds().height, TILE_SIZE / this->getGlobalBounds().width);
}


