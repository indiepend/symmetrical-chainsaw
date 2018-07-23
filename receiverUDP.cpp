#include "receiverUDP.h"



void receiverUDP::setUp()
{
	clientSocket.unbind();
	if (clientSocket.bind(PORT) != sf::Socket::Done) {

	}
	clientSocket.setBlocking(false);
}

void receiverUDP::refresh()
{
	if (clientSocket.receive(tempPack, currentIp, port) != sf::Socket::Done) {

	}
	else {
		tempPack >> currentAnimation >> tempCoord.x >> tempCoord.y;
		tempPack.clear();
	}
}

sf::Vector2f receiverUDP::getCoords()
{
	return tempCoord;
}

std::string receiverUDP::getAnimation()
{
	return currentAnimation;
}

sf::IpAddress receiverUDP::getAdress()
{
	return currentIp;
}

receiverUDP::receiverUDP()
{
}