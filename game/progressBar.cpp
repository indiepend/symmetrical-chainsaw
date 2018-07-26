#include "progressBar.h"

progressBar::progressBar()
{
}

progressBar::progressBar(int width, int height, float measurable, Direction dir){
	ARG_width = width;
	ARG_height = height;
	ARG_measurable = measurable;
	bgRend.create(width, height);
	ARG_dir = dir;
	if (dir == Direction::vertical) {
		step = measurable / width;
	}
	else if (dir == Direction::horizontal) {
		step = measurable / height;
	}
}

void progressBar::create(int width, int height, float measurable, Direction dir) {
	ARG_width = width;
	ARG_height = height;
	ARG_measurable = measurable;
	bgRend.create(width, height);
	barRend.create(width, height);
	ARG_dir = dir;
	if (dir == Direction::vertical) {
		step = height / measurable;
	}
	else if (dir == Direction::horizontal) {
		step = width / measurable;
	}
}

void progressBar::placeBar(int x, int y) {
	ARG_coordX = x;
	ARG_coordY = y;
}

void progressBar::update(float measured) {
	bg.setTexture(bgRend.getTexture());
	bar.setTexture(barRend.getTexture());
	bg.setOrigin(bg.getLocalBounds().width / 2, bg.getLocalBounds().height / 2);
	bar.setOrigin(bar.getLocalBounds().width / 2, bar.getLocalBounds().height / 2);
	bg.setPosition((float)ARG_coordX, (float)ARG_coordY);
	bar.setPosition((float)ARG_coordX, (float)ARG_coordY);
	border.setPosition((float)ARG_coordX, (float)ARG_coordY);
	if (ARG_dir == Direction::vertical) {
		bar.setTextureRect(sf::Rect<int>(0, 0, ARG_width, (int)(measured*step)));
	}
	else if (ARG_dir == Direction::horizontal) {
		bar.setTextureRect(sf::Rect<int>(0, 0, (int)(measured*step), ARG_height));
	}
}

void progressBar::draw(sf::RenderTarget *target) {
	target->draw(border);
	target->draw(bg);
	target->draw(bar);
}

void progressBar::setBorder(int thickness, sf::Color color) {
	borderRend.create(ARG_width + 2 * thickness, ARG_height + 2 * thickness);
	borderRend.clear(color);
	borderRend.display();
	border.setTexture(borderRend.getTexture());
	border.setOrigin(border.getLocalBounds().width / 2, border.getLocalBounds().height / 2);
}

void progressBar::setColors(sf::Color barCol, sf::Color bgCol) {
	ARG_barColor = barCol;
	barRend.clear(barCol);
	barRend.display();
	ARG_bgColor = bgCol;
	bgRend.clear(bgCol);
	bgRend.display();
}

void progressBar::customSprite(sf::Sprite cSprite, Type typeOfSprite) {
	if (Type::backgroundSprite == typeOfSprite) {
		bg = cSprite;
	}
	else if (Type::barSprite == typeOfSprite) {
		bar = cSprite;
	}
}