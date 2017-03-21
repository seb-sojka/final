/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 3/22/2017
** Description: Basic Bandits. Very weak.
** Attack: 2d6
** Defence: 1d6
** Armor: 0
** Strength points: 12
*********************************************************************************************/

#include "bandits.hpp"

Bandit::Bandit()
{
		//sets name
		setName("Bandit");

		//sets armor to 1
		setArmor(0);

		//sets strength ppoints to 12
		setStrPoints(12);

		//sets number of defence dice to 2
		setNumDDice(2);

		//sets number of attack dice to 1
		setNumADice(1);

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
