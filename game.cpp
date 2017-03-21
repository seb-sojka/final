/*****************************************************************************************
** Program Name: Game
** Author: Sebastian Sojka
** Date:3/22/2017
** Description: The base game with spaces and team for computer and player. The end goal is killer the Stag 
** lLOrd. You can explore an are an day. The spaces can be the trading post where you can restore helth to 
** full, forest, mountians, plains, and swamp to explore. When you explore a area, you may encounter bandits
** or wild animals. You may explore an square a day. You have 30 days to defeat the Stag Lord.
** This is based on Pathfinder adventure path, Kingmaker, and the first book, Stoel nLand.
*********************************************************************************************/
#include "game.hpp"

/****************************************************************************************
** Description: Starts the game. Sets team names and add map to invertory for the player.
** Sets up the map and then allows the player to choose an action to either explore area, look an invertory,
** or travel to new land. 
*********************************************************************************************/
Game::Game()
{
	//Intro
	this->intro();
	//Adds map to inventory	
	inventory.push_back(new ItemMap());

	//Sets team name as "Player" (for player) and "Computer" (for computer)
	playerTeam.setName("Player");
	comTeam.setName("Computer");
	
	//Sets up payer team
	setPlayerTeam();

	//Builds mao
	gMap.initializeBoard();
	
	//Display map
	gMap.displayMap();

	//Ask player for action
	playerAction();

	playerAlive = true;

	days = 0;
	
	//Look until either all players characters are killer or 30 days or defeated the stag lord
	std::cout << "Enter into do loop" << std::endl;
	do
	{
		//Moves lieuanat
		gMap.moveLie();


		//Ask player for action
		playerAction();

	} while (days <= 30 && !playerTeam.getLost()&&!won);
	std::cout << "Got out of day loop" << std::endl;
	endGame();

}

Game::~Game()
{
	std::cout << "End loop" << std::endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		Item* trash = inventory.at(i);
		delete trash;
	}
	std::cout << "End loop" << std::endl;
}

/****************************************************************************************
** Description: Set player team to Barbarian, Cleric, and a rouge with each special abilities.
*********************************************************************************************/
void Game::setPlayerTeam()
{
	playerTeam.addCreat(new Barbarian());
	playerTeam.addCreat(new Cleric());
	playerTeam.addCreat(new Rouge());
}

/****************************************************************************************
** Description: Set computer team based on parameter of string. The paramter of the function is string
** to identify what player will fight.
*********************************************************************************************/
void Game::setCompTeam(std::string stringIn)
{
	//Emtpies computer team for new 
	emptyComp();
	if (stringIn == "Lie")
	{
		comTeam.addCreat(new Bandit());
		comTeam.addCreat(new Bandit());
		comTeam.addCreat(new Lie());
	}
	else
	{
		comTeam.addCreat(new Barbarian());
	}
}


/****************************************************************************************
** Description: Empties computer team
*********************************************************************************************/
void Game::emptyComp()
{
	comTeam.emptyTeam();
}

/****************************************************************************************
** Description: Asks for player action.
*********************************************************************************************/
void Game::playerAction()
{
	//if lieutenant and player are onthe same explored space, then they fight 
	if (gMap.isPLayerSpaceExplored() && gMap.liePLayerSameSpace())
	{
		lieEncounter();
	} 
	else if (gMap.isPLayerSpaceExplored() && gMap.fortPLayerSameSpace())
	{
		fortEncounter();
	}
	if(!won)
	{

			//creates menu asking what player wishes to do, explore land,
			std::string choices[] = { "Explore land", "Look at invertory", "Move " };
			Menu enterLand("What do you care to do?", choices, 3);

			int userChoice = 0;
			do
			{
				if (gMap.tradingPLayerSameSpace())
				{
					userChoice = this->tradingPostMenu();
				}
				else
				{
					//Ask user what they wish to do
					userChoice = enterLand.makeChoice();

					if (userChoice == 1)
					{
						if (!gMap.isPLayerSpaceExplored())
						{
							if (this->encounterRoll())
							{
								std::cout << "Area still unexplored becuase of retreating" << std::endl;
							}
							else
							{
								gMap.playExpl();
								days++;
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
				}
			} while (userChoice < 3);

			gMap.displayMap();
			//Ask player where they want to move
			gMap.askMovePlayer();
			
		}
	std::cout << "exiting player exit" << std::endl;
}


bool Game::encounterRoll()
{
	bool retreat = false;
	if (gMap.liePLayerSameSpace())
	{
		lieEncounter();
	}
	else if(gMap.fortPLayerSameSpace())
	{
		fortEncounter();
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
	

	//Menu to allow user to retreat from battle
	std::string choices[] = { "Continue fight", "Retreat" };
	Menu retreatMenu("Do you wish to continue fight or retreat?", choices, 2);
	bool retreat;

	//Loops until a team is without fighters
	do {

		//Asks if user wishes to retreat from battle
		retreat = retreatMenu.makeChoice() - 1;
		if (!retreat)
		{
			retreat = battle(playerTeam.headCreat(), comTeam.headCreat());
		}

		//Add to round
		round++;
	} while (!(playerTeam.getLost() || comTeam.getLost())&& !retreat);

 
	playerTeam.resetRage();
	std::cout << std::endl;
	//returns true if player retreated
	return retreat;

}

/*****************************************************************************************
** Description: Battle bewteen characters. The parament is the 2 character sto fight with creature1
** attacking first.
********************************************************************************************/
bool Game::battle(Creature* creatureA, Creature* creatureB)
{
	bool returnBool = false;

	
	//Asks about retreating after each attack
	std::string choices[] = { "Continue fight", "Retreat" };
	Menu retreatMenu("Do you wish to continue fight or retreat?", choices, 2);
	int counter = 0;
	//Characters attack each in loop until one is dead or round limit.
	do {
		displaySP(creatureA, creatureB);
		//First attack
		creatureA->attack(creatureB);

		//Checks to see if prevoius attack killed creature
		if (!(creatureB->death()))
		{
			//creature is not dead, 2nd creature attacks
			creatureB->attack(creatureA);
		}
		counter++;
		//Asks about retreating after each attack or when on the creatures die		
	} while ((!(creatureA->death()) && !(creatureB->death()) && counter<1000)&& retreatMenu.makeChoice() != 2);


	//checks to see who won and declare winner
	if (creatureA->death())
	{
		//Team A fighter lost
		std::cout << creatureA->getName() << " was knocked out." << std::endl;

		//Add to loser list
		//addLoserList(creatureA);

		//Remove current fighter from fight from Team A
		playerTeam.removeHead();

	}
	else if (creatureB->death())
	{
		//Team B fighter lost
		std::cout << creatureB->getName() << " was killed." << std::endl;


		//Remove current fighter from fight from Team B
		comTeam.removeHead();


	}
	//if you retreat
	else
	{
		//tells player they retreated successful and set retreat bool to true
		std::cout << "You successful retreated." << std::endl;
		returnBool = true;
	}

	return returnBool;
}

/*****************************************************************************************
** Description: Sets up encounter for the lieaunut.
********************************************************************************************/
void Game::lieEncounter()
{
	std::cout << "As you explore the area, you find yourself in front of a well-armed some bandits and well-armed female with that looks the lieutenant of Stag Lord" << std::endl;
	std::cout << "\"You must be \'new\' adventurers that is looking for our bounty\", she says as she draws her two swords" << std::endl;
	std::cout << "\"YOU WILL DEAD LIKE THE REST\", she screams as they attack you." << std::endl;
	//Sets up lieaunut team
	setCompTeam("Lie");

	//starts fight
	bool retreat = fight();

	//if you defeat the lieaunut 
	//you get the key to the fort
	if (!retreat&&playerAlive)
	{

		gMap.showFort();

		//Sets lieaunut to die
		gMap.lieDead();

		//adds keyto invertory.
		inventory.push_back(new Key());

		hasKey = true;
	}
}

/*****************************************************************************************
** Description: Allows player to look at thier invertory
********************************************************************************************/
void Game::lookInv()
{
	//Name of all the items
	std::vector <std::string> items;


	//Adds item name to vector of string
	for (int i = 0; i < inventory.size(); i++)
	{
		items.push_back(inventory.at(i)->getName());
	}

	//Adds exit as an option 
	items.push_back("Exit");

	Menu invMenu("What item do you which to look at?", items);

	int userChoice;

	//will loop until user exits
	do {

		//User makes choice at item to look at
		userChoice = invMenu.makeChoice() - 1;

		{
			if (userChoice != inventory.size())
			{
				//If user chooses map
				if (inventory.at(userChoice)->getName() == "Map")
				{

					//Show player map
					gMap.displayMap();
				}
				else
					//Users get short discription of map
				{
					inventory.at(userChoice)->lookItem();
				}
			}
		}
	//exits if user selct exit
	} while (userChoice != inventory.size());
	
}

/*****************************************************************************************
** Description: Sets up encounter for the Stag Lord.
********************************************************************************************/
void Game::fortEncounter()
{
	
	if (hasKey)
	{
		std::cout << "You unlock the door and open door to the fort." << std::endl;
		std::cout << "As you enter the fort, you hear a roar bellow out from inside." << std::endl;
		std::cout << "A humanoid creature charges at the group. At least a head taller than all, he has the body of man but the head of stag." << std::endl;
		std::cout << "Carrying a club as big as most deer, he readies to fight you all." << std::endl;
		setCompTeam("Fort");
		bool retreat = fight();
		if (!retreat&&playerAlive)
		{
			std::cout << "Killed Stag lord" << std::endl;
			won = true;
			gMap.setFortLoc(nullptr);
		}
	}
	else
	{
		std::cout << "You realize a key will be needed to open the door and assault the fort" << std::endl;
	}
	std::cout << "Exited fort encounter" << std::endl;
}


/*****************************************************************************************
** Description: When player is at the trading post
********************************************************************************************/
int Game::tradingPostMenu()
{
	//creates menu asking what player wishes to do,rest or move,
	std::string choices[] = { "Rest", "Look at invertory", "Move" };
	Menu trading("What do you care to do?", choices, 3);
	int userChoice = 0;
	userChoice = trading.makeChoice();
	//if player decides to rest, it takes a day 
	if (userChoice == 1)
	{
		rest();
		days++;
	}
		//Look at inverory
	if (userChoice == 2)
	{
		lookInv();
	}

	return userChoice;
}


/*****************************************************************************************
** Description: Full restore players to full health.
********************************************************************************************/
void Game::rest()
{
	playerTeam.fullRestore();
}

void Game::addItem(Item * itemIn)
{
	if (inventoryCheck())
	{
		inventory.push_back(itemIn);
	}
	else
	{
		std::cout << "Your invertory is full. Please select item to remove" << std::endl;
		this->removeItem();
		addItem(itemIn);
	}
	return;
}

void Game::removeItem()
{
	//Name of all the items
	std::vector <std::string> items;


	//Adds item name to vector of string
	for (int i = 0; i < inventory.size(); i++)
	{
		items.push_back(inventory.at(i)->getName());
	}

	//Adds exit as an option 
	items.push_back("Exit");

	Menu rmMenu("What item do you wish to removet?", items);
}

bool Game::inventoryCheck()
{
	if (inventory.size() >= ITEMLIMIT)
	{
		return false;
	}
	return true;
}

void Game::intro()
{
	std::cout << "\"By the power invested by the Lords of Lance Coast, you are given the right to hunt Stag Lord and his bandits within the lost lands for thirty days." << std::endl
		<< "Bring back the body of Stag lord for identification and your reward, \" said the note." << std::endl
		<< "You have done this various times. Bring rouges and thugs to justice for a small sum of coins." << std::endl
		<< " But this would be the big one. The Stag bandits and their leader only known as the Stag Lord, have been harassing the nearby towns and cities for some time now"
		<< " but when the hit a local winery the outcry finally came for the lords instead of the peasants. You now have 30 days to find and kill the Stag Lord to get your reward." << std::endl;
	setPlayerTeam();
}

void Game::displaySP(Creature * creatureA, Creature * creatureB)
{
	std::cout << creatureA->getName() << ": " << creatureA->getStrPoints() << "SP\t" << creatureB->getName() << ": " << creatureB->getStrPoints() << "SP" << std::endl;
}

void Game::endGame()
{
	if (won)
	{
		std::cout << "You win" << std::endl;
	}
	else if (days >= 30)
	{
		std::cout << "Lost from time" << std::endl;
	}
	else
	{
		std::cout << "Lost from death" << std::endl;
	}
}

