#pragma once

#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Utilities.h"

class TowerSelect {
public:
	void displayTowerList(sf::RenderWindow &window);

	void setCurTower(int newCurTower);

	void checkForTowerSelect();

	int getCurTower(void);
private:
	int curTower;
};