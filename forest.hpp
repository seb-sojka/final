/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates the individual spaces for the simulation of Langton’s Ant. Allows the
** space to change color, have the ant display symbol on it, and the display symbol for white, black
** and the ant.
********************************************************************************************/
#ifndef SOJKAS_FOREST_HPP
#define SOJKAS_FOREST_HPP
#include <string>
#include "spaces.hpp"

class Forest :public Space
{
public:
	Forest();// Starts space as white

	void enter();

};
#endif