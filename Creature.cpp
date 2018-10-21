#include "Creature.h"

Creature::Creature(xml_node<>* node)
{
	initCreature(node);
}

Creature::~Creature()
{
}

void Creature::initCreature(xml_node<>* node) {

}

// Getter functions
string Creature::getName()
{
	return this->name;
}

string Creature::getStatus()
{
	return this->status;
}

vector <char*> Creature::getVulnerability()
{
	return this->vulnerability;
}

Attack* Creature::getAttack()
{
	return this->attack;
}

vector <Trigger*>Creature::getTriggers()
{
	return this->triggers;
}
