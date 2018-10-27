#include "Parse.h"

Parse::Parse(char* fileName) {
	this->initializeMap(fileName);
}

Parse::~Parse()
{
}

void Parse::initializeMap(char* fileName) {
	file<> xmlFile(fileName);	// Open the file and return a file ptr
	xml_document<> doc;
	doc.parse<0>(xmlFile.data());	// Parse the input file as an xml document

	xml_node<> *node = doc.first_node();	// Map Node

	// XML Vectors	
	Room* room;
	Creature* creature;
	Container* container;
	Item* item;

	xml_node<>* topNode = node->first_node();
	while (topNode != NULL)
	{
		if (string(topNode->name()) == string("room")) {
			room = new Room(topNode);
			rooms[room->name] = room;
		}
		else if (string(topNode->name()) == string("container")) {
			container = new Container(topNode);
			containers[container->name] = container;
		}
		else if (string(topNode->name()) == string("item")) {
			item = new Item(topNode);
			items[item->name] = item;
		}
		else if (string(topNode->name()) == string("creature")) {
			creature = new Creature(topNode);
			creatures[creature->name] = creature;
		}

		topNode = topNode->next_sibling();
	}
}