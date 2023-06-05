#include "UserInterface.h"

Button::Button( sf::Vector2f position, std::unique_ptr<sf::Texture>& texture_ ,std::unique_ptr<sf::Font> &font_,  std::string text)
    : Asset(position, texture_) {
    this->setTextureRect(sf::IntRect(64, 48, 48, 16));
    this->setScale(3.5f, 3.5f);
    buttonText.setFont(*font_);
    buttonText.setCharacterSize(22);
    buttonText.setString(text);
    buttonText.setFillColor(sf::Color::Black);

    //Set the position of text to be at the center of the button
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    sf::Vector2f textPosition(position.x + this->getGlobalBounds().width / 2.f - textBounds.width / 2.f,
        position.y + this->getGlobalBounds().height / 2.f - textBounds.height / 2.f);
    buttonText.setPosition(textPosition);
}

void Button::Callback() {
    onClickCallback();
}

void Button::render(sf::RenderWindow& window) {

    window.draw(*this);
    window.draw(buttonText);
}


//UI


UserInterface::UserInterface(std::unique_ptr<sf::Texture>& texture_){
    font = std::make_unique<sf::Font>();
    background.setFillColor(sf::Color(139, 69, 19));
    background.setSize(sf::Vector2f(1580, 180));
    background.setPosition(10, 710);
    background.setOutlineColor(sf::Color(128, 0, 0));
    background.setOutlineThickness(10);
    if (!font->loadFromFile("fonts/Kalam-Regular.ttf"))//Check if we loaded the font
    {
        std::cout << "Error loading Kalam Font!\n Make sure theres fonts file in the same file as main.cpp and theres Kalam-Regular.ttf in it!" << std::endl;
    }

    placeRectangle.setFillColor(sf::Color::Green);
    placeRectangle.setSize(sf::Vector2f(50.f, 50.f));
    buttons.emplace_back(sf::Vector2f(200, 720), texture_, font, "Candy Tower");
    buttons.emplace_back(sf::Vector2f(500, 720), texture_, font, "Bubblegum shot");
        
    buttons.emplace_back(sf::Vector2f(800, 720), texture_, font, "Cane Blaster");
        
    buttons.emplace_back(sf::Vector2f(1100, 720), texture_, font, "Sweet Eraser");

}

void UserInterface::update(sf::Vector2i mouse_pos) {
    // The partial update (only when the player click
    // Search trough all buttons and if it was clicked turn on place mode
    int i = 0;
    for (i; i < buttons.size();i++) {
        if (buttons[i].getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
        {
            //Put the methods for this specific button
            placeModeOn = !placeModeOn;
            break;
        };
        
    }
    if (i == buttons.size())
    {
        placeModeOn = !placeModeOn;
        //Place the rectangle or cancel the placement
    }
}
void UserInterface::update(sf::Vector2i mouse_pos, int hp, int coins) {

    //Constantly update the position of mouse if its in place mode
    if (placeModeOn) {
        placeRectangle.setPosition(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
    }

}


void UserInterface::render(sf::RenderWindow& window) {
    window.draw(background);
    for (auto& button : buttons) {
        button.render(window);
        
    }
    if (placeModeOn) {
        window.draw(placeRectangle);
    }
}
