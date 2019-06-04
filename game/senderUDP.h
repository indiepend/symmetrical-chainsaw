#include "stdafx.h"
#define PORT 16230
#pragma once

class senderUDP
{
	std::vector <sf::IpAddress> repicients;
	sf::UdpSocket clientSocket;
	sf::Packet actualPack;
public:
	void setUp();
	void addRepicient(sf::IpAddress adress);
	void removeRepicient(sf::IpAddress adress);
	void refresh(std::string animation, sf::Uint32 coordx, sf::Uint32 coordy);
	senderUDP();
	//~senderUDP();
};

