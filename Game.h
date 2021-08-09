#pragma once
#include "Room.h"
#include "Hero.h"
// Cl
class Game {

private:
	// private class for game header file
	Room* currentRoom;
	Hero* hero;
	void createMap(); // void functon to create map

public:

	void run();
	Game();

};



