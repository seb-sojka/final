/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates the individual spaces for the simulation of Langton’s Ant. Allows the 
** space to change color, have the ant display symbol on it, and the display symbol for white, black
** and the ant.
********************************************************************************************/
#ifndef SOJKAS_SPACES_HPP
#define SOJKAS_SPACES_HPP
#include <string>
#include <iostream>
#include "menu.hpp"


class Space
{
protected:
	char displayChar; //Display character for the color
	bool explored;
	bool lieHere;
	bool playHere;
	std::string type;
public:
	Space();
	
	void setExplored(bool); //Sets Color of the space
	bool isExplored(); //Returns color of the space (enum data, not string)


	void setDisplayChar(char); //Set display char based on current color
	char getDisplayChar(); //Returns display character

	void setLieu(bool);
	bool hasLie();

	void setType(std::string);
	std::string getType();

	void setPlay(bool);
	bool hasPlay();

	virtual void enter();

	virtual void explore() = 0;

};
#endif
