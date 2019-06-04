#include "stdafx.h"
#include "przeciwnik.h"

#pragma once
class networkEnemy: public przeciwnik
{
	sf::IpAddress ARG_addr;
public:
	networkEnemy();
	void enemyUpdate();
	virtual void setIdentifier(std::string addr);
	std::string identify();
};