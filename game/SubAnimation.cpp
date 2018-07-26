#include "SubAnimation.h"

void SubAnimation::setName(string name) {
	Name = name;
	isName = SubAnimation::hasName;
}

void SubAnimation::setTexture(string filename) {
	if (!texture.loadFromFile(filename)){
		// error...
	}
}

void SubAnimation::setLength(float length) {
	lengthOfAnimation = length;
}

void SubAnimation::setFrames(int howmuchframes) {
	FrameCounter = howmuchframes;
	iRect = new sf::IntRect[FrameCounter+1];
}

void SubAnimation::setRect(int x, int y, int width, int height, int frame) {
	iRect[frame] = sf::IntRect(x, y, width, height);
}

string SubAnimation::getName() {
	if (isName) {
		return Name;
	}
	else {
		return "none";
	}
}

int SubAnimation::getFrameCount() {
	return FrameCounter;
}

void SubAnimation::setFrame(sf::Sprite * sprite) {
//	(*sprite).move((*sprite).getTextureRect().width - iRect[w+1].width,(*sprite).getTextureRect().height-iRect[w+1].height);
	(*sprite).setTextureRect(iRect[w%FrameCounter+1]);
	(*sprite).setTexture(texture);
//	std::cout << zegar.getElapsedTime().asSeconds() << std::endl;
	if (zegar.getElapsedTime().asSeconds() > lengthOfAnimation / FrameCounter) {
		w++;
		zegar.restart();
	}

}

void SubAnimation::resetTimer() {
	zegar.restart();
}

SubAnimation::SubAnimation()
{
}