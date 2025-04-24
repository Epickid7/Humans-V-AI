// Terminator: high health machine, slow movement speed

#pragma once

#include "../Machine.h"

// Terminator stats
#define CURRENT_HP 10 
#define MAX_HP 10
#define ABILITY_POWER 2 // damage
#define ABILITY_SPEED 2 // how fast it attacks
#define PAYOUT 150
#define MOVEMENT_SPEED 0.1

class Terminator : public Machine {
private:
	sf::Texture terminatorTexture;

public:
	Terminator(double x, double y) : Machine(x, y, CURRENT_HP, MAX_HP, ABILITY_POWER, ABILITY_SPEED,
		AttackType::MELEE, sf::Texture(), PAYOUT, MOVEMENT_SPEED, false) {
		terminatorTexture.loadFromFile(ASSETS_PATH "/images/terminator.png");
	}

	/*Machine(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0, double newMoveSpeed = 0, bool inRange = false)
		: Character(x, y, current, max, power, speed, type, texture) {}*/

	//void useAbility();
};

//void Terminator::useAbility() {}