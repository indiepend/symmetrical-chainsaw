#include "Events.h"

void Events::Handler(sf::RenderWindow * window) {
	EscapeButtonPressed = false;
	EnterButtonPressed = false;
	BackspaceButtonPressed = false;
	inputText = false;
	while ((*window).pollEvent(zdarzenie)) //przyjmuje zdarzenia
	{	
		switch (zdarzenie.type) {
		case sf::Event::Closed:
			(*window).close();
			break;
		case sf::Event::KeyPressed:
			key = zdarzenie.key.code;
			if (zdarzenie.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Escape))
				EscapeButtonPressed = true;
			if (zdarzenie.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Enter))
				EnterButtonPressed = true;
			if (zdarzenie.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Backspace))
				BackspaceButtonPressed = true;
			break;
		case sf::Event::TextEntered:
			inputText = true;
			break;
		default:
			break;
		}
	}
}

bool Events::getInput(string* input)
{
	if (inputText) {
		if(zdarzenie.text.unicode >= 32 && zdarzenie.text.unicode <= 128) {
			(*input) += char(zdarzenie.text.unicode);
		}
		else if (isBackspacePressed()) {
			if((*input).size()>0)
			(*input).erase((*input).end()-1);
		}
		return true;
	}
	return false;
}

sf::Keyboard::Key Events::returnKey() {
	return key;
}

bool Events::isEscapePressed() {
	return EscapeButtonPressed;
}

bool Events::isEnterPressed()
{
	return EnterButtonPressed;
}

bool Events::isBackspacePressed()
{
	return BackspaceButtonPressed;
}

Events::Events()
{
}