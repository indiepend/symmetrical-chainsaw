#include "Camera.h"

void Camera::cameraUpdate(){
	lel = (*prot).getPosition();
	if (los != lel) {
		x=lel.x - los.x;
		y=lel.y - los.y;
		view.move(x*0.15, y*0.15);
	}
	los = view.getCenter();
	(*okno).setView(view);
}
Camera::Camera() {

}
void Camera::getValues(sf::Sprite * Protagonist, sf::RenderWindow * window) {
	protp = (*Protagonist).getGlobalBounds();
	view.setCenter((*Protagonist).getLocalBounds().left + (*Protagonist).getLocalBounds().width / 2, (*Protagonist).getLocalBounds().top - 100);
	sf::Vector2f lol((*window).getSize().x, (*window).getSize().y);
	view.setSize(lol);
	(*window).setView(view);
	prot = Protagonist;
	okno = window;
}

void Camera::getValuesWindow(sf::RenderWindow * window) {
	view.setCenter((*window).getSize().x / 2, (*window).getSize().y/2);
	sf::Vector2f lol((*window).getSize().x, (*window).getSize().y);
	view.setSize(lol);
	(*window).setView(view);
	okno = window;
}

void Camera::cameraUpdateMain() {
	lel = sf::Vector2f(sf::Mouse::getPosition((*okno)));
	if (los != lel) {
		x = lel.x - los.x;
		y = lel.y - los.y;
		view.move(x*0.1, y*0.1);
	}
	los = sf::Vector2f((*okno).getSize().x/2, (*okno).getSize().y / 2);
	(*okno).setView(view);
}

sf::Vector2f Camera::getSize() {
	return view.getSize();
} 

sf::Vector2f Camera::getPosition() {
	return sf::Vector2f(view.getCenter().x,view.getCenter().y);
}