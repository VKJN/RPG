#include "Chest.h"

sf::Texture Chest::texture;

Chest::Chest(sf::Vector2f startPosition) : 
	Item(startPosition, 1) {

	texture.loadFromFile("./Image/Chest.png");
	item.setTexture(&texture);
}