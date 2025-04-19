#include "GridTile.hpp"



GridTile& GridTile::operator=(GridTile& rhs)
{
	// TODO: insert return statement here
	return *this;
}

void GridTile::setSize(sf::Vector2f newSize)
{
	this->size = newSize;
}

sf::Vector2f GridTile::getSize()
{
	return this->size;
}
