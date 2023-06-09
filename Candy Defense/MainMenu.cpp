#include "MainMenu.h"
//In constructor, we pass the refrence to the vector of pointers to an texture to use for the level minatures
//It NEEDS to have an & sign here, because otherwise you would try to copy the vector,
//That attempt would try to copy the unique pointer, and it would result a compile error 
MainMenu::MainMenu(std::vector<std::shared_ptr<sf::Texture>>& textures) {
    level1 = std::make_unique<Asset>(sf::Vector2f(125, 30), textures[0]);
    level2 = std::make_unique<Asset>(sf::Vector2f(125, 230), textures[1]);
    level3 = std::make_unique<Asset>(sf::Vector2f(125, 430), textures[2]);
    if (!kalam.loadFromFile("fonts/Kalam-Regular.ttf"))//checking if we loaded the font
    {
        std::cout << "Error loading Kalam Font!\n Make sure theres fonts file in the same file as main.cpp and theres Kalam-Regular.ttf in it!" << std::endl;
    }
    //Text settings
    text1.setPosition(sf::Vector2f(500, 100));
    text1.setFont(kalam);
    text1.setString("Easy");
    text1.setOutlineColor(sf::Color::White);
    text1.setOutlineThickness(1.5); // Default difficulty graphics

    text2.setPosition(sf::Vector2f(500, 300));
    text2.setFont(kalam);
    text2.setString("Medium");
    text2.setOutlineColor(sf::Color::White);

    text3.setPosition(sf::Vector2f(500, 500));
    text3.setFont(kalam);
    text3.setString("Hard");
    text3.setOutlineColor(sf::Color::White);
    
    level1->setScale(0.7f, 0.7f);
    level2->setScale(0.7f, 0.7f);
    level3->setScale(0.7f, 0.7f);
    
}
void MainMenu::render(sf::RenderWindow &window) {
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(*level1);
    window.draw(*level2);
    window.draw(*level3);

}
void MainMenu::update(sf::Vector2i mouse_pos) {
    //The game check, if the mouse button has been pressed
    //If it has, it gives the object MainMenu the mouse position
    //and the object checks if it pressed the diff or the level
    if (text1.getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        dif = 0;
        text1.setOutlineThickness(1.5);
        text2.setOutlineThickness(0);
        text3.setOutlineThickness(0);
    };
    if (text2.getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        dif = 1;
        text1.setOutlineThickness(0);
        text2.setOutlineThickness(1.5);
        text3.setOutlineThickness(0);
    };
    if (text3.getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        dif = 2;
        text1.setOutlineThickness(0);
        text2.setOutlineThickness(0);
        text3.setOutlineThickness(1.5);
    };
    if (level1->getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        level = 1;
        running = false;
    };
    if (level2->getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        level = 2;
        running = false;
    };
    if (level3->getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
    {
        level = 3;
        running = false;
    };
}
bool MainMenu::isRunning() const {
    return running;
}
void MainMenu::setIsRunning(bool state) 
{
    running = state;
}
int MainMenu::getLevel() const {
    return level;
};
int MainMenu::getDif() const {
    return dif;
};