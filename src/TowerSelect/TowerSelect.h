#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Utilities.h"
#include "../Grid/GridTile.hpp"
#include "../Grid/Grid.hpp"
#include "../Tower.h"
#include "../towers/Bank.h"
#include "../towers/Barricade.h"
#include "../towers/Landmine.h"
#include "../towers/Mortar.h"
#include "../towers/People.h"
#include "../towers/Rifleman.h"
#include "../towers/Stickman.h"
#include "../towers/Tank.h"


class TowerSelect {
public:

	TowerSelect(Tower*towerToPlace = nullptr,int curTower = 0) {

	}

	void displayTowerList(sf::RenderWindow &window);

	void setCurTower(int newCurTower);

	void checkForTowerSelect();

	//function to place tower - returns true if tower placed
	//will also check if sufficient funds at some point
	bool checkForTowerPlace(GridTile **gameBoard[ROW][COLUMN], sf::Vector2f &mouse, std::vector<sf::Sprite> &towerVector);

	int getCurTower(void);
private:
	int curTower;
	Tower* towerToPlace;
};