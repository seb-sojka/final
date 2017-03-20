/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Vampire for battle. Low attack and defence but can use chaem to stop attack. 
** Attack: 1d12
** Defence: 1d6
** Armor: 1
** Strength points: 18
** Charm: 50% chance of oppent not attacking
*********************************************************************************************/
#ifndef SOJKAS_DRAC_HPP
#define SOJKAS_DRACE_HPP
#include "creature.hpp"

class Vampire :public Creature
{
public:
	Vampire();
	bool charm();
	int defence();
	void display();
};

#endif
