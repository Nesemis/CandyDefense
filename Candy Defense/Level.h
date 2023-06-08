#pragma once
#include "Asset.h"
#include "Tile.h"
#include "UserInterface.h"
class Level
{
public:
	Level(std::vector<std::shared_ptr<sf::Texture>>& textures, int level, int dif);
	void render(sf::RenderWindow& window);
	void update(sf::Vector2i mouse_pos, std::vector<std::shared_ptr<sf::Texture>>& textures);
	void update(sf::Time& elapsed, std::vector<std::shared_ptr<sf::Texture>>& textures, sf::Vector2i mouse_pos);
private:
	std::pair<int, int> base;
	std::vector<std::pair<int, int>> path; // path for the enemies to follow
	std::vector<std::pair<int, int>> turns; // Turn scalars  for the enemies pathfinding
	std::vector<std::pair<int, int>> turnPoints; // Turn points where enemies will change velocity

	std::vector<std::unique_ptr<Tower>> vecTowers;
	std::vector<std::unique_ptr<Enemy>> vecEnemies;
	std::vector<std::unique_ptr<Tile>> vecTiles;
	std::vector<std::unique_ptr<Bullet>> vecBullets;
	UserInterface UI;
	void makeTiles(std::vector<std::shared_ptr<sf::Texture>>& textures);
	void makeTurns();
	sf::Clock e_timer;
	int enemies = 5;
	int hp = 100;
	int coins = 100;
	int level = 1;
	eArgs enemyArgs;
	tArgs towerArgs;
	int dif = 0;
};

