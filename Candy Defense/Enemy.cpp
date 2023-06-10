#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns_, std::vector<std::pair<int, int>> turnP_, int dif) :
    Asset(position, texture_),
    turns(turns_),
    turnP(turnP_)
{
    this->setScale(3.2f, 3.2f);
}

void Enemy::update(sf::Time& elapsed, std::vector<std::unique_ptr<Bullet>>& bullets)
{
    //In the first part we move the enemy
    //The enemy need to chceck on which turn it is currently, and then take the next turn
    sf::Vector2f velocity = sf::Vector2f(static_cast<float>(turns[currentTurn].first), static_cast<float>(turns[currentTurn].second));
    this->move(velocity*e_speed * elapsed.asSeconds()); 
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

    //In the second part the enemy checks if it was hit by bullet

    for (int i = 0; i < bullets.size(); i++) {
        if (this->getGlobalBounds().intersects(bullets[i].get()->getGlobalBounds())) {
            e_hp -= bullets[i].get()->getDamage();
            bullets.erase(bullets.begin() + i);
            i--;
            if (e_hp <= 0)
            {
                is_dead = true;
            }
        }
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
    return e_damage;
}

int Enemy::getCoins() const
{
    return coin_gain;
}

float Enemy::getDistance(sf::Vector2f v1, sf::Vector2f v2)
{
    return static_cast<float>(std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2)));
}

Enemy1::Enemy1(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif):
    Enemy(position, texture_, turns, turnP, dif)
{
    textureRect = sf::IntRect(65, 49, 14, 14);
    this->setTextureRect(textureRect);
    //BALANCE PLACE FOR THE ENEMY1 STATS
    e_hp = 3 + dif * (2* 0.5) + dif * 0.5;
    e_damage = 2+ dif * (2 * 0.5) + dif * 0.5;
    e_speed = 180 + dif * 40;
    coin_gain = 20 - dif * (20 * 0.3) - dif * 1;
}

Enemy2::Enemy2(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif) :
    Enemy(position, texture_, turns, turnP, dif)
{
    textureRect = sf::IntRect(65, 18, 16, 15);
    this->setTextureRect(textureRect);
    //BALANCE PLACE FOR THE ENEMY2 STATS
    e_hp = 2 + dif * (2* 0.5) + dif * 0.5;
    e_damage = 2 + dif * (2 * 0.5) + dif * 0.5;
    e_speed = 270 + dif * 50;
    coin_gain = 25 - dif * (25 * 0.3) - dif * 1;
}

Enemy3::Enemy3(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif) :
    Enemy(position, texture_, turns, turnP, dif)
{
    textureRect = sf::IntRect(64,33, 16, 16);
    this->setTextureRect(textureRect);
    //BALANCE PLACE FOR THE ENEMY3 STATS
    e_hp = 10 + dif * (10 * 0.5) + dif * 0.5;
    e_damage = 5 + dif * (5 * 0.5) + dif * 0.5;
    e_speed = 100 + dif * 25;
    coin_gain = 50 - dif * (50 * 0.3) - dif * 1;
}
