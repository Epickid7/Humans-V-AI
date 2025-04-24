
#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Player.h"
#include "Projectile.h"
#include "towers/Bank.h"

class TestCase
{
public:
	void testProjectile();

	void testBarricade();

	void testPerson();

	void testBank();

	void testPlayer();
};

void TestCase::testProjectile()
{
	
}

void TestCase::testBarricade()
{

}

void TestCase::testPerson()
{

}

void TestCase::testBank()
{
	Bank bank(2, 3);
	//if(bank != )
}

void TestCase::testPlayer()
{
	sf::Vector2f pos(300, 400);
	//Projectile bullet(pos ,ASSETS_PATH "/images/brick.png", 100, 50.0);
}