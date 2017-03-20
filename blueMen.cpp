/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Blue men for battle. A mob of small creatures whose defence decreases as strength points decrease
** Attack: 2d6
** Defence: 2d6
** Armor: 0
** Strength points: 12
*********************************************************************************************/
#include "blueMen.hpp"

/*****************************************************************************************
** Description: Contructor for blue men. Sets up stats for blue men.
*********************************************************************************************/
BlueMen::BlueMen()
{
	//Set name
	setName("Blue Men");

	//Set armor to 3
	setArmor(3);

	//Set strength point to 12
	setStrPoints(12);

	//Set number of dice defence to 3
	setNumDDice(3);

	//Set number of attack dice to 2
	setNumADice(2);

	//Set attack die to d10
	Die aDie(10);

	//set defence die to d6
	Die dDie(6);

	//set attack dice to 2d10
	setADice(getNumADice(), aDie);

	//set defence dice to 2d6
	setDDice(getNumDDice(), dDie);
}


/*****************************************************************
** Description: First check if defence dice needs to be decreased. 
** Blue men lose a die for every 4 points of damage.
** Rolls the defence dice for defence and then adds
** the creature armor. returns the results
*************************************************************/
int BlueMen::defence()
{
	//sets reutnr sum to 0
	int sum = 0;

	//checks to see if blue men have taken enough damage for thir defence dice to be decreased
	if (ceil(this->getStrPoints() / 4.0) < this->getNumDDice())
	{
		//if blue have taken enough damgage (4) to reduce thier defence dice pool then it is
		//decreased to the right amount
		this->setNumDDice(ceil(this->getStrPoints() / 4.0));
	}

	//roll defence dice
	for (int i = 0; i < getNumDDice(); i++)
	{
		//adds the number rolled to the sum
		sum += defenceDice[i].rollDie();
	}

	//adds armor to defence sum
	sum += this->getArmor();

	//rturns the sum of defence.
	return sum;
}

/*****************************************************************************************
** Description: Display blue men stats and thier ablity that reduce thier defence.
*********************************************************************************************/
void BlueMen::display()
{
	baseDisplay();
	std::cout << "\t\tFor every 4 points of damage, they lose one defense die";
}
