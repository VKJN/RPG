#pragma once
#include "Item.h"

class Chest : public Item {
private:
	static sf::Texture texture;
public:
	Chest(sf::Vector2f startPosition);
};