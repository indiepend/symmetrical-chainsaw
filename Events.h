#include "stdafx.h"
#pragma once

using namespace std;

class Events
{
	sf::Event zdarzenie;
	sf::Keyboard::Key key;
	string keycode;
	bool EscapeButtonPressed=false;
public:
	Events();
	bool isEscapePressed();
	sf::Keyboard::Key returnKey();
	void Handler(sf::RenderWindow * window);

};

