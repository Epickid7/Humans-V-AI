#pragma once


#include "Grid_Tile.hpp"
#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#define ROW 5
#define COLUMN 10


// 
class Grid 
{
	
public:

	Grid();
	

	
	
private:
	//I need to determine how they will click on a specific square
	//window width -offset % grid width (column number)
	//window_heighth - offset (if any) % grid width (row number)
	
	//declare array of pointers to towers here
	Grid_Tile gridArray[ROW][COLUMN];

};