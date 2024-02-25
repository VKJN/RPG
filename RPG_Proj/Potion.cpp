#include "Potion.h"

Potion::Potion(sf::Vector2f startPosition) :
	Item(startPosition) {

	itemTexture.loadFromFile("./Image/Potion.png");
	item.setTexture(&itemTexture);
}