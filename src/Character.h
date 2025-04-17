#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Character : public sf::RectangleShape {
protected:
	double hp, damage, attackSpeed;
	string ability;

public:

};