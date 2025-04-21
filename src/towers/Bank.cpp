#include "Bank.h"
#include "../Player.h"

Bank::Bank() : Tower(0, 0, 10, 10, 20, 1, AttackType::NEITHER, sf::Texture(bankTexture), 50)
{
}

Bank::Bank(int x, int y) : Tower(x, y, 10, 10, 20, 1, AttackType::NEITHER, sf::Texture(bankTexture), 50)
{

}

//DOES NOT DO ANYTHING
void Bank::useAbility()
{
}

void Bank::useAbility(Player p)
{
	p.addMoney(getAbilityPower());
}

void Bank::destroyTower(void)
{
}
