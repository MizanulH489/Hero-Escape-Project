#include "Hero.h"
// Return defense power
int Hero::getDefensePower() const
{
	return defensePower;
}
// Decrease defense power
void Hero::decreaseDefensePower()
{
	defensePower--;
}
// Set the defense power
void Hero::setDefensePower(int x)
{
	x = defensePower;
}
// Return the retreat count
int Hero::getRetreatCount() const
{
	return retreatCount;
}
// Decrease the retreat count
void Hero::decreaseRetreatCount()
{
	retreatCount--;
	retreatCount < !0;
}
// Heros items, check if there are any in the 3 slots
bool Hero::anyItems() const
{
	for (int i = 0; i < 3; i++) {

		if (bag[i] == nullptr) {

			return false;

		}
		else {

			return true;

		}
	}
}
// Check if the hero is alive
bool Hero::isAlive() const
{
	if (hp > 0) {

		return true;
	}
	else {

		return false;
	}
}
// Prepare battle
int Hero::operator*(Monster& m)
{
	m.hp = m.hp - attackPower < 0 ? 0 : m.hp - attackPower;
	hp = hp - m.attackPower;
	m.decreaseAttackPower();
	decreaseDefensePower();

	if (hp == 0) //hero died
	{
		return -1;

	}
	else if (m.hp == 0) { //monster died

		return 1;

	}
	else { //no one died

		return 0;

	}

}
// hero constructor, set hp, attack power, defense power, retreat count
Hero::Hero(int hp, int attackPower, int defensePower, int retreatCount)
{

	this->hp = hp;
	this->attackPower = attackPower;
	this->defensePower = defensePower;
	this->retreatCount = retreatCount;

	for (int i = 0; i < 2; i++) {

		this->bag[i] = nullptr;

	}

}
// Set hero HP
void Hero::setHP(int hp) {

	this->hp = hp;
}
// Get hero HP
int Hero::getHP() const {

	return this->hp;
}
// Set hero attack power
void Hero::setAttackPower(int attackPower) {

	this->attackPower = attackPower;
}
// Get hero attack power
int Hero::getAttackPower() const {

	return attackPower;
}












