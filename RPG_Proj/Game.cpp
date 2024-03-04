#include "Game.h"
#include <Windows.h>

Game::Game()
	: window(sf::VideoMode(960, 640), "RPG game"),
	player(sf::Vector2f(9 * 32, 6 * 32)),
	map(960, 640),
	inventory(sf::Vector2f(10 * 32, 10 * 32)),
	systemWindow(sf::Vector2f(8 * 32, 15 * 32)),
	th(incrementer)
{
	vector<vector<int>> coords = map.getArrayCoordsByNum(2);
	for (auto el : coords) {
		items.push_back(Chest(sf::Vector2f(el[1] * 32, el[0] * 32)));
	}

	coords = map.getArrayCoordsByNum(3);
	for (auto el : coords) {
		items.push_back(Coin(sf::Vector2f(el[1] * 32, el[0] * 32)));
	}

	coords = map.getArrayCoordsByNum(4);
	for (auto el : coords) {
		items.push_back(Potion(sf::Vector2f(el[1] * 32, el[0] * 32)));
	}
}

Game::~Game() {
	th.join();
}

void Game::incrementer() {
	while (flag) {
		this_thread::sleep_for(chrono::milliseconds(100));
		value++;
		cout << value << endl;
	}
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

		else {
			playerMoveDirection = 0;
		}

		switch (event.type) {
		case sf::Event::KeyReleased:
			if (event.key.scancode == sf::Keyboard::Scan::I) {
				inventory.changeVisible();

				// not work
				/*if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					std::cout << "dasgfadsfhfdsgjfghkghkljjuk;";
					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
					vector<Item> it = inventory.getItems();
					for (int i = 0; i < it.size(); i++) {
						if (it[i].getItem().getGlobalBounds().contains(float(mousePosition.x), float(mousePosition.y))) {
							std::cout << "dasgfadsfhfdsgjfghkghkljjuk;";
							inventory.removeItem(i);
						}
					}
				}*/
			}

			// Проверка системного окна
			/*if (event.key.scancode == sf::Keyboard::Scan::P) {
				systemWindow.setText("full inventory");
				value = 0;
			}*/

			else if (event.key.scancode == sf::Keyboard::Scan::F) {

				// Дубляж, переделать
				if (checkNearbyItems()) {
					if (inventory.getCountItems() >= inventory.getSlotCount()) {
						systemWindow.setText("full inventory");
						value = 0;
						break;
					}

					sf::Vector2f pPos = player.getPosition();
					switch (lastFaced) {
					case 1:
						if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) > 1) {
							for (int i = 0; i < items.size(); i++) {
								if (items[i].getPosition().x == pPos.x && items[i].getPosition().y == pPos.y - 32) {
									inventory.addItem(items[i]);
									map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
									items.erase(items.begin() + i);
								}
							}
						}
						break;

					case 2:
						if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) > 1) {
							for (int i = 0; i < items.size(); i++) {
								if (items[i].getPosition().x == pPos.x + 32 && items[i].getPosition().y == pPos.y) {
									inventory.addItem(items[i]);
									map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
									items.erase(items.begin() + i);
								}
							}
						}
						break;

					case 3:
						if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) > 1) {
							for (int i = 0; i < items.size(); i++) {
								if (items[i].getPosition().x == pPos.x && items[i].getPosition().y == pPos.y + 32) {
									inventory.addItem(items[i]);
									map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
									items.erase(items.begin() + i);
								}
							}
						}
						break;

					case 4:
						if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) > 1) {
							for (int i = 0; i < items.size(); i++) {
								if (items[i].getPosition().x == pPos.x - 32 && items[i].getPosition().y == pPos.y) {
									inventory.addItem(items[i]);
									map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
									items.erase(items.begin() + i);
								}
							}
						}
						break;
					}
					break;
				}
				/*sf::Vector2f pPos = player.getPosition();
				switch (lastFaced) {
				case 1:
					if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x && items[i].getPosition().y == pPos.y - 32) {
								inventory.addItem(items[i]);
								map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;

				case 2:
					if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x + 32 && items[i].getPosition().y == pPos.y) {
								inventory.addItem(items[i]);
								map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;

				case 3:
					if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x && items[i].getPosition().y == pPos.y + 32) {
								inventory.addItem(items[i]);
								map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;

				case 4:
					if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x - 32 && items[i].getPosition().y == pPos.y) {
								inventory.addItem(items[i]);
								map.changeMask(items[i].getPosition().x / 32, items[i].getPosition().y / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;
				}
				break;*/
			}
		}
	}
}

void Game::update(sf::Time deltaTime) {
	sf::Vector2f pPos = player.getPosition();

	switch (playerMoveDirection) {
	case 1:
		if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 1 || map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 5)
			player.move(1);
		break;
	case 2:
		if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 1 || map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 5)
			player.move(2);
		break;
	case 3:
		if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 1 || map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 5)
			player.move(3);
		break;
	case 4:
		if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 1 || map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 5)
			player.move(4);
		break;
	}

	if (playerMoveDirection != 0) {
		lastFaced = playerMoveDirection;
	}

	if (map.getElementByPosition(pPos.x / 32, pPos.y / 32) == 5 && player.getHp() > 0) {
		if (value % 10 == 0) { 
			player.removeHp(5); 
		}
	}

	Sleep(deltaTime.asSeconds());
}

void Game::render() {

	window.clear();

	map.draw(window);
	player.draw(window);

	for (auto el : items) {
		el.draw(window);
	}

	inventory.draw(window);

	if (value < 20) {
		systemWindow.setVisible(true);
	}

	else {
		systemWindow.setVisible(false);
	}

	systemWindow.draw(window);

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

bool Game::checkNearbyItems() {
	sf::Vector2f pPos = player.getPosition();
	switch (lastFaced) {
	case 1:
		return map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) > 1;
		break;

	case 2:
		return map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) > 1;
		break;

	case 3:
		return map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) > 1;
		break;

	case 4:
		return map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) > 1;
		break;
	}
}

int Game::value = 100;
bool Game::flag = true;