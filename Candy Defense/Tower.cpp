#include "Tower.h"


int Tower::t_damage = 1;
float Tower::t_attackSpeed = 1;
float Tower::t_range = 150;
int Tower::t_price = 100;

Tower::Tower(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_ ):
    Asset(position,texture_)
{
    this->setScale(3.2f, 3.2f);
    this->setTextureRect(sf::IntRect(128, 0, 16, 16));
    texture_ptr = texture_;
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
            sf::Vector2f bulletVelocity = normalize(enemies[closestIndex].get()->getPosition() - bulletPos) *1000.0f;
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

