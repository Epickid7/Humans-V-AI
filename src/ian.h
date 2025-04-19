#pragma once

#include <SFML/Graphics.hpp>

class Projectile
{
public:
	Projectile(const sf::Vector2f& size, const sf::Vector2f& pos, sf::Texture& texture, int newDamage, double newSpeed) { this->damage = newDamage, this->speed = newSpeed; }

private:
	int damage;
	double speed;

};