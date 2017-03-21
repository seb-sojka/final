#include "trading.hpp"

Trading::Trading()
{
	setExplored(true);
	setType("Trading Post");
	setDisplayChar('T');
	setPlay(true);
	setLieu(false);
	this->enter();
}


void Trading::explore()
{
	//Already explored so nothing happens
}

void Trading::enter()
{

}



void Trading::encounterRoll()
{
	//No roll in trading post
}
