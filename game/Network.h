#include "stdafx.h"
#include "TCPconnector.h"
#include "senderUDP.h"
#include "receiverUDP.h"
#include "FileToString.h"
#include "Enemy.h"

#pragma once
class Network
{
	TCPconnector TCPcon;
	senderUDP sUDP;
	receiverUDP rUDP;
	FileToString FtS;
	Enemy *ARG_enem;
public:
	enum setIt {
		Up = 1
	};
	void setUp();
	void refresh(std::string animation, sf::Vector2f coords);
	void connect(Enemy *enemy);
	void disconnect();
	sf::Vector2f getCoords();
	std::string getAnimation();
	sf::IpAddress getAdress();
	Network();
	Network(Network::setIt set);
	//~Network();
};

