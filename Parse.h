#ifndef _PARSE_H
#define _PARSE_H
#include "Room.h"
#include "Container.h"
#include "Item.h"
#include "Creature.h"
#include <iostream>
#include <fstream>

class Parse
{
public:
	// Member Variables
	vector <Room*> rooms;
	vector <Container*> containers;
	vector <Item*> items;
	vector <Creature*> creatures;

	// Member functions
	Parse();
	~Parse();
	void initializeMap(char* fileName);
	
private:	
	
	

	// Member functions
	void setupRoom(vector<xml_node<>*> roomNodes);
	void setupContainer(vector<xml_node<>*> containerNodes);
	void setupItem(vector<xml_node<>*> itemNodes);
	void setupCreature(vector<xml_node<>*> creatureNodes);
};


#endif // !_PARSE_H

