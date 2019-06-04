#include "miernik.h"


using namespace std;


//-InitTime in seconds
//-if countdown is true counter will go downwords
//-if countdown is false counter will go upwords
//-you can change it anytime with countdown(new state, new init time);
void miernik::start(bool countdown, int init_Time) {
	countD_U = countdown;
	seconds = init_Time;
	zegarek.restart();
}
void miernik::restart() {
	stop_B = false;
}
void miernik::stop() {
	stop_B = true;
}

miernik::miernik()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color(255, 255, 255));
	text.setOutlineThickness(0.9);
	text.setOutlineColor(sf::Color(0, 0, 0));
}

int miernik::timeInSecs() {
	return seconds;
}
//////////////////////////////////////////////////////////////////////
int miernik::licznik(sf::Clock * zegar)
{
	czasik = (*zegar).getElapsedTime();
	if (czasik.asSeconds() >= 1) {
		(*zegar).restart();
	}
	if (!stop_B) {
		return seconds + floor(czasik.asSeconds());
	}
	else {
		return seconds;
	}

}
/////////////////////////////////////////////////

int miernik::minutnik(sf::Clock * zegar)
{
	czasik = (* zegar).getElapsedTime();
	if (czasik.asSeconds() >= 1) {
		(* zegar).restart();
	}
	if ((0 <= (seconds - floor(czasik.asSeconds()))) && stop_B==false) {
		return seconds - floor(czasik.asSeconds());
	}
	else {
		return seconds;
	}
}

//////////////////////////////////////////////////

string miernik::TimeString(int sekundy, int minuty) {
	stringstream ss;
	if (minuty < 10) {
		ss << "0";
	}
	ss << minuty;//minuty
	ss << ":";
	if (sekundy < 10) {
		ss << "0";
	}
	ss << sekundy;//sekundy
	return ss.str();
}

/////////////////////////////////////////////

void miernik::drawCzas(sf::RenderWindow * window) {
	Czas();
	text.setString(TimeString(a, b));
	text.setOrigin((float)(text.getLocalBounds().width / 2), 0);
	text.setPosition((*window).getSize().x/2, 0);
	(*window).draw(text);
}

void miernik::Czas() {
	if (countD_U) {
		seconds = minutnik(&zegarek);
		a = seconds % 60;
		b = floor(seconds / 60);
	}
	else {
		seconds = licznik(&zegarek);
		a = seconds % 60;
		b = floor(seconds / 60);
	}
}
