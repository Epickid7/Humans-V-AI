#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Projectile : public sf::Sprite
{
public:
	// Projectile Constructor
	Projectile(const sf::Vector2f& pos, const sf::Vector2f& direction, sf::Texture& texture, int newDamage, double newSpeed) : sf::Sprite(texture), speed(newSpeed), damage(newDamage), direction(direction) { setPosition(pos); }

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

	bool OuterBounds() 
	{
		
	}


private:
	int damage;
	double speed;
	sf::Vector2f direction;
};