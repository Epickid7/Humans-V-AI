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

	Tower(const sf::Texture& texture, int maxHealth = 10, double abilitySpeed = 1, int location[2] = nullptr, int cost = 0) :Character(0, 0, 0, 0, 0, 0, 0, texture) {
		setMaxHealth(maxHealth);
		setHealth(maxHealth);
		setAbilitySpeed(abilitySpeed);
		setLocation(location[0], location[1]);
		setCost(cost);
	}
	Tower();
	//Tower(Tower &t);
	~Tower();

	Tower& operator=(Tower& rhs);

	virtual void useAbility() = 0;

	virtual void destroyTower(void);

#pragma region getters

	int getHealth(void) const
	{
		return health;
	}

	int getMaxHealth(void) const
	{
		return maxHealth;
	}

	double getAbilitySpeed() const
	{
		return abilitySpeed;
	}

	int getLocationX() const
	{
		return location[0];
	}

	int getLocationY() const
	{
		return location[1];
	}

	int  getAbilityPower() const
	{
		return abilityPower;
	}
	
	int getCost() const
	{
		return cost;
	}
#pragma endregion


#pragma region setters
	//0 if invalid, 1 for valid/updated
	
	//Must be nonnegative and less than max health
	bool setHealth(int newHealth)
	{
		if (newHealth > maxHealth || newHealth < 0) return 0;
		else
		{
			health = newHealth;
			return 1;
		}
	}
	//Must be nonnegative
	bool setMaxHealth(int newMaxHealth)
	{
		if (newMaxHealth < 0) return 0;
		else
		{
			maxHealth = newMaxHealth;
			return 1;
		}
	}
	//Must be nonnegative
	bool setAbilitySpeed(double newAbilitySpeed)
	{
		if (newAbilitySpeed < 0) return 0;
		else
		{
			abilitySpeed = newAbilitySpeed;
			return 1;
		}
	}
	//No conditions?? boundaries are checked elsewhere
	bool setLocation(int x, int y)
	{
		location[0] = x;
		location[1] = y;
		return 1;
	}
	//Must be nonnegative
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

private:
	int cost;
	int health;
	int maxHealth;
	double abilitySpeed;
	int location[2];
	double abilityPower;

};



#endif