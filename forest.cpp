#include "forest.hpp"

Forest::Forest()
{
	setType("Forest");
	setDisplayChar('F');
	setExplored(false);
	setPlay(false);
	setLieu(false);
}

void Forest::explore()
{
	std::cout << "You explore the new forest area but do not find anything of interest." << std::endl;
	setExplored(true);
}

void Forest::enter()
{
	std::cout << "You enter into a new square of land." << std::endl;
	std::cout << "It is dense with large pine trees and the noise of animals. " << std::endl;
}
