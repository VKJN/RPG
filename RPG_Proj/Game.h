#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Inventory.h"
#include "Map.h"

#include "Item.h"
#include "Chest.h"
#include "Potion.h"
#include "Coin.h"

class Game {
private:
	sf::RenderWindow window;

	Map map;
	Inventory inventory;
	Player player;

	vector<Item> items;

	int playerMoveDirection = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

	void processEvents();
	void update(sf::Time deltaTime);
	void render();

public:
	Game();
	void run();
};