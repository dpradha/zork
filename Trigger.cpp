#include "Trigger.h"

Trigger::Trigger(xml_node<>* node)
{
	initTrigger(node);
}

Trigger::~Trigger()
{
}

void Trigger::initTrigger(xml_node<>* node) {

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