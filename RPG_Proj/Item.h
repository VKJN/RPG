#pragma once
#include <SFML/Graphics.hpp>

class Item {
protected:
	sf::RectangleShape item;
	sf::Texture itemTexture;
public:
	Item(sf::Vector2f startPosition);
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f newPosition);
};