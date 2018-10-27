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
	vector<xml_node<>*> roomNodes;
	vector<xml_node<>*> containerNodes;
	vector<xml_node<>*> itemNodes;
	vector<xml_node<>*> creatureNodes;

	xml_node<>* topNode = node->first_node();
	while (topNode != NULL)
	{
		if (string(topNode->name()) == string("room")) roomNodes.push_back(topNode);
		else if (string(topNode->name()) == string("container")) containerNodes.push_back(topNode);
		else if (string(topNode->name()) == string("item")) itemNodes.push_back(topNode);
		else if (string(topNode->name()) == string("creature")) creatureNodes.push_back(topNode);
		topNode = topNode->next_sibling();
	}

	this->setupRoom(roomNodes);
	this->setupContainer(containerNodes);
	this->setupItem(itemNodes);
	this->setupCreature(creatureNodes);
}


void Parse::setupRoom(vector<xml_node<>*> roomNodes) {
	int size = roomNodes.size();
	int index = 0;
	while (index < size)
	{
		rooms.push_back(new Room(roomNodes[index]));
		index++;
	}
}

void Parse::setupContainer(vector<xml_node<>*> containerNodes) {
	int size = containerNodes.size();
	int index = 0;
	while (index < size)
	{
		containers.push_back(new Container(containerNodes[index]));
		index++;
	}
}

void Parse::setupItem(vector<xml_node<>*> itemNodes) {
	int size = itemNodes.size();
	int index = 0;
	while (index < size)
	{
		items.push_back(new Item(itemNodes[index]));
		index++;
	}
}

void Parse::setupCreature(vector<xml_node<>*> creatureNodes) {
	int size = creatureNodes.size();
	int index = 0;
	while (index < size)
	{
		creatures.push_back(new Room(creatureNodes[index]));
		index++;
	}
}

