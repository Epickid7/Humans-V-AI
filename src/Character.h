#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Character : public sf::RectangleShape { // RectangleShape or Sprite?
protected:
	double hp, damage, attackSpeed;
	string ability;

public:
	
};