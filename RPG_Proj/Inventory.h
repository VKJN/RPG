#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;

class Inventory  {
private:
	sf::RectangleShape inventoryWindow;

	vector<sf::RectangleShape> slots;
	vector<Item> items;

	const sf::Vector2f sizeSlot = sf::Vector2f(50, 50);

	int slotCount = 5;
	int distanceBetweenSlots = 5;
	bool visible = false;
public:
	Inventory(sf::Vector2f startPosition);
	void draw(sf::RenderWindow& window);
	void changeVisible();

	void addItem(Item item);
	void removeItem(int index);

	int getCountItems();
	int getSlotCount();

	vector<Item> getItems();
	bool getVisible();
};