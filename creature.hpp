/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Base ability for a creature in combat. Creature can attack and defend with
** dice. Creature also has armor to defend against attacks. Strength points are used to see if
** creature is still up. Once it hits zero than creature loses. Creaute also has a name.
********************************************************************************************/
#ifndef SOJKAS_CREATURE_HPP
#define SOJKAS_CREATURE_HPP
#include "die.hpp"
#include <algorithm>

class Creature
{
protected:
	Die* attackDice;//Attack dice
	int numADice;//Number of attakc dice
	Die* defenceDice;//Defence dice
	int numDDice;//Number of defence dice
	std::string name;//Name
	int armor;//Armor of creature
	int strPoints;//Strength points
	int maxHealth;
public:
	Creature();
	int attackRoll();
	virtual int defence();

	void setADice(int, Die);
	void setDDice(int, Die);

	int getNumADice();
	int getNumDDice();
	int getArmor();
	int getStrPoints();
	std::string getName();

	void damage(int);

	bool death();

	void setNumADice(int);
	void setNumDDice(int);
	void setArmor(int);
	void setStrPoints(int);
	void setName(std::string);

	void heathReg();

	virtual void display();

	virtual void attack(Creature * defending);

	void baseDisplay();

	void restore();
	
	~Creature();

};

#endif