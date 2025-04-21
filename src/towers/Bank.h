/*
* Bank
* No Damage
* Econ, makes money
* 
*/
#pragma once

#include "../Tower.h"
#include "../Player.h"

class Bank : public Tower
{
public:
	Bank();	

	Bank(int x, int y);

	//DOES NOT DO ANYTHING
	void useAbility();

	void useAbility(Player &p);

	void destroyTower(void);

protected:
	const string bankTexture = ASSETS_PATH "/images/bank.png";
};