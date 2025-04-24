// Toaster: low health machine, quick movement speed

#pragma once

#include "../Machine.h"

// Toaster stats
#define CURRENT_HP 5 
#define MAX_HP 5
#define ABILITY_POWER 2 // damage
#define ABILITY_SPEED 2 // how fast it attacks
#define PAYOUT 100
#define MOVEMENT_SPEED 0.5

class Toaster : public Machine {
private:
	sf::Texture toasterTexture;

public:
	// constructor
	Toaster(double x, double y) : Machine(x, y, CURRENT_HP, MAX_HP, ABILITY_POWER, ABILITY_SPEED,
		AttackType::MELEE, toasterTexture, PAYOUT, 0, MOVEMENT_SPEED, false) {
		toasterTexture.loadFromFile(ASSETS_PATH "/images/toaster.png");
	}

	/*Toaster(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0, double newMoveSpeed = 0, bool inRange = false)
		: Machine(x, y, current, max, power, speed, type, texture, newPayout, newDamage, newMoveSpeed, inRange) {}*/

	void useAbility(Tower& towerInGrid);
};

void Toaster::useAbility(Tower& towerInGrid) {
	
}