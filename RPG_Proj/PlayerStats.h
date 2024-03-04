#pragma once
#include <SFML/Graphics.hpp>

class PlayerStats {
private:
	sf::RectangleShape healthBar;
	sf::RectangleShape bgHealthBar;
	int hp = 100;
	sf::Text hpText;
	sf::Font font;
public:
	PlayerStats();
	void draw(sf::RenderWindow& window);
	int getHealth();
	void setHealth(int hp);
};