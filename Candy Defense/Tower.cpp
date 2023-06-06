#include "Tower.h"


Tower::Tower(tArgs args, sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_ ):
    Asset(position,texture_)
{
    this->setScale(3.2f, 3.2f);
    this->setTextureRect(sf::IntRect(64, 1, 16, 16));
    t_damage = args.damage;
    t_attackSpeed = args.attackSpeed;
    t_range = args.range;
    t_fireTimer.restart();
}

void Tower::update(std::vector<std::unique_ptr<Enemy>>& enemies)
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
            t_fireTimer.restart();
        }
    }
}


int Tower::getDamage() const
{
    return t_damage;
}

float Tower::getRange() const
{
    return t_range;
}

float Tower::getAttackSpeed() const
{
    return t_attackSpeed;
}

float Tower::getDistance(sf::Vector2f v1, sf::Vector2f v2)
{
    return std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
}

