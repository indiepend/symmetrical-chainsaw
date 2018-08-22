#include "stdafx.h"
#pragma once

class Collision
{
protected:
	sf::Sprite * target = NULL;
	sf::Sprite * collidies = NULL;
	int ARG_num = 0;
public:
	//////////////////////////////////////////////////
	///\brief
	///pass necessary things
	///main target then things it can collide with and number of these last
	//////////////////////////////////////////////////
	Collision(sf::Sprite * player, sf::Sprite* collisable, int SpriteNum);

	//////////////////////////////////////////////////
	///\brief
	///default constructor
	//////////////////////////////////////////////////
	Collision();

	//////////////////////////////////////////////////
	///\brief
	///pass necessary things
	///main target then things it can collide with and number of these last
	//////////////////////////////////////////////////
	void setUp(sf::Sprite * player, sf::Sprite* collisable, int SpriteNum);

	//////////////////////////////////////////////////
	///\brief
	///checks if there's any collision
	//////////////////////////////////////////////////
	bool kolizja();
	
	//////////////////////////////////////////////////
	///\brief
	///checks for bottom collision
	///note: it check only bottom of target with top of collisables
	//////////////////////////////////////////////////
	bool bottomCollision();

	//////////////////////////////////////////////////
	///\brief
	///checks for bottom collision
	///note: it check only top of target with bottom of collisables
	//////////////////////////////////////////////////
	bool topCollision();

	//////////////////////////////////////////////////
	///\brief
	///checks for bottom collision
	///note: it check only right side of target with left side of collisables
	//////////////////////////////////////////////////
	bool rightCollision();

	//////////////////////////////////////////////////
	///\brief
	///checks for left collision
	///note: it check only left side of target with right side of collisables
	//////////////////////////////////////////////////
	bool leftCollision();
};