#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, std::shared_ptr<sf::Texture> texture, sf::Vector2f velocity, int damage):
    Asset(position,texture),
    b_velocity(velocity),
    b_damage(damage)
{
    this->setTextureRect(sf::IntRect(68, 80, 9, 8));
    this->setScale(2.5f, 2.5f);
}

void Bullet::update(sf::Time &elapsed)
{
    // Move the bullet with its velocity
    this->move(b_velocity*elapsed.asSeconds());
}


sf::Vector2f Bullet::getPosition() const
{
    return b_position;
}

int Bullet::getDamage() const
{
    return b_damage;
}