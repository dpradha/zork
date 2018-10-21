#ifndef _TRIGGER_H
#define _TRIGGER_H
#include <stdlib.h>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;

typedef struct
{
	string has;
	string object;
	string* owner;
}Owner;

typedef struct
{
	string object;
	string status;
}Status;


class Trigger
{
public:
	Trigger(xml_node<>* node);
	~Trigger();

	// Getter functions
	char* getType();
	char* getCommand();
	Owner* getOwner();
	Status* getStatus();

private:
	// Member variables
	char* type;
	char* command;
	Owner* owner;
	Status* status;

	// Functions
	void initTrigger(xml_node<>* node);
};

#endif