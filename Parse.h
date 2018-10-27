#ifndef _PARSE_H
#define _PARSE_H
#include "Room.h"
#include "Container.h"
#include "Item.h"
#include "Creature.h"
#include <map>
#include <iostream>
#include <fstream>

class Parse
{
public:
	// Member Variables
	map <string, Room*> rooms;
	map <string, Container*> containers;
	map <string, Item*> items;
	map <string, Creature*> creatures;

	// Member functions
	Parse();
	~Parse();
	void initializeMap(char* fileName);
	
private:	
};


#endif // !_PARSE_H

