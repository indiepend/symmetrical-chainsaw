#include "stdafx.h"

#pragma once

using namespace std;

class Sight
{
	sf::CircleShape sightCircle;
	sf::Sprite cSprites;
	sf::BlendMode blendmode;
	sf::RectangleShape rectangle;
	string C_mode;
	int NumS;
	sf::RenderWindow *window = NULL;
	int fade;
	sf::RenderTexture fading;

	sf::Vertex line[1];

	int r_px, r_dx, s_px, s_dx, r_py, r_dy, s_py, s_dy, T1, T2;
public:
	Sight();
	void setUp(sf::RenderWindow *targetwindow, sf::Sprite * collisionSprites, int NumberSprites, string mode = "real");
	void update(sf::Vector2f getCPos);
	void draw();
	//~Sight();
};