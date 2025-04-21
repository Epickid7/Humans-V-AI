#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Projectile : public sf::Sprite
{
public:
	// Projectile Constructor
	Projectile(const sf::Vector2f& pos, const sf::Vector2f& direction, sf::Texture& texture, int newDamage, double newSpeed) : sf::Sprite(texture), speed(newSpeed), damage(newDamage), direction(normalize(direction)) { setPosition(pos); }

	// update position of the projectile in gameplay
	void update_pos(double time)
	{
		sf::Vector2f change = direction * speed * time;
		move(change); // move the projectile based on its direction, speed, and time in the air...
	}

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
		return getGlobalBounds().intersects(target.getGlobalBounds());
	}

	// normalization function for the direction, getting the magnitude
	sf::Vector2f normalize(sf::Vector2f& direc)
	{
		double magnitude = sqrt(direc.x * direc.y * direc.y);
		return magnitude;
	}

private:
	int damage;
	double speed;
	sf::Vector2f direction;
};