// File: Character.h
// Author: Jayren Calub
// Date Created: 4/13/2025

#include "Character.h"

// getters
int Character::getX() {
	return location[0];
}

int Character::getY() {
	return location[1];
}
double Character::getCurrentHealth() {
	return currentHealth;
}

double Character::getMaxHealth() {
	return maxHealth;
}

double Character::getAbilityPower() {
	return abilityPower;
}

double Character::getAbilitySpeed() {
	return abilitySpeed;
}

int Character::getAttackType() {
	return attackType;
}

// setters
void Character::setX(int newX) {
	location[0] = newX;
}

void Character::setY(int newY) {
	location[1] = newY;
}

void Character::setCurrentHealth(double newCur) {
	currentHealth = newCur;
}

void Character::setMaxHealth(double newMax) {
	maxHealth = newMax;
}

void Character::setAbilityPower(double newPower) {
	abilityPower = newPower;
}

void Character::setAbilitySpeed(double newSpeed) {
	abilitySpeed = newSpeed;
}

void Character::setAttackType(AttackType newType) {
	attackType = newType;
}