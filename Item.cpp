#include "Item.h"

Item::Item(xml_node<>* node)
{
	initItem(node);
}

Item::~Item()
{
}

void Item::initItem(xml_node<>* node) {

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

vector <Trigger*> Item::getTriggers()
{
	return this->triggers;
}
