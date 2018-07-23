#include "stdafx.h"
#pragma once

/*
Inherite class
-SetAnimation - sets animation on demand
-GetAnimation - if in last frame SetAnimation was called it gives setted animation in other way it gives "default" animation
*/

using namespace std;
class AnimateAble
{
	//animate - was setanimation called this frame
	bool isAnimatable = false;
	string animation;
protected:
	void SetAnimation(string name);
public:
	bool animatable();
	string GetAnimation();
	AnimateAble();
	//~AnimateAble();
};

