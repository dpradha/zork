#include "Container.h"

Container::Container(xml_node<>* node)
{
	initContainer(node);
}

Container::~Container()
{
}

void Container::initContainer(xml_node<>* node) {

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

vector <string> Container::getAccept()
{
	return this->accept;
}

vector <string> Container::getItems()
{
	return this->items;
}

vector <Trigger*> Container::getTriggers()
{
	return this->triggers;
}
