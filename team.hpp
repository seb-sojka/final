/*****************************************************************************************
** Program Name: Tourney
** Author: Sebastian Sojka
** Date: 3/6/2017
** Description: The team to fight in the tourney. User can set name of team and the the fighters in 
** team.
********************************************************************************************/
#ifndef SOJKAS_TEAM_HPP
#define SOJKAS_TEAM_HPP
#include "barbarian.hpp"
#include "dracula.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "rouge.hpp"
#include "cleric.hpp"
#include "hp.hpp"
#include "menu.hpp"

class Team
{
private:
	std::string name;
	int totalNumCreat;
	int remNumFighters;
	bool lost = false;

	//Creature** creaturesChoices;
	
	struct CreatNode
	{
		Creature* creature;
		CreatNode *next;//next pointer
		CreatNode(Creature* creatIn)//all new nodes are added to the end
		{
			creature = creatIn;//set value
			next = nullptr;
		};
	};
	CreatNode* head;//head pointer
	CreatNode* tail;//tail pointer

	

public:
	Team();
	Team(std::string);

	void emptyTeam();

	~Team();


	void setName(std::string);
	void setTotalFighters(int);

	std::string getName();
	int getTotalFighters();
	int getRemFighters();

	bool getLost();
	void setLost(bool);

	//int pick();
	//void addCreat();

	void addCreat(Creature*);

	void checkName();
	
	//void setTeam();

	void displayTeam();

	Creature* headCreat();

	void removeHead();

	void fullRestore();
};
#endif