#include "MusicPlayer.h"

void MusicPlayer::OpenNPlay(string musicFile) {
	if (!musObj.openFromFile(musicFile)) {

	}
	if (musObj.getStatus() != musObj.Playing) {
		musObj.play();
	}
	threadKiller++;
	watek = spawn();
	watek.detach();
}

void MusicPlayer::ChangeVolume(int NewVol) {
	MaxVol = NewVol;
	musObj.setVolume((float)MaxVol);
}
 
MusicPlayer::MusicPlayer()
{
	musObj.setLoop(true);
}

void MusicPlayer::Turn(float Seconds) {
	int VolStep = 0;
	int Checker = threadKiller;
	float step = Seconds / MaxVol;
	while (VolStep < MaxVol) {
			sf::sleep(sf::seconds(step));
			musObj.setVolume((float)VolStep);
			VolStep++;

			if (threadKiller != Checker)
				break;
	}
	std::cout << "done" << endl;
}

thread MusicPlayer::spawn() {
	return std::thread([=] { Turn(4.0f); });
}