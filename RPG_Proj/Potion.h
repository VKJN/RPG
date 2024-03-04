#pragma once
#include "Item.h"

class Potion : public Item {
private:
	static sf::Texture texture;
	int healAmount = 20;
public:
	Potion(sf::Vector2f startPosition);
};