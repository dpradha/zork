#ifndef _ITEM_H
#define _ITEM_H
#include <stdlib.h>
#include <vector>
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;

class Item {
public:
	string name;
	string description;
	vector<string> turnOnAction;
	string status;
	vector<string> turnOnPrint;
	vector<Trigger*> triggers;
	string writing;

	// Member functions
	Item(xml_node<> *);
	virtual ~Item();
	void initializeItem (xml_node<> *);

private:
	void AddTurnOn(xml_node<> *);
};

#endif /* ITEM_H_ */


