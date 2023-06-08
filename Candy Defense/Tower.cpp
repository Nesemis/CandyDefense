#include "Tower.h"


Tower::Tower(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_ ):
    Asset(position,texture_)
{
    t_fireTimer.restart();
}

void Tower::update(std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<std::unique_ptr<Bullet>>& bullets)
{
    // shoot at the closest target
    if (t_fireTimer.getElapsedTime().asSeconds() >= t_attackSpeed) {
        // find the closest target
        float closestDistance = t_range;
        int closestIndex = -1;
        for (int i = 0; i < enemies.size(); i++) {
            float distance = getDistance(this->getPosition(), enemies[i].get()->getPosition());
            if (distance <= closestDistance) {
                closestDistance = distance;
                closestIndex = i;
            }
        }
     
        if (closestIndex != -1) {
            sf::Vector2f bulletPos = sf::Vector2f(this->getPosition().x+25,this->getPosition().y+25);
            sf::Vector2f bulletVelocity = normalize(enemies[closestIndex].get()->getPosition() - bulletPos) *1200.0f;
            bullets.emplace_back(std::make_unique<Bullet>(bulletPos, texture_ptr,bulletVelocity, t_damage ));
            t_fireTimer.restart();
        }
    }
}

sf::Vector2f Tower::normalize(sf::Vector2f vector)
{
    float length = std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
    if (length != 0) {
        return vector / length;
    }
    else {
        return vector;
    }
}

int Tower::getDamage() 
{
    return t_damage;
}

float Tower::getRange() 
{
    return t_range;
}

float Tower::getAttackSpeed() 
{
    return t_attackSpeed;
}

 int Tower::getPrice() 
{
    return t_price;
}

float Tower::getDistance(sf::Vector2f v1, sf::Vector2f v2)
{
    return std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
}

CandyTower::CandyTower(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture) :
    Tower(position, texture) {
    this->setScale(3.2f, 3.2f);
    this->setTextureRect(sf::IntRect(128, 0, 16, 16));
    texture_ptr = texture;
    t_damage = 1;
    t_attackSpeed = 1;
    t_range = 150;
    t_price = 100;
};
BubblegumShot::BubblegumShot(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture) :
    Tower(position, texture) {
    this->setScale(3.2f, 3.2f);
    this->setTextureRect(sf::IntRect(64, 1, 16, 16));
    texture_ptr = texture;
    t_damage = 2;
    t_attackSpeed = 1;
    t_range = 250;
    t_price = 300;
};
CaneBlaster::CaneBlaster(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture) :
    Tower(position, texture) {
    this->setScale(3.0f, 3.0f);
    this->setTextureRect(sf::IntRect(128, 80, 16, 16));
    texture_ptr = texture;
    t_damage = 3;
    t_attackSpeed = 0.5;
    t_range = 300;
    t_price = 1000;
};
SweetEraser::SweetEraser(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture) :
    Tower(position, texture) {
    this->setScale(3.0f, 3.0f);
    this->setTextureRect(sf::IntRect(64, 80, 16, 16));
    texture_ptr = texture;
    t_damage = 7;
    t_attackSpeed =0.5;
    t_range = 300;
    t_price = 1000;
};