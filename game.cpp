#include "game.hpp"

Game::Game()
{
	actionCount = 0;
	moveCount = 0;
	
	inventory.push_back(new ItemMap());
	playerTeam.setName("Player");
	comTeam.setName("Computer");
	setPlayerTeam();

	gMap.initializeBoard();

	gMap.displayMap();
	
	do
	{
		playerAction();
		gMap.moveLie();
		gMap.askMovePlayer();
		days++;
	} while (days <= 30);
}

void Game::setPlayerTeam()
{
	playerTeam.addCreat(new Barbarian());
	playerTeam.addCreat(new Cleric());
	playerTeam.addCreat(new Rouge());
}

void Game::setCompTeam(std::string stringIn)
{
	emptyComp();
	if (stringIn == "Lie")
	{
		comTeam.addCreat(new Barbarian());
	}
	else
	{
		comTeam.addCreat(new Cleric());
	}
}



void Game::emptyComp()
{
	comTeam.emptyTeam();
}

void Game::playerAction()
{
	if (gMap.isPLayerSpaceExplored() && gMap.liePLayerSameSpace())
	{
		lieEncounter();
	}
	else
	{
		std::string choices[] = { "Explore land", "Look at invertory", "Travel Though"};
		Menu enterLand("What do you care to do?", choices, 3);

		int userChoice = 0;
		do
		{
			userChoice = enterLand.makeChoice();

			if (userChoice == 1)
			{
				actionCount++;
				if (!gMap.isPLayerSpaceExplored())
				{
					if (this->encounterRoll())
					{
						std::cout << "Area still unexplored becuase of retreating" << std::endl;
					}
					else
					{
						gMap.playExpl();
					}
				}
				else
				{
					std::cout << "Square is already explored." << std::endl;
				}
			}
			else if (userChoice == 2)
			{
				lookInv();
			}
		} while (userChoice < 3);
		moveCount++;
		gMap.displayMap();
	}
}

bool Game::encounterRoll()
{
	bool retreat = false;
	if (gMap.liePLayerSameSpace())
	{

		lieEncounter();
		{
			if (randomInt(1, 1) < 50)
			{
				retreat = false;
			}
			else
			{
				retreat = fight();
			}
		}
	}
	return retreat;
}



/*****************************************************************************************
** Description: Loops the team battling until someone won
********************************************************************************************/
bool Game::fight()
{
	std::cin.ignore();
	int round = 1;
	//Loops until a team is without fighters
	std::string choices[] = { "Continue fight", "Retreat" };
	Menu retreatMenu("Do you wish to continue fight or retreat?", choices, 2);
	bool retreat;
	do {
		retreat = battle(playerTeam.headCreat(), comTeam.headCreat());

		//Pauses between rounds
		if (retreat == false)
		{
			retreat = retreatMenu.makeChoice() - 1;
		}


		//Add to round
		round++;
	} while (!(playerTeam.getLost() || comTeam.getLost())&& !retreat);

	//Display winner
	//displayWinner();
	//emptyComTeam();

	std::cout << std::endl;

	return retreat;

	//Display all the fighters who lost
	//displayLoserList();
}

/*****************************************************************************************
** Description: Battle bewteen characters. The parament is the 2 character sto fight with creature1
** attacking first.
********************************************************************************************/
bool Game::battle(Creature* creatureA, Creature* creatureB)
{
	bool returnBool = false;
	std::string choices[] = { "Continue fight", "Retreat" };
	Menu retreatMenu("Do you wish to continue fight or retreat?", choices, 2);

	int counter = 0;
	//Characters attack each in loop until one is dead or round limit.
	do {
		//First attack
		creatureA->attack(creatureB);

		//Checks to see if prevoius attack killed creature
		if (!(creatureB->death()))
		{
			//creature is not dead, 2nd creature attacks
			creatureB->attack(creatureA);
		}

		
	} while ((!(creatureA->death()) && !(creatureB->death()) && counter<1000)&& retreatMenu.makeChoice() != 2);


	//checks to see who won and declare winner
	if (creatureA->death())
	{
		//Team A fighter lost
		std::cout << creatureA->getName() << " was killed." << std::endl;

		//Add to loser list
		//addLoserList(creatureA);

		//Remove current fighter from fight from Team A
		playerTeam.removeHead();

		//Fighter from team b regain some health.
		creatureB->heathReg();
	}
	else if (creatureB->death())
	{
		//Team B fighter lost
		std::cout << creatureB->getName() << " was killed." << std::endl;

		//Add to loser list
		//addLoserList(creatureB);

		//Remove current fighter from fight from Team B
		comTeam.removeHead();

		//Fighter from team A regain some health.
		creatureA->heathReg();
	}
	else
	{
		std::cout << "You successful retreated." << std::endl;
		returnBool = true;
	}

	return returnBool;
}

void Game::lieEncounter()
{
	setCompTeam("Lie");
	bool retreat = fight();
	if (!retreat)
	{
		gMap.lieDead();
		inventory.push_back(new Key());
	}
}

void Game::lookInv()
{
	std::vector <std::string> items;

	for (int i = 0; i < inventory.size(); i++)
	{
		items.push_back(inventory.at(i)->getName());
	}
	items.push_back("Exit");

	Menu invMenu("What item do you which to look at?", items);

	int userChoice;

	do {

		userChoice = invMenu.makeChoice() - 1;


		{
			if (inventory.at(userChoice)->getName() == "Map")
			{
				gMap.displayMap();
			}
			else
			{
				inventory.at(userChoice)->lookItem();
			}
		}
	} while (userChoice != inventory.size());
	
}
