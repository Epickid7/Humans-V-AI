// Dog: low health machine, quick movement speed, 
// drops toaster when killed or contacts tower

#pragma once

#include "../Machine.h"

// Dog stats
#define CURRENT_HP 1
#define MAX_HP 1
#define ABILITY_POWER 0 // damage
#define ABILITY_SPEED 0 // how fast it attacks
#define PAYOUT 50
#define MOVEMENT_SPEED 1

class Dog : public Machine {
private:
	sf::Texture dogTexture;

public:
	Dog(double x, double y) : Machine(x, y, CURRENT_HP, MAX_HP, ABILITY_POWER, ABILITY_SPEED,
		AttackType::MELEE, dogTexture, PAYOUT, MOVEMENT_SPEED, false) {
		dogTexture.loadFromFile(ASSETS_PATH "/images/dog.png");
	}

	/*Machine(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0, double newMoveSpeed = 0, bool inRange = false)
		: Character(x, y, current, max, power, speed, type, texture) {}*/

	void useAbility();
};

void Dog::useAbility() {

}