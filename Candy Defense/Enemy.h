#include "Asset.h"


class Enemy : public Asset
{
public:
    Enemy(sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_,int health, float speed, std::vector<std::pair<int,int>> turns, std::vector<std::pair<int, int>> turnP);
    void update(sf::Time& elapsed);
    bool hasReachedTarget() const;
    bool isDead() const;
    virtual ~Enemy() override {};
private:
    std::vector<std::pair<int, int>> turns; 
    std::vector<std::pair<int, int>> turnP;// vector of scalars to change the velocity
    int e_hp;
    float e_speed;
    bool reachedTarget = false;
    bool is_dead = false;
    int currentTurn = 0; // Int to know which velocity to take
    sf::IntRect textureRect;
    float getDistance(sf::Vector2f v1, sf::Vector2f v2);
};