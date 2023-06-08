#pragma once
#include "Asset.h"

class Bullet : public Asset
{
public:
    Bullet(sf::Vector2f position, std::shared_ptr<sf::Texture> texture_ ,sf::Vector2f velocity, int damage);
    void update(sf::Time& elapsed);
    sf::Vector2f getPosition() const;
    int getDamage() const;

private:
    sf::Vector2f b_position;
    sf::Vector2f b_velocity;
    int b_damage;
};