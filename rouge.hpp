/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Rouge for battle. Lower health with chance to counter attack.
** Attack: 2d6
** Defence: 2d6
** Armor: 0
** Strength points: 15
** Special Ability: 10% to go to counter. When creature attacks the rouge, 10% chance to avoid
** damage and counter attack.
*********************************************************************************************/
#ifndef SOJKAS_ROUGE_HPP
#define SOJKAS_ROUGE_HPP
#include "creature.hpp"

class Rouge :public Creature
{
public:
	Rouge();

};

#endif