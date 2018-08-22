#include "stdafx.h"
#include "StringToFile.h"
#include <chrono>
#include <ctime>

#pragma once
class framecounter
{
	sf::Clock* clock;
	int tempfps, maxfps, minfps,avgfps;
	std::vector <int> delfps;
	bool temp=false;
public:
	void setup();
	void update();
	void draw(sf::RenderWindow* window, sf::Font *font);
	void createlog();
};

