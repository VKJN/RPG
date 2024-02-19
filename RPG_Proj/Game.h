#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

class Game {
private:
	sf::RenderWindow window;
	Map map;
	Player player;

	int playerMoveDirection = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	bool ActiveInventory = false;

public:
	Game();
	void run();
};