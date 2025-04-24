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
	Barricade();
	
	Barricade(int x, int y);

	void destroyTower(void);

protected:
	sf::Texture barricadeTexture;
};