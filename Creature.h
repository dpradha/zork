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

// struct AttackCondition{
// 	Item* object;
// 	string status;
// };

// struct Attack{
// 	AttackCondition* condition;
// 	string print;
// 	vector <string> actions;
// };

class Creature
{
public:
	Creature(xml_node<>* node);
	~Creature();

	// Member variables
	string name;
	string status;
	vector <string> vulnerability;
	Attack* attack;
	vector <Trigger*> triggers;
	string print;
	map<string,string> conditions;
	vector<string> action;
	map<string,string> attack;
	int count;

	// Functions
	void initCreature(xml_node<>* node);

private:
	string intString(int,string);
	void AttackSetUp(xml_node<>*);
	void ConditionSetUp(xml_node<>*);
};

#endif // !_CREATURE_H

