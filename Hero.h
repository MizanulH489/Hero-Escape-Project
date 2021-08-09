#pragma once
#include "Character.h"
#include "Monster.h"
#include "Item.h"


class Hero : public Character {

private:

	int defensePower;
	int retreatCount;


public:

	Item* bag[3];
	int getDefensePower() const;
	void decreaseDefensePower();
	void setDefensePower(int);
	int getRetreatCount() const;
	void decreaseRetreatCount();
	bool anyItems() const;
	bool isAlive() const;
	int operator*(Monster& m);
	Hero(int, int, int, int);
	void setHP(int);
	int getHP() const;
	void setAttackPower(int);
	int getAttackPower() const;

};