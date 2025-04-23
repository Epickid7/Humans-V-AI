#include "Bank.h"

Bank::Bank() : Tower(0, 0, 10, 10, 20, 1, AttackType::NEITHER, bankTexture, 50)
{
	bankTexture.loadFromFile(ASSETS_PATH "/images/bank.png");
}

Bank::Bank(int x, int y) : Tower(x, y, 10, 10, 20, 1, AttackType::NEITHER, bankTexture, 50)
{
	bankTexture.loadFromFile(ASSETS_PATH "/images/bank.png");
}

void Bank::useAbility(Player &p)
{
	p.addMoney(getAbilityPower());
}

void Bank::destroyTower(void)
{
}
