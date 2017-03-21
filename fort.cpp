#include "fort.hpp"

Fort::Fort()
{
	setType("Fort");
	setDisplayChar('^');
	setExplored(false);
	setLieu(true);
	setPlay(false);
}

void Fort::explore()
{
	std::cout << "You see the fort of the Stag Lord" << std::endl;
	//Add more
}


void Fort::enter()
{
	if (this->isExplored())
	{
		std::cout << "As you travel over hill, you see the the Stag Lord's fort" << std::endl;
	}
	else
	{
		std::cout << "You enter into a new square of land." << std::endl;
		std::cout << "It is dense with large pine trees and the noise of animals. " << std::endl;
	}
}

