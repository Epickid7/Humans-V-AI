#include "Character.h"
#include "Tower.h"

class Machine : public Character {
protected:
	int payout;
	double damage, movementSpeed;
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
		sf::Texture& texture, int newPayout, double newDamage, double newMoveSpeed, bool inRange) 
		: Character(x, y, currentHP, maxHP, power, speed, type, texture) {
		payout = newPayout;
		damage = newDamage;
		movementSpeed = newMoveSpeed;
		isInRange = inRange;
	}

	// destructor
	virtual ~Machine() {}

	// setters
	void setPayout(int newPay);
	void setDamage(double newDamage);
	void setMovementSpeed(double newSpeed);
	void setRange(bool newRange);

	// getters
	int getPayout();
	double getDamage();
	double getMovementSpeed();
	bool getRange();

	// member functions
	virtual void useAbility(Tower& towerInGrid) = 0;
	void moveLeft();
};

void Machine::moveLeft() {
	move(sf::Vector2f(-1 * movementSpeed, 0));
}