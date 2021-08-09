#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{

	hero = new Hero(5, 5, 5, 2); //construct and initizlize hero
	createMap(); //initialze map
}


void Game::createMap()
{
	Monster* Furty; // create monster
	Monster* Azza; // Create Monster 2

	Item* hpItem; // item to increase hp
	Item* hpItem2; // item to iuncrease hp
	Item* defItem; // item to increase defense


	// Show rooms that are created


	Furty = new Monster(5, 5); //initialize monster attributes
	Azza = new Monster(6, 6);  //initialize monster attributes
	hpItem = new Item(0, 4); //initialize hp item
	hpItem2 = new Item(0, 5); //initialize hp item
	hpItem2 = new Item(0, 5); //initialize hp item
	defItem = new Item(1, 6); //initialize defense item


	/* ..Map Layout..

						(Abyss)				(Upper dungeon)-------(Exit)
						|					|
						|					|
	(Start Room)-->(Dungeon)------------(Stone Room)
						|					|
						|					|
						|				(Lower Dungeon)
						|
						(Devil's Liar)

	*/

	Room* Start = new Room("Start Room", nullptr, nullptr, nullptr, nullptr, false); //create start room

	Room* StB = new Room("Dungeon", nullptr, nullptr, Start, nullptr, false); //create room to the east of start
	Start->setEastRoom(StB); //connect to start

	Room* StC = new Room("Abyss", StB, nullptr, nullptr, nullptr, defItem); //create room to north of Stb
	StB->setNorthRoom(StC); //connect room to StB

	Room* Central = new Room("Devil's Lair", nullptr, StB, nullptr, nullptr, Furty, hpItem); //create room to the south of Stb
	StB->setSouthRoom(Central); //connect StB to Central

	Room* StE = new Room("Stone Room", nullptr, nullptr, StB, nullptr, Azza); //create room to the east of StB
	StB->setEastRoom(StE); //connect room to StB

	Room* StF = new Room(" Lower Dungeon ", nullptr, StE, nullptr, nullptr, hpItem); //create room ot the south of StE
	StE->setSouthRoom(StF); //connect room to StE

	Room* Stg = new Room(" Upper Dungeon ", StE, nullptr, nullptr, nullptr, hpItem2); //create room ot the north of StE
	StE->setNorthRoom(Stg); //connect room to StE

	Room* Exit = new Room("Exit Room", nullptr, nullptr, Stg, nullptr, true); //create room to the eats of Stg
	Stg->setEastRoom(Exit); //connect room to Stg


	currentRoom = Start; //initialize currentRoom

}


void Game::run()
{

	Room* PreviousRoom = nullptr; //create previous room pointer

	int curr = 0;//array for story line
	string Stories[7]; //create array stories

	//initialize stories indexes
	Stories[0] = "The hero started the quest";
	Stories[1] = "The hero reached the dungeon!";
	Stories[2] = "The hero finds an item!";
	Stories[3] = "The hero has made a great stride in their journey onward.";
	Stories[4] = "Be wary of monsters!";
	Stories[5] = "You're almost there!";
	Stories[6] = "Congrats, you've made it to the exit!";




	while (hero->isAlive() && !currentRoom->isExit()) { //while loop to start game

		//display name, monster, and items
		cout << currentRoom->getName() << endl;
		cout << currentRoom->getRoomMonster()->getHP() << endl;
		cout << currentRoom->getRoomMonster()->getAttackPower() << endl;
		cout << currentRoom->getRoomItem()->getValue() << endl;

		//execute retreat functionality
		if (hero->getRetreatCount() > 0) {

			cout << "Do you want to retreat or not" << endl;
			char ch;

			cout << "Press Y for Yes" << endl;
			std::cin >> ch;

			if (ch == 'Y' || ch == 'y') {

				currentRoom = PreviousRoom;
				hero->decreaseRetreatCount();
			}

		}

		//execute use item functionality
		if (hero->anyItems()) {

			cout << "Do you want to use the item or not" << endl;
			char ch;

			cout << "Press Y for Yes" << endl;
			std::cin >> ch;

			if (ch == 'Y' || ch == 'y') {

				for (int i = 0; i < 3; i++) {

					if (hero->bag[i] != nullptr) {

						if (hero->bag[i]->isDefense()) {

							cout << "We have a defense item at index " << i << endl;
						}
						if (hero->bag[i]->isHP()) {

							cout << "We have a HP item at index " << i << endl;
						}
					}
				}
				int index;
				cout << "Which item do you want to use:";
				std::cin >> index;
				while (index < 0 || index >= 3 || hero->bag[index] == nullptr) {

					cout << "Wrong option, Try again" << endl;
					std::cin >> index;

				}

				if (hero->bag[index]->isDefense()) {

					int currPower = hero->getDefensePower();
					currPower += hero->bag[index]->getValue();
					hero->setDefensePower(currPower);


				}
				else if (hero->bag[index]->isHP()) {

					int currHP = hero->getHP();
					currHP += hero->bag[index]->getValue();
					hero->setHP(currHP);
				}

				hero->bag[index] = NULL;
			}
		}


		//battle with monster functionality
		if (currentRoom->getRoomMonster() != NULL) {

			Monster* currMonster = currentRoom->getRoomMonster();

			int Res = (*hero) * (*currMonster);

			while (Res == 0) {

				Res = (*hero) * (*currMonster);
			}
		}

		if (hero->isAlive()) { //check if hero is alive

			if (currentRoom->getRoomItem() != NULL) {

				cout << "Do you want to pick the item or not" << endl;
				char ch;

				cout << "Press Y for Yes" << endl;
				std::cin >> ch;

				if (ch == 'Y' || ch == 'y') {

					for (int i = 0; i < 3; i++) {

						if (hero->bag[i] != nullptr) {

							if (hero->bag[i]->isDefense()) {

								cout << "We have a defense item at index " << i << endl;

							}
							if (hero->bag[i]->isHP()) {

								cout << "We have a HP item at index " << i << endl;

							}
						}
					}

					int index;
					cout << "Which position do you want to use:"; //ask which item they want to use
					std::cin >> index;

					while (index < 0 || index >= 3 || hero->bag[index] == nullptr) {

						cout << "Wrong option, Try again" << endl;
						std::cin >> index;

					}

					hero->bag[index] = currentRoom->getRoomItem();
					currentRoom->setRoomItem(NULL);

				}
			}

			//move rooms
			bool N = false;
			bool S = false;
			bool E = false;
			bool W = false;



			if (currentRoom->getNorthRoom() != NULL) {
				N = true;
			}

			if (currentRoom->getSouthRoom() != NULL) {
				S = true;
			}
			if (currentRoom->getEastRoom() != NULL) {
				E = true;
			}
			if (currentRoom->getWestRoom() != NULL) {
				W = true;
			}

			if (N = true) {
				cout << "Press N for North" << endl;
			}

			if (S = true) {
				cout << "Press S for South" << endl;
			}

			if (E = true) {
				cout << "Press E for East" << endl;
			}
			if (W = true) {
				cout << "Press W for West" << endl;
			}

			// User input for room
			char ch;
			std::cin >> ch;

			if (ch == 'N') {
				PreviousRoom = currentRoom;
				currentRoom = currentRoom->getNorthRoom(); //move to north room
			}
			else if (ch == 'S') {
				PreviousRoom = currentRoom;
				currentRoom = currentRoom->getSouthRoom(); //move to south room
			}

			else if (ch == 'E') {
				PreviousRoom = currentRoom;
				currentRoom = currentRoom->getEastRoom(); //move to east room
			}
			else if (ch == 'W') {
				PreviousRoom = currentRoom;
				currentRoom = currentRoom->getWestRoom(); //move to west room
			}





		}


		cout << Stories[curr]; // show st following User's compleition of game '
		curr++;
		// Exit message or Game over message
		if (currentRoom->isExit()) {
			cout << "Congratulations" << endl;
		}
		else {
			cout << "Game Over" << endl;
		}



	}


}

