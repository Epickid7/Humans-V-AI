#pragma once


#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// 
class Machine : public sf::RectangleShape
{
public:
	Machine(sf::Vector2f size, sf::Vector2f pos) : RectangleShape(size) {
		
	} 
private:
	
};