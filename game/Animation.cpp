#include "Animation.h"



void Animation::loadAnimations(string filename) {
	leftby = 1;
	loader.loadUp(filename);
	linesCounter = loader.getNumber();
	lines = loader.getString();
	animationCounter = atoi(lines[1].c_str());
	subanimation = new SubAnimation[animationCounter+1];
	for (int i = 0; i < animationCounter; i++) {
		subanimation[i].setName(lines[leftby+1]);
		subanimation[i].setFrames(atoi(lines[leftby+2].c_str()));
		subanimation[i].setTexture(lines[leftby+3]);
		subanimation[i].setLength(atof(lines[leftby + 4].c_str()));
		leftby += 4;
		for (int q = 1; q <= subanimation[i].getFrameCount(); q++) {		
			subanimation[i].setRect(atoi(lines[leftby + 1].c_str()), atoi(lines[leftby + 2].c_str()), atoi(lines[leftby + 3].c_str()), atoi(lines[leftby + 4].c_str()), q);
			leftby += 4;
		}
	}
}

void Animation::listener(string animation) {
	currentAnimation = animation;
	for (int i = 0; i < animationCounter; i++) {
		if (subanimation[i].getName() == currentAnimation) {
			if (kncp != i) {
				subanimation[i].resetTimer();
			}
		}
	}
	updateAnimation();
}

void Animation::updateAnimation() {
	for (int i = 0; i < animationCounter; i++) {
		if (subanimation[i].getName() == currentAnimation) {
			kncp = i;
			subanimation[i].setFrame(&currentFrame);
		}
	}
}

void Animation::drawAnimation(sf::RenderWindow * window) {
	(*window).draw(currentFrame, sf::BlendAlpha);
}

sf::Sprite * Animation::getCurrentFrame() {
	return &currentFrame;
}

Animation::Animation()
{
}