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
		std::cout << "not connected" << std::endl;
		stat = serverSocket.connect(sf::IpAddress("127.0.0.1"), 33253);
	}
	else {
		std::cout << "connected" << std::endl;
	}
	connectPack << "connect";
	serverSocket.send(sf::Packet());
}

bool TCPconnector::lostConnect()
{
	return lostC;
}

bool TCPconnector::newConnect()
{
	return newC;
}

bool TCPconnector::receiveMessage(sf::Packet *msg)
{
	if (newMsg) {
		newMsg = false;
		(*msg) = message;
		message.clear();
		return true;
	}
	else {
		return false;
	}
}

void TCPconnector::sendMessage(std::string mess)
{
	sf::Packet temp;
	temp << "/message" << mess;
	serverSocket.send(temp);
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
	sf::Socket::Status stat=serverSocket.receive(pack);
	if (stat == sf::Socket::Status::Partial) {
		while (stat == sf::Socket::Status::Partial) {
			stat = serverSocket.receive(pack);
		}
	}
	if (stat == sf::Socket::Status::Done) {
		pack >> action;
		std::cout << action << std::endl;
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
		else if (action == "/message") {
			message = pack;
			newMsg = true;
		}
	}
}

void TCPconnector::disconnect()
{
	serverSocket.disconnect();
}

TCPconnector::TCPconnector()
{
}