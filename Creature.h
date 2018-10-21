#ifndef _CREATURE_H
#define _CREATURE_H
#include <stdlib.h>
#include <vector>
#include <string>
#include "Trigger.h"
#include "Item.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;

typedef struct {
	Item* object;
	string status;
}Condition;

typedef struct {
	Condition* condition;
	string print;
	vector <string> actions;
}Attack;

class Creature
{
public:
	Creature(xml_node<>* node);
	~Creature();

	// Getter functions
	string getName();
	string getStatus();
	vector <char*> getVulnerability();
	Attack* getAttack();
	vector <Trigger*> getTriggers();

private:
	// Member variables
	string name;
	string status;
	vector <char*> vulnerability;
	Attack* attack;
	vector <Trigger*> triggers;

	// Functions
	void initCreature(xml_node<>* node);
};

#endif // !_CREATURE_H

