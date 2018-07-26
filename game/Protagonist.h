#include "stdafx.h"
#include "Movin.h"
#include "Collision.h"
#include "AnimateAble.h"

#pragma once
class Protagonist :private Movin, private Collision, public AnimateAble
{
	int w=0,wut=0,falloff=0,HeightOfJump=0,qw=0;
	float health=100;
	sf::Keyboard::Key * keys = NULL;
	bool jumping=false,falling,walkingRight=false,walkingLeft=false,turnNoct=false;
	sf::Sprite * ziomus = NULL;
public:
	Protagonist();
	void Check();
	void setUp(sf::Vector2f coords, sf::Sprite * Picture, sf::Sprite MayCollisionPictures[], int HowManyCSprites,sf::Keyboard::Key * setts);
	void modifyHealth(int mod);
	bool noctovision();
	void pause(bool isPauseTrue=true);
};