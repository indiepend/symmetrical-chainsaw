#include "SoundPlayer.h"


SoundPlayer::SoundPlayer()
{
}

SoundPlayer::SoundPlayer(std::string filename)
{
	if(!buff.loadFromFile(filename)){

	}
}

void SoundPlayer::loadUp(std::string filename)
{
	if (!buff.loadFromFile(filename)) {

	}
}

sf::SoundBuffer * SoundPlayer::getBuffer()
{
	return &buff;
}
