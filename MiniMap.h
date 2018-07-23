#include "stdafx.h"
#pragma once

using namespace std;

class MiniMap
{
	sf::RenderWindow *targetWindow;
	sf::RenderTexture RT_MiniMap;
	sf::RenderTexture *RT_players;
	sf::RenderTexture *RT_collisable;
	sf::Sprite ST_MiniMap;
	sf::Sprite *ST_collisable;
	sf::Sprite *ST_players;
	sf::Sprite *ARG_collisable;
	sf::Sprite *ARG_players;
	sf::View minimapView,defaultView;
	sf::Vector2f tempPos = sf::Vector2f(0, 0);

	bool loadUpPlayer;
	int ARG_Howmany;
	int ARG_Howmanyplayers;
public:
	void create(sf::RenderWindow * wind, sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers = 1);
	void update();
	void draw();
	MiniMap();
	//~MiniMap();
};

