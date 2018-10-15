#include "Creature.h"

Creature::Creature()
{
}

Creature::~Creature()
{
}

// Getter functions
char* Creature::getName()
{
	return this->name;
}

char* Creature::getStatus()
{
	return this->status;
}

CharList Creature::getVulnerability()
{
	return this->vulnerability;
}

Attack Creature::getAttack()
{
	return this->attack;
}

Triggers Creature::getTriggers()
{
	return this->triggers;
}
