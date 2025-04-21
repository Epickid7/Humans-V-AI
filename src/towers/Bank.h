/*
* Bank
* No Damage
* Econ, makes money
* 
*/
#pragma once

#include "../Tower.h"

class Bank : public Tower
{
public:

	Bank(const sf::Texture& texture, int maxHealth = 10, double abilitySpeed = 1, int location[2] = nullptr, int cost = 0) : Tower(texture,maxHealth,abilitySpeed,location,cost) {

	}

	void useAbility();

	void destroyTower(void);
};