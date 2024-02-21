#include "Chest.h"

Chest::Chest(sf::Vector2f startPosition) : 
	Item(startPosition) {

	itemTexture.loadFromFile("./Image/Chest.png");
	item.setTexture(&itemTexture);
}