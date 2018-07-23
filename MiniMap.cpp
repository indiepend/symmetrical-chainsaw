#include "MiniMap.h"

void MiniMap::create(sf::RenderWindow * wind,sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers) {
	tempPos = sf::Vector2f(0, 0);
	targetWindow = wind;
	ARG_collisable = collisable;
	ARG_players = players;
	ARG_Howmany = HowMany;
	ARG_Howmanyplayers = HowManyPlayers;
	RT_MiniMap.create((*wind).getSize().x*2, (*wind).getSize().y*2);
	minimapView.setSize((*wind).getSize().x * 2, (*wind).getSize().y * 2);
	RT_collisable = new sf::RenderTexture[HowMany];
	RT_players = new sf::RenderTexture[HowManyPlayers];
	ST_collisable = new sf::Sprite[HowMany];
	ST_players = new sf::Sprite[HowManyPlayers];
	for (int i = 0; i < ARG_Howmany; i++) {
		RT_collisable[i].create(ARG_collisable[i].getLocalBounds().width, ARG_collisable[i].getLocalBounds().height);
		RT_collisable[i].clear(sf::Color(0, 0, 0));
		RT_collisable[i].display();
		ST_collisable[i].setTexture(RT_collisable[i].getTexture());
		ST_collisable[i].setPosition(ARG_collisable[i].getPosition().x+RT_MiniMap.getSize().x/2, ARG_collisable[i].getPosition().y + RT_MiniMap.getSize().y / 2);
		
	}
	loadUpPlayer = true;
}

void MiniMap::update() {
	ST_MiniMap.setTexture(RT_MiniMap.getTexture());
	RT_MiniMap.clear(sf::Color(150, 200, 0));
	ST_MiniMap.setOrigin(ST_MiniMap.getLocalBounds().width / 2, ST_MiniMap.getLocalBounds().height / 2);
	if (loadUpPlayer) {
//		RT_players[0].create(ARG_players[0].getLocalBounds().width, ARG_players[0].getLocalBounds().height);
//		RT_players[0].clear(sf::Color(200, 0, 0));
//		RT_players[0].display();
//		ST_players[0].setTexture(RT_players[0].getTexture());
//		ST_players[0].setPosition(ST_MiniMap.getPosition());
//		RT_MiniMap.draw(ST_players[0]);
//		for (int i = 1; i < ARG_Howmanyplayers; i++) {
//			RT_players[i].create(ARG_players[i].getLocalBounds().width, ARG_players[i].getLocalBounds().height);
//			RT_players[i].clear(sf::Color(200, 0, 0));
//			RT_players[i].display();
//			ST_players[i].setTexture(RT_players[i].getTexture());
//			ST_players[i].setPosition(ARG_players[i].getPosition());
//			RT_MiniMap.draw(ST_players[i]);
//		}
		loadUpPlayer = false;
	}
	if (tempPos != ARG_players[0].getPosition()) {
		int x, y;
		x = (int)ARG_players[0].getPosition().x - (int)tempPos.x;
		y = ARG_players[0].getPosition().y - tempPos.y;
		for (int i = 0; i < ARG_Howmany; i++) {
			ST_collisable[i].move(-x,-y);
		}
		tempPos += sf::Vector2f(x,y);
	}
	for (int i = 0; i < ARG_Howmany; i++) {
		RT_MiniMap.draw(ST_collisable[i]);
	}
	defaultView = (*targetWindow).getView();
	RT_MiniMap.display();
	minimapView.setViewport(sf::FloatRect(0, 0, 0.25, 0.25));
	minimapView.setCenter(ST_MiniMap.getLocalBounds().left, ST_MiniMap.getLocalBounds().top);
	ST_MiniMap.setPosition(0,0);
}

void MiniMap::draw() {
	(*targetWindow).setView(minimapView);
	(*targetWindow).draw(ST_MiniMap);
	(*targetWindow).setView(defaultView);
}

MiniMap::MiniMap()
{
}