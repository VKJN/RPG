#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

class Inventory  {
private:
	int slotCount = 5;
	sf::RectangleShape inventoryWindow;
	vector<sf::RectangleShape> slots;
	const sf::Vector2f sizeSlot = sf::Vector2f(50, 50);
	int distanceBetweenSlots = 5;
	bool visible = false;
public:
	Inventory(sf::Vector2f startPosition);
	void draw(sf::RenderWindow& window);
	void changeVisible();
};