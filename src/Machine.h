#include "Character.h"

class Machine : public Character {
protected:
	int payout;
	double damage;

public:
	// constructor
	Machine(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0,
		int type = AttackType::NEITHER, const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png"),
		int newPayout = 0, double newDamage = 0)
		: Character(x, y, current, max, power, speed, type, texture) {
		payout = newPayout;
		damage = newDamage;
	}

	// member functions
	virtual void useAbility() = 0;
	virtual void move() = 0;

	// setters
	void setPayout(int newPay);
	void setDamage(int newDamage);

	// getters
	int getPayout();
	double getDamage();
};