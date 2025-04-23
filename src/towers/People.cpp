#include "People.h"


People::People() : Tower(0, 0, 10, 10, 2, 1, AttackType::PROJECTILE, peopleTexture, 60)
{
	peopleTexture.loadFromFile(ASSETS_PATH "/images/people.png");
	brickTexture.loadFromFile(ASSETS_PATH "/images/brick.png");
}

People::People(int x, int y) : Tower(x, y, 10, 10, 2, 1, AttackType::PROJECTILE, peopleTexture, 60)
{
	peopleTexture.loadFromFile(ASSETS_PATH "/images/people.png");
	brickTexture.loadFromFile(ASSETS_PATH "/images/brick.png");
}

void People::useAbility(std::vector<Projectile>& projs)
{
	projs.push_back(*(new Projectile(getPosition(), sf::Texture(brickTexture), getAbilityPower(), 1)));
}

void People::destroyTower(void)
{

}