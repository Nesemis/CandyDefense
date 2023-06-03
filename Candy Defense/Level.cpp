#include "Level.h"
Level::Level(std::vector<std::unique_ptr<sf::Texture>>& textures) {
    path = {
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {2, 10}, {2, 11},
    {3, 11}, {4, 11},  {5, 11},  {6, 11}, {7, 11}, {8, 11}, {9, 11}, {10, 11},  {11, 11}, {12, 11}, {13, 11}, {14, 11}, {15, 11},  {16, 11}, {17, 11}, {18, 11}, {19, 11}, {20, 11},  {21, 11}, {22, 11},{23, 11},{24, 11},{25, 11},{26, 11},{27, 11},{28, 11},{29, 11},
    {29, 11}, {29, 10}, {29, 9}, {29, 8}, {29, 7}, {29, 6}, {29, 5}, {29, 4}, {29, 3}, {29, 2},
    {28, 2},{27, 2}, {26, 2}, {25, 2}, {24, 2}, {23, 2}, {22, 2}, {21, 2}, {20, 2}, {19, 2}, {18, 2}, {17, 2}, {16, 2}, {15, 2}, {14, 2}, {13, 2}, {12, 2}, {11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2},
    {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, 
    {6, 8}, {7, 8},{8, 8},{9,8}, {10, 8}, {11, 8}, {12, 8}, {13, 8},{14, 8},{15, 8},{16, 8},{17, 8},{18, 8},{19, 8},{20,8}, {21, 8},{22, 8},{23, 8},{24, 8}, {25, 8},{26, 8},
    {26, 8}, {26, 7}, {26, 6}, {26, 5}, {26, 5},
    {25, 5}, {24, 5}, {23, 5}, {22, 5}, {21,5}, {20, 5}, {19, 5}, {18, 5}, {17, 5}, {16, 5}, {15, 5}, {14,5}, {13, 5}, {12, 5}, {11, 5}, {10, 5}, 
  
    };
    vecTiles = makeTiles(textures);
};
std::vector<std::unique_ptr<Tile>> Level::makeTiles(std::vector<std::unique_ptr<sf::Texture>>& textures)
{
    std::vector<std::unique_ptr<Tile>> tiles;
    const int numTilesX = 1600 / Tile::TILE_SIZE;
    const int numTilesY = 700 / Tile::TILE_SIZE;
    int type = 0;
    for (int i = 0; i < numTilesX; i++) {
        for (int j = 0; j < numTilesY; j++) {
            int posX = i * Tile::TILE_SIZE;
            int posY = j * Tile::TILE_SIZE;
            type = 0;
            for (const auto& tilePos : path) {
                if (tilePos.first == i && tilePos.second == j) {
                    type = 1;
                    tiles.emplace_back(std::make_unique<Tile>(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)), type, textures[4]));
                    break;
                }
            }
            if (type == 0)
            {
                tiles.emplace_back(std::make_unique<Tile>(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)), type, textures[3]));
            }
           

        }
    }
    return tiles;
}
void Level::render(sf::RenderWindow& window) {
    for (const auto& tile : vecTiles) {
        window.draw(*tile);
    }

};
void Level::update(sf::Vector2i mouse_pos){

};