/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Medusa for battle. low defense and health but high armor can kill any creature in single attack.
** Attack: 2d6
** Defence: 1d6
** Armor: 3
** Strength points: 8
** Glare: If medusa rolls a 12 on attack rool, the oppenenent looks into her eyes and turn to stone.
*********************************************************************************************/
#include "medusa.hpp"

/*****************************************************************************************
** Description: Contructor for medusa. Sets up her stats.
*********************************************************************************************/
Medusa::Medusa()
{
	//Set name
	setName("Medusa");

	//Set armor to 3
	setArmor(3);

	//Set strengthpoints to 8
	setStrPoints(8);

	//Set number of defence dice to 1
	setNumDDice(1);

	//set number of attack dice to 2
	setNumADice(2);

	//Die to be used for attack, d6
	Die aDie(6);

	//die to be used for defence, d6
	Die dDie(6);

	//set the attack dice to 2d6
	setADice(getNumADice(), aDie);

	//set the defence dice to 1d6
	setDDice(getNumDDice(), dDie);
	
}

/*****************************************************************************************
** Description: Medusa can kill any creature immediately if she rolls a 12 with glare.
** Glare: If medusa rolls a 12 on attack rool, the oppenenent looks into her eyes and turn to stone.
*********************************************************************************************/
void Medusa::attack(Creature* defending)
{
	//Defending creature rolls for defence
	int damage = -defending->defence();

	if (defending->getName() == "Rouge" && randomIntOutSeed(1, 10) == 10)
	{
		std::cout << "Rouge avoided attacked and counter attacked." << std::endl;
		defending->attack(this);
	}
	else
	{
		//Checks to see if vampire stopped attack
		if (damage > -1000)
		{

			//Medusa rolls her attack
			int attack = this->attackRoll();

			//checks to see if medusa rolled a 12 and turned oppent to stone
			if (attack >= 12)
			{
				//Display to user that medusa turned defending creature to stone
				std::cout << defending->getName() << " looked in Medusa's eye and turned to stone." << std::endl;

				//sets defending creature to 0 for strength points
				defending->setStrPoints(0);
			}
			else
			{
				//make sure attacking damage is 0 or greater. Sets to 0 if negative (defence > attack)
				damage = std::max(damage, 0);

				//deals damage to defending creature
				defending->damage(damage);

				//displays what creature took damage and from whom and how much
				std::cout << defending->getName() << " took " << damage << " from " << this->getName() << '.' << std::endl;
			}
		}
	}
}

/*****************************************************************************************
** Description: Display medusa's stats and her ability to turn her oppent to stone.
*********************************************************************************************/
void Medusa::display()
{
		baseDisplay();
		std::cout << "\t\tTurns oppent to stone when 12 rolled on attack";
}
