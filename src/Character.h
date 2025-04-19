// File: Character.h
// Author: Jayren Calub
// Date Created: 4/13/2025

#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Character : public sf::Sprite {
protected:
	double hp, damage, attackSpeed;
	string ability;
	sf::Sprite sprite;

public:
	Character(double _hp = 0, double _damage = 0, double _as = 0, string _ability = "") {

	}
};