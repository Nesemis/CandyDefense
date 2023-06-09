#include "UserInterface.h"

Button::Button( sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_ ,std::unique_ptr<sf::Font> &font_,  std::string text, TowerType towerPrice_)
    : Asset(position, texture_),
    towerPrice(towerPrice_){
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




void Button::render(sf::RenderWindow& window) {

    window.draw(*this);
    window.draw(buttonText);
}

TowerType Button::getTowerType()
{
    return towerPrice;
}


//UI


UserInterface::UserInterface(std::shared_ptr<sf::Texture>& texture_){
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

    // create buttons for UI

    buttons.emplace_back(sf::Vector2f(200, 720), texture_, font, "Candy Tower", TowerType::candyTower);
    buttons.emplace_back(sf::Vector2f(550, 720), texture_, font, "Bubblegum shot", TowerType::bubblegumShot);
    buttons.emplace_back(sf::Vector2f(900, 720), texture_, font, "Cane Blaster", TowerType::caneBlaster);
    buttons.emplace_back(sf::Vector2f(1250, 720), texture_, font, "Sweet Eraser", TowerType::sweetEraser);

    // create text to diplay, for only 4 buttons lets do it manually
    std::unique_ptr<sf::Text> hp = std::make_unique<sf::Text>();
    (*hp).setString("HP: 100");
    (*hp).setFont(*font);
    (*hp).setCharacterSize(30);
    (*hp).setFillColor(sf::Color::Red);
    (*hp).setPosition(sf::Vector2f(50,810));
    std::unique_ptr<sf::Text> coins = std::make_unique<sf::Text>();
    (*coins).setString("Coins: 100");
    (*coins).setFont(*font);
    (*coins).setCharacterSize(30);
    (*coins).setFillColor(sf::Color::Yellow);
    (*coins).setPosition(sf::Vector2f(50, 840));
    std::unique_ptr<sf::Text> waves = std::make_unique<sf::Text>();
    (*waves).setString("Wave: 1");
    (*waves).setFont(*font);
    (*waves).setCharacterSize(30);
    (*waves).setFillColor(sf::Color::Red);
    (*waves).setPosition(sf::Vector2f(1450, 810));
    std::unique_ptr<sf::Text> towerPrice = std::make_unique<sf::Text>();
    (*towerPrice).setString("100");
    (*towerPrice).setFont(*font);
    (*towerPrice).setCharacterSize(22);
    (*towerPrice).setFillColor(sf::Color::Yellow);
    sf::FloatRect textBounds = (*towerPrice).getLocalBounds();
    sf::Vector2f textPosition(buttons[0].getGlobalBounds().left + buttons[0].getGlobalBounds().width / 2.f - textBounds.width / 2.f,
        buttons[0].getGlobalBounds().top + buttons[0].getGlobalBounds().height / 2.f - textBounds.height / 2.f + buttons[0].getGlobalBounds().height);

    (*towerPrice).setPosition(sf::Vector2f(textPosition));

    std::unique_ptr<sf::Text> bubblegumPrice = std::make_unique<sf::Text>();
    (*bubblegumPrice).setString("300");
    (*bubblegumPrice).setFont(*font);
    (*bubblegumPrice).setCharacterSize(22);
    (*bubblegumPrice).setFillColor(sf::Color::Yellow);
    textBounds = (*bubblegumPrice).getLocalBounds();
    textPosition = sf::Vector2f(buttons[1].getGlobalBounds().left + buttons[1].getGlobalBounds().width / 2.f - textBounds.width / 2.f,
        buttons[1].getGlobalBounds().top + buttons[1].getGlobalBounds().height / 2.f - textBounds.height / 2.f + buttons[1].getGlobalBounds().height);

    (*bubblegumPrice).setPosition(sf::Vector2f(textPosition));

    std::unique_ptr<sf::Text> blasterPrice = std::make_unique<sf::Text>();
    (*blasterPrice).setString("500");
    (*blasterPrice).setFont(*font);
    (*blasterPrice).setCharacterSize(22);
    (*blasterPrice).setFillColor(sf::Color::Yellow);

    textBounds = (*blasterPrice).getLocalBounds();
    textPosition = sf::Vector2f(buttons[2].getGlobalBounds().left + buttons[2].getGlobalBounds().width / 2.f - textBounds.width / 2.f,
        buttons[2].getGlobalBounds().top + buttons[2].getGlobalBounds().height / 2.f - textBounds.height / 2.f + buttons[2].getGlobalBounds().height);

    (*blasterPrice).setPosition(sf::Vector2f(textPosition));

    std::unique_ptr<sf::Text> eraserPrice = std::make_unique<sf::Text>();
    (*eraserPrice).setString("1000");
    (*eraserPrice).setFont(*font);
    (*eraserPrice).setCharacterSize(22);
    (*eraserPrice).setFillColor(sf::Color::Yellow);

    textBounds = (*eraserPrice).getLocalBounds();
    textPosition = sf::Vector2f(buttons[3].getGlobalBounds().left + buttons[3].getGlobalBounds().width / 2.f - textBounds.width / 2.f,
        buttons[3].getGlobalBounds().top + buttons[3].getGlobalBounds().height / 2.f - textBounds.height / 2.f + buttons[3].getGlobalBounds().height);

    (*eraserPrice).setPosition(sf::Vector2f(textPosition));

    UItext.emplace_back(std::move(hp));
    UItext.emplace_back(std::move(coins));
    UItext.emplace_back(std::move(waves));
    UItext.emplace_back(std::move(towerPrice));
    UItext.emplace_back(std::move(bubblegumPrice));
    UItext.emplace_back(std::move(blasterPrice));
    UItext.emplace_back(std::move(eraserPrice));
}

void UserInterface::update(sf::Vector2i mouse_pos) {
    // The partial update (only when the player click
    // Search trough all buttons and if it was clicked turn on place mode
    int i = 0;
    for (i; i < buttons.size();i++) {
        if (buttons[i].getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)))
        {
            selectedTower = buttons[i].getTowerType();
            placeModeOn = true;
            break;
        };
        
    }
    if (i == buttons.size())
    {
        placeModeOn = false;
        //Place the rectangle or cancel the placement
    }
}
void UserInterface::update(sf::Vector2i mouse_pos, int& hp, int& coins, int&waves) {

    //Constantly update the position of mouse if its in place mode
    //At first, update the strings
    UItext[0].get()->setString("HP: " + std::to_string(hp));
    UItext[1].get()->setString("Coins: " + std::to_string(coins));
    UItext[2].get()->setString("Wave: " + std::to_string(waves+1));
    if (placeModeOn) {
        //Set position of the square to the tile where the mouse is on
        int x = mouse_pos.x - mouse_pos.x%50;
        int y = mouse_pos.y - mouse_pos.y%50;
        placeRectangle.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

}


bool UserInterface::getPlaceMode()
{
    return placeModeOn;
}

void UserInterface::render(sf::RenderWindow& window) {
    window.draw(background);
    for (auto& button : buttons) {
        button.render(window);
        
    }
    for (auto& text : UItext) {
        window.draw(*text);
    }
    if (placeModeOn) {
        window.draw(placeRectangle);
    }
}
