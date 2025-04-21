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

}

void People::destroyTower(void)
{

}