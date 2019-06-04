#include "stdafx.h"
#include "Events.h"

#pragma once
class Chat
{
	std::vector <std::string> messages, senders;
	sf::Text message, sender,input;
	std::string inputMsg,sendMsg;
	sf::Font * ARG_font;
	sf::RenderTexture texture;
	sf::Sprite bg;
	sf::RectangleShape inputBox,background;
	sf::VertexArray quad;
	sf::Vertex quadVer[4];
	Events* ARG_events;
	bool Typing = false,sendReady=false;
public:
	Chat(sf::Font*);
	Chat();
	void setUp(sf::Font*, sf::IntRect, Events*);
	void update(sf::RenderWindow*);
	void addMsg(sf::Packet);
	void addMsg(std::string*);
	std::string pushMessage();
	bool isReady();
	void draw(sf::RenderTarget*);
};
