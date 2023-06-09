#include "Level.h"

Level::Level(std::vector<std::shared_ptr<sf::Texture>>& textures, int level_,int dif_):level(level_), dif(dif_),
UI(textures[3]){
    path = {
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {2, 10}, {2, 11},
    {3, 11}, {4, 11},  {5, 11},  {6, 11}, {7, 11}, {8, 11}, {9, 11}, {10, 11},  {11, 11}, {12, 11}, {13, 11}, {14, 11}, {15, 11},  {16, 11}, {17, 11}, {18, 11}, {19, 11}, {20, 11},  {21, 11}, {22, 11},{23, 11},{24, 11},{25, 11},{26, 11},{27, 11},{28, 11},{29, 11},
    {29, 11}, {29, 10}, {29, 9}, {29, 8}, {29, 7}, {29, 6}, {29, 5}, {29, 4}, {29, 3}, {29, 2},
    {28, 2},{27, 2}, {26, 2}, {25, 2}, {24, 2}, {23, 2}, {22, 2}, {21, 2}, {20, 2}, {19, 2}, {18, 2}, {17, 2}, {16, 2}, {15, 2}, {14, 2}, {13, 2}, {12, 2}, {11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2},
    {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, 
    {6, 8}, {7, 8},{8, 8},{9,8}, {10, 8}, {11, 8}, {12, 8}, {13, 8},{14, 8},{15, 8},{16, 8},{17, 8},{18, 8},{19, 8},{20,8}, {21, 8},{22, 8},{23, 8},{24, 8}, {25, 8},{26, 8},
    {26, 8}, {26, 7}, {26, 6}, {26, 5}, {26, 5},
    {25, 5}, {24, 5}, {23, 5}, {22, 5}, {21,5}, {20, 5}, {19, 5}, {18, 5}, {17, 5}, {16, 5}, {15, 5}, {14,5}, {13, 5}, {12, 5}, {11, 5}, {10, 5}
    };
    std::pair<int, int> v0 = { 0,1 }; //Thats the initial velocity for the enemy, CHANGE HERE TO BE ADEQUATE TO THE CREATED LEVEL(change makeTurns()?)
    base = { 7,4 }; // Thats the left up corner of the base, CHANGE HERE ADEQUATE TO THE CREATED LEVEL
    makeTiles(textures);
    turns.emplace_back(v0);
    makeTurns(); 
    turnPoints.emplace_back(base);
    makeWaves();
    e_timer.restart();
};
void Level::makeTiles(std::vector<std::shared_ptr<sf::Texture>>& textures)
{
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
                    vecTiles.emplace_back(std::make_unique<Tile>(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)), type, textures[4]));
                    break;
                }
            }
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                    if (base.first == i - m && base.second == j - n)
                    {
                        type = 2;
                        vecTiles.emplace_back(std::make_unique<Tile>(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)), type, textures[5]));
                        break;
                    }
            }
            if (type == 0)
            {
                vecTiles.emplace_back(std::make_unique<Tile>(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)), type, textures[3]));
            }
           

        }
    }
}
void Level::makeTurns() {
    //This function takes the whole path and finds the turns for the velocity vector
    //At first we take the diffrence of distance between two tiles
    //Then we check, if the diffrence between two next tiles didn't change
    //If it changed, we find out how it changed 
    //We need to take the turn points, as well as the how it will turn when enemy reaches the point
    int dx1 = path[1].first - path[0].first;
    int dy1 = path[1].second - path[0].second;

    for (size_t i = 2; i < path.size(); i++) {
        int dx2 = path[i].first - path[i - 1].first;
        int dy2 = path[i].second - path[i - 1].second;

        if (dx1 != dx2 || dy1 != dy2) {
            int dx = (dx2 != 0) ? dx2 / std::abs(dx2) : 0;
            int dy = (dy2 != 0) ? dy2 / std::abs(dy2) : 0;
            if (dx != 0 || dy != 0) {
                turns.emplace_back(dx, dy);
                turnPoints.emplace_back(path[i - 1].first, path[i - 1].second);
            }
        }
        dx1 = dx2;
        dy1 = dy2;
    }
    

}
void Level::makeWaves()
{
    vecWaves.emplace_back(Wave({ 5, 0, 0, 100 }));
    vecWaves.emplace_back(Wave({ 3, 1, 1, 200 }));
    vecWaves.emplace_back(Wave({ 3, 2, 2, 0 }));
};

void Level::update(sf::Vector2i mouse_pos, std::vector<std::shared_ptr<sf::Texture>>& textures_){
    //This update is called when the game notices the player input, it is only called in event section 
    //IT WORKS ONLY ON CLICK
    if (UI.getPlaceMode())
    {

        for (auto it = vecTiles.begin(); it != vecTiles.end(); it++) {
            sf::FloatRect tileDim = (*it).get()->getGlobalBounds();
            // Check if you can put a tower here

            switch (UI.selectedTowerP) {
            case candyTowerP:
                if (100 <= coins && (*it).get()->type == 0 && tileDim.contains(sf::Vector2f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))) {
                    coins -= 100;
                    vecTowers.emplace_back(std::make_unique<CandyTower>(sf::Vector2f(tileDim.left, tileDim.top), textures_[7]));
                }
                break;
            case bubblegumShotP:
                if (300 <= coins && (*it).get()->type == 0 && tileDim.contains(sf::Vector2f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))) {
                    coins -= 300;
                    vecTowers.emplace_back(std::make_unique<BubblegumShot>(sf::Vector2f(tileDim.left, tileDim.top), textures_[7]));
                }
                break;
            case caneBlasterP:
                if (500 <= coins && (*it).get()->type == 0 && tileDim.contains(sf::Vector2f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))) {
                    bool allGreen = true;
                    for (int i = 0; i < caneBlasterS; i++) {
                        for (int j = 0; j < caneBlasterS; j++) {
                            //The same logic but with 3  tiles
                            int index = it - vecTiles.begin() + (i * 14) + j;
                            if (index < vecTiles.size())
                            {
                                auto tile_it = it + (i * 14) + j;
                                if (((*tile_it).get()->type != 0)|| j!=0 && index %14 ==0) { // check if we go on the UI
                                    allGreen = false;
                                    break;
                                }
                            }
                            else {
                                allGreen = false;
                                break;
                            }
                        }
                        if (!allGreen) {
                            break;
                        }
                    }
                    if (allGreen) {
                        coins -= 500;
                        vecTowers.emplace_back(std::make_unique<CaneBlaster>(sf::Vector2f(tileDim.left, tileDim.top), textures_[7]));
                    }
                }
                break;
            case sweetEraserP:
                if (1000 <= coins && (*it).get()->type == 0 && tileDim.contains(sf::Vector2f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))) {
                    bool allGreen = true;
                    for (int i = 0; i < sweetEraserS; i++) {
                        for (int j = 0; j < sweetEraserS; j++) {
                            //The same logic but with 3  tiles
                            int index = it - vecTiles.begin() + (i*14) + j;
                            if (index < vecTiles.size())
                            {
                                auto tile_it = it + (i * 14) + j;
                                if (((*tile_it).get()->type != 0) || j != 0 && index % 14 == 0) {
                                    allGreen = false;
                                    break;
                                }
                            }
                            else {
                                allGreen = false;
                                break;
                            }
                        }
                        if (!allGreen) {
                            break;
                        }
                    }
                    if (allGreen) {
                        coins -= 1000;
                        vecTowers.emplace_back(std::make_unique<SweetEraser>(sf::Vector2f(tileDim.left, tileDim.top), textures_[7]));
                    }
                }
                break;
            }
        }
    }
    UI.update(mouse_pos);
    
};
void Level::update(sf::Time &elapsed, std::vector<std::shared_ptr<sf::Texture>>& textures, sf::Vector2i mouse_pos_) {
    //Update every frame
    UI.update(mouse_pos_, hp, coins,wave);
    //Spawn enemies every 2 seconds until you've reached the end of wave enemies counter
    int interval = 2;
    //Optimize randomness to not random the enemy that wont spawn in this wave
    int randomEnemy = 0;
    int nonZeroEnemiesCount = 0;

    if (vecWaves[wave].e1 != 0) {
        nonZeroEnemiesCount++;
    }
    if (vecWaves[wave].e2 != 0) {
        nonZeroEnemiesCount++;
    }
    if (vecWaves[wave].e3 != 0) {
        nonZeroEnemiesCount++;
    }

    if (nonZeroEnemiesCount > 0) {
        int randomIndex = rand() % nonZeroEnemiesCount;

        do {
            randomEnemy++;
            if (vecWaves[wave].e1 != 0 && randomEnemy == 1) {
                randomIndex--;
            }
            if (vecWaves[wave].e2 != 0 && randomEnemy == 2) {
                randomIndex--;
            }
            if (vecWaves[wave].e3 != 0 && randomEnemy == 3) {
                randomIndex--;
            }
        } while (randomIndex >= 0);
    }
    else if (wave < vecWaves.size()-1){
        coins += vecWaves[wave].coin_gain;
        wave++;
    }
    else if(vecEnemies.empty())
    {
        std::cout << "YOU WIN!\n";
    }





    //Spawn the random enemy
    switch (randomEnemy) {
    case 0: e_timer.restart();
    case 1: if (e_timer.getElapsedTime().asSeconds() >= interval) {
        vecWaves[wave].e1--;
        vecEnemies.emplace_back(std::make_unique<Enemy1>(sf::Vector2f(100, 0), textures[6], turns, turnPoints, dif));
        e_timer.restart();
        break;
    }
   case 2: if (e_timer.getElapsedTime().asSeconds() >= interval ) {
        vecWaves[wave].e2--;
        vecEnemies.emplace_back(std::make_unique<Enemy2>(sf::Vector2f(100, 0), textures[6], turns, turnPoints, dif));
        e_timer.restart();
        break;
    }
    case 3: if (e_timer.getElapsedTime().asSeconds() >= interval ) {
        vecWaves[wave].e3--;
        vecEnemies.emplace_back(std::make_unique<Enemy3>(sf::Vector2f(100, 0), textures[6], turns, turnPoints, dif));
        e_timer.restart();
        break;
    }
    }

    // here we update the enemy 
    
    for (auto it = vecEnemies.begin(); it != vecEnemies.end(); ) {
    // If it reached the base, subtract hp
            (*it)->update(elapsed,vecBullets);
            if((*it)->hasReachedTarget()) {
                 hp -= (*it)->getDamage();
                 if (hp < 0)
                 {
                     // Do something here if the player looses 
                     break;
                 }
            it = vecEnemies.erase(it);
            }
            //if it is dead, add coins
            else if ((*it)->isDead())
            {
            coins += (*it)->getCoins();
            it = vecEnemies.erase(it);
            }
            else
            {
                it++;
            }
    }
    //Control the place rectangle
    if (UI.getPlaceMode())
    {
        for (auto it = vecTiles.begin(); it != vecTiles.end(); ++it)
        {
            sf::FloatRect tileDim = (*it).get()->getGlobalBounds();
            bool allGreen = true;
           for (int i = 0; i < UI.selectedTowerS; i++) {
                for (int j = 0; j < UI.selectedTowerS; j++) {
                    int index = (it - vecTiles.begin()) + (i * 14) + j;
                    if (index < vecTiles.size())
                    {
                        auto tile_it = it + (i * 14) + j ;
                        if (((*tile_it).get()->type != 0) || j != 0 && index % 14 == 0) { // check if we go on the UI
                            allGreen = false;
                            break;
                        }
                    }
                    else
                    {
                        allGreen = false;
                        break;
                    }
                }
            }
            if (UI.selectedTowerP <= coins && allGreen && tileDim.contains(sf::Vector2f(static_cast<float>(mouse_pos_.x), static_cast<float>(mouse_pos_.y))))
            {
                UI.placeRectangle.setSize(sf::Vector2f(50*UI.selectedTowerS,50 * UI.selectedTowerS));
                UI.placeRectangle.setFillColor(sf::Color::Green);
                break;
            } // If we have no money and we are on tile where we can put the tower OR if we are on the tile where we cannot put towers, change color to red
            else if (((UI.selectedTowerP > coins && allGreen )||
                (!allGreen) )&& tileDim.contains(sf::Vector2f(static_cast<float>(mouse_pos_.x), static_cast<float>(mouse_pos_.y))) )
            {
                UI.placeRectangle.setSize(sf::Vector2f(50 * UI.selectedTowerS, 50 * UI.selectedTowerS));
                UI.placeRectangle.setFillColor(sf::Color::Red);
                break;
            }
            else
            {
                UI.placeRectangle.setSize(sf::Vector2f(0, 0));
            }
      
        };
    };
    //Here we update the bullets
    for (auto it = vecBullets.begin(); it != vecBullets.end(); ) {

        (*it)->update(elapsed);
        if (!it->get()->getGlobalBounds().intersects(sf::FloatRect(0, 0, 1600, 900))) 
            it = vecBullets.erase(it);
        else
            it++;
    }
    // here we update the towers
    for (auto it = vecTowers.begin(); it != vecTowers.end(); ) {

        (*it)->update(vecEnemies, vecBullets);
        it++;
    }

    

};
void Level::render(sf::RenderWindow& window) {
    //All assets are derived form a single class, so they all use the same method, convenient
    for (const auto& tile : vecTiles) {
        tile.get()->draw(window);
    }
    for (const auto& enemy : vecEnemies) {
        enemy.get()->draw(window);
    }
    for (const auto& tower : vecTowers) {
        tower.get()->draw(window);
    }
    for (const auto& bullet : vecBullets) {
        bullet.get()->draw(window);
    }
    UI.render(window);
};