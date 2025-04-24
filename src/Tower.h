#ifndef TOWER_H
#define TOWER_H

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Projectile.h"

class Tower : public Character
{

public:

	Tower::Tower(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"), int cost = 0)
		: Character(x, y, current, max, power, speed, type, texture)
	{
		setCost(cost);
	}

	/*Tower(int x, int y, double current, double max, double power, double speed,
		int type, const sf::Texture& texture, int cost);*/

	Tower(const Tower &t);

	//Tower();
	~Tower();

	Tower& operator=(Tower& rhs);

	virtual void useAbility();

	virtual void destroyTower(void);

#pragma region getters
	
	int getCost() const
	{
		return cost;
	}
#pragma endregion


#pragma region setters
	//0 if invalid, 1 for valid/updated
	
	bool setCost(int cost)
	{
		if (cost < 0) return 0;
		else 
		{
			this->cost = cost;
			return 1;
		}
	}
#pragma endregion

protected:
	int cost;
};



#endif