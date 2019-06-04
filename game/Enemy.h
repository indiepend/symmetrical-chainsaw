#include "stdafx.h"
#include "przeciwnik.h"
#include "Animation.h"

#pragma once

class Enemy
{
	std::vector <przeciwnik*> enemies;
	std::vector <Animation*> enemAnim;
	int ARG_enem,ARG_N_collisable;
	sf::Sprite *ARG_player, *ARG_collisable;
	void deleteEnemy(int element);
public:
	Enemy();
	void setUp(sf::Sprite * player, sf::Sprite * collisable, int N_collisable, int N_enemies, sf::Vector2f * coords, std::string * animations, std::string * type);
	void setUp(sf::Sprite * player, sf::Sprite * collisable, int N_collisable);
	void addEnemy(std::string identity);
	void addEnemy(sf::Vector2f * coords, std::string * animations, std::string * type);
	void enemySets(std::string identificator, sf::Vector2f * coords, std::string * animations, std::string type);
	void update();
	void deleteEnemy(std::string identity);
	void draw(sf::RenderWindow * window);
	void pause(bool isPauseTrue);
};