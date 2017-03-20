#include "cleric.hpp"

void Cleric::attack(Creature * defending)
{
	Creature::attack(defending);

	if (randomIntOutSeed(1, 10) == 10)
	{
		this->heathReg();
	}
}

Cleric::Cleric()
{
	//sets name
	setName("Cleric");

	//sets armor to 1
	setArmor(3);

	//sets strength ppoints to 12
	setStrPoints(15);

	//sets number of defence dice to 2
	setNumDDice(2);

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

	//Max health
	maxHealth = getStrPoints();
}