#ifndef _MAP_H
#define _MAP_H
#include <stdlib.h>
#include "ClassList.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

private:
	// Member Variables
	RoomList rooms;
	ItemList items;
	ContainerList containers;
	CreatureList creatures;
};


#endif
