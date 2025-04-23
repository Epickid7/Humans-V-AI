#include "Tower.h"






Tower::Tower(const Tower& t)
{
	this->cost = t.getCost();
	this->abilityPower = t.abilityPower;
}

//No dynamic memory to get rid of, nothing extra to do
Tower::~Tower()
{
}

Tower& Tower::operator=(Tower& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	cost = rhs.getCost();

	sf::Sprite::operator=(rhs);

	return *this;
}

void Tower::useAbility()
{
}

//Add any extra on destroy effects for the gameplay
void Tower::destroyTower(void)
{
	

	delete this;
}
