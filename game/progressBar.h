#include "stdafx.h"
#pragma once

using namespace std;

class progressBar
{
public:
	enum class Type {
		backgroundSprite = 0,
		barSprite
	};
	enum class Direction {
		horizontal = 0,
		vertical
	};
private:
	enum class Loading {
		toLoad = 0,
		Loaded
	};
	sf::RenderTexture wholeRend,barRend,bgRend,borderRend;
	sf::Sprite border, bar, bg, whole;
	int ARG_width, ARG_height,ARG_coordX,ARG_coordY;
	float step, ARG_measurable;
	sf::Color ARG_barColor=sf::Color(255,255,255), ARG_bgColor = sf::Color(0, 0, 0), ARG_borderColor = sf::Color(0,0,0);
	progressBar::Direction ARG_dir;
public:
	//\Brief:
	//\direction "horizontal" or "vertical" - default vertical
	//\width and height in pixels
	//\measurable is float which bar shows as max
	void create(int,int,float, Direction = Direction::vertical);
	void setBorder(int, sf::Color);
	void setColors(sf::Color, sf::Color);
	void customSprite(sf::Sprite, Type);
	void placeBar(int, int);
	//\Brief:
	//\measured is actual value which bar shows
	//\if measured is bigger than max nothing happens
	void update(float);
	void draw(sf::RenderTarget*);

	progressBar();
	progressBar(int, int, float, Direction);
};