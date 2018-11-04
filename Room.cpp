#include "Room.h"

Room::Room(xml_node<>* newNode)
{
	initializeRoom(newNode);
}

void Room::borderSetup(rapidxml::xml_node<>* roomNodeChild) {
	string name;
	string direction;
	xml_node<> * roomChild = roomNodeChild->first_node();
	while (roomChild != NULL){
		if(strcmp(roomChild -> name(),"name")==0){
			name = roomChild -> value();
		}		
		else if(strcmp(roomChild -> name(), "direction")==0){
			direction = roomChild -> value();
		}
		roomChild = roomChild->next_sibling();
	}
	this->borders[direction] = name;
}

Room::~Room()
{
}

void Room::initializeRoom(xml_node<>* node) {
	xml_node<>* room = node->first_node();
		while (room != NULL) {
			if(strcmp(room -> name(), "type") == 0) {
				this -> type = room -> value();
			}
			else if(strcmp(room -> name(),"name") == 0) {
				this -> name = room -> value();
			}
			else if (strcmp(room -> name(), "item")==0){
				this -> items.push_back(room -> value());
			}
			else if(strcmp(room -> name(), "container")==0){
				this -> containers.push_back(room -> value());
			}
			else if(strcmp(room -> name(), "trigger")==0){
				this -> triggers.push_back(new Trigger(room));
			}
			else if(strcmp(room -> name(), "type")==0){
				this -> status = room -> value();
			}
			else if(strcmp(room -> name(), "border")==0){
				borderSetup(room);
			}
			else if (strcmp(room -> name(),"description")==0){
				this -> description = room -> value();
			}
			else if (strcmp(room -> name(), "creature")==0){
				this -> creatures.push_back(room -> value());
			}
			room = room->next_sibling();
		}
}

