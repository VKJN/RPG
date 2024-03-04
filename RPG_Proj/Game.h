#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Inventory.h"
#include "Map.h"
#include "SystemWindow.h"

#include "Item.h"
#include "Chest.h"
#include "Potion.h"

class Game {
private:
	sf::RenderWindow window;

	Map map;
	Inventory inventory;
	Player player;
	SystemWindow systemWindow;

	vector<Item> items;

	int lastFaced = 0; // 1 - up; 2 - right; 3 - down; 4 - left
	int playerMoveDirection = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

	static bool flag;
	static int value;
	thread th;
	void static incrementer();

	void processEvents();
	void update(sf::Time deltaTime);
	void render();
public:
	Game();
	~Game();
	void run();
	bool checkNearbyItems();
};