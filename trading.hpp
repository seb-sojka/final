/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates the individual spaces for the simulation of Langton’s Ant. Allows the
** space to change color, have the ant display symbol on it, and the display symbol for white, black
** and the ant.
********************************************************************************************/
#ifndef SOJKAS_TRADING_HPP
#define SOJKAS_TRADING_HPP
#include <string>
#include "spaces.hpp"

class Trading :public Space
{
public:
	Trading();// Starts space as white

	void encounterRoll(); //Places the ant on top of the space (does not change the color)

	void explore(); //Turns color to the oppisite color

	void enter();
};
#endif