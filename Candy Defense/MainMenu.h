#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class MainMenu{
public:
    MainMenu();
    void render(sf::RenderWindow& window);
    void update(sf::Vector2i mouse_pos);
private:
    sf::Font kalam;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    int dif = 0;



};