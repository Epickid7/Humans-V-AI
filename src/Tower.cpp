#include "Tower.h"

Tower::Tower(const sf::Texture &texture, int maxHealth, double abilitySpeed, int location[2], int cost) : sf::Sprite(texture)
{
	setMaxHealth(maxHealth);
	setHealth(maxHealth);
	setAbilitySpeed(abilitySpeed);
	setLocation(location[0], location[1]);
	setCost(cost);

}

Tower::Tower(Tower& t) : sf::Sprite(t.getTexture())
{
	setMaxHealth(t.getMaxHealth());
	setHealth(getMaxHealth());
	setAbilitySpeed(t.getAbilitySpeed());
	setLocation(t.getLocationX(), t.getLocationY());
}

//No dynamic memory to get rid of, nothing extra to do
Tower::~Tower()
{
}

//Add any extra on destroy effects for the gameplay
void Tower::destroyTower(void)
{
	

	delete this;
}
