/*****************************************************************************************
** Program Name: Validator
** Author: Sebastian Sojka
** Date: 2/13/2017
** Description: Validates user input depending on the type. Currently it can validate integer
** without limits, a lower limit, and one with both lower and upper limit.
** Additional, the program can also give and random int between 2 numbers and a random integer
** without limit with both seeds inside the fnunction and outside.
********************************************************************************************/
#ifndef SOJKAS_VALIDATOR_HPP
#define SOJKAS_VALIDATOR_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

int inputInt(); //Checks to see input is an integer. If it is integer it returns the inputed number. If not, it will ask for another integer.
int inputInt(int, int); //Checks to see input is an integer and within a range with lower and upper limit included. If it is integer wit the limts it returns the inputed number. If not, it will ask for another integer.
int inputIntLowerLimit(int); //Checks to see input is an integer and within a range with lower limit included. If it is integer with the limts it returns the inputed number. If not, it will ask for another integer.

double inputDou(); //Checks to see input is an integer. If it is integer it returns the inputed number. If not, it will ask for another integer.
double inputDou(int, int); //Checks to see input is an integer and within a range with lower and upper limit included. If it is integer wit the limts it returns the inputed number. If not, it will ask for another integer.
double inputDouLowerLimit(int); //Checks to see input is an integer and within a range with lower limit included. If it is integer with the limts it returns the inputed number. If not, it will ask for another integer.
double inputDouUpperLimit(int); //Checks to see input is an integer and within a range with lower limit included. If it is integer with the limts it returns the inputed number. If not, it will ask for another integer.

bool intCheck(std::string);


#endif
