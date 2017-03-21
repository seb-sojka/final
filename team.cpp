/*****************************************************************************************
** Program Name: Tourney
** Author: Sebastian Sojka
** Date: 3/6/2017
** Description: The team to fight in the tourney. User can set name of team and the the fighters in
** team.
********************************************************************************************/
#include "team.hpp"

/****************************************************************************************
** Description: Defualt constructor. Creates team with blank name and 0 fighters. It sets up 
** available creatures for the team.
********************************************************************************************/
Team::Team()
{
	
	//sets name and 
	setName("");
	setTotalFighters(0);

	//Sets up circular linked list
	head = new CreatNode(nullptr);
	head->next = nullptr;
	tail = head;

}

Team::Team(std::string nameIn)
{

	//sets name and 
	setName(nameIn);
	setTotalFighters(0);

	//Sets up circular linked list
	head = new CreatNode(nullptr);
	head->next = nullptr;
	tail = head;
}

void Team::emptyTeam()
{
	CreatNode* nodePtr = head;
	do
	{
		CreatNode *trash = nodePtr;

		delete trash->creature;

		nodePtr = nodePtr->next;

		delete trash;
	} while (nodePtr != nullptr);

	//Sets up circular linked list
	head = new CreatNode(nullptr);
	head->next = nullptr;
	tail = head;

}

/****************************************************************************************
** Description: Defualt destuctor. Delete pointers to avoid leaks
********************************************************************************************/
Team::~Team()
{
	/*
	//Deletes aviable creatures 
	for (int i = 0; i < totalNumCreat; i++)
	{
		delete creaturesChoices[i];
	}
	delete[] creaturesChoices;
	creaturesChoices = nullptr;
	
	//Deletes the linked list*/
	CreatNode* nodePtr = head;
	do
	{
		CreatNode *trash = nodePtr;

		delete trash->creature;

		nodePtr = nodePtr->next;

		delete trash;
	} while (nodePtr != nullptr);
}

void Team::setName(std::string nameIn)
{
	name = nameIn;
}

void Team::setTotalFighters(int numIn)
{
	totalNumCreat = numIn;
	remNumFighters = numIn;
}

std::string Team::getName()
{
	return name;
}

int Team::getTotalFighters()
{
	return totalNumCreat;
}

int Team::getRemFighters()
{
	return remNumFighters;
}

bool Team::getLost()
{
	return lost;
}

void Team::setLost(bool boolIn)
{
	lost = boolIn;
}

/*****************************************************************************************
** Description: User pick creature for fighting. Returns user choice as an integer
********************************************************************************************
int Team::pick()
{
	//For the name of all the creatures
	std::string creatureNames[NUMCREATURES];
	for (int i = 0; i < NUMCREATURES; i++)
	{
		creatureNames[i] = creaturesChoices[i]->getName();
	}
	std::string question = "What creature you wish to fight?";
	Menu creaturesMenu(question, creatureNames, NUMCREATURES);

	return creaturesMenu.makeChoice();
}*/

void Team::addCreat(Creature* creatIn)
{
	setTotalFighters(totalNumCreat + 1);
	if (head->creature == nullptr)
	{
		head->creature = creatIn;
	}
	else
	{
		//Checks to make sure every fighter has a unique name
		CreatNode *nPtr = head;

		//moves to tail node
		while (nPtr->next != nullptr)
		{
			nPtr = nPtr->next;
		}

		nPtr->next = new CreatNode(creatIn);
		tail = nPtr->next;

	}

	this->checkName();
}


/*****************************************************************************************
** Description: Adds fighter to the team. User deiced who 
********************************************************************************************
void Team::addCreat()
{
	int pick = this->pick();
	//If there is empty
	if (head->creature == nullptr)
	{
		//head is now a new fighter
		switch (pick)
		{
		case 1:	head->creature = new Vampire();
			break;

		case 2:	head->creature = new Barbarian();
			break;

		case 3:	head->creature = new BlueMen();
			break;

		case 4:	head->creature = new Medusa();
			break;

			//If user choices 5.
		default:head->creature = new HP();
			break;
		}
	}
	else
	{
		//Checks to make sure every fighter has a unique name
		CreatNode *nPtr = head;

		//moves to tail node
		while (nPtr->next != head)
		{
			nPtr = nPtr->next;
		}

		CreatNode *tPtr = nPtr->next;

		//Set creature as the aviable choices.
		//head is now a new fighter
		switch (pick)
		{
		case 1:	nPtr->next = new CreatNode(new Vampire());
			break;

		case 2:	nPtr->next = new CreatNode(new Barbarian());
			break;

		case 3:nPtr->next = new CreatNode(new BlueMen());
			break;

		case 4:	nPtr->next = new CreatNode(new Medusa());
			break;

			//If user choices 5.
		default: nPtr->next = new CreatNode(new HP());
			break;
		}

		nPtr->next->next = tPtr;

		nPtr->next->prev = nPtr;

		//set tail node as new node
		tail = nPtr->next;
	}

	//Checks name of newly added fighter
	checkName();
}*/


/*****************************************************************************************
** Description: Adds fighter to the team. User deiced who
********************************************************************************************/
void Team::checkName()
{
	//Changes name to inlcude team name
	tail->creature->setName(this->getName() + " " + tail->creature->getName());
	
	//Checks to make sure every fighter has a unique name
	CreatNode *nPtr = head;

	//Checks if fighter list is empty
	if (nPtr->creature != nullptr)
	{

		std::string stringNumber = "";
		int numberOf = 1;

		std::string tmpName = tail->creature->getName() + " No. " +std::to_string(numberOf);
	
		do {
			
			//checks to see if fighter already exist in team
			if (nPtr->creature->getName() == tmpName)
			{
				//Adds 1 to number of that fighter
				numberOf++;;
			}

			//then add to name
			stringNumber = std::to_string(numberOf);

			nPtr = nPtr->next;

			tmpName = tail->creature->getName() + " No. " + stringNumber;
		} while (nPtr != nullptr);

		//Adds number after name
		tail->creature->setName(tmpName);
	}
	
}

/*****************************************************************************************
** Description: Allows user to set the fighters of the team
*******************************************************************************************
void Team::setTeam()
{
	//Loops through the number of fighters
	for (int i = 0; i < getTotalFighters(); i++)
	{
		//Allows user to add fighter
		addCreat();
	}
}*/

/*****************************************************************************************
** Description: Display the team name and the fighters of team both alive and dead.
********************************************************************************************/
void Team::displayTeam()
{
	//Display team name
	std::cout << getName();

	//Display the fighters in the team
	std::cout << " with the fighters of " << std::endl;
	CreatNode *nPtr = head;
	do
	{
		std::cout << nPtr->creature->getName() << std::endl;
		nPtr = nPtr->next;
	} while (nPtr != head);


}

//Returns the first fighter in the list still avialable to fight
Creature * Team::headCreat()
{
	return head->creature;
}

/*****************************************************************************************
** Description: Removes character that lost in battle. Also checks to see if there are more 
** avialable fighters. 
********************************************************************************************/
void Team::removeHead()
{
	//Removes 
	remNumFighters--;
	//Checks to see if all fighters are  dead. 
	if (remNumFighters != 0)
	{
		//Moves head to next fighter
		head = head->next;
	}
	else
	{
		//Sets that the team lost
		setLost(true);
	}

	
}

void Team::fullRestore()
{
	CreatNode *nPtr = head;
	do
	{
		nPtr->creature->restore();;
		nPtr = nPtr->next;
	} while (nPtr != nullptr);
}

void Team::resetRage()
{
	CreatNode *nPtr = head;
	do
	{
		nPtr->creature->setRage(false);
		nPtr = nPtr->next;
	} while (nPtr != nullptr);
}
