#include "stdafx.h"
#include "FileToString.h"
#include "SubAnimation.h"

#pragma once

class Animation
{
	std::string ARG_animation;
	sf::Sprite currentFrame;
	FileToString loader;
	int animCount,timer;
	std::string* lines = NULL;
	SubAnimation* subanimation = NULL;
public:

	//////////////////////////////////////////////////
	///\brief
	///reads animation form from file
	///file path can be like that
	///"C://doc/myanimation.txt" or
	///"myanimation.txt" if animation is inside app folder
	//////////////////////////////////////////////////
	void loadAnimations(std::string);

	//////////////////////////////////////////////////
	///\brief
	///draws current animation
	//////////////////////////////////////////////////
	void drawAnimation(sf::RenderWindow*);

	//////////////////////////////////////////////////
	///\brief
	///checks if there is new animation turned on and changes it
	//////////////////////////////////////////////////
	void listener(std::string);

	//////////////////////////////////////////////////
	///\brief
	///returns pointer to current frame of animation
	///makes it modifyable for example: to make it move
	//////////////////////////////////////////////////
	sf::Sprite* getCurrentFrame();
};