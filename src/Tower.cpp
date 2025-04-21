#include "Tower.h"


Tower::Tower(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0, string type = "",
	const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"), int cost = 0)
	: Character(x, y, current, max, power, speed, type, texture)
{
	setCost(cost);
}

//No dynamic memory to get rid of, nothing extra to do
Tower::~Tower()
{
}

//Add any extra on destroy effects for the gameplay
void Tower::destroyTower(void)
{
	

	delete this;
}
