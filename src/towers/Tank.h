/*
* Tank
* Shoot projectile
* Higher Damage
* Higher health
*/

#pragma once

#include "../Tower.h"

class Tank : public Tower
{
	void useAbility();

	void destroyTower(void);
};