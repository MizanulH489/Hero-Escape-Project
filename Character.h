#pragma once

class Character {

private:

	int hp;
	int attackPower;

public:

	virtual void setHP(int) = 0;
	virtual int getHP() const = 0;
	virtual void setAttackPower(int) = 0;
	virtual int getAttackPower() const = 0;

	// Friend class variables 
	friend class Monster;
	friend class Hero;
	friend class Item;
};