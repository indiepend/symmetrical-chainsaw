#include "stdafx.h"
#include "Movin.h"
#include "Collision.h"
#include "AnimateAble.h"

#pragma once

class przeciwnik :private Movin, private Collision, public AnimateAble
{
private:
	sf::Sprite * ziomus = NULL;
	sf::Sprite * bohater = NULL;
	std::string ARG_identifier;
	bool jumping = false, falling = false, walkingRight = false, walkingLeft = false, turnNoct = false, collide = false;
	bool goleft=false, goright=false, jump=false, attack=false,alarmed=false,suspicious=false;
	int w = 0, wut = 0, falloff = 0, HeightOfJump = 0;
	int lol=0;
	float life = 100;
	void gettingRight();
	void gettingLeft();
	void jumps();
	void falls();
	void AI();
public:
	void enemySetUp(sf::Sprite * player, sf::Vector2f coords, sf::Sprite * Picture, sf::Sprite MayCollisionPictures[], int HowManyCSprites);
	void enemyUpdate();
	void modifyHealth(float mod);
	virtual void setIdentifier(std::string identifier);
	virtual std::string identify();

	void pause(bool isPauseTrue);
	przeciwnik();
	//~przeciwnik();
};
