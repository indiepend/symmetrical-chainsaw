#include "Protagonist.h"

void Protagonist::Check() {
	sf::Listener::setPosition(ziomus->getPosition().x, ziomus->getPosition().y, 0);

	if (sf::Keyboard::isKeyPressed(keys[4])) {
		SetAnimation("Attack");
		//to do
	}

	if (qw % 10 == 0) {
	if (sf::Keyboard::isKeyPressed(keys[5])) {
			if (turnNoct == false)
				turnNoct = true;
			else
				turnNoct = false;
		}
	}
	qw++;
	////////////////////////////////////////////////////////////////////////////////////
	if (sf::Keyboard::isKeyPressed(keys[2])) {
		HeightOfJump = FallOffJump(7);
	}
	if (jumping == false) {
		ResetFallOffTime2();
	}

	if (sf::Keyboard::isKeyPressed(keys[2]) && topCollision() == false && jumping == false && falling == false) {
		jumping = true;
	}

	if (jumping == true) {

		if (w < 0) {
			SetAnimation("Jump");
			(*ziomus).move(0, w);
		}
		else {
			ResetJumpTime();
			jumping = false;
		}
		if (topCollision()) {
			w = 0;
		}
		else {
			w = Jump(20, HeightOfJump);
		}


	}
	while (topCollision()) {
		(*ziomus).move(0, 1);
	}
	///////////////////////////////////////////////////////////////////////////////
	if (falling == false)
		ResetFallTime();
	if (!bottomCollision() && jumping == false) {
		falling = true;
		(*ziomus).move(0, Fall());
		while (bottomCollision()) {
			(*ziomus).move(0, -1);
			falling = false;
		}
		if (falling == true) {
			SetAnimation("Fall");
		}
	}

	/////////////////////////////////////////////////////////////////////////////////
	if (!rightCollision()) {
		if (sf::Keyboard::isKeyPressed(keys[1])) {
			walkingRight = true;
			(*ziomus).move(Walk(300), 0);
			SetAnimation("WalkRight");

		}
		else if (walkingRight == true) {
			falloff = FallOff(20);
			if (falloff <= 0 || sf::Keyboard::isKeyPressed(keys[0])) {
				ResetFallOffTime();
				walkingRight = false;
			}
			else {
				SetAnimation("WalkRight");
				(*ziomus).move(falloff, 0);
			}
		}
	}
	while (rightCollision()) {
		(*ziomus).move(-1, 0);
	}
	////////////////////////////////////////////////////////////////////////////////
	if (!leftCollision()) {
		if (sf::Keyboard::isKeyPressed(keys[0])) {
			walkingLeft = true;
			(*ziomus).move(-Walk(300), 0);
			SetAnimation("WalkLeft");
		}
		else if (walkingLeft == true) {
			falloff = FallOff(20);
			if (falloff <= 0 || sf::Keyboard::isKeyPressed(keys[1])) {
				ResetFallOffTime();
				walkingLeft = false;
			}
			else {
				SetAnimation("WalkLeft");
				(*ziomus).move(-falloff, 0);
			}

		}
	}
	while (leftCollision()) {
		(*ziomus).move(1, 0);
	}

	Movin::restart();
}

void Protagonist::setUp(sf::Vector2f coords,sf::Sprite * Picture, sf::Sprite* MayCollisionPictures, int HowManyCSprites, sf::Keyboard::Key * setts) {
	Collision::setUp(Picture, MayCollisionPictures, HowManyCSprites);
	ziomus = Picture;
	(*ziomus).setPosition(coords);
	keys = setts;
	sf::Listener::setDirection(1.f, 0.f, 0.f);
	Movin::restart();
}

void Protagonist::modifyHealth(int mod) {
	health += mod;
}

bool Protagonist::noctovision() {
	return turnNoct;
}

void Protagonist::pause(bool isPauseTrue) {
	if (isPauseTrue == true) {
		Movin::restart();
	}
}

Protagonist::Protagonist()
{
	Movin;
}