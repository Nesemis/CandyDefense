#pragma once
#include "Enemy.h"
#include "Asset.h"
#include "Bullet.h"
struct tArgs
{
    int damage = 5;
    float attackSpeed = 1; //seconds
    float range = 150; //Around 3 tiles of range

};

class Tower : public Asset
{
public:
    Tower(tArgs args, sf::Vector2f position,std::shared_ptr<sf::Texture>& texture);
    void update(std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<std::unique_ptr<Bullet>>& bullets);
    int getDamage() const;
    float getRange() const;
    float getAttackSpeed() const;

private:
    int t_damage;
    float t_attackSpeed;
    float t_range;
    sf::Clock t_fireTimer;
    std::shared_ptr<sf::Texture> texture_ptr;
    float getDistance(sf::Vector2f v1, sf::Vector2f v2);
    sf::Vector2f normalize(sf::Vector2f vector);
};