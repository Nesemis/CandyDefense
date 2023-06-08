#pragma once
#include "Enemy.h"
#include "Asset.h"
#include "Bullet.h"
enum class TowerType {
    CandyTower,
    BubblegumShot,
    CaneBlaster,
    SweetEraser
};

class Tower : public Asset
{
public:
    Tower(sf::Vector2f position,std::shared_ptr<sf::Texture>& texture);
    void update(std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<std::unique_ptr<Bullet>>& bullets);
    static int getDamage() ;
    static float getRange() ;
    static float getAttackSpeed();
    static int getPrice();
private:
    static int t_damage;
    static  float t_attackSpeed;
    static float t_range;
    static int t_price;
    sf::Clock t_fireTimer;
    std::shared_ptr<sf::Texture> texture_ptr;
    float getDistance(sf::Vector2f v1, sf::Vector2f v2);
    sf::Vector2f normalize(sf::Vector2f vector);
};