#include "stdafx.h"
#pragma once

class SoundPlayer
{
	sf::SoundBuffer buff;
public:
	SoundPlayer();
	SoundPlayer(std::string filename);
	void loadUp(std::string filename);
	sf::SoundBuffer * getBuffer();
};

