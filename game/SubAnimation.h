#include "stdafx.h"
#include "Collision.h"

#pragma once

using namespace std;

class SubAnimation :public Collision
{
	string Name;
	int FrameCounter;
	sf::IntRect * iRect = NULL;
	sf::Texture texture;
	sf::Sprite frame;
	sf::Clock zegar;
	float lengthOfAnimation = 1;
	int x, y, width, height,w=0;
	bool isName=false;
	enum {
		hasName = 1
	};
public:
	void setName(string name);
	void resetTimer();
	void setTexture(string filename);
	void setFrames(int howmuchframes);
	void setLength(float length);
	int getFrameCount();
	void setRect(int x, int y, int width, int height, int numberOfFrame = 1);

	string getName();
	void setFrame(sf::Sprite * sprite);

	SubAnimation();
	//~SubAnimation();
};