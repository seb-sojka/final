/*****************************************************************************************
** Program Name: Dice War
** Author: Sebastian Sojka
** Date: 1/30/2017
** Description:  Regular die to be used for Dice War. Set the side of the die and rolls them.
** Has a name based on number of sides and if it is a regular or loaded die.
********************************************************************************************/
#ifndef SOJKAS_DIE_HPP
#define SOJKAS_DIE_HPP

#include <string>
#include "random.hpp"

class Die
{
protected:
	int sides; 
	std::string name;
public:
	Die();
	Die(int);
	void setSides(int);
	int getSides();
	void setName(std::string);
	std::string getName();
	virtual int rollDie();
};

#endif