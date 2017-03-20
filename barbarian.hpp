/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Barbarian for battle.High health with chance to go in rage.
** Attack: 2d6
** Defence: 2d6
** Armor: 1
** Strength points: 20
** Special Ability: 10% to go into rage. When in rage, deals extra die of damage when attacking. 
** Exits rage after combat.
*********************************************************************************************/
#ifndef SOJKAS_BARBARIAN_HPP
#define SOJKAS_BARBARIAN_HPP
#include "creature.hpp"

class Barbarian :public Creature
{
private:
	bool rage;
public:
	Barbarian();
	int attackRoll();
	void damage(int);

	void setRage(bool);
	bool getRage();
	
};

#endif
