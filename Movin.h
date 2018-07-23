#include "stdafx.h"
#pragma once
class Movin :public sf::Clock
{
	sf::Clock zegar;
	sf::Time czas4 = sf::seconds(0), czas3 = sf::seconds(0),czas2 = sf::seconds(0),czas1 = sf::seconds(0),czas0 = sf::seconds(0);
	float grawitacja,grawitacja2, speed;
	int value;

protected:
	void restart();

public:
	int Fall(int V0fall=0);
	int Jump(int Vjump,int modifyAble);
	int FallOffJump(int V0jump);
	int FallOff(int SpeedOfFall);
	void ResetJumpTime();
	void ResetFallTime();
	void ResetFallOffTime();
	void ResetFallOffTime2();
	int Walk(int V);
	Movin();
	//~Movin();
};