#include "Asset.h"
struct eArgs
{
    int hp = 20;
    float e_speed = 200;
    int e_damage = 1;
    int coin_gain = 20;
};

class Enemy : public Asset
{
public:
    Enemy(eArgs args_, sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_, std::vector<std::pair<int, int>> turns, std::vector<std::pair<int, int>> turnP);
    void update(sf::Time& elapsed);
    bool hasReachedTarget() const;
    bool isDead() const;
    int getDamage() const;
    int getCoins() const;
    virtual ~Enemy() override {};
private:
    std::vector<std::pair<int, int>> turns; // vector of scalars to change the velocity
    std::vector<std::pair<int, int>> turnP; // vector of turn points for enemy to know where to turn
    eArgs args;
    bool reachedTarget = false;
    bool is_dead = false;
    int currentTurn = 0; // Int to know which velocity to take
    sf::IntRect textureRect;
    float getDistance(sf::Vector2f v1, sf::Vector2f v2);
};