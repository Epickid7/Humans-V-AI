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
public:
	People(int x, int y);

	void useAbility();

	void destroyTower(void);

protected:
	const string peopleTexture = ASSETS_PATH "/images/people.png"
};