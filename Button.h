#include "stdafx.h"
#pragma once

using namespace std;

/*
Button() - didntdonothing

text methods - modyfying text of button
placeButton() - places button on screen
setButtonColor() - sets color of button
secondColor() - color when mouse is on button
setBorder() - sets border
*/
class Button
{
	sf::Sprite backS, border;
	sf::Text text;
	sf::RenderWindow * wind = NULL;
	sf::RenderTexture * R_text = NULL;
	sf::RenderTexture V_Rtext;
	sf::Color c1, c2, c3, c4, current, currentTxt;
	sf::Vector2f vector1 = sf::Vector2f(0, 0), vector2 = sf::Vector2f(0, 0);

	string alignes="left";
	int x, y,w,h,thick,step;
	double R, G, B, q, r, e;
	bool clicked=false,animationed,animating, renderWindow;
public:
	Button();
	//width and height in pixels
	//border can be also used as margin for text
	//in that case leave last argument empty
	void createButton(int width, int height, sf::RenderWindow * window, sf::Color ofbutton, bool animated=true);
	//version with sf::RenderTexture
	void createButton(int width, int height, sf::RenderTexture * renderTexture, sf::RenderWindow * window, sf::Color ofbutton, bool animated = true);
	void checkButton(sf::Color color, sf::Vector2f mouse = sf::Vector2f(0,0));
	void moveButton(sf::Vector2f move);
	void setBorder(int thickness, sf::Color colorOfBorder, sf::Color secondColor);
	void drawButton();
	//range 0.0-1.0
	//place it after all text methods
	//align for text in button can be "left" "center" or "right"
	void placeButton(float coordx=0,float coordy=0, string align="left");

	bool isClicked();
	///text methods///
	void setFont(sf::Font * font);
	void setCharacterSize(int size);
	void setString(sf::String textinbutton);
	void setFillColor(sf::Color oftext);


	//~Button();
};