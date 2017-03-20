/*****************************************************************************************
** Program Name: Langston's Ant
** Author: Sebastian Sojka
** Date: 1/23/2017
** Description: Creates the individual spaces for the simulation of Langton’s Ant. Allows the 
** space to change color, have the ant display symbol on it, and the display symbol for white, black
** and the ant.
********************************************************************************************/
#ifndef SOJKAS_GAME_HPP
#define SOJKAS_GAME_HPP
#include <string>

#include "board.hpp"
#include "team.hpp"
#include "item.hpp"
#include "map.hpp"

const int ITEMLIMIT = 10;

class Game
{
private:
	Team playerTeam;
	Team comTeam;
	Map gMap;
	int days;
	std::vector<Item*> inventory;
	bool playerAlive = true;
	bool hasKey = false;
	bool won = false;
public:
	Game();
	void setPlayerTeam();
	void setCompTeam(std::string);
	void emptyComp();;
	void playerAction();
	bool encounterRoll();
	bool fight();
	bool battle(Creature * creatureA, Creature * creatureB);
	void lieEncounter();
	void lookInv();
	void fortEncounter();
	void tradingPostMenu();
	void rest();
};


#endif
