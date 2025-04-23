#include "Tower.h"


Tower::Tower(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
	int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"), int cost = 0)
	: Character(x, y, current, max, power, speed, type, texture)
{
	setCost(cost);
}

Tower::Tower(Tower& t)
{
	cost = t.getCost();
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
