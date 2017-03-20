#include "combat.hpp"

/*****************************************************************************************
** Description: Defualt constructor. Enters the aviable characters to fight, seeds random number generator,
** and starts the menu.
********************************************************************************************/
Combat::Combat()
{
	//Adds all the characters to avilable choices
	creatures = new Creature*[NUMCREATURES];
	creatures[0] = new Vampire();
	creatures[1] = new Barbarian();
	creatures[2] = new BlueMen();
	creatures[3] = new Medusa();
	creatures[4] = new HP();

	//Create random seed for a random integer
	unsigned seed = std::time(0);
	//Seeds the random generator
	std::srand(seed);
	
	//For testing
	//test();

	//Goes to start menu
	startMenu();
}

/*****************************************************************
** Start menu. Allows user to fight, display fighters or exit
*****************************************************************/
void Combat::startMenu()
{
	//Sets up start menu. Allows user to fight, display fighters or exit
	std::string choices[] = {"Fight", "Display fighters", "Exit"};
	std::string question = "What do you wish to do?";
	Menu startMenu(question, choices, 3);
	
	int choice;

	do {

		//User chooses
		choice = startMenu.makeChoice();

		//Start fight
		if (choice == 1)
		{
			startBattle();
		}

		//Display fighters
		else if (choice == 2)
		{
			display();
		}

		//Exits
	} while (choice != 3);


}

/*****************************************************************
** Starts the battle. Allow user to choose characters and then fight
*****************************************************************/
void Combat::startBattle()
{
	//Character for choice
	Creature* creat1;
	Creature* creat2;

	//User select the character they wish to fight
	setCreature(creat1);
	setCreature(creat2);

	//Randomly decides how attacks first
	if (randomIntOutSeed(1, 2) == 1)
	{
		//character 1 attack first
		battle(creat1, creat2);
	}

	else
	{		
		//character 2 attack first
		battle(creat2, creat1);
	}

	//Delete characters to avoid leaks
	delete creat1;
	delete creat2;
	creat1 = nullptr;
	creat2 = nullptr;
}

/*****************************************************************
** Display characters to choose from and thier stats and special ability
*****************************************************************/
void Combat::display()
{
	//Title display
	std::string displayTitle = "Name\t\t\tAttack\tDefence\tArmor\tStrength Points\tSpecial Abilites";
	std::cout << displayTitle <<std::endl;

	//Display each character stats
	for (int i = 0; i < NUMCREATURES; i++)
	{
		creatures[i]->display();
		std::cout << std::endl;
	}
}

/*****************************************************************************************
** Description: test to check fighters can fight each other without trouble and display creature
********************************************************************************************/
void Combat::test()
{
	//Character for choice
	Creature* creat1;
	Creature* creat2;
	
	display();

	for (int j = 1; j <= NUMCREATURES; j++)
	{
		setCreature(creat1, j);
		for (int i = 1; i <= NUMCREATURES; i++)
		{
			setCreature(creat2, i);
			battle(creat1, creat2);
			delete creat2;
		}
		delete creat1;
	}

	creat1 = nullptr;
	creat2 = nullptr;
}

/*****************************************************************************************
** Description: Destructor. Delete creatures to avoid leaks.
********************************************************************************************/
Combat::~Combat()
{
	for(int i = 0; i < NUMCREATURES; i++)
	{
		delete creatures[i];
	}
	delete[] creatures;
	creatures = nullptr;
}

/*****************************************************************************************
** Description: Battle bewteen characters. The parament is the 2 character sto fight with creature1 
** attacking first.
********************************************************************************************/
void Combat::battle(Creature* creature1, Creature* creature2)
{
	//counter to end fight if something goes wrong
	int counter = 0;

	//Characters attack each in loop until one is dead or round limit.
	do {
		//First attack
		creature1->attack(creature2);

		//Checks to see if prevoius attack killed creature
		if (!(creature2->death()))
		{
			//creature is not dead, 2nd creature attacks
			creature2->attack(creature1);
		}

		//add one to counter
		counter++;
	} while (!(creature1->death()) && !(creature2->death()) && counter<1000);
	
	//checks to see who won and declare winner
	if (creature1->death())
	{
		std::cout << creature1->getName() << " was knocked out." << std::endl;
		std::cout << creature2->getName() << " is the winner." << std::endl;
	}
	else
	{
		std::cout << creature2->getName() << " was knocked out." << std::endl;
		std::cout << creature1->getName() << " is the winner." << std::endl;
	}
}

/*****************************************************************************************
** Description: User pick creature for fighting. Returns user choice as an integer
********************************************************************************************/
int Combat::pick()
{
	//For the name of all the creatures
	std::string creatureNames[NUMCREATURES];
	for (int i = 0; i < NUMCREATURES; i++)
	{
		creatureNames[i] = creatures[i]->getName();
	}
	std::string question = "What creature you wish to fight?";
	Menu creaturesMenu(question, creatureNames, NUMCREATURES);

	return creaturesMenu.makeChoice();
}

/*****************************************************************************************
** Description: Sets creature to be used in battle. Parameter is pointer to creature by reference
********************************************************************************************/
void Combat::setCreature(Creature*& creatIn)
{
	//Gets user choice
	int pick = this->pick();

	//Set creature as the aviable choices.
	switch (pick)
	{
	case 1:	creatIn = new Vampire();
			break;

	case 2:	creatIn = new Barbarian();
			break;

	case 3:	creatIn = new BlueMen();
			break;

	case 4:	creatIn = new Medusa();
			break;
	
	//If user choices 5.
	default:creatIn = new HP();
			break;
	}
}

void Combat::setCreature(Creature*& creatIn, int pick)
{
	//Set creature as the aviable choices.
	switch (pick)
	{
	case 1:	creatIn = new Vampire();
		break;

	case 2:	creatIn = new Barbarian();
		break;

	case 3:	creatIn = new BlueMen();
		break;

	case 4:	creatIn = new Medusa();
		break;

		//If user choices 5.
	default:creatIn = new HP();
		break;
	}
}
