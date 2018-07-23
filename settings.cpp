#include "settings.h"

void settings::loadSettings(sf::RenderWindow * window,sf::Font * fonts) {
	font = fonts;
	targetwindow = window;

	gray_S.create(500, 300);
	gray_S.clear(sf::Color(100, 100, 100));
	Sgray_S.setTexture(gray_S.getTexture());
	Sgray_S.setOrigin(Sgray_S.getLocalBounds().width / 2, Sgray_S.getLocalBounds().width / 2);
	Sgray_S.setPosition((*targetwindow).getSize().x / 2, (*targetwindow).getSize().y / 2);

	powrot.createButton(170, 57, targetwindow, sf::Color(0, 0, 0));
	powrot.setFont(&font[1]);
	powrot.setCharacterSize(20);
	powrot.setFillColor(sf::Color(255, 255, 255));
	powrot.setString(L"Powrót");
	powrot.placeButton(0.15, 0.15, "center");
	powrot.setBorder(1, sf::Color(255, 180, 20), sf::Color(0, 0, 0));

	rt_S.create((*targetwindow).getSize().x * 2 / 3, (*targetwindow).getSize().y * 2 / 2.5f);
	bg_S.setPosition((*targetwindow).getSize().x / 1.7f, (*targetwindow).getSize().y / 1.9f);

	loader.loadUp("settings.txt");
	ustawienia = loader.getString();
	otherSets[0].setFont(fonts[1]);
	otherSets[0].setCharacterSize(30);
	otherSets[0].setFillColor(sf::Color::White);
	otherSets[0].setString("Gracz");
	otherSets[0].setPosition(rt_S.getSize().x*0.07, rt_S.getSize().y*0.02);

	for (int i = 0; i < 6; i++) {
		keyBOARD[i] = sf::Keyboard::Key(atoi(ustawienia[i * 2 + 2].c_str()));

		setts[i].setFont(fonts[1]);
		setts[i].setCharacterSize(20);
		setts[i].setFillColor(sf::Color::White);
		setts[i].setString(ustawienia[i * 2 + 1]);
		setts[i].setOrigin(sf::Vector2f(setts[i].getLocalBounds().width / 2, setts[i].getLocalBounds().height * 2 / 3));
		setts[i].setPosition(rt_S.getSize().x*0.1, rt_S.getSize().y*0.15 + rt_S.getSize().y*0.07*i);

		sterowanie[i].createButton(120, 25, &rt_S, targetwindow, sf::Color(0, 0, 0), false);
		sterowanie[i].setFont(&fonts[1]);
		sterowanie[i].setCharacterSize(13);
		sterowanie[i].setFillColor(sf::Color(255, 255, 255));
		sterowanie[i].setString(keyString.returnKeyString(atoi(ustawienia[i * 2 + 2].c_str())));
		sterowanie[i].placeButton(0.25, 0.07*i + 0.15, "center");
		sterowanie[i].setBorder(1, sf::Color(255, 180, 20), sf::Color(0, 0, 0));
	}
}

void settings::updateSettings(sf::Keyboard::Key key, bool insideGame) {
	inGame = insideGame;
	if (inGame == false) {
		powrot.checkButton(sf::Color::White);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || powrot.isClicked()) {
		if (inGame == false) {
			ip = 0;
		}
		clicked_S = false;
		if (change) {
			writer.ToFile("settings.txt", ustawienia, loader.getNumber());
			change = false;
		}
	}
	rt_S.clear(sf::Color::Black);
	rt_S.draw(otherSets[0]);
	for (int i = 0; i < 6; i++) {
		sterowanie[i].drawButton();
		rt_S.draw(setts[i]);
	}
	rt_S.display();
	bg_S.setTexture(rt_S.getTexture());
	bg_S.setOrigin(bg_S.getLocalBounds().width / 2, bg_S.getLocalBounds().height / 2);

	text_S.setFont(font[0]);
	text_S.setCharacterSize(20);
	text_S.setFillColor(sf::Color::Black);
	text_S.setString(L"Wciœnij dowolny klawisz");
	text_S.setOrigin(sf::Vector2f(text_S.getLocalBounds().width / 2, text_S.getLocalBounds().height * 2 / 3));
	text_S.setPosition((*targetwindow).getSize().x / 2, (*targetwindow).getSize().y / 2);

	for (int i = 0; i < 6; i++) {
		sterowanie[i].checkButton(sf::Color::White, sf::Vector2f((*targetwindow).mapPixelToCoords(sf::Mouse::getPosition(*targetwindow)).x - bg_S.getPosition().x + rt_S.getSize().x / 2, (*targetwindow).mapPixelToCoords(sf::Mouse::getPosition(*targetwindow)).y - bg_S.getPosition().y + rt_S.getSize().y / 2));
		if (sterowanie[i].isClicked()) {
			clicked_S = true;
			anotherBagOfInts = i;
		}
	}

	if (clicked_S == true && sf::Keyboard::isKeyPressed(key))
	{
		clicked_S = false;
		int keyes = key;
		stringstream ss;
		ss << keyes;
		keyBOARD[anotherBagOfInts] = key;
		ustawienia[anotherBagOfInts * 2 + 2] = ss.str();
		change = true;
		sterowanie[anotherBagOfInts].setString(keyString.returnKeyString(atoi(ustawienia[anotherBagOfInts * 2 + 2].c_str())));
	}
}

void settings::drawSettings() {
	if (inGame == false) {
		powrot.drawButton();
	}
	(*targetwindow).draw(bg_S);

	if (clicked_S) {
		(*targetwindow).draw(Sgray_S);
		(*targetwindow).draw(text_S);
	}
}

sf::Keyboard::Key * settings::getSetts() {
	return keyBOARD;
}

int settings::getIp() {
	return ip;
}
void settings::setIp(int IP) {
	ip = IP;
}

sf::Sprite * settings::getSs() {
	return &bg_S;
}

settings::settings()
{
}
