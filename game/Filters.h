#include "stdafx.h"
#include <ctime>
#pragma once

class Filters
{
	int ih = 0;
	int random;
	int scale;
	bool filterActive=false;
	sf::Vector2i pos;
	sf::Uint8* pixels = NULL;
	sf::RenderWindow * targetwindow = NULL;
	sf::Texture textr;
	sf::Sprite sprite;
public:
	void setNoctovision(sf::Vector2i size);
	void activeNoctovision(bool noct);
	void drawNoctovision(sf::Vector2f position);
	void setWindow(sf::RenderWindow * wind);
	Filters();
	//~Filters();
};

