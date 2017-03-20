/*****************************************************************************************
** Program Name: Tourney
** Author: Sebastian Sojka
** Date: 3/6/2017
** Description: The program pits two teams of fighters, Team A and Team B. User decides how many 
** fighters and the fighters themselves. Display the winner of each round and the current score.
** Also there is a loser linked list for everyone defeated (not circular). 
** Scoring: Each team starts with points equal to the number of fighters on each team. Each 
** time a fighter is knocked out, the time loses a point. When one team is out of fighters, they
** lose and winner is declared. 
********************************************************************************************/
#ifndef SOJKAS_TOURNEY_HPP
#define SOJKAS_TOUNREY_HPP
#include "team.hpp"
#include <iostream>
class Tourney
{
private:
	Team teamA;
	Team teamB;
	int round;
	
	struct LoserList
	{
		Creature* fighter;
		int roundLost;
		LoserList *next;//next pointer
		LoserList(Creature* fighterIn)//all new nodes are added to the begin
		{
			fighter = fighterIn;//set value
		};
	};

	LoserList* head;//head pointer

public:
	Tourney();
	~Tourney();
	void fight(Team * player, Team * comp);
	void fight();
	void battle(Creature*, Creature*);
	void displayWinner();
	void displayScore();
	int getRound();

	void addLoserList(Creature*);
	void displayLoserList();
};

#endif