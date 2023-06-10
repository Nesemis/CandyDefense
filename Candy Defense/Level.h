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
	Level(std::vector<std::shared_ptr<sf::Texture>>& textures, int level, int dif);
	void render(sf::RenderWindow& window);
	void update(sf::Keyboard::Key key, std::vector<std::shared_ptr<sf::Texture>>& textures);
	void update(sf::Vector2i mouse_pos, std::vector<std::shared_ptr<sf::Texture>>& textures);
	void update(sf::Time& elapsed, std::vector<std::shared_ptr<sf::Texture>>& textures, sf::Vector2i mouse_pos);
	bool getHasWon();
	bool getHasLost();
private:
	std::pair<int, int> base;
	std::vector<std::pair<int, int>> path; // path for the enemies to follow
	std::vector<std::pair<int, int>> turns; // Turn scalars  for the enemies pathfinding
	std::vector<std::pair<int, int>> turnPoints; // Turn points where enemies will change velocity
	std::vector<Wave> vecWaves;
	std::vector<std::unique_ptr<Tower>> vecTowers;
	std::vector<std::unique_ptr<Enemy>> vecEnemies;
	std::vector<std::unique_ptr<Tile>> vecTiles;
	std::vector<std::unique_ptr<Bullet>> vecBullets;
	UserInterface UI;
	void makeTiles(std::vector<std::shared_ptr<sf::Texture>>& textures);
	void makeTurns();
	void makeWaves();
	sf::Clock e_timer;
	int wave = 0;
	int hp = 100;
	int coins = 2000;
	int level = 1;
	int dif = 0;
	bool has_won = false;
	bool has_lost = false;
};

