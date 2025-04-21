#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


// Projectile class encapsulates all the logic going with the projectiles that towers will shoot at the robot invaders. 

class Projectile : public sf::Sprite
{
public:
	// Projectile Constructor
	Projectile(const sf::Vector2f& pos, sf::Texture& texture, int newDamage, double newSpeed) : sf::Sprite(texture), speed(newSpeed), damage(newDamage) { setPosition(pos); }

	// update position of the projectile in gameplay, maybe don't need
	//void update_pos(double time)
	//{
	//	sf::Vector2f change = direction.x * direction.y * speed * time;
	//	move(change); // move the projectile based on its direction, speed, and time in the air...
	//}

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

	sf::Vector2f getDirection(void) const
	{
		return direction;
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

	void setDirection(sf::Vector2f newDirection)
	{
		direction = normalize(newDirection);
	}

private:
	int damage;
	double speed;
	sf::Vector2f direction;

	// normalization function for the direction, getting the magnitude
	sf::Vector2f normalize(sf::Vector2f& direc)
	{
		double magnitude = sqrt(direc.x * direc.x + direc.y * direc.y);
		direc = sf::Vector2f(direc.x / magnitude, direc.y / magnitude);
		return direc;
	}
};