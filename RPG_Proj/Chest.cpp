#include "Chest.h"

sf::Texture Chest::texture;

Chest::Chest(sf::Vector2f startPosition) : 
	Item(startPosition) {

	texture.loadFromFile("./Image/Chest.png");
	item.setTexture(&texture);
}