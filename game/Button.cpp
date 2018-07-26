#include "Button.h"

void Button::createButton(int width, int height, sf::RenderWindow * window, sf::Color ofbutton, bool animated) {
	h = height;
	w = width;
	R_text = &V_Rtext;
	wind = window;
	renderWindow = false;
	c1 = ofbutton;
	animationed = animated;
	sf::Texture backT;
	backT.create(width, height);
	backS.setTexture(backT);
	backS.setColor(ofbutton);
	backS.setOrigin(backS.getLocalBounds().width / 2, backS.getLocalBounds().height / 2);
}

void Button::createButton(int width, int height, sf::RenderTexture * renderTexture, sf::RenderWindow * window, sf::Color ofbutton, bool animated) {
	h = height;
	w = width;
	R_text = renderTexture;
	wind = window;
	renderWindow = true;
	c1 = ofbutton;
	animationed = animated;
	sf::Texture backT;
	backT.create(width, height);
	backS.setTexture(backT);
	backS.setColor(ofbutton);
	backS.setOrigin(backS.getLocalBounds().width / 2, backS.getLocalBounds().height / 2);
}

void Button::placeButton(float coordx, float coordy, string align) {
	if (renderWindow == false) {
		backS.setPosition(sf::Vector2f(coordx*(*wind).getSize().x, coordy*(*wind).getSize().y));
	}
	else {
		backS.setPosition(sf::Vector2f(coordx*(*R_text).getSize().x, coordy*(*R_text).getSize().y));
	}
	alignes = align;

	if (align == "center") {
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height *2 / 3));
		text.setPosition(sf::Vector2f(backS.getGlobalBounds().left + backS.getGlobalBounds().width / 2, backS.getGlobalBounds().top + backS.getGlobalBounds().height / 2));
	}
	else if (align == "left") {
		text.setOrigin(sf::Vector2f(0, text.getLocalBounds().height * 2 / 3));
		text.setPosition(sf::Vector2f(backS.getGlobalBounds().left, backS.getGlobalBounds().top + backS.getGlobalBounds().height / 2));
	}
	else if (align == "right") {
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height * 2 / 3));
		text.setPosition(sf::Vector2f(backS.getGlobalBounds().left + backS.getGlobalBounds().width, backS.getGlobalBounds().top + backS.getGlobalBounds().height / 2));
	}
}

void Button::setBorder(int thickness, sf::Color colorOfBorder,sf::Color secondColor) {
	sf::Texture borderText;
	thick = thickness;
	borderText.create(w+2*thickness, h+2*thickness);
	border.setTexture(borderText);
	border.setOrigin(border.getLocalBounds().width / 2, border.getLocalBounds().height / 2);
	border.setPosition(backS.getPosition().x, backS.getPosition().y);
	border.setColor(colorOfBorder);
	c3 = colorOfBorder;
	c4 = secondColor;
}

void Button::moveButton(sf::Vector2f move) {//////////////////NIEUZYWANE I ZABRANIAM TEGO TYKAC
	vector1 = sf::Vector2f(sf::Mouse::getPosition((*wind)));
	if (vector2 != vector1) {
	//	backS.move(sf::Vector2f((vector1.x - vector2.x)*0.1, (vector1.y - vector2.y)*0.1));
	//	text.move(sf::Vector2f((vector1.x - vector2.x)*0.1, (vector1.y - vector2.y)*0.1));
	}
	vector2 = sf::Vector2f(sf::Mouse::getPosition((*wind)));
}

void Button::checkButton(sf::Color color, sf::Vector2f mouse) {
	if (renderWindow == true) {
		if ((*wind).hasFocus() && backS.getGlobalBounds().contains(mouse)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				clicked = true;
			}
			if (animationed == false) {
				backS.setColor(color);
				border.setColor(c4);
				text.setFillColor(c1);
			}
			else {
				if (animating == true) {
					if (current == color) {
						animating = false;
						step = 0;
					}
					else {
						currentTxt.r = c2.r - (fabs(c2.r - c1.r) / 10)*step;
						currentTxt.g = c2.g - (fabs(c2.g - c1.g) / 10)*step;
						currentTxt.b = c2.b - (fabs(c2.b - c1.b) / 10)*step;

						current.r = c1.r + (fabs(c1.r - color.r) / 10)*step;
						current.g = c1.g + (fabs(c1.g - color.g) / 10)*step;
						current.b = c1.b + (fabs(c1.b - color.b) / 10)*step;
						step++;
					}
				}
				else {
					animating = true;
				}
				text.setFillColor(currentTxt);
				backS.setColor(current);
			}
		}
		else {
			current = c1;
			currentTxt = c2;
			animating = false;
			step = 0;
		}
	}
	else {
		if ((*wind).hasFocus() && backS.getGlobalBounds().contains((*wind).mapPixelToCoords(sf::Mouse::getPosition((*wind))))) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				clicked = true;
			}
			if (animationed == false) {
				backS.setColor(color);
				border.setColor(c4);
				text.setFillColor(c1);
			}
			else {
				if (animating == true) {
					if (current == color) {
						animating = false;
						step = 0;
					}
					else {
						currentTxt.r = c2.r - (fabs(c2.r - c1.r) / 10)*step;
						currentTxt.g = c2.g - (fabs(c2.g - c1.g) / 10)*step;
						currentTxt.b = c2.b - (fabs(c2.b - c1.b) / 10)*step;

						current.r = c1.r + (fabs(c1.r - color.r) / 10)*step;
						current.g = c1.g + (fabs(c1.g - color.g) / 10)*step;
						current.b = c1.b + (fabs(c1.b - color.b) / 10)*step;
						step++;
					}
				}
				else {
					animating = true;
				}
				text.setFillColor(currentTxt);
				backS.setColor(current);
			}
		}
		else {
			current = c1;
			currentTxt = c2;
			animating = false;
			step = 0;
		}
	}

}

void Button::drawButton(){
	if (renderWindow == true) {
		(*R_text).draw(border);
		(*R_text).draw(backS);
		(*R_text).draw(text);
	}
	else {
		(*wind).draw(border);
		(*wind).draw(backS);
		(*wind).draw(text);
	}

	backS.setColor(c1);
	border.setColor(c3);
	text.setFillColor(c2);
	clicked = false;
}

bool Button::isClicked() {
	return clicked;
}
/*
Text methods
*/

void Button::setFont(sf::Font * font) {
	text.setFont((*font));
}
void Button::setCharacterSize(int size) {
	text.setCharacterSize(size);
}
void Button::setString(sf::String textinbutton) {
	text.setString(textinbutton);
	if (alignes == "center") {
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height * 2 / 3));
	}
	else if (alignes == "left") {
		text.setOrigin(sf::Vector2f(0, text.getLocalBounds().height * 2 / 3));
	}
	else if (alignes == "right") {
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height * 2 / 3));
	}
}
void Button::setFillColor(sf::Color oftext) {
	text.setFillColor(oftext);
	c2 = oftext;
}

Button::Button()
{
}
