/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates board for simulation of Langton’s Ant. It includes the ant, the spaces, and board.
** Creates the first emtpy board and places the ant on top of it. Also
********************************************************************************************/

#include "board.hpp"
#include <iostream>


/*****************************************************************
** Description: Creates the intial board with white spaces asking the user for
** the size of the board and method for starting location of the ant 
*****************************************************************/
void Map::initializeBoard()
{
	//Create random seed for a random integer
	unsigned seed = std::time(0);

	//Seeds the random generator
	std::srand(seed);

	setWidth(3);
	setHeight(3);

	do 
	{
		fortVert = randomIntOutSeed(1, getHeight());
		fortHor = randomIntOutSeed(65, 65+getWidth()-1); //ASCII for 'A' to 'F'
	} while (fortVert == 1 && fortHor == 65);

	createBoard();


}

/*****************************************************************
** Description: Creates the board in a string for the similation and places 
** the ant on the board.
*****************************************************************/
void Map::createBoard()
{
	northWest = new SpaceNode(new Trading());
	northWest->north = nullptr;
	northWest->east = nullptr;
	northWest->south = nullptr;
	northWest->west = nullptr;
	northWest->horLoc = 'A';
	northWest->vertLoc = 1;

	for (int j = 0; j < width; j++)
	{
		SpaceNode* nPtr = northWest;


		if (j != 0)
		{
			while (nPtr->east != nullptr)
			{
				nPtr = nPtr->east;
			}
			
			if (fortHor == nPtr->horLoc + 1 && fortVert == nPtr->vertLoc)
			{
				nPtr->east = new SpaceNode(new Fort());
			}
			else
			{
				nPtr->east = new SpaceNode(new Forest());
			}
			nPtr->east->north = nullptr;
			nPtr->east->west = nPtr;
			nPtr->east->east = nullptr;
			nPtr->east->south = nullptr;
			nPtr->east->horLoc = nPtr->horLoc + 1;
			nPtr->east->vertLoc = 1;
			nPtr = nPtr->east;
		}
		for (int i = 1; i < height; i++)
		{
			while (nPtr->south != nullptr)
			{
				nPtr = nPtr->south;
			}
			
			if (fortHor == nPtr->horLoc && fortVert == nPtr->vertLoc + 1)
			{
				nPtr->south = new SpaceNode(new Fort());
				setLieLoc(nPtr->south);
			}
			else
			{
				nPtr->south = new SpaceNode(new Forest());
			}
			nPtr->south->north = nPtr;
			nPtr->south->east = nullptr;
			nPtr->south->west = nullptr;
			nPtr->south->south = nullptr;
			nPtr->south->horLoc = nPtr->horLoc;
			nPtr->south->vertLoc = nPtr->vertLoc + 1;
		}
	}



	SpaceNode* westPtr = northWest;
	SpaceNode* eastPtr = northWest->east;

	while (eastPtr != nullptr)
	{

		while (eastPtr->south != nullptr)
		{
			eastPtr->south->west = westPtr->south;
			westPtr->south->east = eastPtr->south;
			westPtr = westPtr->south;
			eastPtr = eastPtr->south;
		}

		while (eastPtr->north != nullptr)
		{
			westPtr = westPtr->north;
			eastPtr = eastPtr->north;
		}

		eastPtr = eastPtr->east;

		westPtr = westPtr->east;

	}

	setPlayerLoc(northWest);
}



//Sets height of the board
void Map::setHeight(int columns)
{
	height = columns;
}

//Sets width of the board
void Map::setWidth(int rows)
{
	width = rows;
}

//Returns height of the board
int Map::getHeight()
{
	return height;
}

//Returns the width of the board
int Map::getWidth()
{
	return width;
}

char Map::getLieHorLoc()
{
	return playerLocation->horLoc;
}

int Map::getLieVertLoc()
{
	return playerLocation->vertLoc;
}

char Map::getPlayHorLoc()
{
	return playerLocation->horLoc;
}

int Map::getPlayVertLoc()
{
	return playerLocation->vertLoc;
}

void Map::setLieLoc(SpaceNode* nodeIn)
{
	lieLocation = nodeIn;
}

void Map::setPlayerLoc(SpaceNode* nodeIn)
{
	playerLocation = nodeIn;
}

void Map::setFortLoc(SpaceNode * nodeIn)
{
	fortLocation = nodeIn;
}

/*
void Map::setLieHorLoc()
{
	lieHor = lieLocation->horLoc;
}


void Map::setLieVertLoc()
{
	lieVert = lieLocation->vertLoc;
}

void Map::setPlayHorLoc()
{
	playHor = playerLocation->horLoc;
}

void Map::setPlayVertLoc()
{
	playVert = getPlayVertLoc();
}*/

void Map::moveLie()
{
	if (lieAlive)
	{
		SpaceNode* nPtr = lieLocation;


		nPtr->space->setLieu(false);

		SpaceNode* tPtr = nPtr;

		do
		{
			int lieMovement = randomIntOutSeed(1, 5);
			switch (lieMovement)
			{
			case 1:
				tPtr = nPtr->north;
				break;
			case 2:
				tPtr = nPtr->east;
				break;
			case 3:
				tPtr = nPtr->south;
				break;
			case 4:
				tPtr = nPtr->west;
				break;
			case 5:
			default:
				tPtr = nPtr;
				break;
			}
		} while (tPtr == nullptr);

		tPtr->space->setLieu(true);

		setLieLoc(tPtr);
	}
}

void Map::askMovePlayer()
{

	std::vector<std::string> direction;

	if (playerLocation->north != nullptr)
	{
		direction.push_back("North");
	}

	if (playerLocation->south != nullptr)
	{
		direction.push_back("South");
	}

	if (playerLocation->east != nullptr)
	{
		direction.push_back("East");
	}

	if (playerLocation->west != nullptr)
	{
		direction.push_back("West");
	}

	Menu directionQ("What direction do you wish to travel?", direction);

	movePlayer(direction.at(directionQ.makeChoice()-1));
}

void Map::movePlayer(std::string direction)
{
	playerLocation->space->setPlay(false);
	

	if (direction == "North")
	{
		playerLocation = playerLocation->north;
	}
	if (direction == "South")
	{
		playerLocation = playerLocation->south;
	}
	if (direction == "West")
	{
		playerLocation = playerLocation->west;
	}
	if (direction == "East")
	{
		playerLocation = playerLocation->east;
	}
	
	playerLocation->space->setPlay(true);

	playerLocation->space->enter();
}

void Map::displayMap()
{
	
	std::string map = "";
	for (int i = 0; i < width; i++)
	{
		map == "------------- \n";
		SpaceNode* nPtr = northWest;
		for (int j = 0; j < i; j++)
		{
			nPtr = nPtr->south;
		}
		while (nPtr != nullptr)
		{
			map += '|';
			if (nPtr->space->hasPlay())
			{
				map += 'P';
			}

			if (nPtr->space->hasLie())
			{
				map += 'L';
			}

			//if (nPtr->space->isExplored())
			{
				map += nPtr->space->getDisplayChar();
			}
			/*else
			{
				map += ' ';
			}*/
			nPtr = nPtr->east;
		}
		map += "| \n";
	}

	std::cout << map;

}

void Map::playExpl()
{
	playerLocation->space->explore();
}


bool Map::isPLayerSpaceExplored()
{
	return playerLocation->space->isExplored();
}


bool Map::liePLayerSameSpace()
{
	return playerLocation->space->hasLie() == playerLocation->space->hasPlay();
}

void Map::lieDead()
{
	lieAlive = false;
	lieLocation = nullptr;
}
