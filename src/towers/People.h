/*
* People
* Shoot Projectiles (bricks)
* Low Damage (2)
* Average Health (10)
* 
*/

#pragma once

#include "../Tower.h"

class People : public Tower
{
	void useAbility();

	void destroyTower(void);
};