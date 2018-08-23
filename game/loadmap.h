#include "stdafx.h"
#include "FileToString.h"

#include "VirtLoad.h"
#pragma once

/*
schemat pliku mapy:
-naglowek:
*texture
*font
*spriteM
*spriteT
*text
*protagonistStart
*enemySpawn
*star
*endPoint
-tresc zalezna od naglowka
-komentarze miedzy naglowkami pod trescia
*/


class loadmap
{
private:
	/**new ver.*/
	sf::Sprite tempS;
	sf::Texture tempT;
	sf::Vector2f tempV;
	std::string tempStr;
	std::vector <sf::Texture> V_textures;
	std::vector <sf::Sprite> V_Hsprites;
	std::vector <sf::Sprite> V_ForwImgs;
	std::vector <sf::Sprite> V_BackImgs;
	std::vector <sf::Vector2f> V_EnemCoord;
	std::vector <std::string> V_EnemType;
	std::vector <std::string> V_AnimSrc;
	sf::RenderTarget *drawTarget = NULL;
	sf::Font *A_font = NULL;
	sf::Text *A_texts = NULL;
	sf::Vector2f *A_EnemCoord = NULL;
	sf::Vector2f* A_ProtCoord = NULL;

	std::string *A_Lines = NULL;
	std::string *A_AnimSrc = NULL;
	std::string *A_EnemType = NULL;
	int N_Lines = 0;
	int N_texts = 0, N_fonts = 0;//texts
	int N_textures = 0, N_spritesM = 0, N_spritesT = 0;//sprites
	int N_starts = 0, N_stars = 0, N_spawns = 0, N_ends = 0;//gameplay
	FileToString loader;

	void checker();
	void reset();
	void loadtexture(int * i);
	void loadfont(int * i);
	void loadBackSprite(int * i);
	void loadForwSprite(int * i);
	void loadspriteT(int * i);
	void loadtext(int * i);
	void setStart(int * i);
	void setSpawn(int * i);
	void setStar(int * i);
	void setEnd(int * i);

public:
	loadmap();
	void loadUp(std::string map, sf::RenderTarget * target);
	void drawText();
	void drawForwImgs();
	void drawBackImgs();
	void drawCollisables();
	sf::Vector2f PlayerCoords();
	sf::Vector2f * EnemyCoords();
	std::string * eAnimSource();
	std::string * EnemyType();
	int CollisionNum();
	int EnemyNumber();
	sf::Sprite * Collisionable();
};