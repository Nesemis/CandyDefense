#include "Enemy.h"

Enemy::Enemy(eArgs args_, sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns_, std::vector<std::pair<int, int>> turnP_) :
    Asset(position, texture_),
    args(args_),
    turns(turns_),
    turnP(turnP_)
{
    
    textureRect = sf::IntRect(1, 49, 13, 13);
    this->setTextureRect(textureRect);
    this->setScale(3.60f,3.60f);
}

void Enemy::update(sf::Time& elapsed)
{
    //The enemy need to chceck on which turn it is currently, and then take the next turn

    sf::Vector2f velocity = sf::Vector2f(static_cast<float>(turns[currentTurn].first), static_cast<float>(turns[currentTurn].second));
    this->move(velocity*args.e_speed * elapsed.asSeconds()); 
    // here it needs to chceck if after the move it reached the turn and should currentTurn++
    float pos_x = this->getPosition().x;
    float pos_y = this->getPosition().y;
    if ((pos_x >= (static_cast<float>(turnP[currentTurn].first)*50) &&( velocity.x > 0))
    || (pos_x <= (static_cast<float>(turnP[currentTurn].first)*50) && (velocity.x < 0))
    || (pos_y <= (static_cast<float>(turnP[currentTurn].second)*50) && (velocity.y < 0))
    || (pos_y >= (static_cast<float>(turnP[currentTurn].second)*50) && (velocity.y > 0))
    ){ 
        currentTurn++;
    };
    // if the enemy colides with the base tile, change reached target to true
    sf::Vector2f base((static_cast<float>(turnP[7].first)+1)*50, (static_cast<float>(turnP[7].second)+1)*50);
    if (this->getGlobalBounds().intersects(sf::FloatRect(base, sf::Vector2f(50.0f, 50.0f))))
    {
        reachedTarget = true;
    }
    if (args.hp < 0)
    {
        is_dead = true;
    }
}





bool Enemy::hasReachedTarget() const
{
    return reachedTarget;
}

bool Enemy::isDead() const
{
    return is_dead;
}

int Enemy::getDamage() const
{
    return args.e_damage;
}

int Enemy::getCoins() const
{
    return args.coin_gain;
}

float Enemy::getDistance(sf::Vector2f v1, sf::Vector2f v2)
{
    return static_cast<float>(std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2)));
}
