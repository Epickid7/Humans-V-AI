#include "Barricade.h"


Barricade::Barricade() : Tower(0, 0, 20, 20, 0, 1, AttackType::NEITHER, barricadeTexture, 40)
{
	barricadeTexture.loadFromFile(ASSETS_PATH "/images/barricade.png");
}

Barricade::Barricade(int x, int y) : Tower(x, y, 20, 20, 0, 1, AttackType::NEITHER, barricadeTexture, 40)
{
	barricadeTexture.loadFromFile(ASSETS_PATH "/images/barricade.png");
}

void Barricade::destroyTower(void)
{
}
