/*
* People
* Shoot Projectiles (bricks)
* Low Damage
*  cost is 60
*/

#pragma once

#include "../Tower.h"

class People : public Tower
{
	void useAbility();

	void destroyTower(void);
};