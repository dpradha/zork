#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <stdlib.h>
#include <vector>
#include <string>
#include "Item.h"
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace rapidxml;
using namespace std;


class Container
{
public:
	Container(xml_node<>* node);
	~Container();

	// Member Variables
	char* name;
	char* status;
	vector <string> accept;
	vector <string> items;
	vector <Trigger*> triggers;

	// Functions
	void initContainer(xml_node<>* node);
	
private:
	
};

#endif