#include "GameRun.h"



GameRun::GameRun()
{
}

void GameRun::loadUp()
{
	window.create(sf::VideoMode(1280, 720, 32), "panda's game", 7);
	//window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);
	sieci.setUp();
	meni = new menu();
	(*meni).setWindow(&window);
}

void GameRun::everything()
{
	while (window.isOpen())//petla programu
	{
		zdarzenia.Handler(&window);
		if ((*meni).getOP() == 0) {
			if ((*meni).getLoadMenu()) {//wydarzenia wywolywane raz podczas trybu
				BgMusic.OpenNPlay("MenuMusic.wav");
				(*meni).setLoadMenu(false);
			}
			////////////////////////////////////////////////////////////////
			kamera.getValuesWindow(&window);
			kamera.cameraUpdateMain();
			(*meni).menuUpdate(zdarzenia.returnKey());
			////////////////////////////////////////////////////////////////
			window.clear(sf::Color(230, 230, 230));
			(*meni).menuDraw();
			window.display();
		}
		if ((*meni).getOP() == 1) {
			if (game_menu.load()) { //wydarzenia wywolywane raz podczas trybu
				wrogowie = new Enemy();
				filtr = new Filters();
				BgMusic.OpenNPlay("walkthewalk.flac");
				game_menu.inGameLoad(&window);
				(*filtr).setWindow(&window);
				map.loadUp((*meni).getMap(), &window);
				playerAnim.loadAnimations("anim.txt");
				bohater.setUp(map.PlayerCoords(), playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum(), (*meni).getSetts());
				(*wrogowie).setUp(playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum(), map.EnemyNumber(), map.EnemyCoords(), map.eAnimSource(), map.EnemyType());
				hud.setUp(&window, map.Collisionable(), map.CollisionNum(), playerAnim.getCurrentFrame());
				kamera.getValues(playerAnim.getCurrentFrame(), &window);
				(*filtr).setNoctovision(sf::Vector2i(kamera.getSize()));
				wzrok.setUp(&window, map.Collisionable(), map.CollisionNum());
				game_menu.setLoadFalse();
				watek = new std::thread(std::bind(&GameRun::update, this));
				watek->detach();
			}
			///////////////////////////////////////////////////////////////////////////////
			
			
			if (game_menu.pauseCheck(zdarzenia.isEscapePressed()) == false) {
				hud.update(100);
				kamera.cameraUpdate();
				(*filtr).activeNoctovision(bohater.noctovision());
				wzrok.update(kamera.getPosition());
				bohater.pause(false);
				(*wrogowie).pause(false);
				bohater.Check();
			}
			else {

			}
			///////////////////////////////////////////////////////////////////////////////
			window.clear(sf::Color(230, 230, 230));
			map.drawBackImgs();
			map.drawCollisables();
			map.drawText();
			(*wrogowie).draw(&window);
			playerAnim.drawAnimation(&window);
			(*filtr).drawNoctovision(kamera.getPosition());
			hud.draw();
			wzrok.draw();
			map.drawForwImgs();
			if (game_menu.pauseCheck(zdarzenia.isEscapePressed()) == true) {
				game_menu.inGameDraw();
			}
			window.display();
		}
		if ((*meni).getOP() == 2) {
			if (c == 1) { //wydarzenia wywolywane raz podczas trybu
				wrogowie = new Enemy();
				//filtr = new Filters();
				//(*filtr).setWindow(&window);
				map.loadUp("mapa2.txt", &window);
				playerAnim.loadAnimations("anim.txt");
				hud.setUp(&window, map.Collisionable(), map.CollisionNum(), playerAnim.getCurrentFrame());
				bohater.setUp(map.PlayerCoords(), playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum(), (*meni).getSetts());
				kamera.getValues(playerAnim.getCurrentFrame(), &window);
				//(*filtr).setNoctovision(sf::Vector2i(kamera.getSize()));
				(*wrogowie).setUp(playerAnim.getCurrentFrame(), map.Collisionable(), map.CollisionNum());
				sieci.connect(wrogowie);
				c--;
			}
			///////////////////////////////////////////////////////////////////////////////
			//(*filtr).activeNoctovision(bohater.noctovision());
			hud.update(50);

			playerAnim.listener(bohater.GetAnimation());
			kamera.cameraUpdate();
			(*wrogowie).update();
			sieci.refresh(bohater.GetAnimation(), (*playerAnim.getCurrentFrame()).getPosition());
			///////////////////////////////////////////////////////////////////////////////
			window.clear(sf::Color(230, 230, 230));
			map.drawBackImgs();
			map.drawCollisables();
			map.drawText();
			(*wrogowie).draw(&window);
			playerAnim.drawAnimation(&window);
			//(*filtr).drawNoctovision(kamera.getPosition());
			map.drawForwImgs();
			hud.draw();
			window.display();
		}
	}
}

void GameRun::update()
{
	while (1) {
		if (game_menu.pauseCheck(zdarzenia.isEscapePressed()) == false) {

			hud.restart();
			bohater.Check();
			playerAnim.listener(bohater.GetAnimation());
			(*wrogowie).update();




		}
		else {
			bohater.pause(true);
			(*wrogowie).pause(true);
			hud.stop();
			game_menu.inGameUpdate(kamera.getPosition(), meni, zdarzenia.returnKey());
		}
		sf::sleep(sf::seconds(1.f / 30.f));
		if (game_menu.load()) {
			break;
		}
	}
}


GameRun::~GameRun()
{
}
