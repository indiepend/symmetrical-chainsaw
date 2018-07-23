#include "stdafx.h"
#pragma once

class Collision
{
protected:
	sf::Sprite * ziomek = NULL;
	sf::Sprite * Sprajcik = NULL;
	int HowMany = 0;
public:
	Collision(sf::Sprite * ProtagonistSprite, sf::Sprite CollisableSprites[], int HowManySprites);
	Collision();
	void setUp(sf::Sprite * ProtagonistSprite, sf::Sprite CollisableSprites[], int HowManySprites);
	bool kolizja();
	bool bottomCollision();
	bool topCollision();
	bool rightCollision();
	bool leftCollision();
	//~Collision();
};