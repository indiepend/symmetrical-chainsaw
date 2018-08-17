#include "progressBar.h"

progressBar::progressBar()
{
}

progressBar::progressBar(int width, int height, float measurable, Direction dir){
	bg.setSize(sf::Vector2f(width, height));
	bg.setOrigin(bg.getLocalBounds().width / 2, bg.getLocalBounds().height / 2);

	ARG_dir = dir;
	if (dir == Direction::vertical) {
		step = measurable / width;
	}
	else if (dir == Direction::horizontal) {
		step = measurable / height;
	}
}

void progressBar::create(int width, int height, float measurable, Direction dir) {
	bg.setSize(sf::Vector2f(width, height));
	bg.setOrigin(bg.getLocalBounds().width / 2, bg.getLocalBounds().height / 2);

	ARG_dir = dir;
	if (dir == Direction::vertical) {
		step = height / measurable;
	}
	else if (dir == Direction::horizontal) {
		step = width / measurable;
	}
}

void progressBar::placeBar(int x, int y) {
	bar.setPosition(x, y);
	bg.setPosition(sf::Vector2f(x, y));
}

void progressBar::update(float measured) {
	if (ARG_dir == Direction::vertical) {
		bar.setSize(sf::Vector2f(bg.getSize().x, measured*step));
	}
	else if (ARG_dir == Direction::horizontal) {
		bar.setSize(sf::Vector2f(measured*step, bg.getSize().y));
	}
	bar.setOrigin(bar.getLocalBounds().width / 2, bar.getLocalBounds().height / 2);
}

void progressBar::draw(sf::RenderTarget *target) {
	target->draw(bg);
	target->draw(bar);
}

void progressBar::setBorder(int thickness, sf::Color color) {
	bg.setOutlineThickness(thickness);
	bg.setOutlineColor(color);
	bg.setOrigin(bg.getLocalBounds().width / 2-thickness, bg.getLocalBounds().height / 2-thickness);
}

void progressBar::setColors(sf::Color barCol, sf::Color bgCol) {
	bar.setFillColor(barCol);
	bg.setFillColor(bgCol);
}

void progressBar::customTexture(sf::Texture* texture, Type typeOfSprite) {
	if (Type::background == typeOfSprite) {
		bg.setTexture(texture);
	}
	else if (Type::bar == typeOfSprite) {
		bar.setTexture(texture);
	}
}