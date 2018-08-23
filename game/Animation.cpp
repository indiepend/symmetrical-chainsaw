#include "Animation.h"

void Animation::loadAnimations(std::string filename) {
	int leftby = 1;
	loader.loadUp(filename);
	lines = loader.getString();
	animCount = atoi(lines[1].c_str());
	subanimation = new SubAnimation[animCount +1];
	for (int i = 0; i < animCount; i++) {
		subanimation[i].setName(lines[leftby+1]);
		subanimation[i].setFrames(atoi(lines[leftby+2].c_str()));
		subanimation[i].setTexture(lines[leftby+3]);
		subanimation[i].setLength(std::stof(lines[leftby + 4].c_str()));
		subanimation[i].setSound(lines[leftby + 5]);
		leftby += 5;
		for (int q = 1; q <= subanimation[i].getFrameNum(); q++) {		
			subanimation[i].setRect(atoi(lines[leftby + 1].c_str()), atoi(lines[leftby + 2].c_str()), atoi(lines[leftby + 3].c_str()), atoi(lines[leftby + 4].c_str()), q);
			leftby += 4;
		}

	}
}

void Animation::listener(std::string animation) {
	ARG_animation = animation;
	for (int i = 0; i < animCount; i++) {
		if (subanimation[i].getName() == ARG_animation) {
			if (timer != i) {
				subanimation[i].resetTimer();
			}
			timer = i;
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