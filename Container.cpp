#include "Container.h"

Container::Container(xml_node<>* node)
{
	initContainer(node->first_node());
}

Container::~Container()
{
}

void Container::initContainer(xml_node<>* node) {
	while (node != NULL)
	{
		if (strcmp(node->name(), "name") == 0) {
			this->name = node->value();
		}
		else if (strcmp(node->name(), "item") == 0) {
			this->items.push_back(node->value());
		}
		else if (strcmp(node->name(), "accept") == 0) {
			this->accept.push_back(node->value());
			truthValue = true;
		}
		else if (strcmp(node->name(), "status") == 0) {
			this->status = node->value();
		}
		else if (strcmp(node->name(), "trigger") == 0) {
			this->triggers.push_back(new Trigger(node));
		}
		node = node->next_sibling();
	}
	
}
