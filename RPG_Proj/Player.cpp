#include "Player.h"
#include "Player.h"
#include <iostream>

Player::Player() {

	player.setRadius(16.f);
	player.setPosition(440.f, 280.f);
	sf::Texture* texture = new sf::Texture;

	if (!texture->loadFromFile("./Image/Taylor.png")) std::cout << "texture not load";

	player.setTexture(texture);
	
}

void Player::move(sf::Vector2f movement) {
	player.move(movement);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}