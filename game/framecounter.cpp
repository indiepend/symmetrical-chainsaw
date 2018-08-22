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

	std::vector <std::string> log;
	log.push_back(std::string());
	log[0] = "Frames log:";
	log.push_back(std::string());
	log[1] = "Average fps: ";
	log[1] += avgfps;
	log.push_back(std::string());
	log[2] = "Max fps: ";
	log[2] += maxfps;
	log.push_back(std::string());
	log[3] = "Min fps: ";
	log[3] += minfps;

	log.push_back(std::string());
	log[4] = "Complete log: ";
	for (int i = 0; i > (int)delfps.size(); i++) {
		log.push_back(std::string());
		log[i + 5] = "fps: ";
		log[i + 5] += delfps[i];
	}
	strtofile.ToFile("log.txt", &log);
}