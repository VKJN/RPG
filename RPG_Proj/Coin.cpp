#include "Coin.h"

Coin::Coin(sf::Vector2f startPosition) :
	Item(startPosition) {

	itemTexture.loadFromFile("./Image/Coin.png");
	item.setTexture(&itemTexture);
}