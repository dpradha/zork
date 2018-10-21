#include "Room.h"

Room::Room(xml_node<>* node)
{
	initRoom(node);
}

Room::~Room()
{
}

void Room::initRoom(xml_node<>* node) {

}

// Getter functions

char* Room::getDescription()
{
	return this->description;
}

char* Room::getName()
{
	return this->name;
}

char* Room::getStatus()
{
	return this->status;
}

char* Room::getType()
{
	return this->type;
}

vector <Border*> Room::getBorders()
{
	return this->borders;
}

vector <Container*> Room::getContainers()
{
	return this->containers;
}

vector <Item*> Room::getItems()
{
	return this->items;
}

vector <Creature*> Room::getCreatures()
{
	return this->creatures;
}

vector <Trigger*> Room::getTriggers()
{
	return this->triggers;
}
