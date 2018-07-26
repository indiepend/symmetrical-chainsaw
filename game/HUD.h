#include "miernik.h"
#include "MiniMap.h"
#include "progressBar.h"

#pragma once
class HUD
{
	sf::RenderWindow * okno = NULL;
	sf::RenderTarget *target;
	sf::View tempView;
	miernik licznik;
	MiniMap mapka;
	progressBar lifePoints;
public:
	HUD();
	void setUp(sf::RenderWindow * window, sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers = 1);
	void update(float Points);
	void draw();

	void restart();
	void stop();
	//~HUD();
};

