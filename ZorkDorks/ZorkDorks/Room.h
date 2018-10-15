#ifndef _ROOM_H
#define _ROOM_H
#include <stdlib.h>
#include <vector>
#include "ClassList.h"

using namespace std;

typedef struct {
	char* direction;
	char* name;
}Border;

typedef std::vector <Border> BorderList;

class Room
{
public:
	Room();
	~Room();
	
	// Getter functions
	char* getDescription();
	char* getName();
	char* getStatus();
	char* getType();
	BorderList getBorders();
	ContainerList getContainers();
	ItemList getItems();
	CreatureList getCreatures();
	TriggerList getTriggers();


private:
	// Member Variables
	char* description;
	char* name;
	char* status;
	char* type;
	BorderList borders;
	ContainerList containers;
	ItemList items;
	CreatureList creatures;
	TriggerList triggers;
};

#endif