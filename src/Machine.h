#pragma once

#include "Character.h"
#include "Tower.h"

class Machine : public Character {
protected:
	// no damage variable, will use ability power
	int payout;
	double movementSpeed;
	bool isInRange;

public:
	// constructor
	/*Machine(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0, double newMoveSpeed = 0, bool inRange = false)
		: Character(x, y, current, max, power, speed, type, texture) {
		payout = newPayout;
		damage = newDamage;
		movementSpeed = newMoveSpeed;
		isInRange = inRange;
	}*/

	Machine(int x, int y, double currentHP, double maxHP, double power, double speed, int type,
		const sf::Texture& texture, int newPayout, double newMoveSpeed, bool inRange) 
		: Character(x, y, currentHP, maxHP, power, speed, type, texture) {
		payout = newPayout;
		movementSpeed = newMoveSpeed;
		isInRange = inRange;
	}

	// destructor
	virtual ~Machine() {}

	// setters
	void setPayout(int newPay);
	void setMovementSpeed(double newSpeed);
	void setRange(bool newRange);

	// getters
	int getPayout();
	double getMovementSpeed();
	bool getRange();

	// member functions
	//virtual void useAbility(Tower& towerInGrid) = 0;
	void moveLeft();
};