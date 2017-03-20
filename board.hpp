/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates board for simulation of Langton’s Ant. It includes the ant, the spaces, and board.
** Creates the first emtpy board and places the ant on top of it. Also 
********************************************************************************************/

#ifndef SOJKAS_MAP_HPP
#define SOJKAS_MAP_HPP

#include <string>
#include <vector>
#include "forest.hpp"
#include "fort.hpp"
#include "trading.hpp"
#include "menu.hpp"
#include "random.hpp"

class Map
{

private:
	int width; //Width of the board
	int height; //Height of the board

	struct SpaceNode
	{
		Space* space;
		SpaceNode* north;
		SpaceNode* south;
		SpaceNode* east;
		SpaceNode* west;

		SpaceNode(Space* type)
		{
			space = type;
		}
		char horLoc;
		int vertLoc;

	};

	bool lieAlive = true;

	SpaceNode* northWest;//head pointer

	SpaceNode* playerLocation;

	SpaceNode* fortLocation;

	SpaceNode* lieLocation;

	int fortVert;
	char fortHor;

public:
	void initializeBoard(); //First build of the board
	void createBoard(); //Creates a string of the board

	void setHeight(int columns);
	void setWidth(int rows);

	int getHeight();
	int getWidth();

	char getLieHorLoc();
	int getLieVertLoc();

	char getPlayHorLoc();
	int getPlayVertLoc();

	void setLieLoc(SpaceNode * nodeIn);

	void setPlayerLoc(SpaceNode * nodeIn);

	void setFortLoc(SpaceNode * nodeIn);

	//void setLieHorLoc();
	//void setLieVertLoc();

	//void setPlayHorLoc();
	//void setPlayVertLoc();

	void moveLie();

	void askMovePlayer();
	void movePlayer(std::string);

	void displayMap();

	void playExpl();

	bool isPLayerSpaceExplored();
	bool liePLayerSameSpace();
	bool fortPLayerSameSpace();

	bool tradingPLayerSameSpace();

	void lieDead();
};

#endif
