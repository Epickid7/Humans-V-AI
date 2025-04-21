#ifndef TOWER_H
#define TOWER_H

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Character.h"

class Tower : public Character
{

public:

	Tower(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0, string type = "",
		const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"), int cost = 0) 
		: Character(x, y, current, max, power, speed, type, texture);

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