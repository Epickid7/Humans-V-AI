#include "People.h"
#include "People.h"

People::People() : Tower(0, 0, 10, 10, 2, 1, AttackType::PROJECTILE, sf::Texture(bankTexture), 60)
{
}

People::People(int x, int y) : Tower(x, y, 10, 10, 2, 1, AttackType::PROJECTILE, sf::Texture(peopleTexture), 60)
{

}

void People::useAbility()
{
	//Hopefully the position value is right
	//Speed could be adjusted later, not sure what to put it as
	new Projectile(getPosition(), sf::Texture(brickTexture), abilityPower, 1);

	//Dont worry about freeing this later, should all be handled by the projectile class
}

void People::destroyTower(void)
{

}