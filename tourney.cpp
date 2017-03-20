#include "tourney.hpp"

/*****************************************************************************************
** Description: Default constructor. Seeds random generator. Asks for how many fighters on the team.
** And then sets the fighters of the teams followed by starting the fightinh. 
*******************************************************************************************
Tourney::Tourney()
{

	//sets head and tail node of loser list to null
	head = nullptr;

	//Create random seed for a random integer
	unsigned seed = std::time(0);

	//Seeds the random generator
	std::srand(seed);

	//Ask and gets the number of fighters in the teams.
	std::cout << "How many fighters do you for each team?" << std::endl;
	int numTeam = inputIntLowerLimit(1);
	
	//Sets the number of fighters and team name.
	teamA.setName("Team A");
	teamA.setTotalFighters(numTeam);

	teamB.setName("Team B");
	teamB.setTotalFighters(numTeam);

	//Ask for the fighters for team A
	std::cout << "Set the fighters for " << teamA.getName() << std::endl;
	teamA.setTeam();
	std::cout << "------------------------------------------------------------------------" << std::endl;

	//Ask for the fighters for team B
	std::cout << "Set the fighters for " << teamB.getName() << std::endl;
	teamB.setTeam();

	//Start Fight
	fight();
}

Tourney::Tourney(Team* player, Team* comp)
{

	teamA = player;
	teamB = comp;

	//Start Fight
	fight();
}*/


Tourney::~Tourney()
{
	LoserList* nodePtr = head;
	while (nodePtr != nullptr)
	{
		LoserList *trash = nodePtr;

		nodePtr = nodePtr->next;

		delete trash;
	}
}

/*****************************************************************************************
** Description: Loops the team battling until someone won
********************************************************************************************/
void Tourney::fight(Team* player, Team* comp)
{
	std::cin.ignore();
	round = 1;
	//Loops until a team is without fighters
	do {
		battle(teamA.headCreat(), teamB.headCreat());
		
		//Pauses between rounds
		std::cout << "Press enter to continue" << std::endl;
		std::cin.ignore();
		std::cin.clear();
		
		//Add to round
		round++;
	} while (!(teamA.getLost() || teamB.getLost()));

	//Display winner
	displayWinner();

	std::cout << std::endl;

	//Display all the fighters who lost
	displayLoserList();
}

/*****************************************************************************************
** Description: Loops the team battling until someone won
********************************************************************************************/
void Tourney::fight()
{
	std::cin.ignore();
	round = 1;
	//Loops until a team is without fighters
	do {
		battle(teamA.headCreat(), teamB.headCreat());

		//Display Score
		displayScore();

		//Pauses between rounds
		std::cout << "Press enter to continue" << std::endl;
		std::cin.ignore();
		std::cin.clear();

		//Add to round
		round++;
	} while (!(teamA.getLost() || teamB.getLost()));

	//Display winner
	displayWinner();

	std::cout << std::endl;

	//Display all the fighters who lost
	displayLoserList();
}

/*****************************************************************************************
** Description: Battle bewteen characters. The parament is the 2 character sto fight with creature1
** attacking first.
********************************************************************************************/
void Tourney::battle(Creature* creatureA, Creature* creatureB)
{
	//counter to end fight if something goes wrong
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

		//add one to counter
		counter++;
	} while (!(creatureA->death()) && !(creatureB->death()) && counter<1000);

	//checks to see who won and declare winner
	if (creatureA->death())
	{
		//Team A fighter lost
		std::cout << creatureA->getName() << " was knocked out." << std::endl;
		std::cout << creatureB->getName() << " is the winner." << std::endl;

		//Add to loser list
		addLoserList(creatureA);

		//Remove current fighter from fight from Team A
		teamA.removeHead();

		//Fighter from team b regain some health.
		creatureB->heathReg();
	}
	else
	{
		//Team B fighter lost
		std::cout << creatureB->getName() << " was knocked out." << std::endl;
		std::cout << creatureA->getName() << " is the winner." << std::endl;

		//Add to loser list
		addLoserList(creatureB);

		//Remove current fighter from fight from Team B
		teamB.removeHead();

		//Fighter from team A regain some health.
		creatureA->heathReg();
	}
}

/*****************************************************************************************
** Description: Display winner of the touney
********************************************************************************************/
void Tourney::displayWinner()
{
	//Display score
	displayScore();

	//Declare the winner
	std::cout << "Winner of the tourney is ..." << std::endl;
	
	//Declare team B the winner
	if (teamA.getLost())
	{
		teamB.displayTeam();
	}

	//Declare team A the winner
	else
	{
		teamA.displayTeam();
	}
}

void Tourney::displayScore()
{
	//Display what round it is
	std::cout << std::endl << "   Round " << getRound() << std::endl;

	//Spacing for the score
	std::string player1Space = "  ", player2Space = "\t   ";

	//Display score of the match
	std::cout << teamA.getName() <<"\t" << teamB.getName() << std::endl;
	std::cout << player1Space << teamA.getRemFighters() << player2Space << teamB.getRemFighters() << std::endl;
}

int Tourney::getRound()
{
	return round;
}

//
void Tourney::addLoserList(Creature * creatIn)
{
	
	//If loser list is empty
	if (head == nullptr)
	{
		//head is now a new loser
		head = new LoserList(creatIn);

		//next node is set to null
		head->next = nullptr;
	}
	else
	//Adds newly losing character to top of the loser list
	{
	
		LoserList* nPtr = head;

		//head is now a new loser
		head = new LoserList(creatIn);

		//previous head is now the next for the new head node
		head->next = nPtr;
	}

	//Set round the loser lost
	head->roundLost = round;
}

void Tourney::displayLoserList()
{

	std::cout << "Loser List" << std::endl;
	if (head)
	{
		//If not empty
		LoserList *nPtr = head;
		//Display the values of list
		while (nPtr)
		{
			std::cout << nPtr->fighter->getName() << " lost in round " << std::to_string(nPtr->roundLost) << std::endl;;
			nPtr = nPtr->next;
		}
	}
	//If empty tell user
	else
	{
		std::cout << "There were no losers today." << std::endl;
	}
}

