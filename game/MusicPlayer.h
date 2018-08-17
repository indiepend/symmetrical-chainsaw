#include "stdafx.h"
#include <thread>
#pragma once

class MusicPlayer
{
	sf::Music musObj;
	int MaxVol = 20,threadKiller=0;
	std::thread thread;

	//////////////////////////////////////////////////
	///\brief
	///internal function for smooth play of music
	//////////////////////////////////////////////////
	void Turn(float);

	//////////////////////////////////////////////////
	///\brief
	///internal spawn of thread to execute Turn(float)
	//////////////////////////////////////////////////
	std::thread spawn();

public:

	//////////////////////////////////////////////////
	///\brief
	///opens file and plays it instantly
	///file path can be like that
	///"C://doc/mymusic.ogg" or
	///"mymusic.ogg" if music file is inside app folder
	//////////////////////////////////////////////////
	void OpenNPlay(std::string);

	//////////////////////////////////////////////////
	///\brief
	///changes volume to set number
	///range from 0(mute) to 100(loudest)
	//////////////////////////////////////////////////
	void ChangeVolume(int);
};

