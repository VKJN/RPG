#pragma once
#include "Item.h"

class Potion : public Item {
private:
	static sf::Texture texture;
public:
	Potion(sf::Vector2f startPosition);
};