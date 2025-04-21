#include "Tower.h"

//Tower::Tower(const sf::Texture &texture, int maxHealth, double abilitySpeed, int location[2], int cost) : sf::Sprite(texture)
//{
//	setMaxHealth(maxHealth);
//	setHealth(maxHealth);
//	setAbilitySpeed(abilitySpeed);
//	setLocation(location[0], location[1]);
//	setCost(cost);
//
//}

//Tower::Tower(Tower& t) : sf::Sprite(t.getTexture())
//{
//	setMaxHealth(t.getMaxHealth());
//	setHealth(getMaxHealth());
//	setAbilitySpeed(t.getAbilitySpeed());
//	setLocation(t.getLocationX(), t.getLocationY());
//}
Tower::Tower() {

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

	this->health = rhs.health;
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

//Add any extra on destroy effects for the gameplay
void Tower::destroyTower(void)
{
	

	delete this;
}
