#include "item.hpp"
#include <iostream>
#ifndef SOJKAS_ITEMKEY_HPP
#define SOJKAS_ITEMKEY_HPP

class Key : public Item
{
public:
	Key();
	void lookItem();
};
#endif