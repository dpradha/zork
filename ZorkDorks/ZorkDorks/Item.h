#ifndef _ITEM_H
#define _ITEM_H
#include <stdlib.h>
#include <vector>
#include "ClassList.h"

using namespace std;

typedef struct {
	char* print;
	char* action;
}TurnOn;

class Item
{
public:
	Item();
	~Item();

	// Getter functions
	char* getName();
	char* getStatus();
	char* getDescription();
	char* getWriting();
	TurnOn* getTurnOn();
	TriggerList getTriggers();

private:
	// Member variables
	char* name;
	char* status;
	char* description;
	char* writing;
	TurnOn* turnOn;
	TriggerList triggers;
};
#endif

