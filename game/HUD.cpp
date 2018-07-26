#include "HUD.h"



HUD::HUD()
{

}

void HUD::setUp(sf::RenderWindow * window, sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers) {
	okno = window;
	target = window;
	licznik.start(0);
	mapka.create(window,collisable,HowMany,players);
	lifePoints.create(200, 25, 100,progressBar::Direction::horizontal);
	lifePoints.placeBar(115, 690);
	lifePoints.setColors(sf::Color(150,0,0),sf::Color(0,0,0));
	lifePoints.setBorder(2, sf::Color::Black);
}

void HUD::update(float Points) {
	mapka.update();
	lifePoints.update(Points);
}

void HUD::draw() {
	tempView = (*okno).getView();
	(*okno).setView((*okno).getDefaultView());
	licznik.drawCzas(okno);
	lifePoints.draw(target);
	(*okno).setView(tempView);
	mapka.draw();
}

void HUD::restart() {
	licznik.restart();
}
void HUD::stop() {
	licznik.stop();
}
