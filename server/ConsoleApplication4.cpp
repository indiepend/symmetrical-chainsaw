#include "stdafx.h"
#include <iostream>
#include <SFML/Network.hpp>
#define PORT 36424

///SERVER APP 0.0.1
int main() {
	std::cout << "server ver. 0.0.1" << std::endl;
	int socQ=0;
	sf::TcpSocket *tempsock = new sf::TcpSocket;
	std::string message="",command="";
	std::vector <sf::TcpSocket*> socket;
	socket.push_back(tempsock);
	std::vector <sf::IpAddress> addresses;
	sf::Packet mapPack, ipPack, msgPack;
	mapPack << "sets";
	sf::TcpListener listener;

	listener.setBlocking(false);
	if (listener.listen(33253) != sf::Socket::Done){

	}

	while (1) {///main loop
		///check for new client
		if (listener.accept(*socket[socQ]) == sf::Socket::Done) {
			std::cout << "connected " <<(*socket[socQ]).getRemoteAddress() << std::endl;
			(*socket[socQ]).setBlocking(false);
			(*socket[socQ]).send(mapPack);
			if (addresses.size() != 0) {
				ipPack << "add" << addresses.size();
				int add = addresses.size();
				for (int i = 0; i < add; i++) {
					ipPack << addresses[i].toInteger();
				}
				(*socket[socQ]).send(ipPack);
				ipPack.clear();
			}
			addresses.push_back((*socket[socQ]).getRemoteAddress());
			if (socQ != 0) {
				ipPack << addresses[socQ].toInteger();
				for (int i = 0; i < socQ; i++) {
					(*socket[i]).send(ipPack);
				}
				ipPack.clear();
			}
			sf::TcpSocket *tempsock2 = new sf::TcpSocket;
			socket.push_back(tempsock2);
			socQ++;
		}
		/////////////////////////////////////////////////////////////
		sf::Socket::Status stat;
		///checking for disconnections, messages etc. for each client
		for (int i = 0; i < socQ; i++) {
			stat = (*socket[i]).receive(msgPack);
			if (stat == sf::Socket::Status::Done) {//client sent something
				msgPack >> command;
				if (command == "/message") {
					msgPack >> message;
					msgPack.clear();
					msgPack << command << (*socket[i]).getRemoteAddress().toInteger() << message;
					for (int q = 0; q < socQ; q++) {
						if(q!=i)
						while((*socket[q]).send(msgPack)==sf::Socket::Status::Partial);
					}
					msgPack.clear();
					command.clear();
					message.clear();
				}
			}
			else if (stat == sf::Socket::Status::Disconnected) {//client disconnected
					socQ--;
					std::cout << "disconnected " << (*socket[i]).getRemoteAddress() << std::endl;
					socket.erase(socket.cbegin() + i);
					ipPack << "sub" << addresses[i].toInteger();
					addresses.erase(addresses.cbegin() + i);
					for (int q = 0; q < socQ; q++) {
						(*socket[q]).send(ipPack);
					}
					ipPack.clear();
				}
		}
		////////////////////////////////////////////////////////////
		sf::sleep(sf::seconds(0.5));///half second of idle
	}
}
