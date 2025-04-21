// Toaster: low health machine, quick speed

#pragma once

#include "../Machine.h"

class Toaster : public Machine {
private:


public:
	// constructor
	Machine(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0, double newMoveSpeed = 0, bool inRange = false)
		: Character(x, y, current, max, power, speed, type, texture) {}

	void useAbility();
	void move();
};

void Toaster::useAbility() {

}

void Toaster::move() {

}