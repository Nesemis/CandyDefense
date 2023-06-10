#include "Asset.h"
#include "Bullet.h"

class Enemy : public Asset
{
public:
    Enemy(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif);
    void update(sf::Time& elapsed, std::vector<std::unique_ptr<Bullet>>& bullets);
    bool hasReachedTarget() const;
    bool isDead() const;
    int getDamage() const;
    int getCoins() const;
    virtual ~Enemy() override {};
protected:
    std::vector<std::pair<int, int>> turns; // vector of scalars to change the velocity
    std::vector<std::pair<int, int>> turnP; // vector of turn points for enemy to know where to turn
    int e_hp = 1;
    float e_speed = 0;
    int e_damage = 0;
    int coin_gain = 0;
    bool reachedTarget = false;
    bool is_dead = false;
    int currentTurn = 0; // Int to know which velocity to take
    int currentFrame = 0; // Int to know which frame to display
    sf::IntRect textureRect;
    float getDistance(sf::Vector2f v1, sf::Vector2f v2);
    void updateAnimation(int time);
};
class Enemy1 : public Enemy
{
public:
    Enemy1(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif);
};
class Enemy2 : public Enemy
{
public:
    Enemy2(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif);
};
class Enemy3 : public Enemy
{
public:
    Enemy3(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP, int dif);
};