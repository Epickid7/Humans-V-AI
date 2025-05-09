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

	void useAbility(Player &p);

	void destroyTower(void);

protected:
	sf::Texture bankTexture;
};