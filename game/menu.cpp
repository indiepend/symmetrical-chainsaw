#include "menu.h"

menu::menu(sf::RenderWindow * window)
{
	targetwindow = window;
	loadMainMenu();
	loadTable();
	setties.loadSettings(targetwindow,fonts);
}

menu::menu()
{
}

void menu::setWindow(sf::RenderWindow * window)
{
	targetwindow = window;
	loadMainMenu();
	loadTable();
	setties.loadSettings(targetwindow, fonts);
}

void menu::setLoadMenu(bool Load) {
	loadMenu = Load;
}

bool menu::getLoadMenu() {
	return loadMenu;
}

int menu::getOP() {
	return op;
}

void menu::setOP(int OP) {
	op = OP;
}
///////////////////////////////////////////////////////////////////////////////
void menu::menuUpdate(sf::Keyboard::Key key) {
	if (ip == 0) {
		updateMainMenu();
	}
	else if (ip == 1) {
		updateTable();
	}
	else if (ip == 2) {
		setties.updateSettings(key);
		ip = setties.getIp();
	}
}

///////////////////////////////////////////////////////////////////////////////
void menu::menuDraw() {
	if (ip == 0) {
		drawMainMenu();
	}
	else if (ip == 1) {
		drawTable();
	}
	else if (ip == 2) {
		setties.drawSettings();
	}
}
/////////////////////////////////////////////////////////////////////////////

void menu::drawMainMenu() {
	(*targetwindow).draw(backgroundsprite);
	(*targetwindow).draw(texts[0]);
	for (int i = 4; i >= 0; i--) {
		przycisk[i].drawButton();
	}
	//(*targetwindow).draw(circle);
	//(*targetwindow).draw(fastsprite);
}

void menu::loadMainMenu() {
	srand((int)time(0));
	if (!fonts[1].loadFromFile("arial.ttf")) {}
	if (!fonts[0].loadFromFile("Semplicita Light.otf")) {}
	if (!blurShader.loadFromFile("blur.frag", sf::Shader::Fragment)) {}
	//////////////////////////////////////////////////////////////////////
	if (!background.loadFromFile("background.png")) {}
	sndPlayer.loadUp("click.wav"); //sound of buttons - load
	sound.setLoop(false); //sound loop
	sound.setBuffer(*sndPlayer.getBuffer()); //sound buffer
	backgroundsprite.setTexture(background);
	blurShader.setUniform("texture", sf::Shader::CurrentTexture);
	blurShader.setUniform("blur_radius", 0.001f);

	circle.setRadius(20);
	circle.setFillColor(sf::Color::Yellow);
	
	rt_S.create(circle.getRadius() * 100, circle.getRadius() * 100);
	rt_S.clear(sf::Color(0, 0, 0, 0));
	circle.setPosition(rt_S.getSize().x / 2, rt_S.getSize().y / 2);
	rt_S.draw(circle);
	rt_S.display();
	fastsprite.setTexture(rt_S.getTexture());
	for (int i = 100; i >= 0; i--) {
		rt_S.draw(fastsprite, &blurShader);
		rt_S.display();
		fastsprite.setTexture(rt_S.getTexture());
	}

	//fastsprite.setPosition(sf::Vector2f(rand() % (*targetwindow).getSize().x, (*targetwindow).getSize().y + 200));
	fastsprite.setOrigin(fastsprite.getLocalBounds().width / 2, fastsprite.getLocalBounds().height / 2);
	fastsprite.setPosition(500, 500);
	tlo.create(1280, 720);
	tlo.clear();
	for (int i = 100; i >= 0; i--) {
		sf::RenderStates states;
		blend = sf::BlendAlpha;
		blend.colorSrcFactor = blend.One;
		states.blendMode = blend;
		states.shader = &blurShader;
		tlo.draw(backgroundsprite, states);
		tlo.display();
		backgroundsprite.setTexture(tlo.getTexture());
	}
	backgroundsprite.setPosition(0, 0);

	///////////////////////////////////////////////////////////////////
	texts[0].setFont(fonts[0]);
	texts[0].setCharacterSize(12);
	texts[0].setPosition(sf::Vector2f((*targetwindow).getSize().x*0.02f, (*targetwindow).getSize().y*0.97f));
	texts[0].setString("Ver. 0.1.26 debug no. 1");
	texts[0].setFillColor(sf::Color(255, 150, 0));
	////////////////////////////////////////////////////////////////////
	for (int i = 4; i >= 0; i--) {
		przycisk[i].createButton(170, 57, targetwindow, sf::Color(0, 0, 0));
		przycisk[i].setFont(&fonts[1]);
		przycisk[i].setCharacterSize(20);
		przycisk[i].setFillColor(sf::Color(255, 255, 255));
	}
	////////////////////////////////////////////////////////////////////////
	przycisk[0].setString(L"Tabela Poziomów");
	przycisk[0].placeButton(0.87f, 0.25f, "center");
	przycisk[0].setBorder(1, sf::Color(255,255,255), sf::Color(0,0,0));

	przycisk[1].setString("Szybka Gra");
	przycisk[1].placeButton(0.87f, 0.35f, "center");
	przycisk[1].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));

	przycisk[2].setString(L"Twórcy");
	przycisk[2].placeButton(0.87f, 0.45f, "center");
	przycisk[2].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));

	przycisk[3].setString("Ustawienia");
	przycisk[3].placeButton(0.87f, 0.55f, "center");
	przycisk[3].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));

	przycisk[4].setString(L"Wyjœcie");
	przycisk[4].placeButton(0.87f, 0.8f, "center");
	przycisk[4].setBorder(1, sf::Color(255, 255, 255), sf::Color(0, 0, 0));
}

void menu::updateMainMenu() {
	fastsprite.setPosition(fastsprite.getPosition().x, fastsprite.getPosition().y-1);
	//circle.setPosition(circle.getPosition().x, circle.getPosition().y - 2);
	//if (rand() % 2) {
	//	circle.move(rand() % 3, -rand() % 5);
	//}
	//else {
	//	circle.move(-rand() % 3, -rand() % 5);
	//}
	//if (rand() % 2) {
	//	fastsprite.move(rand() % 3, -rand() % 5);
	//}
	//else {
	//	fastsprite.move(-rand() % 3, -rand() % 5);
	//}


	przycisk[0].checkButton(sf::Color(255, 255, 255));
	przycisk[1].checkButton(sf::Color(255, 255, 255));
	przycisk[2].checkButton(sf::Color(255, 255, 255));
	przycisk[3].checkButton(sf::Color(255, 255, 255));
	przycisk[4].checkButton(sf::Color(255, 255, 255));

	if (przycisk[0].isClicked()) {
		ip = 1;
		sound.play();
	}
	if (przycisk[1].isClicked()) {
		op = 2;
		sound.play();
	}
	if (przycisk[2].isClicked()) {
		op = 3;
		sound.play();
	}
	if (przycisk[3].isClicked()) {
		ip = 2;
		sound.play();
		setties.setIp(ip);
	}
	if (przycisk[4].isClicked()) {
		sound.play();
		sf::sleep(sf::milliseconds(200));
		exit(0);
	}
}

//////////////////////////////////////////////////////////////////////////////
void menu::loadTable() {
	/* tabela poziomow */
	loader.loadUp("table.txt");
	ilepoziomow = loader.getNumber() / 2;
	linia = loader.getString();

	ilezakladek = (int)std::ceil((float)ilepoziomow / (float)12);//12 poziomow na zakladke
	ilepustych = 12-(ilepoziomow % 12);//ile zostaje kratek bez poziomu w ostatniej zakladce
	miniaturyS = new sf::Sprite[12*ilezakladek+1];
	miniaturyT = new sf::Texture[ilepoziomow+1];
	int y=0;
	int lm = 0;

	powrot.createButton(170, 57, targetwindow, sf::Color::Black);
	powrot.setFont(&fonts[1]);
	powrot.setCharacterSize(20);
	powrot.setFillColor(sf::Color(255, 255, 255));
	powrot.setString(L"Powrót");
	powrot.placeButton(0.15f, 0.15f, "center");
	powrot.setBorder(1, sf::Color(255, 180, 20), sf::Color::Black);

	std::cout << ilezakladek << std::endl;
	for (int i = 1; i <= ilezakladek; i++) {
		for (int q = 1; q <= 12; q++) {
			lm = (q-1) % 4;
			if ((q-1) % 4 == 0) {
				y += 160;
			}
			if (i == ilezakladek && q > ilepoziomow % 12 ) { //jezeli to ostatnia zakladka a poziomow jest mniej niz 12
				pixels = new sf::Uint8[150 * 100 * 4];
				hm.create(150, 100);
				hm.update(pixels);
				miniaturyS[q*i].setTexture(hm);
				miniaturyS[q*i].setColor(sf::Color(0, 0, 0,255));
			}
			else {
				miniaturyT[q*i].loadFromFile(linia[q * 2]);//ladowanie miniatur
				miniaturyS[q*i].setTexture(miniaturyT[q*i]);
			}
			miniaturyS[q*i].setOrigin(sf::Vector2f(miniaturyS[q*i].getGlobalBounds().width / 2, miniaturyS[q*i].getGlobalBounds().height / 2));
			miniaturyS[q*i].setPosition((lm * 170)+385.0f, y+50.0f);//pozycja sprite
			std::cout << miniaturyS[q*i].getPosition().x << std::endl;
			std::cout << miniaturyS[q*i].getPosition().y << std::endl;
		}
		y = 0;//zerowanie pozycji y dla nastepnej zakladki
	}
}
///////////////////////////////////////////////////////////////////////////////

void menu::drawTable() {
	powrot.drawButton();
	for (int i = 1; i <= 12; i++) {
		(*targetwindow).draw(miniaturyS[i*qp]);
	}
	for (int i = 1; i <= ilepoziomow; i++){
		miniaturyS[i].setScale(sf::Vector2f(1.0, 1.0));
	}
}
/////////////////////////////////////////////////////////////////////////////
void menu::updateTable() {
	powrot.checkButton(sf::Color(255, 255, 255));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || powrot.isClicked()) {
		ip = 0;
		sound.play();
	}
	for (int i = 1; i <= ilepoziomow; i++) {
		sf::FloatRect rect = miniaturyS[i].getGlobalBounds();
		if (rect.contains(sf::Vector2f(sf::Mouse::getPosition((*targetwindow))))) {
			miniaturyS[i].setScale(sf::Vector2f(1.2f, 1.2f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				op = 1;
				sound.play();
				mapa = linia[i * 2-1];
			}
		}
	}
}

sf::Keyboard::Key * menu::getSetts() {
	return setties.getSetts();
}

string menu::getMap() {
	return mapa;
}

settings * menu::passSets() {
	return &setties;
}
