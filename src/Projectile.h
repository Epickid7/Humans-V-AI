#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


// Projectile class encapsulates all the logic going with the projectiles that towers will shoot at the robot invaders. 

class Projectile : public sf::Sprite
{
public:
	// Projectile Constructor
	Projectile(sf::Vector2f& pos, sf::Texture& texture, int newDamage, double newSpeed) : sf::Sprite(texture), speed(newSpeed), damage(newDamage) { setPosition(pos); }


	// damage getter
	int getDamage(void) const
	{
		return damage;
	}

	// speed getter
	double getSpeed(void) const
	{
		return speed;
	}

	

	// check if the Projectile is out of bounds
	bool OuterBounds(const sf::RenderWindow& window) const
	{
		sf::Vector2f pos = getPosition();
		return pos.x < 0 || pos.x > window.getSize().x || pos.y < 0 || pos.y > window.getSize().y;
	}

	// check for collision with a robobot
	bool checkCollision(const sf::Sprite& target) const 
	{
		if (getGlobalBounds().findIntersection(target.getGlobalBounds()))
		{
			return true;
		}
	}

	// setters
	void setDamage(int& newDamage)
	{
		damage = newDamage;
	}

	void setSpeed(double& newSpeed)
	{
		speed = newSpeed;
	}

	

private:
	int damage;
	double speed;
};