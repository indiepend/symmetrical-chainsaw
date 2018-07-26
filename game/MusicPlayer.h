#include "stdafx.h"
#include <thread>
#pragma once

using namespace std;

class MusicPlayer
{
	sf::Music musObj;

	int MaxVol = 20;
	int threadKiller = 0;
	thread watek;
	void Turn(float Seconds);
public:
	void OpenNPlay(string musicFile);
	void ChangeVolume(int NewVol);
	thread spawn();
	MusicPlayer();
};

