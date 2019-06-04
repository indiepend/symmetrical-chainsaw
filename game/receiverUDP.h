#include "stdafx.h"
#define PORT 16230
#pragma once
class receiverUDP
{
	sf::UdpSocket clientSocket;
	sf::Vector2f tempCoord;
	std::string currentAnimation;
	sf::IpAddress currentIp;
	sf::Packet tempPack;
	unsigned short port;
public:
	void setUp();
	void refresh();
	sf::Vector2f getCoords();
	std::string getAnimation();
	sf::IpAddress getAdress();
	receiverUDP();
	//~receiverUDP();
};
