#include "TCPconnector.h"

void TCPconnector::setUp(senderUDP *udp)
{
	serverSocket.setBlocking(false);
	ARG_udp = udp;
}

void TCPconnector::connect(sf::IpAddress serverAdress)
{
	stat = serverSocket.connect(serverAdress, 33253);
	if (stat != sf::Socket::Done)
	{
		// error...
	}
	connectPack << "connect";
	serverSocket.send(connectPack);
}

bool TCPconnector::lostConnect()
{
	return lostC;
}

bool TCPconnector::newConnect()
{
	return newC;
}

sf::Packet TCPconnector::getNewCon()
{
	newCleaner clean(bool &newC, sf::Packet &newPack);
	return newPack;
}

sf::Packet TCPconnector::getLostCon()
{
	lostCleaner clean(bool &lostC, sf::Packet &lostPack);
	return lostPack;
}

void TCPconnector::receive()
{
	serverSocket.receive(pack);
	pack >> action;
	if (action == "add") {
		pack >> clients;
		for (int i = 0; i < clients; i++) {
			pack >> adress;
			sf::IpAddress ip(adress);
			(*ARG_udp).addRepicient(ip);
			newC = true;
		}
	}
	else if (action == "sub") {
		pack >> clients;
		for (int i = 0; i < clients; i++) {
			pack >> adress;
			sf::IpAddress ip(adress);
			(*ARG_udp).removeRepicient(ip);
			lostC = true;
		}
	}
	else if (action == "sets") {

	}
}

void TCPconnector::disconnect()
{
	serverSocket.disconnect();
}

TCPconnector::TCPconnector()
{
}

