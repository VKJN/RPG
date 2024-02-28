#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class SystemWindow {
private:
	sf::RectangleShape systemWindow;
	sf::Font font;
	sf::Text text;

	bool visible = false;
public:
	SystemWindow(sf::Vector2f startPosition);
	void draw(sf::RenderWindow& window);
	void setVisible(bool flag);
	void setText(std::string text);
	bool getVisible();
};