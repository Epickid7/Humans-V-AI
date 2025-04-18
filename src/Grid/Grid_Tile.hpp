#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// 
class Grid_Tile : public sf::Sprite
{

public:
	Grid_Tile(sf::Vector2f scale, sf::Vector2f pos, sf::Vector2f square_width, const sf::Texture& texture) : Sprite(texture) {
		this->setScale(scale);
		this->setPosition(pos);
		
	}
	void setSize(sf::Vector2f newSize);

	

private:
	//I need to determine how they will click on a specific square
	//window width -offset % grid width (column number)
	//window_heighth - offset (if any) % grid width (row number)
	sf::Vector2f size;

	


};