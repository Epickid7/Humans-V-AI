/*
* Bank
* No Damage
* Econ, makes money
* 
*/
#pragma once

#include "../Tower.h"

class Bank : public Tower
{
public:
	Bank();

	Bank(int x, int y);

	void useAbility();

	void destroyTower(void);

protected:
	const string bankTexture = ASSETS_PATH "/images/bank.png";
};