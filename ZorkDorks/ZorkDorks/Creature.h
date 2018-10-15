#ifndef _CREATURE_H
#define _CREATURE_H
#include <stdlib.h>
#include <vector>
#include "ClassList.h"

using namespace std;

typedef struct {
	Item* object;
	char* status;
}Condition;

typedef struct {
	Condition* condition;
	char* print;
	CharList actions;
}Attack;

class Creature
{
public:
	Creature();
	~Creature();

	// Getter functions
	char* getName();
	char* getStatus();
	CharList getVulnerability();
	Attack getAttack();
	TriggerList getTriggers();

private:
	// Member variables
	char* name;
	char* status;
	CharList vulnerability;
	Attack attack;
	TriggerList triggers;
};

#endif // !_CREATURE_H

