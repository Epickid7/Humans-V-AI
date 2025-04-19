/*
* Mortar
* Shoot Projectile
* Min range, cant attack nearby enemies
* High Damage
* Low Health
*/

#pragma once

#include "../Tower.h"

class Mortar : public Tower
{
	void useAbility();

	void destroyTower(void);
};