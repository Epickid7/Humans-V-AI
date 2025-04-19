/*
* Barricade, wall/obstacle tower
* No Damage
* Higher Health
*/

#pragma once

#include "../Tower.h"

class Barricade : public Tower
{
	//Barricade() : Tower(sf::Texture(), 15, 1, { 0, 0 });

	void useAbility();

	void destroyTower(void);
};