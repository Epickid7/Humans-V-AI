#include "Bank.h"

Bank::Bank(int x, int y) : Tower(x, y, 10, 10, 20, 1, AttackType::NEITHER, sf::Texture(bankTexture), 50)
{

}

void Bank::useAbility()
{
	//money += 20;
}

void Bank::destroyTower(void)
{
}
