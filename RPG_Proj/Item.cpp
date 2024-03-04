#include "Item.h"

Item::Item(sf::Vector2f startPosition, int index) {
	item.setPosition(startPosition);
	item.setSize(sf::Vector2f(32.f, 32.f));
	this->index = index;
}

sf::Vector2f Item::getPosition() {
	return item.getPosition();
}

void Item::draw(sf::RenderWindow& window) {
	window.draw(item);
}

void Item::setPosition(sf::Vector2f newPosition) {
	item.setPosition(newPosition);
}

sf::RectangleShape Item::getItem() {
	return item;
}

int Item::getIndex() {
	return index;
}
