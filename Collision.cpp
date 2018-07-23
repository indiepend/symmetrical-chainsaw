#include "Collision.h"

//////////////////////////////////////////////////////////////////////////////
bool Collision::kolizja() {
	sf::FloatRect anim = (*ziomek).getGlobalBounds();
	for (int i = 0; i < HowMany; i++) {
		if (anim.intersects(Sprajcik[i].getGlobalBounds())) {
			i = HowMany;
			return true;
		}
	}
			return false;

}
//////////////////////////////////////////////////////////////////////////////
bool Collision::leftCollision() {
	sf::FloatRect anim= (*ziomek).getGlobalBounds();
	for (int i = 0; i < HowMany; i++) {
		sf::FloatRect sprite = Sprajcik[i].getGlobalBounds();
		if (fabs(anim.left - (sprite.left + sprite.width)) <= fabs(anim.left - sprite.left) && anim.intersects(sprite)) {
			i = HowMany;
			return true;
		}
	}
			return false;
}
bool Collision::rightCollision() {
	sf::FloatRect anim = (*ziomek).getGlobalBounds();
	for (int i = 0; i < HowMany; i++) {
		sf::FloatRect sprite = Sprajcik[i].getGlobalBounds();
		if (fabs(sprite.left - (anim.left + anim.width)) <= fabs((sprite.left + sprite.width) - (anim.left + anim.width)) && anim.intersects(sprite)) {
			i = HowMany;
			return true;
		}
	}
	return false;
}
//////////////////////////////////////////////////////////////////////////////
bool Collision::bottomCollision() {
	sf::FloatRect anim = (*ziomek).getGlobalBounds();
	for (int i = 0; i < HowMany; i++){
		sf::FloatRect sprite = Sprajcik[i].getGlobalBounds();
		if (fabs(sprite.top - (anim.top + anim.height)) <= fabs((sprite.top + sprite.height) - (anim.top + anim.height)) && anim.intersects(sprite)) {
			i = HowMany;
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////
bool Collision::topCollision() {
	sf::FloatRect anim = (*ziomek).getGlobalBounds();
	for (int i = 0; i < HowMany; i++) {
		sf::FloatRect sprite = Sprajcik[i].getGlobalBounds();
		if (fabs(anim.top - (sprite.top + sprite.height)) <= fabs(anim.top - sprite.top) && anim.intersects(sprite)) {
			i = HowMany;
			return true;
		}
	}
	return false;
}

void Collision::setUp(sf::Sprite * ProtagonistSprite, sf::Sprite CollisableSprites[], int HowManySprites) {
	ziomek = ProtagonistSprite;
	HowMany = HowManySprites;
	Sprajcik = new sf::Sprite[HowManySprites];
	for (int i = 0; i < HowManySprites; i++) {
		Sprajcik[i] = CollisableSprites[i];
	}
}
//////////////////////////////////////////////////////////////////////////////
Collision::Collision(sf::Sprite * ProtagonistSprite, sf::Sprite CollisableSprites[], int HowManySprites) {
	ziomek = ProtagonistSprite;
	HowMany = HowManySprites;
	Sprajcik = new sf::Sprite[HowManySprites];
	for (int i = 0; i < HowManySprites; i++) {
		Sprajcik[i] = CollisableSprites[i];
	}
}

Collision::Collision() {

}