#include "Item.h"

Item::Item(sf::Vector2f startPosition) {
	item.setPosition(startPosition);
	item.setSize(sf::Vector2f(32.f, 32.f));
}

sf::Vector2f Item::getPosition() {
	return item.getPosition();
}

void Item::draw(sf::RenderWindow& window) {
	window.draw(item);
}