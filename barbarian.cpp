/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Barbarian for battle. Good stats without a special ability.
** Attack: 2d6
** Defence: 2d6
** Armor: 0
** Strength points: 12
*********************************************************************************************/
#include "barbarian.hpp"

Barbarian::Barbarian()
{
	//sets name
	setName("Barbarian");
	
	//sets armor to 1
	setArmor(1);

	//sets strength ppoints to 12
	setStrPoints(20);

	//sets number of defence dice to 2
	setNumDDice(2);

	//Sets rage as false
	setRage(false);

	//sets number of attack dice to 2
	setNumADice(2);

	//set die for attacking to d6
	Die aDie(6);

	//set die for defending to d6
	Die dDie(6);

	//set attakc dice to 2d6
	setADice(getNumADice(), aDie);

	//set defence dice to 2d6;
	setDDice(getNumDDice(), dDie);

}

/*****************************************************************
** Description: Rolls the attack dice for attack and returns the results
*************************************************************/
int Barbarian::attackRoll()
{
	//sum to be reutrn. starts at zero
	int sum = Creature::attackRoll();

	//If barbarian is in rage, then roll extra dive 
	if (rage)
	{
		sum += this->attackDice[0].rollDie();
	}

	//returns sum
	return sum;
}


void Barbarian::damage(int damIn)
{
	Creature::damage(damIn);

	if (randomIntOutSeed(1, 10) == 10)
	{
		setRage(true);
	}

}

void Barbarian::setRage(bool boolIn)
{
	rage = boolIn;
}

bool Barbarian::getRage()
{
	return rage;
}