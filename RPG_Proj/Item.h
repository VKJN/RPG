#pragma once
#include <SFML/Graphics.hpp>

class Item {
protected:
	sf::RectangleShape item;
	sf::Texture itemTexture;
	int index = 0;
public:
	Item(sf::Vector2f startPosition, int index);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f newPosition);

	sf::RectangleShape getItem();
	int getIndex();
};