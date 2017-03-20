/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates the individual spaces for the simulation of Langton’s Ant. Allows the
** space to change color, have the ant display symbol on it, and the display symbol for white, black
** and the ant.
********************************************************************************************/

#include "spaces.hpp"

/*****************************************************************
** Description: Sets the starting color of the space to White.
*****************************************************************/
Space::Space()
{
	setType("Emtpy"); 
}


void Space::setExplored(bool boolIn)
{
	explored = boolIn;
}

bool Space::isExplored()
{
	return explored;
}

void Space::setDisplayChar(char charIn)
{
	displayChar = charIn;
}

char Space::getDisplayChar()
{
	return displayChar;
}

void Space::setLieu(bool boolIn)
{
	lieHere = boolIn;
}

bool Space::hasLie()
{
	return lieHere;
}

void Space::setType(std::string stringIn)
{
	type = stringIn;
}

std::string Space::getType()
{
	return type;
}

void Space::setPlay(bool boolIn)
{
	playHere = boolIn;
}

bool Space::hasPlay()
{
	return playHere;
}

void Space::enter()
{
	std::cout << "You enter into a new square of land.";
	
}

void Space::explore()
{
	setExplored(true);
}
