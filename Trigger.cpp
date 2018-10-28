#include "Trigger.h"

Trigger::Trigger(xml_node<>* trigger) {
	initTrigger(trigger);
}

Trigger::~Trigger() {}

void Trigger::initTrigger(xml_node<>* trigger) {
	xml_node<>* topNode = trigger->first_node();
	
	while (topNode != NULL)
	{
		if (string(topNode->name()) == string("type")) {
			this->type = string(topNode->value());
		}
		else if (string(topNode->name()) == string("command")) {
			this->commands.push_back(string(topNode->value()));
		}
		else if (string(topNode->name()) == string("condition")) {
			if (this->hasOwner(topNode)) {
				this->conditions.push_back(this->initCondition(topNode, true));
			}
			else {
				this->conditions.push_back(this->initCondition(topNode, false));
			}
		}
		if (string(topNode->name()) == string("action")) {
			this->actions.push_back(string(topNode->value()));
		}
		if (string(topNode->name()) == string("print")) {
			this->print = string(topNode->value());
		}
		topNode = topNode->next_sibling();
	}
	
}

bool Trigger::hasOwner(xml_node<>* condition) {
	xml_node<>* topNode = condition->first_node()->next_sibling();
	
	while (topNode != NULL) {
		if (string(topNode->name()) == string("owner")) return true;
		topNode = topNode->next_sibling();
	}
	return false;
}

TriggerCondition* Trigger::initCondition(xml_node<>* conditionNode, bool hasOwner) {
	xml_node<>* topNode = conditionNode->first_node();
	TriggerCondition* condition = new TriggerCondition;
	condition->isOwner = hasOwner;

	if (hasOwner) {
		condition->owner = new TriggerCondOwner;
		while (topNode != NULL) {
			if (string(topNode->name()) == string("has")) {
				condition->owner->has = string(topNode->value());
			}
			if (string(topNode->name()) == string("object")) {
				condition->owner->object = string(topNode->value());
			}
			if (string(topNode->name()) == string("owner")) {
				condition->owner->owner = string(topNode->value());
			}
			topNode = topNode->next_sibling();
		}
	}

	else {
		condition->status = new TriggerCondStatus;
		while (topNode != NULL) {
			if (string(topNode->name()) == string("object")) {
				condition->status->object = string(topNode->value());
			}
			if (string(topNode->name()) == string("status")) {
				condition->status->status = string(topNode->value());
			}
			topNode = topNode->next_sibling();
		}
	}
	
	return condition;
}