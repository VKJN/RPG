#include "Map.h"
#include <iostream>

Map::Map(int width, int height)
	: backgroundTile(sf::Vector2f(width, height))
{
	sf::Texture* texture = new sf::Texture;
	if (!texture->loadFromFile("./image/map.png")) std::cout << "texture not load";

	backgroundTile.setTexture(texture);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			maskTiles[i][j].setSize(sf::Vector2f(32, 32));
			maskTiles[i][j].setFillColor(sf::Color((mask[i][j] == 1) ? sf::Color(0, 255, 0, 0) : sf::Color(0, 0, 255, 0)));
			maskTiles[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
		}
	}
}

int Map::getElementByPosition(int x, int y) {
	return mask[y][x];
}

void Map::draw(sf::RenderWindow& window) {
	window.draw(backgroundTile);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			window.draw(maskTiles[i][j]);
		}
	}
}

vector<vector<int>> Map::getArrayCoordsByNum(int num) {
	vector<vector<int>> coords;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			if (mask[i][j] == num) {
				vector<int> coord;
				coord.push_back(i);
				coord.push_back(j);
				coords.push_back(coord);
			}
		}
	}
	return coords;
}