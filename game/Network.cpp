#include "Network.h"

void Network::setUp()
{
	sUDP.setUp();
	rUDP.setUp();
	TCPcon.setUp(&sUDP);
	FtS.loadUp("serverAddress.txt");
}

void Network::refresh(std::string animation,sf::Vector2f coords)
{
	sUDP.refresh(animation, coords.x, coords.y);

	TCPcon.receive();
	if (TCPcon.newConnect()){
		int num;
		std::string str;
		sf::Packet tempPack = TCPcon.getNewCon();
		tempPack >> num;	
		for (int i = 0; i > num; i++) {
			tempPack >> str;
			(*ARG_enem).addEnemy(str);
		}
	}
	if (TCPcon.lostConnect()) {
		int num;
		std::string str;
		sf::Packet tempPack = TCPcon.getLostCon();
		tempPack >> num;
		for (int i = 0; i > num; i++) {
			tempPack >> str;
			(*ARG_enem).deleteEnemy(str);
		}
	}

	rUDP.refresh();
	(*ARG_enem).enemySets(rUDP.getAdress().toString(), &rUDP.getCoords(), &rUDP.getAnimation(), "networkEnemy");
}

void Network::connect(Enemy *enemy)
{
	ARG_enem = enemy;
	sf::IpAddress adress((*FtS.getString()));
	TCPcon.connect(adress);
}

void Network::disconnect()
{
	TCPcon.disconnect();
}

void Network::sendMessage(std::string msg)
{
	TCPcon.sendMessage(msg);
}

bool Network::receiveMessage(sf::Packet* pack)
{
	return TCPcon.receiveMessage(pack);
}

sf::Vector2f Network::getCoords()
{
	return rUDP.getCoords();
}

std::string Network::getAnimation()
{
	return rUDP.getAnimation();
}

sf::IpAddress Network::getAdress()
{
	return rUDP.getAdress();
}

Network::Network(Network::setIt set)
{
	sUDP.setUp();
	rUDP.setUp();
	TCPcon.setUp(&sUDP);
	FtS.loadUp("serverAddress.txt");
}

Network::Network()
{
}