#ifndef _TRIGGER_H
#define _TRIGGER_H
#include <stdlib.h>
#include "ClassList.h"

typedef struct
{
	char* has;
	Item* object;
	char* owner;
}Owner;

typedef struct
{
	Container* object;
	char* status;
}Status;


class Trigger
{
public:
	Trigger();
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
};

#endif