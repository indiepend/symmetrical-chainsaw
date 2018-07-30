// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "loadmap.h"
#include "Movin.h"
#include "HUD.h"
#include "Protagonist.h"
#include "Camera.h"
#include "menu.h"
#include "Filters.h"
#include "Animation.h"
#include "Enemy.h"
#include "Events.h"
#include "Sight.h"
#include "inGame_Menu.h"
#include "MusicPlayer.h"
#include "Network.h"
#include "networkEnemy.h"


#include "GameRun.h"
/*******************************************************************************
Ver. 0.1.26 debug nr. 1 / SFML ver 2.5.0 / 32-bit debug

zmiany od 0.1.2:
-wybieranie sterowania
-stringi ze znakami unicode
-miernik naprawiony
-menu ingame
-wprowadzenie muzyki w tle w menu i na poziomach
-nowy-responsywniejszy sposob wczytywania i projektowania map
-kompletny HUD
*automatycznie generowana minimapa
*czas nad samej gorze
*pasek zycia
-ulepszone menu
*dzwieki menu

zmiany od 0.1.1:
-wprowadzony miernik czasu w gore i w dol(nie wiem jakim cudem dziala; do przepisania)
-projektowanie map z pliku txt (obiektowo)(przestarzale)
-u gory czas jaki udalo sie przetrwac (obiektowo)
-chodzenie i skakanie (obiektowo)
-kolizje(przestarzale)
-kamera
-filtry kamery
*blur
*noktowizja
-menu
-tryby gry
-tablica z lvlami
-plynne chodzenie
-plynna kamera
-rozne sprite dla czynnosci
-skok w zale¿noœci od czasu trzymania klawisza
-punkty zycia
-atakowanie
-animacje
-wprowadzenie przeciwnikow
-wprowadzenie wzroku podstawowego
-podstawowe AI przeciwnikow
-oddzielna klasa dla wydarzen

W trakcie:
-wprowadzenie dŸwieku +
-wprowadzenie wzroku zaawansowanego
-ulepszone menu
*wincyj opcji
*jakieœ unosz¹ce siê cz¹steczki w tle +
-ustawienie natezenia dzwiekow i muzyki
-scroll bar ^
-tryb sieciowy DM //przejscie do wersji 0.1.3 prealpha
*tcp +++
*udp ++
*klasa spinajaca ++
*klasa odbierajaca info
*klasa networkEnemy ++
*wdrozenie +

Bugi:
-dokonczenie klasy loadmap dla tekstu

do wprowadzenia w nastepnych wersjach:
-animationSource <--- klasa zarzadzania animacjami
-walka
-zabicie przeciwnikow jako koniec poziomu
-rozne typy przeciwnikow
-animacje mieszane
-tryb coop na jednej klawiaturze
-tryb sieciowy coop
-nowe kolizje
-stworzenie watku odswiezajacego i sprawdzajacego
-ulepszone menu
*lepsiejsze animacje
-optymalizacje
-3 gwiazdki, jedna za pokonanie przeciwnikow, druga za dotarcie na wyznaczony punkt na mapie, trzecia za czas
*******************************************************************************/

using namespace std;

int main()
{
	//GameRun game;
	//game.loadUp();
	//game.everything();
	Sight wzrok;
	Filters *filtr=NULL;
	loadmap map;
	MusicPlayer BgMusic;
	HUD hud;
	inGame_Menu game_menu;
	Protagonist bohater;
	Enemy *wrogowie=NULL;
	Animation playerAnim, animacjePrzeciwnikow;
	Camera kamera;
	Network sieci(Network::setIt::Up);
	networkEnemy netEnem;
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "panda's game",7);
	menu meni(&window);
	window.setFramerateLimit(30);
	Events zdarzenia;
	int a = 1, b = 1, c = 1;
	srand((int)time(0));
	while (window.isOpen())//petla programu
	{
		zdarzenia.Handler(&window);
		if (meni.getOP() == 0) {
			 if(meni.getLoadMenu()){//wydarzenia wywolywane raz podczas trybu
				 BgMusic.OpenNPlay("MenuMusic.wav");
				meni.setLoadMenu(false);
			}
			////////////////////////////////////////////////////////////////
			kamera.getValuesWindow(&window);
			kamera.cameraUpdateMain();
			meni.menuUpdate(zdarzenia.returnKey());
			////////////////////////////////////////////////////////////////
			window.clear(sf::Color(230, 230, 230));
			meni.menuDraw();
			window.display();
		}
		if (meni.getOP() == 1) {
			if(game_menu.load()) { //wydarzenia wywolywane raz podczas trybu
				wrogowie = new Enemy();
				filtr = new Filters();
				BgMusic.OpenNPlay("walkthewalk.flac");
				game_menu.inGameLoad(&window);
				(*filtr).setWindow(&window);
				map.loadUp(meni.getMap(), &window);
				playerAnim.loadAnimations("anim.txt");
				bohater.setUp(map.PlayerCoords(), playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum(),meni.getSetts());
				(*wrogowie).setUp(playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum(), map.EnemyNumber(), map.EnemyCoords(), map.eAnimSource(), map.EnemyType());
				hud.setUp(&window, map.Collisionable(), map.CollisionNum(), playerAnim.getCurrentFrame());
				kamera.getValues(playerAnim.getCurrentFrame(), &window);
				(*filtr).setNoctovision(sf::Vector2i(kamera.getSize()));
				wzrok.setUp(&window, map.Collisionable(), map.CollisionNum());
				game_menu.setLoadFalse();
			}
			///////////////////////////////////////////////////////////////////////////////
			if (game_menu.pauseCheck(zdarzenia.isEscapePressed()) == false) {
				(*filtr).activeNoctovision(bohater.noctovision());
				hud.restart();
				bohater.Check();
				playerAnim.listener(bohater.GetAnimation());
				(*wrogowie).update();
				kamera.cameraUpdate();
				hud.update(100);
				wzrok.update(kamera.getPosition());
				bohater.pause(false);
				(*wrogowie).pause(false);
			}
			else {
				bohater.pause(true);
				(*wrogowie).pause(true);
				hud.stop();
				game_menu.inGameUpdate(kamera.getPosition(), &meni, zdarzenia.returnKey());
			}
			///////////////////////////////////////////////////////////////////////////////
			window.clear(sf::Color(230, 230, 230));
			map.drawSoftSprites();
			map.drawHardSprites();
			map.drawText();
			(*wrogowie).draw(&window);
			playerAnim.drawAnimation(&window);
			(*filtr).drawNoctovision(kamera.getPosition());
			hud.draw();
			wzrok.draw();
			//if (game_menu.pauseCheck(zdarzenia.isEscapePressed()) == false) {
				game_menu.inGameDraw();
			//}
			window.display();
		}
		if (meni.getOP() == 2) {
			if(c==1){ //wydarzenia wywolywane raz podczas trybu
				wrogowie = new Enemy();
				//filtr = new Filters();
				//(*filtr).setWindow(&window);
				map.loadUp("mapa2.txt", &window);
				playerAnim.loadAnimations("anim.txt");
				hud.setUp(&window, map.Collisionable(), map.CollisionNum(), playerAnim.getCurrentFrame());
				hud.setEvents(&zdarzenia,&sieci);
				bohater.setUp(map.PlayerCoords(), playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum(), meni.getSetts());
				kamera.getValues(playerAnim.getCurrentFrame(), &window);
				//(*filtr).setNoctovision(sf::Vector2i(kamera.getSize()));
				(*wrogowie).setUp(playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum());
				sieci.connect(wrogowie);
				c--;
			}
			///////////////////////////////////////////////////////////////////////////////
			//(*filtr).activeNoctovision(bohater.noctovision());
			hud.netUpdate(50);
			bohater.Check();
			playerAnim.listener(bohater.GetAnimation());
			kamera.cameraUpdate();
			(*wrogowie).update();
			sieci.refresh(bohater.GetAnimation(), (*playerAnim.getCurrentFrame()).getPosition());
			///////////////////////////////////////////////////////////////////////////////
			window.clear(sf::Color(230, 230, 230));
			map.drawSoftSprites();
			map.drawHardSprites();
			map.drawText();
			(*wrogowie).draw(&window);
			playerAnim.drawAnimation(&window);
			//(*filtr).drawNoctovision(kamera.getPosition());
			hud.netDraw();
			window.display();
		}
	}
}
//int main() {
//	sf::Vector2i v;
//	float skok,grawitacja, velocity;
//	int x, y, op, petla = 1, ilesprite = 3, hsprite, tsprite, lsprite, xsprite, ax, as, ah, tanim, klatka, fps, wpowietrzu2 = 0, speed;
//	bool kolizja = false, kolizjay = false, wpowietrzu = false;
//	std::string klatki;
//	int ruch[3];
//	sf::FloatRect nice;
//	sf::FloatRect boh;
//	sf::Color test(255, 255, 255);
//	sf::Time czas;
//	sf::Time czas2 = sf::seconds(0);
//	sf::Clock stoper;
//	sf::Clock zegar;
//
//
//	sf::Font font;
//	if (!font.loadFromFile("arial.ttf"))
//	{
//		// error...
//	}
//
//	sf::Text text;
//	text.setFont(font);
//	text.setString("menu:");
//	text.setPosition(1475, 150);
//	text.setCharacterSize(50);
//	text.setFillColor(test);
//	sf::Text opcje[10];
//	for (int i = 0; i < 10; i++) {
//		opcje[i].setFont(font);
//		opcje[i].setCharacterSize(35);
//		opcje[i].setFillColor(test);
//	}
//	opcje[0].setString("kampania");
//	opcje[0].setPosition(1550, 250);
//	opcje[1].setString("szybka gra");
//	opcje[1].setPosition(1550, 350);
//	opcje[2].setString("opcje");
//	opcje[2].setPosition(1550, 450);
//	opcje[3].setString("wyjdz");
//	opcje[3].setPosition(1550, 550);
//
//	sf::Text klatek;
//	klatek.setFont(font);
//	klatek.setPosition(1475, 150);
//	klatek.setCharacterSize(50);
//	klatek.setFillColor(test);
//	sf::Time sekunda = sf::seconds(0);
//
//	sf::Texture tekstura;
//	if (!tekstura.loadFromFile("textura.png", sf::IntRect(0, 0, 1920, 1080)))
//	{
//		// error...
//	}
//
//	sf::Sprite sprite;
//	sprite.setTexture(tekstura);
//	sprite.setPosition(0, 0);
//
//	sf::Texture tekstura2;
//	if (!tekstura2.loadFromFile("podloga.png", sf::IntRect(0, 0, 1920, 100)))
//	{
//		// error...
//	}
//	sf::Texture tekstura4;
//	if (!tekstura4.loadFromFile("skrzynia.png"))
//	{
//		// error...
//	}
//	sf::Texture tekstura5;
//	if (!tekstura5.loadFromFile("patyczakstoi.png"))
//	{
//		// error...
//	}
//	sf::Texture tekstura6;
//	if (!tekstura6.loadFromFile("wskaznik.png"))
//	{
//		// error...
//	}
//
//	sf::Sprite spritet[3];//textury twarde
//	spritet[0].setTexture(tekstura2);
//	spritet[0].setPosition(0, 930);
//	spritet[1].setTexture(tekstura4);
//	spritet[1].setPosition(888, 880);
//	spritet[2].setTexture(tekstura4);
//	spritet[2].setPosition(0, 880);
//
//	sf::Sprite sprite5;
//	sprite5.setTexture(tekstura5);
//	sprite5.setPosition(500, 530);
//	sf::Sprite sprite6;
//	sprite6.setTexture(tekstura6);
//
//	sf::RenderWindow okno(sf::VideoMode(1920, 1080), "testy", sf::Style::Fullscreen);
//	okno.setMouseCursorVisible(false);
//	op = 0;
//
//	sf::Event event;
//
//	while (okno.isOpen())
//	{
//		while (okno.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				exit(0);
//			else if (event.key.code == sf::Keyboard::Escape)
//				exit(0);
//		} //while
//
//		v = sf::Mouse::getPosition();
//		x = v.x;
//		y = v.y;
//		switch (op)
//		{
//
//		case 0://menu
//		{
//
//			sprite6.setPosition(v.x, v.y);
//
//			sf::FloatRect kolizja = opcje[0].getGlobalBounds();
//			if (kolizja.contains(sf::Vector2f(v.x, v.y))) {
//				opcje[0].setStyle(sf::Text::Bold);
//				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					op = 1;
//			}
//			kolizja = opcje[1].getGlobalBounds();
//
//			if (kolizja.contains(sf::Vector2f(v.x, v.y))) {
//				opcje[1].setStyle(sf::Text::Bold);	
//				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
//					op = 2;
//			}
//			kolizja = opcje[2].getGlobalBounds();
//
//			if (kolizja.contains(sf::Vector2f(v.x, v.y))) {
//				opcje[2].setStyle(sf::Text::Bold);
//				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					op = 3;
//			}
//			kolizja = opcje[3].getGlobalBounds();
//
//			if (kolizja.contains(sf::Vector2f(v.x, v.y))) {
//				opcje[3].setStyle(sf::Text::Bold);
//				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					exit(0);
//			}
//
//			okno.clear();
//			okno.draw(text);
//			okno.draw(sprite6);
//			for (int i = 0; i < 10; i++) {
//				okno.draw(opcje[i]);
//			}
//			okno.display();
//
//			opcje[0].setStyle(sf::Text::Regular);
//			opcje[1].setStyle(sf::Text::Regular);
//			opcje[2].setStyle(sf::Text::Regular);
//			opcje[3].setStyle(sf::Text::Regular);
//			opcje[4].setStyle(sf::Text::Regular);
//
//			break;
//		}
//		case 1: {
//			cout << "heh" << endl;
//			while (petla == 1) {
//				zegar.restart();
//				petla = 0;
//			}
//			//            sekunda += zegar.restart();
//			//            if(sekunda.asseconds()>=1){
//			//                fps = klatka/60;
//			//                zegar.restart();
//			//                klatka=0;
//			//                std::ostringstream ss;
//			//                ss << fps;
//			//                klatki = ss.str();
//			//                klatek.setstring(klatki);
//			//            }
//			//            klatka++;
//
//			boh = sprite5.getGlobalBounds();
//			as = boh.left;
//			ax = boh.width;
//			ah = boh.height;
//			tanim = boh.top;
//			cout << "heh" << endl;
//			for (int i = 0; i <= ilesprite; i++) {
//				nice = spritet[i].getGlobalBounds();
//				lsprite = nice.left;
//				xsprite = nice.width;
//				tsprite = nice.top;
//				hsprite = nice.height;
//				if (lsprite == (as + ax) && (((tanim + ah) > tsprite && tanim < tsprite) || (tanim<(tsprite + hsprite) && (tanim + ah)>(tsprite + hsprite))))
//				{
//					kolizja = true;
//				}
//				else if ((lsprite + xsprite) == as && (((tanim + ah) > tsprite && tanim < tsprite) || (tanim<(tsprite + hsprite) && (tanim + ah)>(tsprite + hsprite))))
//				{
//					kolizja = true;
//				}
//			}
//			cout << "heh" << endl;
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//			{
//				if (kolizja == false) {
//					czas = zegar.getElapsedTime();
//					sprite5.move(-350 * czas.asSeconds(), 0);
//				}
//				else {
//					sprite5.move(0, 0);
//				}
//			}
//			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//			{
//				if (kolizja == false) {
//					czas = zegar.getElapsedTime();
//					sprite5.move(350 * czas.asSeconds(), 0);
//				}
//				else {
//					sprite5.move(0, 0);
//				}sf::Clock zegar;
//			}
//			//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && wpowietrzu==false)
//			//            {
//			//            wpowietrzu=true;
//			//            stoper.restart();
//						//czas2 = sf::seconds(0);
//			//            }
//
//						//if (wpowietrzu == true) {
//						//	//skok
//						//	//x=//v0t-//gt2/2
//						//		czas2 += stoper.restart();
//						//		grawitacja = pow(czas2.asSeconds(),2)/200;
//						//		velocity = 50 * czas2.asSeconds();
//						//		if (kolizjay == false) {
//						//			speed = grawitacja;
//						//	 	}
//						//		else {
//						//			speed = -grawitacja;
//						//		}
//						//		sprite5.move(0, speed);
//						//		    if(kolizjay == true){
//						//				speed = 0;
//						//		    }
//
//						//	}
//
//						                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && wpowietrzu==false)
//						                {
//						                wpowietrzu=true;
//						                wpowietrzu2=1;
//						                stoper.restart();
//						                }
//										for (int i = 0; i <= ilesprite; i++) {
//											nice = spritet[i].getGlobalBounds();
//											lsprite = nice.left;
//											tsprite = nice.top;
//											xsprite = nice.width;
//											if (tsprite == (tanim + ah) && (((as + ax) > lsprite) && (as < (lsprite + xsprite))))
//											{
//												kolizjay = true;
//											}
//										}
//										if (kolizjay == true) {
//											speed = 0;
//											wpowietrzu = false;
//										}
//										else {
//											wpowietrzu = true;
//											wpowietrzu2 = 2;
//										}
//
//										if (wpowietrzu == true) {
//															cout << kolizjay << endl;
//															cout << wpowietrzu << endl;
//															cout << wpowietrzu2 << endl;
//											switch (wpowietrzu2) {
//											case 1: {//skok
//												czas2 += stoper.restart();
//												speed = 6 + -pow(czas2.asSeconds(), 2);
//												sprite5.move(0, speed);
//												if (speed <= 0) {
//													wpowietrzu = false;
//													wpowietrzu2 = 0;
//													czas2 = sf::seconds(0);
//												}
//												break;
//											}
//											case 2: {//opadanie
//												if (kolizjay == false) {
//													czas = zegar.getElapsedTime();
//													speed =  pow(czas.asMilliseconds(), 2);
//											//		speed = czas.asMicroseconds();
//													sprite5.move(0, speed);
//												}
//												else {
//													wpowietrzu = false;
//													wpowietrzu2 = 0;
//												}
//												break;
//											}
//
//											}
//										}
//										cout << "heh" << endl;
//				zegar.restart();
//				okno.clear();
//				okno.draw(sprite);
//				okno.draw(sprite5);
//				okno.draw(klatek);
//				for (int i = 0; i < ilesprite; i++) {
//					okno.draw(spritet[i]);
//				}
//				okno.display();
//				kolizja = false;
//				kolizjay = false;
//				//                if (event.key.code == sf::keyboard::escape)
//				//                 op=2;//wejscie do menu
//								//kampania
//				break;
//
//			}
//		case 2:
//			sprite6.setPosition(x, y);
//
//			//szybka gra
//			break;
//		case 3:
//			//opcje
//			break;
//		}
//		}
//	}
//	
//bool sprawdzenie(sf::FloatRect& boh,sf::FloatRect& nice){
//                bool kolizja;
//                int hsprite,tsprite,lsprite,xsprite,ax,as,ah;
//				int tanim = 0;
//                as=boh.left;
//                ax=boh.width;
//                ah=boh.height;
//
//                lsprite=nice.left;
//                xsprite=nice.width;
//                tsprite=nice.top;
//                hsprite=nice.height;
//                if ((lsprite+xsprite)==as && (((tanim+ah)>tsprite && tanim<tsprite) || (tanim<(tsprite+hsprite) && (tanim+ah)>(tsprite+hsprite))))
//                    {
//                return kolizja=true;
//                }
//                else
//                return kolizja=false;
//}
/*
void enemyAI(){
while(bpozycja - epozycja <= 1000){void stoj();}
if(bpozycja - epozycja <= 5){
void ezaatakujwprawo();
}
else if(bpozycja - epozycja >= -5){
void ezaatakujwlewo();
}
else if(bpozycja > epozycja)
{
void eidzwprawo();
}
else if(bpozycja < epozycja)
{
void eidzwlewo();
}

}
*/