#include "stdafx.h"
#include "Movin.h"

///KLASA DO DZIEDZICZENIA
///INHERITE CLASS

/***********************************************
* klasa ruch:
* float Walk - zwraca predkosc chodu
* float Jump - zwraca szybkosc skoku
* float Fall - zwraca szybkosc spadania
***********************************************/


	int Movin::Walk(int V){
		value = V;
		return zegar.getElapsedTime().asSeconds()*V;
	}

	int Movin::FallOff(int SpeedOfFall) {
		czas1 += zegar.getElapsedTime();
		return (value*zegar.getElapsedTime().asSeconds()) - (czas1.asSeconds()*SpeedOfFall);
	}

	int Movin::FallOffJump(int V0jump) {
		czas4 += zegar.getElapsedTime();
		//std::cout << czas4.asSeconds() << std::endl;
		if (czas4.asSeconds() < 0.3) {
			return V0jump*(czas4.asSeconds()/0.3);
		}
		else {
			return V0jump;
		}
	}

	int Movin::Jump(int Vjump, int modifyAble) {
		czas2 += zegar.getElapsedTime();
		grawitacja = pow(czas2.asSeconds(), 2);
		return (Vjump*czas2.asSeconds()) - grawitacja-(12+modifyAble);
	}
	void Movin::ResetFallOffTime() {
		czas1 = sf::seconds(0);
	}
	void Movin::ResetJumpTime(){
		czas2 = sf::seconds(0);
	}
	void Movin::ResetFallTime() {
		czas3 = sf::seconds(0);
	}
	void Movin::ResetFallOffTime2() {
		czas4 = sf::seconds(0);
	}
	int Movin::Fall(int V0fall) {
		czas3 += zegar.getElapsedTime();
		grawitacja2 = pow(czas3.asSeconds()+0.7, 2)*6;
		std::cout << grawitacja2 << std::endl;
		if (grawitacja2 > 0.01)
			return grawitacja2;
		else
			return 1;
	}
	void Movin::restart() {
		zegar.restart();
	}

	Movin::Movin(){
		zegar = sf::Clock::Clock();
	}