#include <iostream>
#include "Character.h"

using namespace std;
// Set the hp
void Character::setHP(int hp) {

	hp = this->hp;
}
// Return the HP
int Character::getHP() const {

	return hp;

}
// Set attack power
void Character::setAttackPower(int attackPower) {

	attackPower = this->attackPower;
};
// Return attack power
int Character::getAttackPower() const {

	return attackPower;
}
