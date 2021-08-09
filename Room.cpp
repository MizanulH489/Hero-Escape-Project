#include "Room.h"
// Set room name
void Room::setName(string name)
{
	name = this->name;
}
// Get room name
string Room::getName() const
{
	return name;
}
// Set the east room
void Room::setEastRoom(Room* east)
{
	east = this->east;
}
// Set the west room
void Room::setWestRoom(Room* west)
{
	west = this->west;
}
//set the north room
void Room::setNorthRoom(Room* north)
{
	north = this->north;
}
// Set the south room
void Room::setSouthRoom(Room* south)
{
	south = this->south;
}
//return east room
Room* Room::getEastRoom() const
{
	return east;
}
//return west room
Room* Room::getWestRoom() const
{
	return west;
}
// Set the north room
Room* Room::getNorthRoom() const
{
	return north;
}
// Set the south room
Room* Room::getSouthRoom() const
{
	return south;
}
// Set the room with a monster
void Room::setRoomMonster(Monster* monster)
{
	monster = this->roomMonster;

}
// Get the room with a monster
Monster* Room::getRoomMonster() const
{
	return roomMonster;
}
// Set the room with an item
void Room::setRoomItem(Item* roomItem)
{
	roomItem = this->roomItem;
}
// Return item in room
Item* Room::getRoomItem() const
{
	return roomItem;
}

bool Room::isExit()
{
	return false;
}
// Room with item and monster
Room::Room(string name, Room* n, Room* s, Room* e, Room* w, Monster* m, Item* item)
{

	this->name = " ";
	n = north = 0;
	s = south = 0;
	w = west = 0;
	e = east = 0;
	m = roomMonster = 0;
	item = roomItem = 0;

}
// Room with monster only
Room::Room(string name, Room* n, Room* s, Room* e, Room* w, Monster* m)
{
	this->name = " ";
	n = north = 0;
	s = south = 0;
	w = west = 0;
	e = east = 0;
	m = roomMonster = 0;

}
//room with item only
Room::Room(string name, Room* n, Room* s, Room* e, Room* w, Item* item)
{

	this->name = " ";
	n = north = 0;
	s = south = 0;
	w = west = 0;
	e = east = 0;
	item = roomItem = 0;

}
// Exit room
Room::Room(string name, Room* n, Room* s, Room* e, Room* w, bool exit)
{
	this->name = " ";
	n = north = 0;
	s = south = 0;
	w = west = 0;
	e = east = 0;
	exit = true;
}
