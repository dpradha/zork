#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <stdlib.h>
#include <vector>
#include "ClassList.h"

using namespace std;

class Container
{
public:
	Container();
	~Container();

	// Getter functions
	char* getName();
	char* getStatus();
	ItemList getAccept();
	ItemList getItems();
	TriggerList getTriggers();

private:
	// Member Variables
	char* name;
	char* status;
	ItemList accept;
	ItemList items;
	TriggerList triggers;
};

#endif