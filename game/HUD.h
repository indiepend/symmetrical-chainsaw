#include "miernik.h"
#include "MiniMap.h"
#include "progressBar.h"
#include "Events.h"
#include "Chat.h"
#include "Network.h"
#include "framecounter.h"

#pragma once
class HUD
{
	sf::RenderWindow * okno = NULL;
	sf::RenderTarget *target;
	sf::View tempView;
	sf::Font forChat;
	miernik licznik;
	MiniMap mapka;
	progressBar lifePoints;
	Events *ARG_event;
	Chat *netChat;
	Network *ARG_net;
	framecounter counter;
public:
	HUD();
	void setUp(sf::RenderWindow * window, sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers = 1);
	void setEvents(Events*,Network*);
	void update(float Points);
	void netUpdate(float Points);
	void draw();
	void netDraw();

	void restart();
	void stop();
};

