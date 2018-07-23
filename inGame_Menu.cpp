#include "inGame_Menu.h"


void inGame_Menu::inGameLoad(sf::RenderWindow *window) {
	targetwindow = window;
	T_bg.create((*window).getSize().x, (*window).getSize().y);
	T_bg.clear(sf::Color(0, 0, 0, 156));
	heh.create(350, 500);
	heh.clear(sf::Color(0, 0, 0, 240));
	yu.setTexture(heh.getTexture());
	yu.setOrigin(yu.getLocalBounds().width / 2, yu.getLocalBounds().height / 2);
	yu.setPosition((float)((*window).getSize().x / 2), (float)((*window).getSize().y / 2));
	T_bg.draw(yu);

	for (int i = 2; i >= 0; i--) {
		przycisk[i].createButton(170, 57, &T_bg,window, sf::Color(0, 0, 0));
		przycisk[i].setFont(&font);
		przycisk[i].setCharacterSize(25);
		przycisk[i].setFillColor(sf::Color(255, 255, 255));
	}
	////////////////////////////////////////////////////////////////////////
	przycisk[0].setString("Ustawienia");
	przycisk[0].placeButton(0.5f, 0.3f, "center");
	przycisk[0].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));

	przycisk[1].setString(L"Menu G³ówne");
	przycisk[1].placeButton(0.5f, 0.4f, "center");
	przycisk[1].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));

	przycisk[2].setString(L"Powrót");
	przycisk[2].placeButton(0.5f, 0.5f, "center");
	przycisk[2].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));

	bg.setTexture(T_bg.getTexture());
	bg.setOrigin(bg.getLocalBounds().width / 2, bg.getLocalBounds().height / 2);
	T_bg.display();
}

void inGame_Menu::inGameUpdate(sf::Vector2f cameraPosition, menu * Main_Menu, sf::Keyboard::Key key) {
	bg.setPosition(cameraPosition);
	SettiesMenu = (*Main_Menu).passSets();
	settsSprite = (*SettiesMenu).getSs();
	for (int i = 0; i <= 2; i++) {
		przycisk[i].checkButton(sf::Color::White, sf::Vector2f((*targetwindow).mapPixelToCoords(sf::Mouse::getPosition(*targetwindow)).x - bg.getPosition().x + T_bg.getSize().x / 2, (*targetwindow).mapPixelToCoords(sf::Mouse::getPosition(*targetwindow)).y - bg.getPosition().y + T_bg.getSize().y / 2));
	}
	if (przycisk[2].isClicked()) {
		pause_B = false;
	}
	if (przycisk[1].isClicked()) {
		(*Main_Menu).setOP(0);
		load_B = true;
		pause_B = false;
		(*Main_Menu).setLoadMenu(true);
	}
	if (przycisk[0].isClicked()) {
		Setts = true;
	}
	if (Setts == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			Setts = false;
		}
		(*SettiesMenu).updateSettings(key,true);
		(*settsSprite).setPosition(cameraPosition);
	}
	drawIt = true;
}

void inGame_Menu::inGameDraw() {
	if (drawIt) {
		(*targetwindow).draw(bg);
		for (int i = 2; i >= 0; i--) {
			przycisk[i].drawButton();
		}
		if (Setts == true) {
			(*SettiesMenu).drawSettings();
		}
	}
	drawIt = false;
}

bool inGame_Menu::pauseCheck(bool Escape) {
	if (Escape && pause_B == false) {
		pause_B = true;
	}
	else if (Escape && pause_B == true && Setts == false) {
		pause_B = false;
	}
	return pause_B;
}

bool inGame_Menu::load() {
	return load_B;
}

void inGame_Menu::setLoadFalse() {
	load_B=false;
}

inGame_Menu::inGame_Menu()
{
	if (!font.loadFromFile("Semplicita Light.otf")) {}
}
