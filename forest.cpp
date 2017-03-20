#include "forest.hpp"

Forest::Forest()
{
	setType("Forest");
	setDisplayChar('F');
	setExplored(false);
	setPlay(false);
	setLieu(false);
}

void Forest::enter()
{
	std::cout << "You enter into a new square of land." << std::endl;
}
