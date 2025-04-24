#include "Machine.h"

// setters
void Machine::setPayout(int newPay) {
	payout = newPay;
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

double Machine::getMovementSpeed() {
	return movementSpeed;
}

bool Machine::getRange() {
	return isInRange;
}

void Machine::moveLeft() {
	move(sf::Vector2f(-1 * movementSpeed, 0));
}