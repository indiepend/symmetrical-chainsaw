#include "AnimateAble.h"

void AnimateAble::SetAnimation(std::string name) {
	ARG_name = name;
	isAnimatable = true;
}

bool AnimateAble::animatable() {
	return isAnimatable;
}

std::string AnimateAble::GetAnimation() {
	if (isAnimatable == true) {
		isAnimatable = false;
		return ARG_name;
	}
	else {
		isAnimatable = false;
		return "default";
	}
}