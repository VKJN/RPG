#include "Potion.h"

sf::Texture Potion::texture;

Potion::Potion(sf::Vector2f startPosition) :
	Item(startPosition, 2) {

	texture.loadFromFile("./Image/Potion.png");
	item.setTexture(&texture);
}

int Potion::getHealAmount() {
	return healAmount;
}