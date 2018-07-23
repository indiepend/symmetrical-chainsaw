#include "stdafx.h"
#include "FileToString.h"
#include "SubAnimation.h"

#pragma once

using namespace std;

class Animation
{
	string currentAnimation;
	sf::Sprite currentFrame;
	FileToString loader;
	int linesCounter,animationCounter,leftby=1,kncp=0;
	string * lines = NULL;
	SubAnimation * subanimation = NULL;
	void updateAnimation();
public:
	void loadAnimations(string filename);
	void drawAnimation(sf::RenderWindow * window);
	void listener(string animation);
	sf::Sprite * getCurrentFrame();
	Animation();
	//~Animation();
};