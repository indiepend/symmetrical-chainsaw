#include "Collision.h"

bool Collision::kolizja() {
	sf::FloatRect anim = (*target).getGlobalBounds();
	for (int i = 0; i < ARG_num; i++) {
		if (anim.intersects(collidies[i].getGlobalBounds())) {
			i = ARG_num;
			return true;
		}
	}
			return false;

}

bool Collision::leftCollision() {
	sf::FloatRect anim= (*target).getGlobalBounds();
	for (int i = 0; i < ARG_num; i++) {
		sf::FloatRect sprite = collidies[i].getGlobalBounds();
		if (anim.intersects(sprite)) {
			if (fabs(anim.left - (sprite.left + sprite.width)) <= fabs(anim.left - sprite.left)) {
				i = ARG_num;
				return true;
			}
		}
	}
			return false;
}
bool Collision::rightCollision() {
	sf::FloatRect anim = (*target).getGlobalBounds();
	for (int i = 0; i < ARG_num; i++) {
		sf::FloatRect sprite = collidies[i].getGlobalBounds();
		if (anim.intersects(sprite)) {
			if (fabs(sprite.left - (anim.left + anim.width)) <= fabs((sprite.left + sprite.width) - (anim.left + anim.width))) {
				i = ARG_num;
				return true;
			}
		}
	}
	return false;
}

bool Collision::bottomCollision() {
	sf::FloatRect anim = (*target).getGlobalBounds();
	for (int i = 0; i < ARG_num; i++){
		sf::FloatRect sprite = collidies[i].getGlobalBounds();
		if (anim.intersects(sprite)) {
			if (fabs(sprite.top - (anim.top + anim.height)) <= fabs((sprite.top + sprite.height) - (anim.top + anim.height))) {
				i = ARG_num;
				return true;
			}
		}
	}
	return false;
}

bool Collision::topCollision() {
	sf::FloatRect anim = (*target).getGlobalBounds();
	for (int i = 0; i < ARG_num; i++) {
		sf::FloatRect sprite = collidies[i].getGlobalBounds();
		if (anim.intersects(sprite)) {
			if (fabs(anim.top - (sprite.top + sprite.height)) <= fabs(anim.top - sprite.top)) {
				i = ARG_num;
				return true;
			}
		}
	}
	return false;
}

void Collision::setUp(sf::Sprite * ProtagonistSprite, sf::Sprite* collide, int SpriteNum) {
	target = ProtagonistSprite;
	ARG_num = SpriteNum;
	collidies = collide;
}

Collision::Collision(sf::Sprite * ProtagonistSprite, sf::Sprite* collide, int SpriteNum) {
	target = ProtagonistSprite;
	ARG_num = SpriteNum;
	collidies = collide;
}

Collision::Collision() {

}