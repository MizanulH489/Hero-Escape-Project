#include "Item.h"
#include "Character.h"

// Check if item is hp or not
bool Item::isHP() const
{
	if (type == 0) {

		return true;
	}
	else {

		return false;
	}

}
// Check if item is defense or not
bool Item::isDefense() const
{
	if (type == 1) {

		return true;

	}
	else {

		return false;
	}

}
// Return item value
int Item::getValue() const
{
	return value;
}
// Item constructor, set type and value
Item::Item(int type, int value)
{

	this->type = 0;
	this->value = 0;
}


