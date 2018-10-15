#include "Room.h"

Room::Room()
{
}

Room::~Room()
{
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

BorderList Room::getBorders()
{
	return this->borders;
}

ContainerList Room::getContainers()
{
	return this->containers;
}

ItemList Room::getItems()
{
	return this->items;
}

CreatureList Room::getCreatures()
{
	return this->creatures;
}

TriggerList Room::getTriggers()
{
	return this->triggers;
}
