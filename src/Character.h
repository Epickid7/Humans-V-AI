// File: Character.h
// Author: Jayren Calub
// Date Created: 4/13/2025

#pragma once

#include <iostream>
#include <string>

using std::string;

// Include SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Character : public sf::Sprite {
protected:
	int location[2];
	double currentHealth, maxHealth, abilityPower, abilitySpeed;
	string attackType;
	sf::Texture texture;
	
public:
	// constructor
	Character(int x = 0, int y = 0, double current = 0, double max = 0, double power = 0, double speed = 0, string type = "", 
		const sf::Texture& texture = sf::Texture(ASSETS_PATH "/images/default.png")) : Sprite(texture) {
		location[0] = x;
		location[1] = y;
		currentHealth = current;
		maxHealth = max;
		abilityPower = power;
		abilitySpeed = speed;
		attackType = type;
	}

	// getters
	int getX();
	int getY();
	double getCurrentHealth();
	double getMaxHealth();
	double getAbilityPower();
	double getAbilitySpeed();
	string getAttackType();
	// potential getter for texture???

	// setters
	void setX(int newX);
	void setY(int newY);
	void setCurrentHealth(double newCur);
	void setMaxHealth(double newMax);
	void setAbilityPower(double newPower);
	void setAbilitySpeed(double newSpeed);
	void setAttackType(string newType);
};