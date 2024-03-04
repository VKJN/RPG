#include "PlayerStats.h"

PlayerStats::PlayerStats() {
	healthBar.setSize(sf::Vector2f(320, 32));
	healthBar.setPosition(sf::Vector2f(0, 0));
	healthBar.setFillColor(sf::Color(175, 30, 75));
	healthBar.setOutlineColor(sf::Color::Black);
	healthBar.setOutlineThickness(2);

	bgHealthBar.setSize(sf::Vector2f(320, 32));
	bgHealthBar.setPosition(sf::Vector2f(0, 0));
	bgHealthBar.setFillColor(sf::Color(80, 30, 45));
	bgHealthBar.setOutlineColor(sf::Color::Black);
	bgHealthBar.setOutlineThickness(2);

	font.loadFromFile("./Fonts/arialbd.ttf");
	hpText.setFont(font);
	hpText.setFillColor(sf::Color::White);
	hpText.setString(std::to_string(hp) + " / 100");
	hpText.setPosition(sf::Vector2f(healthBar.getGlobalBounds().width / 3, healthBar.getGlobalBounds().height / 8));
	hpText.setCharacterSize(20);
	hpText.setOutlineThickness(2);
}

void PlayerStats::draw(sf::RenderWindow& window) {
	window.draw(bgHealthBar);
	window.draw(healthBar);
	window.draw(hpText);
}

int PlayerStats::getHealth() {
	return hp;
}

void PlayerStats::setHealth(int hp) {
	if (hp > 100) hp = 100;
	if (hp < 0) hp = 0;

	this->hp = hp;
	hpText.setString(std::to_string(hp) + " / 100");
	healthBar.setSize(sf::Vector2f(hp * 3.2, 32));
}