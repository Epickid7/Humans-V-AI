#include "Barricade.h"


Barricade::Barricade() : Tower(0, 0, 20, 20, 0, 1, AttackType::NEITHER, sf::Texture(barricadeTexture), 40)
{

}

Barricade::Barricade(int x, int y) : Tower(x, y, 20, 20, 0, 1, AttackType::NEITHER, sf::Texture(barricadeTexture), 40)
{

}

void Barricade::useAbility()
{
}

void Barricade::destroyTower(void)
{
}
