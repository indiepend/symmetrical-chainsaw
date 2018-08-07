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
	//////////////////////////////////////////////////
	///\brief
	///default constructor
	//////////////////////////////////////////////////
	Button();

	//////////////////////////////////////////////////
	///\brief
	///constructor overload
	///gets basic parameters to draw button
	Button(int, int, sf::RenderWindow*, sf::Color = sf::Color::Black, bool = true);

	//////////////////////////////////////////////////
	///\brief
	///constructor overload with sf::RenderTexture instead sf::RenderWindow
	//////////////////////////////////////////////////
	Button(int width, int height, sf::RenderTexture * renderTexture, sf::RenderWindow * window, sf::Color ofbutton, bool animated = true);

	//width and height in pixels
	//border can be also used as margin for text
	//in that case leave last argument empty
	void createButton(int width, int height, sf::RenderWindow * window, sf::Color ofbutton, bool animated=true);
	//overload with sf::RenderTexture
	void createButton(int width, int height, sf::RenderTexture * renderTexture, sf::RenderWindow * window, sf::Color ofbutton, bool animated = true);
	void checkButton(sf::Color color, sf::Vector2f mouse = sf::Vector2f(0,0));
	void moveButton(sf::Vector2f move);
	void setBorder(int thickness, sf::Color colorOfBorder, sf::Color secondColor);
	void drawButton();

	//////////////////////////////////////////////////
	///\brief
	///range from 0.0(left side of screen) to 1.0(right side of screen)
	///place it after all text methods
	///align for text in button can be "left" "center" or "right"
	//////////////////////////////////////////////////
	void placeButton(float=0,float=0,string="left");

	//////////////////////////////////////////////////
	///\brief
	///checks if button has been clicked
	//////////////////////////////////////////////////
	bool isClicked();

	///text methods///
	/////////////////////////////////////////////////

	//////////////////////////////////////////////////
	void setFont(sf::Font*);

	//////////////////////////////////////////////////
	///\brief
	///default size is 30
	//////////////////////////////////////////////////
	void setCharacterSize(int);

	//////////////////////////////////////////////////

	//////////////////////////////////////////////////
	void setString(sf::String);

	//////////////////////////////////////////////////

	//////////////////////////////////////////////////
	void setFillColor(sf::Color);
};