#pragma once

class Item {

private:

	int type;
	int value;

public:

	bool isHP() const;
	bool isDefense() const;
	int getValue() const;
	Item(int, int);


};