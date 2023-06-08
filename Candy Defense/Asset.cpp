#include "Asset.h"
Asset::Asset(sf::Vector2f position, std::shared_ptr<sf::Texture>& texture_) {
	this->setPosition(position);
	this->setTexture(std::move(*texture_));
};

void Asset::draw(sf::RenderWindow& window) {
	window.draw(*this);
};

