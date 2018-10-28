#ifndef _TRIGGER_H
#define _TRIGGER_H
#include <stdlib.h>
#include <string>
#include <vector>
#include <stdbool.h>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;

struct TriggerCondOwner
{
	string has;
	string object;
	string owner;
};

 struct TriggerCondStatus
{
	string object;
	string status;
};

struct TriggerCondition
{
	bool isOwner;
	TriggerCondOwner* owner;
	TriggerCondStatus* status;
};

class Trigger
{
public:
	Trigger(xml_node<>* trigger);
	~Trigger();

	// Member variables
	string type;
	vector <string> commands;
	vector <TriggerCondition*> conditions;
	string print;
	vector <string> actions;

	// Functions
	void initTrigger(xml_node<>* trigger);
	bool hasOwner(xml_node<>* condition);
	TriggerCondition* initCondition(xml_node<>* condition, bool hasOwner);

private:
	
};

#endif