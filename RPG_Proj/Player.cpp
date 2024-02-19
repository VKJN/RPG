#include "Player.h"
#include "Map.h"
#include <iostream>

Player::Player(sf::Vector2f startPosition) {

	if (!texture.loadFromFile("./Image/Player.png")) std::cout << "texture not load";
	if (!inventoryTexture.loadFromFile("./Image/inventory.png")) std::cout << "texture not load";

	player.setTexture(&texture);
	inventory.setTexture(&inventoryTexture);

	inventory.setSize(sf::Vector2f(256.f, 64.f));
	inventory.setPosition(340, 400);

	player.setSize(sf::Vector2f(32.f, 32.f));
	player.setPosition(startPosition);
}

void Player::move(int direction) {
	// 1 - up; 2 - right; 3 - down; 4 - left
	switch (direction) {
	case 1:
		player.move(sf::Vector2f(0, -32));
		break;
	case 2:
		player.move(sf::Vector2f(32, 0));
		break;
	case 3:
		player.move(sf::Vector2f(0, 32));
		break;
	case 4:
		player.move(sf::Vector2f(-32, 0));
		break;
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}

void Player::drawInventory(sf::RenderWindow& window) {
	window.draw(inventory);
}

sf::Vector2f Player::getPosition() {
	return player.getPosition();
}