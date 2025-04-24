#include "Machine.h"

// setters
void Machine::setPayout(int newPay) {
	payout = newPay;
}

void Machine::setDamage(double newDamage) {
	damage = newDamage;
}

void Machine::setMovementSpeed(double newSpeed) {
	movementSpeed = newSpeed;
}

void Machine::setRange(bool newRange) {
	isInRange = newRange;
}

// getters
int Machine::getPayout() {
	return payout;
}

double Machine::getDamage() {
	return damage;
}

double Machine::getMovementSpeed() {
	return movementSpeed;
}

bool Machine::getRange() {
	return isInRange;
}

void Machine::moveLeft() {
	move(sf::Vector2f(-1 * movementSpeed, 0));
}