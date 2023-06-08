#pragma once
#include "Enemy.h"
#include "Asset.h"
#include "Bullet.h"
enum TowerType{
    candyTower = 100,
    bubblegumShot = 300,
    caneBlaster = 500,
    sweetEraser = 1000
};
class Tower : public Asset
{
public:
    Tower(sf::Vector2f position,std::shared_ptr<sf::Texture>& texture);
    void update(std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<std::unique_ptr<Bullet>>& bullets);
    int getDamage();
    float getRange();
    float getAttackSpeed();
    int getPrice();
protected:
    int t_damage=0;
    float t_attackSpeed=0;
    float t_range=0;
    int t_price=0;
    sf::Clock t_fireTimer;
    std::shared_ptr<sf::Texture> texture_ptr;
    float getDistance(sf::Vector2f v1, sf::Vector2f v2);
    sf::Vector2f normalize(sf::Vector2f vector);
};

class CandyTower : public Tower
{
public:
    CandyTower(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture);
};
class BubblegumShot : public Tower
{
public:
    BubblegumShot(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture);
};
class CaneBlaster : public Tower
{
public:
    CaneBlaster(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture);
};
class SweetEraser : public Tower
{
public:
    SweetEraser(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture);
};