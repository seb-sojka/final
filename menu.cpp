/*****************************************************************************************
** Program Name: Menu
** Author: Sebastian Sojka
** Date: 2/13/2017
** Description: Allows for quick creation of menus. The prorgam can ask the question and
** get a response from the user
********************************************************************************************/
#include "menu.hpp"

/*****************************************************************************************
** Description: Creates the base menu. The parameters include the question to be ask as a string, 
** an array of string for the choices and number of choices as an integer 
********************************************************************************************/
Menu::Menu(std::string questionIn, std::string choicesIn[], int size)
{
	//Sets the choices avaible
	setChoices(choicesIn, size);

	setAsk(questionIn);
}

Menu::Menu(std::string questionIn, std::vector<std::string> choicesIn)
{
	for (int i = 0; i < choicesIn.size(); i++)
	{
		choices.push_back(choicesIn.at(i));
	}

	setAsk(questionIn);
}

/*****************************************************************************************
** Description: Set the choices for the menu. The parameters of function is include the choices available 
** as an array of string and the number of choices as integers 
********************************************************************************************/
void Menu::setChoices(std::string choicesIn[], int size)
{
	for (int i = 0; i < size; i++)
	{
		choices.push_back(choicesIn[i]);
	}

}

//Sets the question to ask. The parameter of function is a string. 
void Menu::setAsk(std::string questionIn)
{
	question = questionIn;
}


/*****************************************************************************************
** Description: Returns the choices available
********************************************************************************************/
std::string Menu::getChoices()
{

	std::string returnString = "";

	//Adds the avialbe choices with number realted to it
	for (int i = 0; i < choices.size(); i++)
	{
		returnString += choices.at(i) + " = " + std::to_string(i + 1) + "\n";
	}
	return returnString;
}


//Returns the question being asked in the menu
std::string Menu::getAsk()
{
	return question;
}

/*****************************************************************************************
** Description: Validates the user input for menu. The parameter of function is integer.
********************************************************************************************/
bool Menu::validatorChoice(int choiceIn)
{
	//Sets as valid 
	bool valid = true;

	//Make sure the user choice 
	if ((choiceIn < 1) || (choiceIn > choices.size()))
	{
		valid = false;
		std::cout << "The choice was invalid. Please select a valid choice.";
	}
	return valid;
}

int Menu::makeChoice()
{
	int choice;
	
	//Repeat the question and choices until user selects the a possible choice
	do
	{
		//Displays the question to the menu
		std::cout << std::endl << question << std::endl;

		//Display the avialbe choices of the menu.
		std::cout << getChoices();

		//Gets the user choice from the 
		choice = inputInt();

		//Validates the choice of the user
	} while (!(validatorChoice(choice)));

	//Returns the choice user made as an int
	return choice;
}