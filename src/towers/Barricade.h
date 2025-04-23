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
	Barricade::Barricade() : Tower(0, 0, 20, 20, 0, 1, AttackType::NEITHER, sf::Texture(barricadeTexture), 40)
	{

	}
	
	Barricade(int x, int y);

	void destroyTower(void);

protected:
	const string barricadeTexture = ASSETS_PATH "/images/barricade.png";
};