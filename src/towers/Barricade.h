/*
* Barricade, wall/obstacle tower
* No Damage
* Higher Health
*/

#pragma once

#include "../Tower.h"

class Barricade : public Tower
{
public:
	Barricade(int x, int y);

	void useAbility();

	void destroyTower(void);

protected:
	const string barricadeTexture = ASSETS_PATH "/images/barricade.png";
};