#include "MainMenu.h"
MainMenu::MainMenu() {

    if (!kalam.loadFromFile("fonts/Kalam-Regular.ttf"))
    {
        std::cout << "Error loading Kalam Font!\n Make sure theres fonts file in the same file as main.cpp and theres Kalam-Regular.ttf in it!" << std::endl;
    }
    text1.setPosition(sf::Vector2f(500, 100));
    text1.setFont(kalam);
    text1.setString("Easy");
    text1.setOutlineColor(sf::Color::White);
    text2.setPosition(sf::Vector2f(500, 300));
    text2.setFont(kalam);
    text2.setString("Medium");
    text2.setOutlineColor(sf::Color::White);
    text3.setPosition(sf::Vector2f(500, 500));
    text3.setFont(kalam);
    text3.setString("Hard");
    text3.setOutlineColor(sf::Color::White);

}
void MainMenu::render(sf::RenderWindow &window) {
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);

}
void MainMenu::update(sf::Vector2i mouse_pos) {
    //Gra sprawdza, czy jest wciœniêta mysz
    //Jeœli jest, podaje obiektowi main menu pozycjê myszki
    //a on sprawdza jaki poziom trundoœci oraz planszê wybrano
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

}
