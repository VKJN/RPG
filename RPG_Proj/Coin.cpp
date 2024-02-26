#include "Coin.h"

sf::Texture Coin::texture;

Coin::Coin(sf::Vector2f startPosition) :
	Item(startPosition) {

	texture.loadFromFile("./Image/Coin.png");
	item.setTexture(&texture);
}