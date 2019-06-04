#include "przeciwnik.h"

void przeciwnik::enemyUpdate() {
	AI();
	collide = false;
	////////////////////////////////////////////////////////////////////////////////////
	gettingRight();
	///////////////////////////////////////////////////////////////////////////////
	gettingLeft();
	/////////////////////////////////////////////////////////////////////////////////
	jumps();
	////////////////////////////////////////////////////////////////////////////////
	falls();

	goleft = false;
	goright = false;
	jump = false;

	Movin::restart();
}


void przeciwnik::AI() {
	if (fabs((*bohater).getPosition().x - (*ziomus).getPosition().x) < 20) {
		SetAnimation("Attack");
	}
	if (fabs((*bohater).getPosition().x - (*ziomus).getPosition().x) < 500 && fabs((*bohater).getPosition().x - (*ziomus).getPosition().x) > 20) {
		if ((*bohater).getPosition().x - (*ziomus).getPosition().x > 0)
			goright = true;
		else if((*bohater).getPosition().x - (*ziomus).getPosition().x < 0)
			goleft = true;
	}
	if (collide) {
		jump = true;
	}
}

void przeciwnik::enemySetUp(sf::Sprite * player, sf::Vector2f coords,sf::Sprite * Picture, sf::Sprite* MayCollisionPictures, int HowManyCSprites) {
	Collision::setUp(Picture, MayCollisionPictures, HowManyCSprites);
	ziomus = Picture;
	(*ziomus).setPosition(coords);
	bohater = player;
	Movin::restart();
}

void przeciwnik::modifyHealth(float mod) {
	life += mod;
}

void przeciwnik::setIdentifier(std::string identifier)
{
	ARG_identifier=identifier;
}

std::string przeciwnik::identify()
{
	return ARG_identifier;
}

void przeciwnik::gettingRight() {
	if (!rightCollision()) {
		if (goright) {
			walkingRight = true;
			(*ziomus).move(Walk(100), 0);
			SetAnimation("WalkRight");
		}
		while (rightCollision()) {
			collide = true;
			(*ziomus).move(-1, 0);
		}
	}
}

void przeciwnik::gettingLeft() {
	if (!leftCollision()) {
		if (goleft) {
			walkingLeft = true;
			(*ziomus).move(-Walk(100), 0);
			SetAnimation("WalkLeft");
		}
		while (leftCollision()) {
			collide = true;
			(*ziomus).move(1, 0);
		}
	}
}

void przeciwnik::jumps() {

	if (jump==true && topCollision() == false && jumping == false && falling == false) {
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
			w = Jump(15, 0);
		}
	}
	while (topCollision()) {
		(*ziomus).move(0, 1);
	}
}

void przeciwnik::falls() {
	if (falling == false) {
		ResetFallTime();
	}
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
}

void przeciwnik::pause(bool isPauseTrue) {
	if (isPauseTrue == true) {
		Movin::restart();
	}
}

przeciwnik::przeciwnik()
{
}