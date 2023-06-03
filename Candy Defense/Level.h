#pragma once
#include "Asset.h"
#include "Tile.h"
class Level
{
public:
	Level(std::vector<std::unique_ptr<sf::Texture>>& textures);
	void render(sf::RenderWindow& window);
	void update(sf::Vector2i mouse_pos);
private:
	std::vector<std::pair<int, int>> path;
	std::vector<std::unique_ptr<Asset>> assets; // TUTAJ DODAJ WEKTOR WSZYSTKICH OBIEKTÓW GRY
	std::vector<std::unique_ptr<Tile>> makeTiles(std::vector<std::unique_ptr<sf::Texture>>& textures);
	std::vector<std::unique_ptr<Tile>> vecTiles;
	
	int hp = 100;
	int coins=0;
};

