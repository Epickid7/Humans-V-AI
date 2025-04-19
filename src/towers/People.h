/*
* People
* Shoot Projectiles (bricks)
* Low Damate
* 
*/

#pragma once

#include "../Tower.h"

class People : public Tower
{
	void useAbility();

	void destroyTower(void);
};