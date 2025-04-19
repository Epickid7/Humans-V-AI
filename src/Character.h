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
	
public:
	// constructor
	//Tower(const sf::Texture &texture, int maxHealth = 10, double abilitySpeed = 1, int location[2] = nullptr);
	/*Character(int newX, int newY, double current, double max, double power, double speed, 
		string attack, const sf::Texture&) {

	}

	Character(int location[2] = nullptr, double current = 0, double max = 0, double power = 0, 
		double speed = 0, string attackType = "", const sf::Texture& texture) : Sprite(texture) {

	}*/
};