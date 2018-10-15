#include "Container.h"

Container::Container()
{
}

Container::~Container()
{
}

// Getter functions
char* Container::getName()
{
	return this->name;
}

char* Container::getStatus()
{
	return this->status;
}

ItemList Container::getAccept()
{
	return this->accept;
}

ItemList Container::getItems()
{
	return this->items;
}

TriggerList Container::getTriggers()
{
	return this->triggers;
}
