#include "stdafx.h"
#pragma once

using namespace std;

class Events
{
	sf::Event zdarzenie;
	sf::Keyboard::Key key;
	string keycode;
	bool EscapeButtonPressed = false, inputText = false, EnterButtonPressed = false, BackspaceButtonPressed = false;
public:
	Events();
	bool isEscapePressed();
	bool isEnterPressed();
	bool isBackspacePressed();
	sf::Keyboard::Key returnKey();
	void Handler(sf::RenderWindow * window);
	bool getInput(string*);
};

