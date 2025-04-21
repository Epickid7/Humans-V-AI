#include "Machine.h"

// setters
void Machine::setPayout(int newPay) {
	payout = newPay;
}

void Machine::setDamage(int newDamage) {
	damage = newDamage;
}

// getters
int Machine::getPayout() {
	return payout;
}

double Machine::getDamage() {
	return damage;
}