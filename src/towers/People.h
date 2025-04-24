/*
* People
* Shoot Projectiles (bricks)
* Low Damage (2)
* Average Health (10)
*  cost is 60
*/

#pragma once

#include "../Tower.h"
#include "../Projectile.h"
#include <vector>

class People : public Tower
{
public:
	People();

	People(int x, int y);

	People(People& p);

	People & operator=(People & p);



	void useAbility(std::vector<Projectile>& projs);

	void destroyTower(void);

protected:
	string peopleTexture = ASSETS_PATH "/images/people.png";
	string brickTexture = ASSETS_PATH "/images/brick.png";
};