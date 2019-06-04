#include "stdafx.h"
#pragma once

using namespace std;

/*
start() - rozpoczêcie odmierzania czasu
Czas() - czas w minutach i sekundach w stringu
drawCzas(okno rysowania) - rysowanie stringa w oknie
*/
class miernik
{
private:
	int seconds,initTime,a, b, min = 0;
	bool countD_U,stop_B=false;
	sf::Clock zegarek;
	sf::Time czasik;
	sf::Text text;
	sf::Font font;

	int licznik(sf::Clock * zegar);
	int minutnik(sf::Clock * zegar);
	string TimeString(int sekundy, int minuty);
	void Czas();
public:

	miernik();
	void start(bool countdown=true, int initTime=0);
	void restart();
	void stop();
	void drawCzas(sf::RenderWindow * window);
	int timeInSecs();
};