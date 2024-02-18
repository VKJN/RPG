#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

class Game {
private:
	sf::RenderWindow window;
	Map map;
	Player player;

	void processEvents();
	void update();
	void render();

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingLeft = false, mIsMovingRight = false;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

public:
	Game();
	void run();
};