/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Stag Lord is a barbarian always enraged for battle.High health with chance to go in rage.
** Attack: 2d6
** Defence: 2d6
** Armor: 1
** Strength points: 20
** Special Ability: 10% to go into rage. When in rage, deals extra die of damage when attacking.
** Exits rage after combat.
*********************************************************************************************/
#ifndef SOJKAS_STAG_HPP
#define SOJKAS_STAG_HPP
#include "barbarian.hpp"

class StagLord :public Barbarian
{
public:
	StagLord();


};

#endif
