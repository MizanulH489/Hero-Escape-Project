#include "Monster.h"
// Decrease monster attack power
void Monster::decreaseAttackPower()
{
	attackPower--;
}
// Monster constructor, set hp and attack power
Monster::Monster(int hp, int attackPower)
{
	this->hp = hp;
	this->attackPower = attackPower;
}
// Set monster hp
void Monster::setHP(int hp) {

	this->hp = hp;
}
// Get monster hp
int Monster::getHP() const {

	return hp;
}
// Set monster attack power
void Monster::setAttackPower(int attackPower) {

	this->attackPower = attackPower;
}
//get monster attack power
int Monster::getAttackPower() const {

	return attackPower;
}