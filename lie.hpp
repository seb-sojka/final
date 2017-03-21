#pragma once
/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: lieutenant for battle. Similar to rouge but will less attack. Does 
** attack twice a turn
** Attack: 2d4
** Defence: 2d6
** Armor: 0
** Strength points: 15

*********************************************************************************************/
#ifndef SOJKAS_LIE_HPP
#define SOJKAS_LIE_HPP
#include "creature.hpp"

class Lie :public Creature
{
public:
	Lie();
};
#endif