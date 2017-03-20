/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Medusa for battle. low defense and health but can kill any creature in single attack.
** Attack: 2d6
** Defence: 1d6
** Armor: 3
** Strength points: 8
** Glare: If medusa rolls a 12 on attack rool, the oppenenent looks into her eyes and turn to stone.
*********************************************************************************************/
#ifndef SOJKAS_MEDUSA_HPP
#define SOJKAS_MEDUSA_HPP
#include "creature.hpp"

class Medusa :public Creature
{
public:
	Medusa();
	void attack(Creature * defending);
	void display();
};

#endif