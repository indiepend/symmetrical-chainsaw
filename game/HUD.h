#include "miernik.h"
#include "MiniMap.h"
#include "progressBar.h"
#include "Events.h"
#include "Chat.h"
#include "Network.h"
#include "framecounter.h"
#include "thread"

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


	std::thread* ss_thr;
	sf::Texture* ss_texture;
	void ss_internal(sf::Texture*);
public:
	HUD();
	void setUp(sf::RenderWindow * window, sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers = 1);
	void setEvents(Events*,Network*);
	void setEvents(Events*);
	void update(float Points);
	void netUpdate(float Points);
	void draw();
	void netDraw();
	void createlog();
	void makescreenshot();
	void restart();
	void stop();
};

