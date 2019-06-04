#include "Chat.h"


Chat::Chat(sf::Font *font)
{
	ARG_font = font;
	message.setFont(*font);
	sender.setFont(*font);
	message.setCharacterSize(12);
	sender.setCharacterSize(12);
	message.setFillColor(sf::Color::White);
	sender.setFillColor(sf::Color::Cyan);
	sender.setStyle(sf::Text::Italic);
}

Chat::Chat()
{
}

void Chat::setUp(sf::Font * font, sf::IntRect dimensions, Events * events)
{
	ARG_events = events;

	ARG_font = font;
	message.setFont(*font);
	sender.setFont(*font);
	message.setCharacterSize((dimensions.height - 24) / 10 );
	sender.setCharacterSize((dimensions.height - 24) / 10);
	message.setFillColor(sf::Color::White);
	sender.setFillColor(sf::Color::Cyan);
	message.setOutlineColor(sf::Color::Black);
	sender.setOutlineColor(sf::Color::Black);
	message.setOutlineThickness(1);
	sender.setOutlineThickness(1);
	sender.setStyle(sf::Text::Italic);


	texture.create(dimensions.width, dimensions.height);
	texture.clear(sf::Color::Transparent);
	bg.setPosition(dimensions.left, dimensions.top);

	inputBox.setSize(sf::Vector2f(dimensions.width - 4, 20));
	inputBox.setFillColor(sf::Color::Black);
	inputBox.setOutlineColor(sf::Color::White);
	inputBox.setOutlineThickness(2);

	quad.setPrimitiveType(sf::Quads);
	quadVer[0].position = sf::Vector2f(0, 0);
	quadVer[1].position = sf::Vector2f(dimensions.width, 0);
	quadVer[2].position = sf::Vector2f(dimensions.width, dimensions.height);
	quadVer[3].position = sf::Vector2f(0, dimensions.height);
	quadVer[0].color = sf::Color::Transparent;
	quadVer[1].color = sf::Color::Transparent;
	quadVer[2].color = sf::Color::Black;
	quadVer[3].color = sf::Color::Black;
	quad.append(quadVer[0]);
	quad.append(quadVer[1]);
	quad.append(quadVer[2]);
	quad.append(quadVer[3]);

	inputBox.setPosition(2, dimensions.height- 2 - inputBox.getSize().y);

	input.setPosition(3, dimensions.height - 22);
	input.setFont(*font);
	input.setCharacterSize(18);
	input.setFillColor(sf::Color::White);
}

void Chat::update(sf::RenderWindow * target)
{
	if (inputBox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*target)-sf::Vector2i(bg.getPosition()))) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Typing = true;
	}
	else if (ARG_events->isEnterPressed()) {
		Typing = true;
	}
	if (!inputBox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*target) - sf::Vector2i(bg.getPosition()))) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Typing = false;
	}
	if (Typing == true && ARG_events->isEnterPressed()) {
		Typing = false;
		if (inputMsg != "") {
			sendReady = true;
			sendMsg = inputMsg;
			addMsg(&inputMsg);
		}
		input.setString("");
	}
	if (Typing) {
		inputBox.setFillColor(sf::Color(50,50,50));
		if (ARG_events->getInput(&inputMsg)) {
			input.setString(inputMsg);
		}
	}
	else {
		inputBox.setFillColor(sf::Color::Black);
	}
}

void Chat::addMsg(sf::Packet pack)
{
	messages.push_back(std::string());
	senders.push_back(std::string());
	sf::Uint32 add = 0;
	pack >> add;
	sf::IpAddress address(add);
	senders[senders.size()-1] = address.toString();
	senders[senders.size() - 1] += ": ";
	pack >> messages[messages.size()-1];
}

void Chat::addMsg(std::string* msg)
{
	messages.push_back(*msg);
	senders.push_back("player:");
	(*msg).clear();
}

std::string Chat::pushMessage()
{
	return sendMsg;
}

bool Chat::isReady()
{
	if (sendReady) {
		sendReady = false;
		return true;
	}
	return false;
}

void Chat::draw(sf::RenderTarget * target)
{
	texture.clear(sf::Color::Transparent);
	texture.draw(quad);
	if (messages.size() > 10) {
		for (int i = 9; i >= 0; i--) {
			message.setString(messages[i - 10 + messages.size()]);
			sender.setString(senders[i - 10 + senders.size() ]);
			sender.setPosition(0, i*sender.getCharacterSize());
			message.setPosition(sender.getLocalBounds().width, i*sender.getCharacterSize());
			texture.draw(sender);
			texture.draw(message);
		}
	}
	else {
		for (int i = senders.size()-1; i >= 0; i--) {
			message.setString(messages[i]);
			sender.setString(senders[i]);
			sender.setPosition(0, i*sender.getCharacterSize());
			message.setPosition(sender.getLocalBounds().width, i*sender.getCharacterSize());
			texture.draw(sender);
			texture.draw(message);
		}
	}
	texture.draw(inputBox);
	texture.draw(input);
	texture.display();
	bg.setTexture(texture.getTexture());
	(*target).draw(bg);
}
