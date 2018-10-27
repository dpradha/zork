#include "Parse.h"

Parse::Parse()
{
	
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
			rooms[room->getName()] = room;
		}
		else if (string(topNode->name()) == string("container")) {
			container = new Container(topNode);
			containers[container->getName] = container;
		}
		else if (string(topNode->name()) == string("item")) {
			item = new Item(topNode);
			items[item->getName] = item;
		}
		else if (string(topNode->name()) == string("creature")) {
			creature = new Creature(topNode);
			creatures[creature->getName] = creature;
		}
		topNode = topNode->next_sibling();
	}
}