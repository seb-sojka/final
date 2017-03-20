/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates the individual spaces for the simulation of Langton’s Ant. Allows the
** space to change color, have the ant display symbol on it, and the display symbol for white, black
** and the ant.
********************************************************************************************/
#ifndef SOJKAS_FORT_HPP
#define SOJKAS_FORT_HPP
#include <string>
#include "spaces.hpp"

class Fort :public Space
{
public:
	Fort();// Starts space as white

	virtual void explre(); //Turns color to the oppisite color

	void enter();

};
#endif