#pragma once
#include "Asset.h"

class Tile : public Asset
{
public:
    void update(sf::Time& elapsed);
    Tile(sf::Vector2f position, int type, std::unique_ptr<sf::Texture>& texture);
    static const int TILE_SIZE = 50;
    int type;
    virtual ~Tile() override {};
};