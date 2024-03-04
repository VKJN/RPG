#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerStats.h"

class Player {
private:
	sf::RectangleShape player;
	sf::Texture texture;

	PlayerStats stats;
public:
	Player(sf::Vector2f startPosition);
	void move(int direction);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void addHp(int hp);
	void removeHp(int hp);
	int getHp();
};