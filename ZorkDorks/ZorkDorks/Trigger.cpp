#include "Trigger.h"

Trigger::Trigger()
{
}

Trigger::~Trigger()
{
}

// Getter Functions
char* Trigger::getType()
{
	return this->type;
}

char* Trigger::getCommand()
{
	return this->command;
}

Owner* Trigger::getOwner()
{
	return this->owner;
}

Status* Trigger::getStatus()
{
	return this->status;
}