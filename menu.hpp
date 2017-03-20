/*****************************************************************************************
** Program Name: Menus
** Author: Sebastian Sojka
** Date: 2/13/2017
** Description: Allows for quick creation of menus. The prorgam can ask the question and
** get a response from the user 
********************************************************************************************/
#ifndef SOJKAS_MENU_HPP
#define SOJKAS_MENU_HPP

#include <string>
#include <vector>
#include <iostream>
#include "validator.hpp"

class Menu
{
private:
	std::vector<std::string> choices;//Choices avaiable to user
	std::string question;//Question to be asked to user
public:
	Menu(std::string question, std::string choices[], int numChoices);
	Menu(std::string questionIn, std::vector<std::string> choices);
	//Create menu with title question, choices, and the number of them
	//Menu(std::string question, std::vector<std::string> choices);//Create menu with title question, choices, and the number of them
	void setChoices(std::string[], int);//Sets the choices for user
	void setAsk(std::string);//sets the question to be asked
	std::string getChoices();//returns the aviable choices in string with number chooses
	std::string getAsk();//returns the question
	bool validatorChoice(int);//validates the user choice
	int makeChoice();//returns integer in associate
	//~Menu();
};


#endif