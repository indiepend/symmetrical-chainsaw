#include "networkEnemy.h"

networkEnemy::networkEnemy()
{
}

void networkEnemy::enemyUpdate()
{

}

void networkEnemy::setIdentifier(std::string addr)
{
	ARG_addr = sf::IpAddress (addr);
}

std::string networkEnemy::identify()
{
	return ARG_addr.toString();
}