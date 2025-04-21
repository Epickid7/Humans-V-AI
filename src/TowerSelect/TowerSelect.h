#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Utilities.h"
#include "../Grid/GridTile.hpp"
#include "../Grid/Grid.hpp"


class TowerSelect {
public:
	void displayTowerList(sf::RenderWindow &window);

	void setCurTower(int newCurTower);

	void checkForTowerSelect();

	//function to place tower - returns true if tower placed
	//will also check if sufficient funds at some point
	bool checkForTowerPlace(GridTile **gameBoard[ROW][COLUMN], sf::Vector2f &mouse, std::vector<sf::Sprite> &towerVector);

	int getCurTower(void);
private:
	int curTower;
};