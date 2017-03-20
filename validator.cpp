/*****************************************************************************************
** Program Name: Validator
** Author: Sebastian Sojka
** Date: 2/13/2017
** Description: Validates user input depending on the type. Currently it can validate integer
** without limits, a lower limit, and one with both lower and upper limit.
** Additional, the program can also give and random int between 2 numbers and a random integer
** without limit
********************************************************************************************/

#include "validator.hpp"


/*****************************************************************
** Description: Validates user input of integer
*****************************************************************/
int inputInt()
{
	int returnInt;

	//Gets an input from the user
	std::cin >> returnInt;

	//Checks to see if the user input is integer. It will repeat until user enters a valid integer.
	while (std::cin.fail())
	{
		//Clears and ignores the previous user input if not an integer
		std::cin.clear();
		std::cin.ignore();

		//Prompts user that the input was not an integer
		std::cout << std::endl << "You did not enter a valid integer. Please eneter an integer. Thank you" << std::endl;

		//Gets an integer from the user
		std::cin >> returnInt;
	}

	//returns user entered integer
	return returnInt;
}

/*****************************************************************
** Description: Validates user input of integer with upper and lower limit
** The parameters of the function is 2 integers reprenting the lower and upper limit
*****************************************************************/
int inputInt(int int1, int int2)
{
	int returnInt;

	int lowerLimit, upperLimit ;

	//Checks to see which parameter is the lower and upper limit.
	if (int1 > int2)
	{
		//if the first integer is larger then the second integer, then lower limit is the second integer
		// and the upper limit is first integer
		lowerLimit = int2;
		upperLimit = int1;
	}
	else
	{
		//if the first integer is larger then the second integer, then lower limit is the second integer
		// and the upper limit is first integer
		lowerLimit = int1;
		upperLimit = int2;
	}

	//Gets an input from the user
	std::cin >> returnInt;

	//Checks to see if the user input is integer and the integer is between the limits.  It will repeat until user enters a valid integer. 
	while ((std::cin.fail()) || (returnInt > upperLimit) || (returnInt < lowerLimit))
	{
		//Clears and ignores the previous user input if not an integer
		std::cin.clear();
		std::cin.ignore();

		//Prompts user that the input was not valid integer or between the limits
		std::cout << std::endl << "You did not enter a valid integer. Please eneter an integer between " << lowerLimit << " and " << upperLimit << ". Thank you" << std::endl;

		//Gets an input from the user
		std::cin >> returnInt;
	}

	//returns user entered integer
	return returnInt;
}

/*****************************************************************
** Description: Validates user input of integer with upper and lower limit
** The parameters of the function is 1 integer reprenting the lower limit
*****************************************************************/
int inputIntLowerLimit(int lowerLimit)
{
	int returnInt;

	//Gets an input from the user
	std::cin >> returnInt;

	//Checks to see if the user input is integer and the integer is between the limits. It will repeat until user enters a valid integer.
	while ((std::cin.fail()) ||  (returnInt < lowerLimit))
	{
		//Clears and ignores the previous user input if not an integer
		std::cin.clear();
		std::cin.ignore();

		//Prompts user that the input was not valid integer or above the limit
		std::cout << std::endl << "You did not enter a valid integer. Please eneter an integer greater than or equal " << lowerLimit << ". Thank you" << std::endl;

		//Gets an input from the user
		std::cin >> returnInt;
	}

	//returns user entered integer
	return returnInt;
}


/*****************************************************************
** Description: Validates user input of integer with upper and lower limit
** The parameters of the function is 1 integer reprenting the upper limit
*****************************************************************/
int inputIntUpperLimit(int upperLimit)
{
	int returnInt;

	//Gets an input from the user
	std::cin >> returnInt;

	// Checks to see if the user input is integer and the integer is between the limits.It will repeat until user enters a valid integer.
	while ((std::cin.fail()) || (returnInt > upperLimit))
	{
		//Clears and ignores the previous user input if not an integer
		std::cin.clear();
		std::cin.ignore();
		
		//Prompts user that the input was not valid integer or above the limit
		std::cout << std::endl << "You did not enter a valid integer. Please eneter an integer less than or equal " << upperLimit << ". Thank you" << std::endl;

		//Gets an input from the user
		std::cin >> returnInt;
	}

	//returns user entered integer
	return returnInt;
}

/*****************************************************************
** Description: Validates user input of integer with upper and lower limit
** The parameters of the function is 1 integer reprenting the lower limit
*****************************************************************/
double inputDouLowerLimit(int lowerLimit)
{
	double returnDou;

	//Gets an input from the user
	std::cin >> returnDou;

	//Checks to see if the user input is integer and the integer is between the limits. It will repeat until user enters a valid integer.
	while ((std::cin.fail()) || (returnDou < lowerLimit))
	{
		//Clears and ignores the previous user input if not an integer
		std::cin.clear();
		std::cin.ignore();

		//Prompts user that the input was not valid integer or above the limit
		std::cout << std::endl << "You did not enter a valid integer. Please eneter an integer greater than or equal " << lowerLimit << ". Thank you" << std::endl;

		//Gets an input from the user
		std::cin >> returnDou;
	}

	//returns user entered integer
	return returnDou;
}


/*****************************************************************
** Description: Validates user input of integer with upper and lower limit
** The parameters of the function is 1 integer reprenting the upper limit
*****************************************************************/
double inputDouUpperLimit(int upperLimit)
{
	double returnDou;

	//Gets an input from the user
	std::cin >> returnDou;

	// Checks to see if the user input is integer and the integer is between the limits.It will repeat until user enters a valid integer.
	while ((std::cin.fail()) || (returnDou > upperLimit))
	{
		//Clears and ignores the previous user input if not an integer
		std::cin.clear();
		std::cin.ignore();

		//Prompts user that the input was not valid integer or above the limit
		std::cout << std::endl << "You did not enter a valid integer. Please eneter an integer less than or equal " << upperLimit << ". Thank you" << std::endl;

		//Gets an input from the user
		std::cin >> returnDou;
	}

	//returns user entered integer
	return returnDou;
}

/*****************************************************************
** Description: Checks if string is an integer. Returns true if integer
** and false if not a integer. Parameter of function is string.
*****************************************************************/
bool intCheck(std::string stringIn)
{
	//return boolean starts as true
	bool returnBool = true;

	//Does nothing if string is blank
	if (stringIn == "")
	{
		returnBool = false;
	}
	else
	{

		//If string is not blank, check to see if each char is a digit
		//Loops to the end of string
		for (int i = 0; i < stringIn.size(); i++)
		{
			//if char is not a digit and the starting char is not '-' for negative numbers
			if (!(isdigit(stringIn.at(i))) && !(i == 0 && stringIn.at(i) == '-'))
			{
				//Sets return bool to false
				returnBool = false;

				//Ends loop by seting the counter to the string size
				i = stringIn.size();
			}
		}
	}

	//Returns bool
	return returnBool;
}

