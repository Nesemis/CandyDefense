#pragma once
#include "Asset.h"
#include "Tile.h"
#include "UserInterface.h"
struct Wave {
	int e1=0;
	int e2=0;
	int e3=0;
	int coin_gain=0;
	float interval = 0;
};

class Level
{
public:
	Level(std::vector<std::shared_ptr<sf::Texture>>& textures, int dif);
	void render(sf::RenderWindow& window);
	void update(sf::Keyboard::Key key, std::vector<std::shared_ptr<sf::Texture>>& textures);
	void update(sf::Vector2i mouse_pos, std::vector<std::shared_ptr<sf::Texture>>& textures);
	void update(sf::Time& elapsed, std::vector<std::shared_ptr<sf::Texture>>& textures, sf::Vector2i mouse_pos);
	bool getHasWon();
	bool getHasLost();
	virtual ~Level() {};
protected:
	std::pair<int, int> base;
	std::vector<std::pair<int, int>> path; // path for the enemies to follow
	std::vector<std::pair<int, int>> turns; // Turn scalars  for the enemies pathfinding
	std::vector<std::pair<int, int>> turnPoints; // Turn points where enemies will change velocity
	std::vector<Wave> vecWaves;
	std::vector<std::unique_ptr<Tower>> vecTowers;
	std::vector<std::unique_ptr<Enemy>> vecEnemies;
	std::vector<std::unique_ptr<Tile>> vecTiles;
	std::vector<std::unique_ptr<Bullet>> vecBullets;
	std::vector<std::unique_ptr<Asset>> vecBackgroundSprites;
	UserInterface UI;
	void makeTiles(std::vector<std::shared_ptr<sf::Texture>>& textures);
	void makeTurns();
	virtual void makeWaves() = 0;
	virtual void makeScenery(std::vector<std::shared_ptr<sf::Texture>>& textures) = 0;
	sf::Clock e_timer;
	int wave = 0;
	int hp = 100;
	int coins = 400;
	int level = 1;
	int dif = 0;
	bool has_won = false;
	bool has_lost = false;
};

class Level1 : public Level
{
public:
	Level1(std::vector<std::shared_ptr<sf::Texture>>& textures, int dif);
	virtual void makeWaves();
	virtual void makeScenery(std::vector<std::shared_ptr<sf::Texture>>& textures);
	virtual ~Level1()override {};
};
class Level2 : public Level
{
public:
	Level2(std::vector<std::shared_ptr<sf::Texture>>& textures, int dif);
	virtual void makeWaves();
	virtual void makeScenery(std::vector<std::shared_ptr<sf::Texture>>& textures);
	virtual ~Level2()override {};
};
class Level3 : public Level
{
public:
	Level3(std::vector<std::shared_ptr<sf::Texture>>& textures, int dif);
	virtual void makeWaves();
	virtual void makeScenery(std::vector<std::shared_ptr<sf::Texture>>& textures);
	virtual ~Level3()override {};
};