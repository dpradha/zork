#include "Item.h"

Item::Item(xml_node<>* newNode)
{
	initializeItem(newNode);
}

Item::~Item()
{
}

void Item::initializeItem(xml_node<>* node) {
	xml_node<>* item = node->first_node();
	while(item != NULL) {
				if(strcmp(item->name(),"name") == 0) {
					this->name = item->value();
				}
				else if (strcmp(item->name(),"trigger")==0) {
					this->triggers.push_back(new Trigger(item));
				}
				else if(strcmp(item->name(),"status") == 0) {
					this->status = item->value();
				}
				else if (strcmp(item->name(),"writing") == 0) {
					this->writing = item->value();
				}
				else if (strcmp(item->name(),"description") == 0) {
					this->description = item->value();
				}
				else if (strcmp(item->name(),"turnon") == 0) {  
					AddTurnOn(item->first_node());
				}
				item = item->next_sibling();
			}
}

void Item::AddTurnOn(xml_node<>* node) {
	while(node != NULL) {
		if(strcmp(node->name(),"action") == 0) {
			this->turnOnAction.push_back(node->value());
		}
		else if(strcmp(node->name(),"print") == 0) {
			this->turnOnPrint.push_back(node->value());
		}
		node = node->next_sibling();
	}
}

