/*
* Landmine
* Blows up on contact
* 0 health?
* Medium Damage
*/

#pragma once

#include "../Tower.h"

class Landmine : public Tower
{
	void useAbility();

	void destroyTower(void);
};