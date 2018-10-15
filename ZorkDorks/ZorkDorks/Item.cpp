#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}

// Getter functions
char* Item::getName()
{
	return this->name;
}

char* Item::getStatus()
{
	return this->status;
}

char* Item::getDescription()
{
	return this->description;
}

char* Item::getWriting()
{
	return this->writing;
}

TurnOn* Item::getTurnOn()
{
	return this->turnOn;
}

TriggerList Item::getTriggers()
{
	return this->triggers;
}
