#pragma once
#include "Item.h"

class Coin : public Item {
private:
	static sf::Texture texture;
public:
	Coin(sf::Vector2f startPosition);
};