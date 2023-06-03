#pragma once
#include "Asset.h"

class Tile : public Asset
{
public:
    static const int TILE_SIZE = 50;
    int type;
    
    Tile(sf::Vector2f position, int type, std::unique_ptr<sf::Texture>& texture);
    sf::Vector2f _getPosition() const;

};