#include "stdafx.h"
#include "senderUDP.h"

#pragma once
class TCPconnector
{
	struct lostCleaner {
		bool *ARG_lostC;
		sf::Packet *ARG_lostPack;
		lostCleaner(bool *lostC,sf::Packet *lostPack) {

		}
		~lostCleaner() {
			(*ARG_lostC) = false;
			(*ARG_lostPack).clear();
		}
	};
	struct newCleaner {
		bool *ARG_newC;
		sf::Packet *ARG_newPack;
		newCleaner(bool *newC, sf::Packet *newPack) {

		}
		~newCleaner() {
			(*ARG_newC) = false;
			(*ARG_newPack).clear();
		}
	};
	sf::TcpSocket serverSocket;
	sf::Socket::Status stat;
	sf::Packet connectPack;
	sf::Packet pack;
	sf::Packet newPack,lostPack;
	sf::Uint32 clients, adress;
	std::string action;
	senderUDP *ARG_udp;
	bool lostC=false, newC=false;
public:
	void setUp(senderUDP *udp);
	void connect(sf::IpAddress serverAdress);
	bool lostConnect();
	bool newConnect();
	sf::Packet getNewCon();
	sf::Packet getLostCon();
	void receive();
	void disconnect();
	TCPconnector();
};

