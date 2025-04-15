#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#define ROW 5
#define COLUMN 10


// 
class Grid : public sf::Sprite
{
	
public:
	Grid(sf::Vector2f scale, sf::Vector2f pos, sf::Vector2f square_width, const sf::Texture& texture) : Sprite(texture) {
		this->setScale(scale);
		this->setPosition(pos);
		this->squareWidth = square_width;
	}
	void setSquareWidth(sf::Vector2f newSquareWidth);

	
	
private:
	//I need to determine how they will click on a specific square
	//window width -offset % grid width (column number)
	//window_heighth - offset (if any) % grid width (row number)
	sf::Vector2f squareWidth;
	
	
};