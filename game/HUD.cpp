#include "HUD.h"


HUD::HUD()
{

}

void HUD::setUp(sf::RenderWindow * window, sf::Sprite * collisable, int HowMany, sf::Sprite * players, int HowManyPlayers) {
	okno = window;
	target = window;
	counter.setup();
	licznik.start(0);
	mapka.create(window,collisable,HowMany,players);
	lifePoints.create(200, 25, 100,progressBar::Direction::horizontal);
	lifePoints.placeBar(115, 690);
	lifePoints.setColors(sf::Color(150,0,0),sf::Color(0,0,0));
	lifePoints.setBorder(2, sf::Color::Black);
	if (forChat.loadFromFile("Arial.ttf"));
}

void HUD::setEvents(Events * event,Network* net)
{
	ARG_event = event;
	ARG_net = net;
	netChat = new Chat();
	netChat->setUp(&forChat, sf::IntRect(900, 520, 380, 200), ARG_event);
}
void HUD::setEvents(Events * event)
{
	ARG_event = event;
}

void HUD::update(float Points) {
	counter.update();
	mapka.update();
	lifePoints.update(Points);
}

void HUD::netUpdate(float Points) {
	counter.update();
	mapka.update();
	lifePoints.update(Points);
	netChat->update(okno);
	sf::Packet tempPack;
	if ((*ARG_net).receiveMessage(&tempPack)) {
		netChat->addMsg(tempPack);
	}
	if (netChat->isReady()) {
		(*ARG_net).sendMessage(netChat->pushMessage());
	}
}

void HUD::draw() {
	tempView = (*okno).getView();
	mapka.draw();
	(*okno).setView((*okno).getDefaultView());
	licznik.drawCzas(okno);
	lifePoints.draw(target);
	counter.draw(okno, &forChat);
	(*okno).setView(tempView);
}

void HUD::netDraw()
{
	tempView = (*okno).getView();
	(*okno).setView((*okno).getDefaultView());
	licznik.drawCzas(okno);
	lifePoints.draw(target);
	netChat->draw(target);
	(*okno).setView(tempView);
	mapka.draw();
}

void HUD::createlog()
{
	counter.createlog();
}

void HUD::makescreenshot()
{
	std::cout << "yup " << endl;
	sf::Texture temptext;
	temptext.create(okno->getSize().x, okno->getSize().y);
	temptext.update(*okno);
	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
	std::time_t tt = std::chrono::system_clock::to_time_t(today);
	char buffer[80];
	struct tm * timeinfo = new tm();
	localtime_s(timeinfo, &tt);
	strftime(buffer, 80, "screenshot-%dDay-%mMonth-%yYear-%H-%M-%S.jpg", timeinfo);
	sf::Image temp = temptext.copyToImage();
	temp.saveToFile(buffer);
}

void HUD::restart() {
	licznik.restart();
}

void HUD::stop() {
	licznik.stop();
}