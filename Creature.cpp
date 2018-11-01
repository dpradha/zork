#include "Creature.h"

Creature::Creature(xml_node<>* node)
{
	initCreature(node);
}

Creature::~Creature()
{
}

void Creature::initCreature(xml_node<>* node) {
	xml_node<> *creature = node->first_node();
	this->count = 0;
	while (creature != NULL) {
		if (strcmp(creature->name(),"name")==0) {
			this->name = creature->value();
		}
		else if (strcmp(creature->name(),"status")==0) {
			this->status = creature->value();
		}
		else if (strcmp(creature->name(),"vulnerability")==0) {
			this->vulnerabilities.push_back(creature->value());
		}
		else if (strcmp(creature->name(),"trigger")==0) {
			this->triggers.push_back(new Trigger(creature));
		}
		else if (strcmp(creature->name(),"attack")==0) {
			AttackSetUp(creature->first_node());
		}
		creature = creature->next_sibling();
	}
}
void Creature::AttackSetUp(xml_node<>* node) {
	while (node != NULL){
		if (strcmp(node->name(),"condition")==0){
		    ConditionSetUp(node->first_node());
		}
		if (strcmp(node->name(),"print")==0){
		    this->attack[node->name()] = node->value();
		}
		if (strcmp(node->name(),"action")==0){
			this->attack[intString(count,node->name())] = node->value();
		    count++;
		}
			node = node -> next_sibling();
	 }
}

string Creature::intString(int i,string j) {
	string s;
	stringstream out;
	out << i;
	s = out.str();
	return j+s;
}

void Creature::ConditionSetUp(xml_node<>* firstnode) {
	while (firstnode != NULL) {
		if(strcmp(firstnode->name(),"status")==0) {
			this->conditions[firstnode->name()] = firstnode->value();
		}
		else if (strcmp(firstnode->name(), "has")==0) {
			this->conditions[firstnode->name()] = firstnode->value();
		}
		else if (strcmp(firstnode->name(), "object")==0) {
					this->conditions[firstnode->name()] = firstnode->value();
		}
		else if (strcmp(firstnode->name(), "owner")==0) {
					this->conditions[firstnode->name()] = firstnode->value();
		}
		firstnode = firstnode->next_sibling();
	}
}

