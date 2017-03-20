/*****************************************************************************************
** Program Name: Combat
** Author: Sebastian Sojka
** Date: 2/20/2017
** Description: Base ability for a creature in combat. Creature can attack and defend with 
** dice. Creature also has armor to defend against attacks. Strength points are used to see if
** creature is still up. Once it hits zero than creature loses. Creaute also has a name.
********************************************************************************************/
#include "creature.hpp"

/*****************************************************************
** Description: Destructor. Delete the attack and defence dice to avoid leaks
*************************************************************/
Creature::~Creature()
{

	delete[] attackDice;
	attackDice = nullptr;
	
	delete[] defenceDice;
	defenceDice = nullptr;
}


Creature::Creature()
{
}


/*****************************************************************
** Description: Rolls the attack dice for attack and returns the results
*************************************************************/
int Creature::attackRoll()
{
	//sum to be reutrn. starts at zero
	int sum = 0;

	//Rolls all the attack dice 
	for (int i = 0; i < this->getNumADice(); i++)
	{
		//Roll an attack die and adds to the sum
		sum += this->attackDice[i].rollDie();
	}

	//reutrns sum
	return sum;
}


/*****************************************************************
** Description: Rolls the defence dice for defence and then adds 
** the creature armor. returns the results
*************************************************************/
int Creature::defence()
{
	//sum to be returned. starts at zero
	int sum = 0;

	//Rolls all the defence dice
	for (int i = 0; i < getNumDDice(); i++)
	{
		//rolls an attack die and adds to the returning sum
		sum += defenceDice[i].rollDie();
	}

	//adds armor
	sum += getArmor();

	//returns sum for defence
	return sum;
}


void Creature::setADice(int numIn, Die dieIn)
{
	this->attackDice = new Die[numIn];

	for (int i = 0; i < numIn; i++)
	{
		this->attackDice[i] = dieIn;
	}
}

void Creature::setDDice(int numIn, Die dieIn)
{
	this->defenceDice = new Die[numIn];

	for (int i = 0; i < numIn; i++)
	{
		this->defenceDice[i] = dieIn;
	}
}

int Creature::getNumADice()
{
	return numADice;
}

int Creature::getNumDDice()
{
	return numDDice;
}

int Creature::getArmor()
{
	return armor;
}

int Creature::getStrPoints()
{
	return strPoints;
}

std::string Creature::getName()
{
	return name;
}

void Creature::damage(int damageIn)
{
	strPoints -= damageIn;
}

/*****************************************************************
** Description:Checks to see to the creature has died or knocked out
*************************************************************/
bool Creature::death()
{
	//sets return bool as false
	bool returnBool = false;
	
	//checks to see if strength points to less than or equal to 0
	if (this->getStrPoints() <= 0)
	{
		//if strength points is less than or equal to 0 death is set as true
		returnBool = true;
	}

	//return results
	return returnBool;
}

void Creature::setNumADice(int dieIn)
{
	numADice = dieIn;
}

void Creature::setNumDDice(int dieIn)
{
	numDDice = dieIn;
}

void Creature::setArmor(int armorIn)
{
	armor = armorIn;
}

void Creature::setStrPoints(int strIn)
{
	strPoints = strIn;
}

void Creature::setName(std::string nameIn)
{
	name = nameIn;
}
/*****************************************************************
** Description: Character can regain health. Roll of 6-sided die
** Characters can be overhealed.
*************************************************************/
void Creature::heathReg()
{
	Die regen(6);
	setStrPoints(this->strPoints + regen.rollDie());
}

/*****************************************************************
** Description: Display stats and special abilities of creature if appicalable
*************************************************************/
void Creature::display()
{
	baseDisplay();
}

/*****************************************************************
** Description: Create attacks defending creature
*************************************************************/
void Creature::attack(Creature* defending)
{
	//Defending creature rolls for defence
	int damage = -defending->defence();
	
	//Checks to see if vampire stopped attack
	if (damage > -1000)
	{

		//Attacking creauture attacks
		damage += this->attackRoll();
	}

	//make sure attacking damage is 0 or greater. Sets to 0 if negative (defence > attack)
	damage = std::max(damage, 0);

	//deals damage to defending creature
	defending->damage(damage);

	//displays what creature took damage and from whom and how much
	std::cout << defending->getName() << " took " << damage << " from " << this->getName() << '.' << std::endl;
}


/*****************************************************************
** Description: Display the base stats of a creature
*************************************************************/
void Creature::baseDisplay()
{
	//Limits the length of name to be displayed to user to 23 characters
	std::string displayName = this->getName();
	displayName.resize(23, ' ');

	//adds name to be displayed 
	std::string display = displayName + ' ';

	//display the number of attack dice and what they are
	display += std::to_string(this->getNumADice()) + 'd' + std::to_string(this->attackDice->getSides()) + "\t";

	//display the number of defence dice and what they are
	display += std::to_string(this->getNumDDice()) + 'd' + std::to_string(this->defenceDice->getSides()) + "\t";
	
	//display armor of creature
	display += std::to_string(this->getArmor()) + "\t";
	
	//display strength points of creature
	display += std::to_string(this->getStrPoints());

	//display the creature stats
	std::cout << display;
}

void Creature::restore()
{
	setStrPoints(maxHealth);
}

/*bool operator==(Creature* a, Creature* b)
{
	return a->getName() == b->getName();
}*/
