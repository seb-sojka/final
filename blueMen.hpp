/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Blue men for battle. A mob of small creatures whose defence decreases as strength points decrease
** Attack: 2d6
** Defence: 2d6
** Armor: 0
** Strength points: 12
*********************************************************************************************/
#ifndef SOJKAS_BLUEMEN_HPP
#define SOJKAS_BLUEMEN_HPP
#include "creature.hpp"
#include <math.h>

class BlueMen :public Creature
{
public:
	BlueMen();
	int defence();
	void display();
};

#endif