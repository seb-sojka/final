/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: The boy who lived (aka Harry Porter) for battle. Good attack and defence and can revive after the first fall
** Attack: 2d6
** Defence: 2d6
** Armor: 0
** Strength points: 10
** Hogwart:If Harry dies (i.e. strength <=0), he immediately recovers and his total strength becomes 20. If he were
** to die again, then he’s dead
*********************************************************************************************/
#include "hp.hpp"

/*****************************************************************************************
** Description: Contructor for boy who lived. Sets up his stats.
*********************************************************************************************/
HP::HP()
{
	//sets name
	setName("The boy who lived");

	//set armor to 0
	setArmor(0);

	//set strengthpoint to 10
	setStrPoints(10);

	//set number of defence dice to 2
	setNumDDice(2);

	//set number of attack dice to 2
	setNumADice(2);

	//set die to be used for attack to d6
	Die aDie(6);

	//set die to used for attack to d6
	Die dDie(6);

	//set attack dice to 2d6
	setADice(getNumADice(), aDie);

	//set defence dice to 2d6
	setDDice(getNumDDice(), dDie);

	//set if revive is available to true
	setReviveAvail(true);
}

/*****************************************************************************************
** Description: Checks to see if harry porter died. if revive is avialable and harry is died,
** harry is revived and stronger than ever.
*********************************************************************************************/
bool HP::death()
{
	//sets return bool as false
	bool returnBool = false;
	
	//checks to see if strength points to less than or equal to 0
	if (this->getStrPoints() <= 0)
	{

		//checks to see if revive is avialable
		if (getReviveAvail())
		{
			//revives harry if avialable
			revive();
		}
		else
		{
			//sets return bool to true if harry is died
			returnBool = true;
		}
	}

	//returns bool
	return returnBool;
}

/*****************************************************************************************
** Description: Revives harry porter and sets his strength points to 20
*********************************************************************************************/
void HP::revive()
{
	//Tells user that harry have been revived and stronger
	std::cout << this->getName() << " has been revived and stronger than ever." << std::endl;

	//sets strength points to 20
	setStrPoints(20);

	//sets revive available to false
	setReviveAvail(false);
}

void HP::setReviveAvail(bool bIn)
{
	reviveAvail = bIn;
}

bool HP::getReviveAvail()
{
	return reviveAvail;
}


/*****************************************************************************************
** Description: Display harry's stats and his ability to be revieved
*********************************************************************************************/
void HP::display()
{
	//display base stats
	baseDisplay();

	//display his special ability
	std::cout << "\t\tIf Harry dies, he immediately recovers and his total strength becomes 20. Only once per a fight.";
}
