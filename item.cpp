#include "item.hpp"

Item::Item()
{
	setName("");
}

std::string Item::getName()
{
	return name;
}

void Item::setName(std::string nameIn)
{
	name = nameIn;
}

