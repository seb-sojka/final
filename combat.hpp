#ifndef SOJKAS_COMBAT_HPP
#define SOJKAS_COMBAT_HPP
#include "barbarian.hpp"
#include "dracula.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "hp.hpp"
#include "menu.hpp"

const int NUMCREATURES = 5;

class Combat
{
private:
	Creature** creatures;
public:
	Combat();
	~Combat();
	//void attack(Creature*, Creature*);
	void battle(Creature*, Creature*);
	int pick();
	void setCreature(Creature*&);
	void setCreature(Creature *&, int);
	void startMenu();
	void startBattle();
	void display();
	void test();
};

#endif