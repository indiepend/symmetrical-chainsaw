#include "Key.h"

string Key::returnKeyString(int keyNum)
{
	return keys[keyNum + 1];
}

string Key::returnKeyString(sf::Keyboard::Key key)
{
	int keyo = key;
	return keys[keyo + 1];
}

Key::Key()
{
}
