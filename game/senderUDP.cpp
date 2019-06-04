#include "senderUDP.h"



void senderUDP::setUp()
{
	clientSocket.unbind();
	if (clientSocket.bind(20146) != sf::Socket::Done)
	{
		// error...
	}
	clientSocket.setBlocking(false);
}

void senderUDP::addRepicient(sf::IpAddress adress)
{
	repicients.push_back(adress);
}

void senderUDP::removeRepicient(sf::IpAddress adress)
{
	for (int i = 0; i < repicients.size(); i++) {
		if (repicients[i] == adress) {
			repicients.erase(repicients.cbegin()+i-1);
			break;
		}
	}
}

void senderUDP::refresh(std::string animation, sf::Uint32 coordx, sf::Uint32 coordy)
{
	actualPack << animation << coordx << coordy;
	for (int i = 0; i < repicients.size(); i++) {
		clientSocket.send(actualPack, repicients[i], PORT);
	}
	actualPack.clear();
}

senderUDP::senderUDP()
{
}