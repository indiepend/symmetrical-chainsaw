#include "AnimateAble.h"

void AnimateAble::SetAnimation(string name) {
	animation = name;
	isAnimatable = true;
}

bool AnimateAble::animatable() {
	return isAnimatable;
}

string AnimateAble::GetAnimation() {
	if (isAnimatable == true) {
		isAnimatable = false;
		return animation;
	}
	else {
		isAnimatable = false;
		return "default";
	}
}

AnimateAble::AnimateAble()
{
}


//AnimateAble::~AnimateAble()
//{
//}
