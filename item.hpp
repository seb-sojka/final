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
#ifndef SOJKAS_ITEM_HPP
#define SOJKAS_ITEM_HPP
#include <string>

class Item
{
protected:
	std::string name;
public:
	Item();
	virtual void lookItem() = 0;
	std::string getName();
	void setName(std::string);
};



class Key : public Item
{
public:
	Key();
	void lookItem();
	std::string useItem();
};

#endif