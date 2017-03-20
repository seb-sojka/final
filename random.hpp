/*****************************************************************************************
** Program Name: Random
** Author: Sebastian Sojka
** Date: 2/6/2017
** Description: The program can also give and random int between 2 numbers and a random integer
** without limit with both seeds inside the function and outside.
********************************************************************************************/
#ifndef SOJKAS_RANDOM_HPP
#define SOJKAS_RANDOM_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

int randomInt(int, int); //Returns a random integer between a range of integers (included)
int randomIntOutSeed(int, int); //Returns a random integer between a range of integers (included) with a outside seed
int randomIntOutSeed(); //Returns a random integer with a outside see. (no limit) 
int randomInt(); //Returns a random integer. (no limit)

#endif