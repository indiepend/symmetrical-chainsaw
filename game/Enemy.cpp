#include "Enemy.h"
#include "networkEnemy.h"

void Enemy::deleteEnemy(int element)
{
	enemAnim.erase(enemAnim.cbegin() + element);
	enemies.erase(enemies.cbegin() + element);
}

Enemy::Enemy()
{
}

void Enemy::setUp(sf::Sprite * player, sf::Sprite * collisable,int N_collisable,int N_enemies, sf::Vector2f * coords, std::string * animations, std::string * type) {
	ARG_enem = N_enemies;
	ARG_player = player;
	ARG_collisable = collisable;
	ARG_N_collisable = N_collisable;

	for (int i = 0; i < ARG_enem; i++) {
		enemies.push_back(&przeciwnik());
		enemies[i] = new przeciwnik();
		enemAnim.push_back(&Animation());
		enemAnim[i] = new Animation();
		(*enemAnim[i]).loadAnimations(animations[i]);
		(*enemies[i]).enemySetUp(player, coords[i], (*enemAnim[i]).getCurrentFrame(), collisable, N_collisable);
	}
}

void Enemy::setUp(sf::Sprite * player, sf::Sprite * collisable, int N_collisable)
{
	ARG_player = player;
	ARG_collisable = collisable;
	ARG_N_collisable = N_collisable;
}

void Enemy::addEnemy(std::string identity)
{
	przeciwnik *tempenem = new networkEnemy();
	enemies.push_back(tempenem);
	(*enemies[enemies.size()]).setIdentifier(identity);
	enemAnim.push_back(&Animation());
}

void Enemy::addEnemy(sf::Vector2f * coords, std::string * animations, std::string * type)
{
	enemies.push_back(&przeciwnik());
	enemies[enemies.size()] = new przeciwnik();
	enemAnim.push_back(&Animation());
	(*enemAnim[enemAnim.size()]).loadAnimations(*animations);
	enemies[enemies.size()]->enemySetUp(ARG_player, *coords, (*enemAnim[enemAnim.size()]).getCurrentFrame(), ARG_collisable, ARG_N_collisable);
}

void Enemy::enemySets(std::string identificator,sf::Vector2f * coords, std::string * animations, std::string type)
{
	for (int i = enemAnim.size(); i != 0; i--) {
		if (identificator == enemies[i]->identify()) {
			(*enemAnim[i]).loadAnimations(*animations);
			enemies[i]->enemySetUp(ARG_player, *coords, (*enemAnim[i]).getCurrentFrame(), ARG_collisable, ARG_N_collisable);
			break;
		}
	}
}

void Enemy::pause(bool isPauseTrue) {
	for (int i = 0; i < (int)enemies.size(); i++) {
		enemies[i]->pause(isPauseTrue);
	}
}

void Enemy::update() {
	for (int i = 0; i < (int)enemies.size(); i++) {
		(*enemAnim[i]).listener(enemies[i]->GetAnimation());
		enemies[i]->enemyUpdate();
	}
}

void Enemy::deleteEnemy(std::string identity)
{
	for (int i = 0; i < (int)enemies.size(); i++) {
		if (identity == (*enemies[i]).identify()) {
			enemAnim.erase(enemAnim.cbegin() + i);
			enemies.erase(enemies.cbegin() + i);
			break;
		}
	}
}

void Enemy::draw(sf::RenderWindow * window) {
	for (int i = 0; i < (int)enemies.size(); i++) {
		(*enemAnim[i]).drawAnimation(window);
	}
}