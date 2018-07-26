#include "Events.h"

void Events::Handler(sf::RenderWindow * window) {
	EscapeButtonPressed = false;
	while ((*window).pollEvent(zdarzenie)) //przyjmuje zdarzenia
	{
		switch (zdarzenie.type) {
		case sf::Event::Closed:
			(*window).close();
			break;
		case sf::Event::KeyPressed:
			key = zdarzenie.key.code;
			if (zdarzenie.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Escape)) {
				EscapeButtonPressed = true;
			}
			break;
		default:
			break;
		}
	}
}

sf::Keyboard::Key Events::returnKey() {
	return key;
}

bool Events::isEscapePressed() {
	return EscapeButtonPressed;
}

Events::Events()
{
}