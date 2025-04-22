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

	//this->health = rhs.health;
	this->maxHealth = rhs.maxHealth;
	this->abilityPower = rhs.abilityPower;
	this->abilitySpeed = rhs.abilitySpeed;
	this->cost = rhs.cost;
	this->location[0] = rhs.location[0];
	this->location[1] = rhs.location[1];
	//this->attackType = rhs.attackType;
	//this->currentHealth = rhs.currentHealth;

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
