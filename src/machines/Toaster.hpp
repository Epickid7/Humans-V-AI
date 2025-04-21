// Toaster: low health machine, quick movement speed

#pragma once

#include "../Machine.h"

class Toaster : public Machine {
private:
	const string bankTexture = ASSETS_PATH "/images/toaster.png";

public:
	// constructor
	Toaster(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0, double newMoveSpeed = 0, bool inRange = false)
		: Machine(x, y, current, max, power, speed, type, texture, newPayout, newDamage, newMoveSpeed, inRange) {}

	void useAbility(Tower& towerInGrid);
};

void Toaster::useAbility(Tower& towerInGrid) {
	
}