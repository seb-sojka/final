#include "fort.hpp"

Fort::Fort()
{
	setType("Fort");
	setDisplayChar('^');
	setExplored(false);
	setLieu(true);
	setPlay(false);
}

void Fort::encounterRoll()
{

}

void Fort::turnExplored()
{
	setExplored(true);
	setDisplayChar('F');
}

void Fort::enter()
{
	if (this->isExplored())
	{
		std::cout << "As you travel over hill, you see the the Stag Lord's fort" << std::endl;
		std::string choices[] = { "Attack fort", "Inspect Fort", "Retreat" };
		Menu attackFort("What do you care to do?", choices, 3);


	}
}

/*void Fort::bossFight()
{

}*/