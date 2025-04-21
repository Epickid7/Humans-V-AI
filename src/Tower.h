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

	Tower(int x, int y, double current, double max, double power, double speed,
		int type, const sf::Texture& texture, int cost);

	Tower(Tower &t);
	~Tower();

	Tower& operator=(Tower& rhs);

	virtual void useAbility() = 0;

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