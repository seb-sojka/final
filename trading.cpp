#include "trading.hpp"

Trading::Trading()
{
	setExplored(true);
	setType("Trading Post");
	setDisplayChar('T');
	setPlay(true);
	setLieu(false);
}


void Trading::explore()
{
	//Already explored so nothing happens
}

void Trading::enter()
{
	std::cout << "You return Oblong's trading post." << std::endl;
	std::cout << "His wife prepares a meal for you all and ask what he do for ya. Maybe so rest to recovery your strenght" << std::endl;
}
