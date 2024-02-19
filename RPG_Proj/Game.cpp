#include "Game.h"
#include <Windows.h>

Game::Game()
	: window(sf::VideoMode(960, 640), "RPG game"),
	player(sf::Vector2f(9*32, 6*32)),
	map(960, 640)
{

}

void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerMoveDirection = 1;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerMoveDirection = 2;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerMoveDirection = 3;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerMoveDirection = 4;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			ActiveInventory = true;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			ActiveInventory = false;
		}

		else {
			playerMoveDirection = 0;
		}
	}
}

void Game::update(sf::Time deltaTime) {
	if (!ActiveInventory) {
		sf::Vector2f pPos = player.getPosition();

		switch (playerMoveDirection) {
		case 1:
			if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 1)
				player.move(1);
			break;
		case 2:
			if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 1)
				player.move(2);
			break;
		case 3:
			if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 1)
				player.move(3);
			break;
		case 4:
			if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 1)
				player.move(4);
			break;
		}

		Sleep(deltaTime.asSeconds());
	}
}

void Game::render() {

	window.clear();
	map.draw(window);
	player.draw(window);

	if (ActiveInventory) {
		player.drawInventory(window); 
	}

	window.display();
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		render();
	}
}