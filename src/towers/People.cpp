#include "People.h"


People::People() : Tower(0, 0, 10, 10, 2, 1, AttackType::PROJECTILE, getPeopleTexture(), 60)
{
	peopleTexture.loadFromFile(ASSETS_PATH "/images/people.png");
	brickTexture.loadFromFile(ASSETS_PATH "/images/brick.png");
}

People::People(int x, int y) : Tower(x, y, 10, 10, 2, 1, AttackType::PROJECTILE, sf::Texture(ASSETS_PATH "/images/people.png"), 60)
{
	peopleTexture.loadFromFile(ASSETS_PATH "/images/people.png");
	brickTexture.loadFromFile(ASSETS_PATH "/images/brick.png");
}

People::People(People& p)
{
	this->abilityPower = p.abilityPower;
	this->abilitySpeed = p.abilitySpeed;
	this->attackType = p.attackType;
	this->brickTexture = p.brickTexture;
	this->cost = cost; 
	this->currentHealth = currentHealth;
	this->setPosition(p.getPosition());
	this->texture = p.texture;
	this->maxHealth = p.maxHealth;
	this->peopleTexture = p.peopleTexture;
	this->peopleTexture = p.peopleTexture;
}

People& People::operator=(People& p)
{
	// TODO: insert return statement here

	
	this->brickTexture = p.brickTexture;

	this->peopleTexture = p.peopleTexture;

	Tower::operator=(p);

	return *this;
}

void People::useAbility(std::vector<Projectile>& projs)
{
	projs.push_back(*(new Projectile(getPosition(), sf::Texture(brickTexture), getAbilityPower(), 1)));
}

sf::Texture& People::getPeopleTexture(void)
{
	// TODO: insert return statement here
	return this->peopleTexture;
}

void People::destroyTower(void)
{

}