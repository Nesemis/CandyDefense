#pragma once
#include "Asset.h"
#include "Tile.h"
#include "Enemy.h"
class Level
{
public:
	Level(std::vector<std::unique_ptr<sf::Texture>>& textures, int level, int dif);
	void render(sf::RenderWindow& window);
	void update(sf::Vector2i mouse_pos);
	void update(sf::Time& elapsed, std::vector<std::unique_ptr<sf::Texture>>& textures);
private:
	std::pair<int, int> base;
	std::vector<std::pair<int, int>> path; // path for the enemies to follow
	std::vector<std::pair<int, int>> turns; // Turn scalars  for the enemies pathfinding
	std::vector<std::pair<int, int>> turnPoints; // Turn points where enemies will change velocity
	std::vector<std::unique_ptr<Asset>> vecAssets; // Vector of every future enemy, tile, bullet and tower
	void makeTiles(std::vector<std::unique_ptr<sf::Texture>>& textures);
	void makeTurns();
	sf::Clock e_timer;
	int enemies = 5;
	int hp = 100;
	int coins = 0;
	int level = 1;
	eArgs enemyArgs;
	int dif = 0;
};

