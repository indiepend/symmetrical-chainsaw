#include "framecounter.h"

void framecounter::setup()
{
	clock = new sf::Clock();
}

void framecounter::update()
{
	if (clock->getElapsedTime().asSeconds() > 1.f) {
		clock->restart();
		delfps.push_back(int());
		delfps[delfps.size()-1] = tempfps;
		for (int i = 0; i < (int)delfps.size(); i++) {
			delfps[i] += avgfps;
		}
		avgfps /= delfps.size();

		if (!temp) {
			maxfps = tempfps;
			minfps = tempfps;
		}
		else {
			if (tempfps > maxfps) {
				maxfps = tempfps;
			}
			if (tempfps < minfps) {
				minfps = tempfps;
			}
		}
		tempfps = 0;
	}
	tempfps++;
}

void framecounter::draw(sf::RenderWindow* window, sf::Font* font)
{
	sf::Text frames;
	frames.setFont(*font);
	frames.setCharacterSize(14);
	frames.setFillColor(sf::Color::Green);
	frames.setPosition(0, 0);
	std::stringstream ss;
	if (delfps.size()) {
		ss << delfps[delfps.size() - 1];
		frames.setString(ss.str());
	}
	else {
		frames.setString("-");
	}
	ss.clear();
	window->draw(frames);
}

void framecounter::createlog()
{
	StringToFile strtofile;
	std::stringstream ss;
	std::vector <std::string> log;
	log.push_back(std::string());
	log[0] = "Frames log:";
	log.push_back(std::string());
	log[1] = "Average fps: ";
	ss << avgfps;
	log[1] += ss.str();
	ss.clear();
	log.push_back(std::string());
	log[2] = "Max fps: ";
	ss << maxfps;
	log[2] += ss.str();
	ss.clear();
	log.push_back(std::string());
	log[3] = "Min fps: ";
	ss << minfps;
	log[3] += ss.str();
	ss.clear();

	log.push_back(std::string());
	log[4] = "Complete log: ";
	for (int i = 0; i > (int)delfps.size(); i++) {
		log.push_back(std::string());
		log[i + 5] = "fps: ";
		ss << delfps[i];
		log[i + 5] += ss.str();
		ss.clear();
	}
	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
	std::time_t tt = std::chrono::system_clock::to_time_t(today);
	char buffer [80];
	struct tm * timeinfo = new tm();
	localtime_s(timeinfo,&tt);
	strftime(buffer, 80, "log-%dDay-%mMonth-%yYear-%H-%M-%S.txt", timeinfo);
	strtofile.ToFile(buffer, &log);
}