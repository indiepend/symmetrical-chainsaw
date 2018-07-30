#include "stdafx.h"
#include "loadmap.h"
#include "Movin.h"
#include "HUD.h"
#include "Protagonist.h"
#include "Camera.h"
#include "menu.h"
#include "Filters.h"
#include "Animation.h"
#include "Enemy.h"
#include "Events.h"
#include "Sight.h"
#include "inGame_Menu.h"
#include "MusicPlayer.h"
#include "Network.h"
#include "networkEnemy.h"
#pragma once

class GameRun
{
	Sight wzrok;
	Filters *filtr = NULL;
	loadmap map;
	MusicPlayer BgMusic;
	HUD hud;
	inGame_Menu game_menu;
	Protagonist bohater;
	Enemy *wrogowie = NULL;
	Animation playerAnim, animacjePrzeciwnikow;
	Camera kamera;
	Network sieci;
	networkEnemy netEnem;
	sf::RenderWindow window;
	menu *meni;
	Events zdarzenia;

	std::thread *watek;

	int a = 1, b = 1, c = 1;
public:
	GameRun();
	void loadUp();
	void everything();
	void setMode();
	void update();
	void draw();
	~GameRun();
};

