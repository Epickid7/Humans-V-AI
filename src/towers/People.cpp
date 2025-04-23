#include "People.h"


People::People() : Tower(0, 0, 10, 10, 2, 1, AttackType::PROJECTILE, sf::Texture(peopleTexture), 60)
{
}

People::People(int x, int y) : Tower(x, y, 10, 10, 2, 1, AttackType::PROJECTILE, sf::Texture(peopleTexture), 60)
{

}

void People::useAbility(std::vector<Projectile>& projs)
{
	projs.push_back(*(new Projectile(this->getPosition(), sf::Texture(brickTexture), getAbilityPower(), 1)));
}

void People::destroyTower(void)
{

}