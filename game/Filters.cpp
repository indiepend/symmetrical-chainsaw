#include "Filters.h"

void Filters::setWindow(sf::RenderWindow * wind) {
	targetwindow = wind;
}

void Filters::setNoctovision(sf::Vector2i size) {
	scale = 8;
		pos = size / scale;
		textr.create(size.x / scale, size.y / scale);
		srand(time(0));
		pixels = new sf::Uint8[size.x * size.y * 4];
		sprite.setTexture(textr);
		sprite.scale(sf::Vector2f(scale, scale));
		sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().left + sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().top + sprite.getLocalBounds().height) / 2));
}

void Filters::activeNoctovision(bool noct) {
	filterActive = noct;
	if (ih % 2 == 0) {
	for (register int i = 0; i < pos.x*pos.y*4; i += 4) {
		pixels[i] = 120; // r
		pixels[i + 1] = rand() % 10 + 130;//g
		pixels[i + 2] = 120;//b
		pixels[i + 3] = 150;//alpha
	}
	textr.update(pixels);
}
ih += 1;
}



void Filters::drawNoctovision(sf::Vector2f pos) {
	sprite.setPosition(pos);
	if (filterActive == true) {
		(*targetwindow).draw(sprite);
	}
	filterActive = false;
}