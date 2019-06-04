#include "stdafx.h"

#include "Button.h"
#include "FileToString.h"
#include "StringToFile.h"
#include "Key.h"
#pragma once

class settings
{
	sf::RenderWindow * targetwindow = NULL;
	sf::RenderTexture gray_S;
	sf::RenderTexture rt_S;
	sf::Sprite Sgray_S;
	sf::Sprite bg_S;
	sf::Text text_S;
	sf::Keyboard::Key keyBOARD[6];
	sf::Text setts[10];
	sf::Text otherSets[10];
	sf::Font * font = NULL;

	string * ustawienia;
	int	ip = 0;
	int anotherBagOfInts;
	bool clicked_S, change = false,inGame=false;

	Button powrot;
	Button sterowanie[6];
	FileToString loader;
	StringToFile writer;
	Key keyString;
public:
	void drawSettings();
	void updateSettings(sf::Keyboard::Key key, bool inGame=false);
	void loadSettings(sf::RenderWindow * window,sf::Font * fonts);
	sf::Keyboard::Key * getSetts();
	sf::Sprite * getSs();
	int getIp();
	void setIp(int Ip);

	settings();
	//~settings();
};