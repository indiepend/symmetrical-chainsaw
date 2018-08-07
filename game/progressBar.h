#include "stdafx.h"
#pragma once

class progressBar
{
public:
	enum class Type {
		background = 0,
		bar
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
	sf::RectangleShape bg,bar;
	float step;
	Direction ARG_dir;
public:
	//////////////////////////////////////////////////
	///\brief
	///creates new progress bar
	///set dimensions then set maximum value for bar
	///then set its direction "horizontal" or "vertical"
	///default value is "vertical"
	//////////////////////////////////////////////////
	void create(int,int,float, Direction = Direction::vertical);

	//////////////////////////////////////////////////
	///\brief
	///sets border around background
	///set its thickness and color
	//////////////////////////////////////////////////
	void setBorder(int, sf::Color);

	//////////////////////////////////////////////////
	///\brief
	///set colors of background and progressbar
	//////////////////////////////////////////////////
	void setColors(sf::Color, sf::Color);

	//////////////////////////////////////////////////
	///\brief
	///set custom texture instead just color of background or progress bar
	///by default it's progress bar
	//////////////////////////////////////////////////
	void customTexture(sf::Texture*, Type=Type::bar);

	//////////////////////////////////////////////////
	///\brief
	///places bar in app
	///coordinates are in pixels
	//////////////////////////////////////////////////
	void placeBar(int, int);

	//////////////////////////////////////////////////
	///\brief
	///updates bar with passed value
	///note: if value is bigger than maximum nothing really happens
	//////////////////////////////////////////////////
	void update(float);

	//////////////////////////////////////////////////
	///\brief
	///draws progress bar to passed target
	//////////////////////////////////////////////////
	void draw(sf::RenderTarget*);

	//////////////////////////////////////////////////
	///\brief
	///default constructor
	//////////////////////////////////////////////////
	progressBar();

	//////////////////////////////////////////////////
	///\brief
	///constructor overload
	///set dimensions then set maximum value for bar
	///then set its direction "horizontal" or "vertical"
	///default value is "vertical"
	//////////////////////////////////////////////////
	progressBar(int, int, float, Direction = Direction::vertical);
};