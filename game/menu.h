#pragma once
#include "stdafx.h"
#include "Button.h"
#include "FileToString.h"
#include "StringToFile.h"
#include "Key.h"
#include "settings.h"
#include "SoundPlayer.h"

using namespace std;

class menu
{
	//////////////////////////sfml///////////////////////////////
	sf::Sprite * miniaturyS=NULL;
	sf::Texture * miniaturyT = NULL;
	sf::Texture background;
	sf::Texture hm;
	sf::Uint8 * pixels = NULL;
	sf::Text texts[6];
	sf::Font fonts[2];
	sf::Shader blurShader,pixelShader;
	sf::Sprite backgroundsprite,buttons[4],fastsprite;
	sf::RenderWindow * targetwindow = NULL;
	sf::RenderTexture tlo,tlo2;
	sf::RenderTexture rt_S;
	sf::Sprite bg_S;
	sf::Text setts[10];
	sf::Text otherSets[10];
	sf::View rt_View;
	sf::RenderTexture gray_S;
	sf::Sprite Sgray_S;
	sf::Text text_S;
	sf::Keyboard::Key keyBOARD[6];
	sf::CircleShape circle;
	sf::Sound sound;
	////////////////////////zmienne/////////////////////////
	int qp = 1;/*przelacznik zakladek*/
	int	op = 0;/*przelacznik trybow gry*/
	int	ip = 0;//przelacznik menu
	int ilezakladek,ilepustych,ilepoziomow,anotherBagOfInts;//
	bool clicked_S,change=false,loadMenu=true;
	string * linia = NULL;
	string * ustawienia = NULL;
	string mapa;
	Button przycisk[5];
	Button powrot;
	Button sterowanie[6];
	FileToString loader,loader2;
	StringToFile writer;
	sf::Vector2f cameraPos;
	Key keyString;
	settings setties;
	SoundPlayer sndPlayer;
	/////////////////////////metody/////////////////////////
	void drawMainMenu(); //rysowanie menu glownego
	void drawTable(); //rysowanie tabeli poziomow
	void loadTable();//ladowanie tabeli poziomow
	void loadMainMenu();//ladowanie menu glownego
	void updateMainMenu();//aktualizacja glownego menu
	void updateTable();//aktualizacja tabeli

public:
	string getMap();
	void menuDraw();
	void menuUpdate(sf::Keyboard::Key key);
	sf::Keyboard::Key * getSetts();
	int getOP();
	void setOP(int OP);
	settings * passSets();
	void setLoadMenu(bool Load);
	bool getLoadMenu();
	menu(sf::RenderWindow * window);
	menu();
	void setWindow(sf::RenderWindow * window);
	//~menu();
};

