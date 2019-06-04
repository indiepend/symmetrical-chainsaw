#include "Camera.h"

void Camera::cameraUpdate(){
	lel = (*prot).getPosition();
	if (los != lel) {
		view.move((lel.x - los.x)*0.15, (lel.y - los.y)*0.15);
	}
	los = view.getCenter();
	(*ARG_window).setView(view);
}

void Camera::getValues(sf::Sprite * Protagonist, sf::RenderWindow * window) {
	ARG_window = window;
	prot = Protagonist;

	view.setCenter((*Protagonist).getLocalBounds().left + (*Protagonist).getLocalBounds().width / 2, (*Protagonist).getLocalBounds().top - 100);
	view.setSize((*window).getSize().x, (*window).getSize().y);
	(*window).setView(view);
}

void Camera::getValuesWindow(sf::RenderWindow * window) {
	ARG_window = window;
	view.setCenter((*window).getSize().x / 2, (*window).getSize().y/2);
	view.setSize((*window).getSize().x, (*window).getSize().y);
	(*window).setView(view);
}

void Camera::cameraUpdateMain() {
	lel = sf::Vector2f(sf::Mouse::getPosition((*ARG_window)));
	if (los != lel) {
		view.move((lel.x - los.x)*0.1, (lel.y - los.y)*0.1);
	}
	los = sf::Vector2f((*ARG_window).getSize().x/2, (*ARG_window).getSize().y / 2);
	(*ARG_window).setView(view);
}

sf::Vector2f Camera::getSize() {
	return view.getSize();
} 

sf::Vector2f Camera::getPosition() {
	return sf::Vector2f(view.getCenter().x,view.getCenter().y);
}