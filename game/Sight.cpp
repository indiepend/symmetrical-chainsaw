#include "Sight.h"



Sight::Sight()
{
}

void Sight::setUp(sf::RenderWindow *targetwindow, sf::Sprite * collisionSprites, int NumberSprites, string mode) {
	window = targetwindow;
	NumS = NumberSprites;
	C_mode = mode;
	fade = 80;
	sightCircle.setFillColor(sf::Color::Transparent);
	sightCircle.setOutlineThickness(5000);
	sightCircle.setOutlineColor(sf::Color(230, 230, 230));
	blendmode = sf::BlendAlpha;
	blendmode.colorSrcFactor = blendmode.One;

	if (C_mode == "mouse") {
		sightCircle.setRadius(150);
		sightCircle.setOrigin(sightCircle.getRadius(), sightCircle.getRadius());
	}
	else if (C_mode == "homie") {
		fading.create((*window).getSize().x, (*window).getSize().y);
		fading.clear(sf::Color::Transparent);

		sightCircle.setRadius(300);
		sightCircle.setPointCount(200);
		sightCircle.setOrigin(sightCircle.getRadius(), sightCircle.getRadius());
		sightCircle.setPosition((*window).getSize().x/2, (*window).getSize().y/2);
		fading.draw(sightCircle);
	
		for (int i = 0; i <= fade; i++) {
			sightCircle.setRadius(sightCircle.getRadius() - 0.5);
			sightCircle.setOrigin(sightCircle.getRadius(), sightCircle.getRadius());
			sightCircle.setOutlineThickness(0.5);
			sightCircle.setOutlineColor(sf::Color(230, 230, 230,255-((255/fade)*i)));
			fading.draw(sightCircle);
		}
		cSprites.setTexture(fading.getTexture());
		cSprites.setOrigin(cSprites.getGlobalBounds().width / 2, cSprites.getGlobalBounds().height / 2);
	}
	else if (C_mode == "wide_homie") {
		fading.create((*window).getSize().x, (*window).getSize().y);
		fading.clear(sf::Color::Transparent);

		rectangle.setSize(sf::Vector2f((*window).getSize()));
		rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
		rectangle.setPosition(sf::Vector2f((*window).getSize().x/2, (*window).getSize().y / 2));
		rectangle.setFillColor(sf::Color::Transparent);
		fading.draw(rectangle);

		for (int i = 0; i <= fade; i++) {
			rectangle.setSize(sf::Vector2f(rectangle.getSize().x - 1, rectangle.getSize().y-1));
			rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
			rectangle.setOutlineThickness(1);
			rectangle.setOutlineColor(sf::Color(230, 230, 230, 255 - ((255 / fade)*i)));
			fading.draw(rectangle);
		}
		cSprites.setTexture(fading.getTexture());
		cSprites.setOrigin(cSprites.getGlobalBounds().width / 2, cSprites.getGlobalBounds().height / 2);
	}
	else if (C_mode == "real") {
		line[0].position = sf::Vector2f(10, 10);
		r_px = 10;
		r_py = 10;
		r_dx = 15;
		r_dy = 10;
		T1 = 15;
		line[1].position = sf::Vector2f(r_px+r_dx*T1, r_py + r_dy*T1);


	}
}

void Sight::update(sf::Vector2f getCPos) {
	if (C_mode == "mouse") {
		sightCircle.setPosition((*window).mapPixelToCoords(sf::Mouse::getPosition((*window))));
	}
	else if (C_mode == "homie") {
		cSprites.setPosition(getCPos);
	}
	else if (C_mode == "wide_homie") {
		cSprites.setPosition(getCPos);
	}
	else if (C_mode == "real") {

	}
	for (int i = 1; i < NumS;i++) {

	}
}

void Sight::draw() {
	if (C_mode == "mouse") {
		(*window).draw(sightCircle, sf::BlendAlpha);
	}
	else if (C_mode == "homie") {
		(*window).draw(cSprites,blendmode);
	}
	else if (C_mode == "wide_homie") {
		(*window).draw(cSprites, blendmode);
	}
	else if (C_mode == "real") {
		(*window).draw(line,2,sf::Lines);
	}
}