#ifndef _ROOM_H
#define _ROOM_H
#include <vector>
#include <string>
#include <map>
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

	// Member Variables
	string description;
	string name;
	string status;
	string type;
	
	map<string,string> borders;
	vector <string> creatures;
	vector <Trigger*> triggers;
	vector <string> containers;
	vector <string> items;

	//Member functions
	Room(xml_node<>*);
	~Room();
	
private:
	// Member functions
	void initializeRoom(xml_node<>*);
	void borderSetup(rapidxml::xml_node<> *roomNodeChild);
};

#endif