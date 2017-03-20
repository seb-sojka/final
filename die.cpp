/*****************************************************************************************
** Program Name: Dice War
** Author: Sebastian Sojka
** Date: 1/30/2017
** Description:  Regular die to be used for Dice War. Set the side of the die and rolls them.
** Has a name based on number of sides and if it is a regular or loaded die.
********************************************************************************************/
#include "die.hpp"

/*****************************************************************************************
** Description: Defualt constructor. Sets sides of die to 0 and name to ""
********************************************************************************************/
Die::Die()
{
	setSides(0);
	setName("");
}

/*****************************************************************************************
** Description: Constructor with paramete of the sides of the die as an integer
********************************************************************************************/
Die::Die(int sidesIn)
{
	//Set the number of sides of the die
	setSides(sidesIn);

	//Sets the name of the die to "Regular " number of sides "-sided die"
	setName("Regular " + std::to_string(sides) + "-sided die");
}

//Set number of sides of the die
void Die::setSides(int sidesIn)
{
	sides = sidesIn;
}

//Returns the number of sides of the die
int Die::getSides()
{
	return sides;
}

//Sets name of the die
void Die::setName(std::string nameIn)
{
	name = nameIn;
}

//Returns the name of the die
std::string Die::getName()
{
	return name;
}

//Rolls the die based on random integer generator with an outside seed
int Die::rollDie()
{
	return randomIntOutSeed(1, sides);
}