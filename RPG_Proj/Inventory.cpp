#include "Inventory.h"

Inventory::Inventory(sf::Vector2f startPosition) {
	int x = slotCount * (sizeSlot.x + distanceBetweenSlots * 2);
	int y = sizeSlot.y + distanceBetweenSlots * 2;

	inventoryWindow.setSize(sf::Vector2f(x, y));
	inventoryWindow.setPosition(startPosition);
	inventoryWindow.setFillColor(sf::Color(0, 0, 0, 50));

	for (int i = 0; i < slotCount; i++) {
		sf::RectangleShape slot(sizeSlot);
		int slotX = startPosition.x + distanceBetweenSlots + (distanceBetweenSlots * 2 +  sizeSlot.x) * i;
		int slotY = startPosition.y + distanceBetweenSlots;

		slot.setPosition(sf::Vector2f(slotX, slotY));
		slot.setFillColor(sf::Color(0, 0, 0, 50));
		slots.push_back(slot);
	}
}

void Inventory::draw(sf::RenderWindow& window) {
	if (visible) {
		window.draw(inventoryWindow);
		for (auto i : slots) {
			window.draw(i);
		}
	}
}

void Inventory::changeVisible() {
	visible = !visible;
}