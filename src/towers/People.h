/*
* People
* Shoot Projectiles (bricks)
* Low Damage (2)
* Average Health (10)
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
	const string peopleTexture = ASSETS_PATH "/images/people.png";
	const string brickTexture = ASSETS_PATH "/images/brick.png";
};