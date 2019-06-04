#include "MusicPlayer.h"

void MusicPlayer::OpenNPlay(std::string musicFile) {
	musObj.setLoop(true);
	if (!musObj.openFromFile(musicFile));
	if (musObj.getStatus() != musObj.Playing)
		musObj.play();
	threadKiller++;
	thread = spawn();
	thread.detach();
}

void MusicPlayer::ChangeVolume(int NewVol) {
	MaxVol = NewVol;
	musObj.setVolume((float)MaxVol);
}

void MusicPlayer::Turn(float Seconds) {
	int VolStep = 0;
	int Checker = threadKiller;
	float step = Seconds / MaxVol;
	while (VolStep < MaxVol) {
			sf::sleep(sf::seconds(step));
			musObj.setVolume((float)VolStep++);
			if (threadKiller != Checker)
				break;
	}
}

std::thread MusicPlayer::spawn() {
	return std::thread([=] { Turn(4.0f); });
}