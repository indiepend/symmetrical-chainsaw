#include "stdafx.h"
#include "Button.h"
#include "menu.h"
#include "settings.h"

#pragma once

using namespace std;

class inGame_Menu
{
	sf::Keyboard::Key C_key;
	sf::Font font;
	sf::RenderTexture T_bg;
	sf::RenderTexture heh;
	sf::Sprite * settsSprite;
	sf::Sprite yu;
	sf::Sprite bg;
	sf::RenderWindow *targetwindow=NULL;

	bool pause_B = false;
	bool load_B=true;
	bool drawIt = false;
	bool Setts = false;
	int ip = 1;

	settings * SettiesMenu;
	Button przycisk[3];
public:
	inGame_Menu();

	void inGameLoad(sf::RenderWindow *window);
	void inGameUpdate(sf::Vector2f cameraPosition, menu * Main_Menu, sf::Keyboard::Key key);
	void inGameDraw();

	bool pauseCheck(bool Escape);
	bool load();
	void setLoadFalse();
	//~inGame_Menu();
};

