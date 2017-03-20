/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: The boy who lived (aka Harry Porter) for battle. Good attack and defence and can revive after the first fall
** Attack: 2d6
** Defence: 2d6
** Armor: 0
** Strength points: 10
** Hogwart:If Harry dies (i.e. strength <=0), he immediately recovers and his total strength becomes 20. If he were
** to die again, then he’s dead
*********************************************************************************************/
#ifndef SOJKAS_HP_HPP
#define SOJKASHP_HPP
#include "creature.hpp"


class HP :public Creature
{
private: 
	bool reviveAvail;//Checks to see if revive is avialable
public:
	HP();
	bool death();
	void revive();
	void setReviveAvail(bool);
	bool getReviveAvail();
	void display();


};

#endif