#ifndef _ITEM_H
#define _ITEM_H
#include <stdlib.h>
#include <vector>
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;

typedef struct {
	char* print;
	char* action;
}TurnOn;

class Item
{
public:
	Item(xml_node<>* node);
	~Item();

	// Getter functions
	char* getName();
	char* getStatus();
	char* getDescription();
	char* getWriting();
	TurnOn* getTurnOn();
	vector <Trigger*> getTriggers();

private:
	// Member variables
	char* name;
	char* status;
	char* description;
	char* writing;
	TurnOn* turnOn;
	vector <Trigger*> triggers;

	// Functions
	void initItem(xml_node<>* node);
};
#endif

