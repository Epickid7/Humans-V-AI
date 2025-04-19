#pragma once


#include <iostream>

// Include SFML libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// 
class Machine : public Character
{
public:
	Machine(sf::Vector2f size, sf::Vector2f pos) : RectangleShape(size) {
		this->setPosition(pos);
	} 

	//Machine();
private:
	
};