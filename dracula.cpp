/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Vampire for battle. Low attack and defence but high health can use charm to stop attack.
** Attack: 1d12
** Defence: 1d6
** Armor: 1
** Strength points: 18
** Charm: 50% chance of oppent not attacking
*********************************************************************************************/
#include "dracula.hpp"

/*****************************************************************************************
** Description: Contructor for vampire. Sets up his stats.
*********************************************************************************************/
Vampire::Vampire()
{
	//set name
	setName("Vampire");

	//set armor to 1
	setArmor(1);

	//set strength points to 18
	setStrPoints(18);

	//set number of defence dice to 1
	setNumDDice(1);

	//set number of attack dice to 1
	setNumADice(1);

	//set attack die to d12
	Die aDie(12);

	//set defence die to d6
	Die dDie(6);

	//set attack dice to 1d12
	setADice(getNumADice(), aDie);

	//set defence dice to 1d6
	setDDice(getNumDDice(), dDie);
}

/*****************************************************************************************
** Description: Vampire can charm oppent to not attack. has 50/50 chance. Returns true if charmed
** and stop attack and false if the chamr failed
*********************************************************************************************/
bool Vampire::charm()
{
	//Gets rand number with out seed of either 0 (false) and 1 (true)
	bool returnCharm = randomIntOutSeed(0, 1);
		
	//return the result
	return returnCharm;
}


/*****************************************************************************************
** Description: Defence roll for vampire. If vampire charm his oppenent, oppentent does not attack him.
** This done by seting the defense to be return as really high.
*********************************************************************************************/
int Vampire::defence()
{
	//sum to be returned. starts at zero
	int sum = 0;

	//Checks to see if vampire chamred oppenent
	if (this->charm())
	{
		//Tells the user vampire charm attacker
		std::cout << "Vampire successful charm attacker and stops attack" << std::endl;

		//Sets defence high to prevent damage
		sum = 1000000;
	}
	else
	{
		//Rolls all the defence dice
		for (int i = 0; i < getNumDDice(); i++)
		{
			//rolls an attack die and adds to the returning sum
			sum += defenceDice[i].rollDie();
		}

		//adds armor
		sum += getArmor();
	}
	//returns sum for defence
	return sum;
}

void Vampire::display()
{
	baseDisplay();
	std::cout << "\t\tHas 50/50 chance to charm opponent into not attacking";
}

