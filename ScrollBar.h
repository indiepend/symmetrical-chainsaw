#include "stdafx.h"
#pragma once

using namespace std;

class ScrollBar
{
public:
	void createScroll(int width, int height, sf::RenderWindow * window, sf::Color bg = sf::Color::Black, sf::Color ofScrollButton = sf::Color::White);
	//gives position of scroll 0.0 (start of scroll) - 1.0 (end point)
	float checkScrollPos(sf::Color color, sf::Vector2f mouse = sf::Vector2f(0, 0));
	void setBorder(int thickness, sf::Color colorOfBorder);

	ScrollBar();
};

