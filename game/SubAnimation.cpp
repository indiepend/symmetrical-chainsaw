#include "SubAnimation.h"

void SubAnimation::setName(std::string name) {
	ARG_name = name;
	isName = true;
}

void SubAnimation::setTexture(std::string filename) {
	if (!texture.loadFromFile(filename)){
		//error
	}
}

void SubAnimation::setLength(float length) {
	ARG_length = length;
}

void SubAnimation::setFrames(int framNum) {
	ARG_framNum = framNum;
	iRect = new sf::IntRect[ARG_framNum +1];
}

void SubAnimation::setRect(int x, int y, int width, int height, int frame) {
	iRect[frame] = sf::IntRect(x, y, width, height);
}

std::string SubAnimation::getName() {
	if (isName) {
		return ARG_name;
	}
	return "none";
}

int SubAnimation::getFrameNum() {
	return ARG_framNum;
}

void SubAnimation::setFrame(sf::Sprite * sprite) {
	(*sprite).setTextureRect(iRect[w%ARG_framNum +1]);
	(*sprite).setTexture(texture);
	if (zegar.getElapsedTime().asSeconds() > ARG_length / ARG_framNum) {
		w++;
		zegar.restart();
	}
}

void SubAnimation::resetTimer() {
	zegar.restart();
}