#include "stdafx.h"
#pragma once
class Camera
{
	float x, y;
	sf::Sprite * prot = NULL;
	sf::View view;
	sf::RenderWindow * okno = NULL;
	sf::FloatRect protp;
	sf::Vector2f pos,lel,los=sf::Vector2f(0,0);
public:
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	void cameraUpdate();
	void cameraUpdateMain();
	Camera();
	void getValues(sf::Sprite * Protagonist, sf::RenderWindow * window);
	void getValuesWindow(sf::RenderWindow * window);
	//~Camera();
};