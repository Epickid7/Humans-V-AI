/*
* Melee tower
* 1 tile attack range
* attack faster?
* higher damage?
*/

#pragma once

#include "../Tower.h"

class Stickman : public Tower
{
	Stickman() : Tower(sf::Texture(), 10, .5, { 0, 0 });

	void useAbility();

	void destroyTower(void);
};