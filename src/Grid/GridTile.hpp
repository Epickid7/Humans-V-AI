#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// 
class GridTile : public sf::Sprite
{

public:
	GridTile(sf::Vector2f pos = {0.0,0.0}, sf::Vector2f square_width = { 0.0,0.0 }, const sf::Texture& texture = {}) : Sprite(texture) {
		this->setPosition(pos);
		this->hasTower = false;
		
	}


	GridTile& operator=(GridTile& rhs);



	void setSize(sf::Vector2f newSize);
	void setHasTower(bool newHasTower);

	sf::Vector2f getSize();
	bool getHasTower();

private:
	//I need to determine how they will click on a specific square
	//window width -offset % grid width (column number)
	//window_heighth - offset (if any) % grid width (row number)
	sf::Vector2f size;
	bool hasTower;

	


};
