#pragma once
#include "Character.h"


class Monster : public Character {

public:

	void decreaseAttackPower();
	Monster(int, int);
	void setHP(int);
	int getHP() const;
	void setAttackPower(int);
	int getAttackPower() const;

};