#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
	sf::CircleShape player;
public:
	Player();
	void move(sf::Vector2f movement);
	void draw(sf::RenderWindow& window);
};