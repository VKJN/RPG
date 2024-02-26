#include "Potion.h"

sf::Texture Potion::texture;

Potion::Potion(sf::Vector2f startPosition) :
	Item(startPosition) {

	texture.loadFromFile("./Image/Potion1.png");
	item.setTexture(&texture);
}