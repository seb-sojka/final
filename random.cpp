#include "random.hpp"
/*****************************************************************
** Description: Returns an random integer between 2 integers (included)
** The parameters of the function is 2 integers reprenting the upper and lower limit
*****************************************************************/
int randomInt(int int1, int int2)
{

	int lowInt, highInt;
	int randomInteger;

	//Checks to see which parameter is the lower and upper limit.
	if (int1 > int2)
	{
		//if the first integer is larger then the second integer, then lower limit is the second integer
		// and the upper limit is first integer
		lowInt = int2;
		highInt = int1;
	}
	else
	{
		//if the first integer is larger then the second integer, then lower limit is the second integer
		// and the upper limit is first integer
		lowInt = int1;
		highInt = int2;
	}

	//Finds the difference between the upper limit and lower limit
	int difference = highInt - lowInt + 1;

	//Calculates random integer between the upper and lower limt (they are included as possible integers)
	randomInteger = randomInt() % difference + lowInt;

	//Returns random integer between the limits.
	return randomInteger;
}

/*****************************************************************
** Description: Returns an random integer between 2 integers (included) and uses outside seed
** The parameters of the function is 2 integers reprenting the upper and lower limit
*****************************************************************/
int randomIntOutSeed(int int1, int int2)
{
	{

		int lowInt, highInt;
		int randomInteger;

		//Checks to see which parameter is the lower and upper limit.
		if (int1 > int2)
		{
			//if the first integer is larger then the second integer, then lower limit is the second integer
			// and the upper limit is first integer
			lowInt = int2;
			highInt = int1;
		}
		else
		{
			//if the first integer is larger then the second integer, then lower limit is the second integer
			// and the upper limit is first integer
			lowInt = int1;
			highInt = int2;
		}

		//Finds the difference between the upper limit and lower limit
		int difference = highInt - lowInt + 1;

		//Calculates random integer between the upper and lower limt (they are included as possible integers)
		randomInteger = randomIntOutSeed() % difference + lowInt;

		//Returns random integer between the limits.
		return randomInteger;
	}
}

/*****************************************************************
** Description: Returns an random integer. Uses outside seed
*****************************************************************/
int randomIntOutSeed()
{
	//Returns a random integer
	return rand();
}

/*****************************************************************
** Description: Returns an random integer.
*****************************************************************/
int randomInt()
{
	//Create random seed for a random integer
	unsigned seed = std::time(0);

	//Seeds the random generator
	std::srand(seed);

	//Returns a random integer
	return rand();
}
