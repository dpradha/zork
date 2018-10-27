#ifndef _ROOM_H
#define _ROOM_H
#include <stdlib.h>
#include <vector>
#include <string>
#include "Container.h"
#include "Item.h"
#include "Creature.h"
#include "Trigger.h"
#include "Item.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;

typedef struct {
	string direction;
	string name;
}Border;


class Room
{
public:
	Room(xml_node<>* node);
	~Room();
	// Member Variables
	char* description;
	char* name;
	char* status;
	char* type;
	vector <Border*> borders;
	vector <Container*> containers;
	vector <Item*> items;
	vector <Creature*> creatures;
	vector <Trigger*> triggers;

	// Functions
	void initRoom(xml_node<>* node);

private:
};

#endif