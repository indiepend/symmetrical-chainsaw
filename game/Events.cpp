#include "Events.h"

void Events::Handler(sf::RenderWindow * window) 
{
	EscapePsd = false;
	EnterPsd = false;
	BackspacePsd = false;
	inputText = false;
	while ((*window).pollEvent(event))
	{	
		switch (event.type) {
		case sf::Event::Closed:
			(*window).close();
			break;
		case sf::Event::KeyPressed:
			key = event.key.code;
			if (event.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Escape))
				EscapePsd = true;
			if (event.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Enter))
				EnterPsd = true;
			if (event.key.code == sf::Keyboard::Key(sf::Keyboard::Key::Backspace))
				BackspacePsd = true;
			break;
		case sf::Event::TextEntered:
			inputText = true;
			break;
		default:
			break;
		}
	}
}

bool Events::getInput(std::string* input)
{
	if (inputText) {
		if(event.text.unicode >= 32 && event.text.unicode <= 128) {
			(*input) += char(event.text.unicode);
		}
		else if (isBackspacePressed()) {
			if((*input).size()>0)
			(*input).erase((*input).end()-1);
		}
		return true;
	}
	return false;
}

sf::Keyboard::Key Events::returnKey() 
{
	return key;
}

bool Events::isEscapePressed() 
{
	return EscapePsd;
}

bool Events::isEnterPressed()
{
	return EnterPsd;
}

bool Events::isBackspacePressed()
{
	return BackspacePsd;
}