#include "PlayGame.h"

PlayGame::PlayGame(Parse* parse)
{
	startGame(parse);
}

PlayGame::~PlayGame()
{
}

// Member Functions
void PlayGame::startGame(Parse* parse) {
	string cmd;
	presentRoom = "Entrance";
	bool trigger;
	cout << parse->rooms.find(presentRoom)->second->description << endl;

	while (true)
	{
		getline(cin, cmd);
		trigger = checkRoomTrigger(cmd, parse);

		if (trigger == false) {
			gameCommands(cmd, parse);
			checkTriggers("", parse);
		}
	}
}

/************************************* Trigger Functions *****************************************/
bool PlayGame::checkTriggers(string cmd, Parse* parse) {
	bool trigger = false;
	
	if (trigger == false) 
		trigger = checkRoomTrigger(cmd, parse);

	if (trigger == false)
		trigger = checkContainerTrigger(cmd, parse);

	if (trigger == false)
		trigger = checkCreatureTrigger(cmd, parse);

	return trigger;
}


bool PlayGame::checkRoomTrigger(string cmd, Parse* parse) {
	vector <Trigger*> rt = parse->rooms.find(presentRoom)->second->triggers;
	unsigned int i = 0, index = 0;
	bool trigger = false;
	vector <string> trigCmds;

	while (i < rt.size()) {
		trigCmds = rt[i]->commands;
		if (find(trigCmds.begin(), trigCmds.end(), cmd) != trigCmds.end()) {
			index = distance(trigCmds.begin(), find(trigCmds.begin(), trigCmds.end(), cmd));
			trigger = checkTriggerCondition(rt[index]->condition, parse);
			if (trigger == true) {
				cout << rt[index]->print << endl;
				if (rt[index]->type.compare("single") == 0)
					rt[index]->type = "used";

				return trigger;
			}
		}
		i++;
	}
	return false;
}


bool PlayGame::checkContainerTrigger(string cmd, Parse* parse) {
	vector <string> containers_inside_room = parse->rooms.find(presentRoom)->second->containers;
	vector <Trigger*> cntr;
	vector<string>::iterator i = containers_inside_room.begin();
	vector <Trigger*>::iterator j;
	vector <string>::iterator k;
	vector <string> trigCmds;

	bool trigger = false;
	while (i != containers_inside_room.end()) {
		cntr = parse->containers[(*i)]->triggers;
		
		j = cntr.begin();
		while (j != cntr.end()) {
			trigCmds = (*j)->commands;
			if (find(trigCmds.begin(), trigCmds.end(), cmd) != trigCmds.end()) {
				trigger = checkTriggerCondition((*j)->condition, parse);
				if (trigger) {
					cout << (*j)->print << endl;

					k = (*j)->actions.begin();

					while (k != (*j)->actions.end()) {
						behindTheSceneCmds(*k, parse);
						k++;
					}
					if ((*j)->type == "single")
						(*j)->type = "used";
					return true;
				}
			}
			j++;
		}
		i++;
	}

	return trigger;
}


bool PlayGame::checkCreatureTrigger(string cmd, Parse* parse) {
	vector <string> creatures_inside_room = parse->rooms.find(presentRoom)->second->creatures;
	vector <Trigger*> cretrg;
	vector<string>::iterator i = creatures_inside_room.begin();
	vector <Trigger*>::iterator j;
	vector <string>::iterator k;
	vector <string> trigCmds;
	bool trigger = false;

	while (i != creatures_inside_room.end()) {
		cretrg = parse->creatures[*i]->triggers;
		
		j = cretrg.begin();
		while (j != cretrg.end()) {
			trigCmds = (*j)->commands;
			if (find(trigCmds.begin(), trigCmds.end(), cmd) != trigCmds.end()) {
				trigger = checkTriggerCondition((*j)->condition, parse);
				if (trigger) {
					cout << (*j)->print << endl;
					
					k = (*j)->actions.begin();
					while (k != (*j)->actions.end()) {
						behindTheSceneCmds(*k, parse);
						k++;
					}

					if ((*j)->type == "single")
						(*j)->type = "used";
					return true;
				}
			}
			
			j++;
		}

		i++;
	}
}


bool PlayGame::checkTriggerCondition(TriggerCondition* tc, Parse* parse) {
	map<string, Container*> containers = parse->containers;
	map<string, Item*> items = parse->items;

	if (tc->isOwner) {
		string has = tc->owner->has;
		string owner = tc->owner->owner;
		string object = tc->owner->object;

		if (has.compare("no") == 0) {
			if (inventory.count(object) == 0) return true;
			return false;
		}
		else if (has.compare("yes") == 0) {
			if (owner.compare("inventory") == 0) {
				inventoryObjFreq = inventory.count(object);
			}
			else {
				// Find the object inside the container's item list
				vector <string> containerItems = containers[tc->owner->owner]->items;
				if (find(containerItems.begin(), containerItems.end(), object) != containerItems.end()) 
					return true;
				else return false;
			}
		}
	}

	else {
		string object = tc->status->object;
		string status = tc->status->status;

		if (items.count(object) > 0) {
			if (status == items[object]->status) return true;
			else return false;
		}
		else if (containers.count(object) > 0) {
			if (status == containers[object]->status) return true;
			else return false;
		}
	}

	return false;
}


/************************************* Game Command Functions *****************************************/
void PlayGame::behindTheSceneCmds(string cmd, Parse* parse) {
	stringstream iss(cmd);
	vector <string> bts(istream_iterator<string>{iss}, istream_iterator<string>());

	if (bts[0] == "Add") {
		// Add to game logic
	}
	else if (bts[0] == "Delete") {
		// Delete logic
	}
	else if (bts[0] == "Update") {
		// Update logic
	}
	else if (bts[0] == "Game" && bts[0] == "Over") {
		cout << "Victory!" << endl;
		exit(EXIT_SUCCESS);
	}
	else {
		// All other game commands
		gameCommands(cmd, parse);
	}
}



void PlayGame::gameCommands(string cmd, Parse* parse) {
	istringstream iss(cmd);
	vector <string> bts(istream_iterator<string>{iss}, istream_iterator<string>());

	Room* room = parse->rooms[presentRoom];
	if (bts[0] == "n" || bts[0] == "s" || bts[0] == "e" || bts[0] == "w") {
		// Move room logic
	}
	else if (bts[0] == "i") {
		// Print inventory logic
	}
	else if (bts.size() == 2 && bts[0] == "take") {
		// Take item logic
	}
	else if (bts.size() == 2 && bts[0] == "open" && bts[0] == "exit") {
		// Check room exit logic
	}
	else if (bts.size() == 2 && bts[0] == "open" && bts[0] != "exit") {
		// Open container logic
	}
	else if (bts.size() == 2 && bts[0] == "read") {
		// Read item logic
	}
	else if (bts.size() == 2 && bts[0] == "drop") {
		// Drop item logic
	}
	else if (bts.size() == 4 && bts[0] == "put") {
		// Put item in container logic
	}
	else if (bts.size() == 3 && bts[0] == "turn" && bts[1] == "on") {
		// Turn on item logic
	}
	else if (bts.size() == 4 && bts[0] == "attack") {
		// Attack creature with item logic
	}
	else {
		cout << "Error! Wrong Command" << endl;
	}
}


/////////////////////////////////////// 
//////
//////
////// 13 sub-functions for the game commands function
//////
//////
//////
///////////////////////////////////////
void Game::openContainer(string container,xmlpars* data){
	Room * currentRoomPtr = data -> rooms.find(currentRoom)->second;
	vector<string>::iterator temp;
	int a =findInVector(container,currentRoomPtr->container);
	if(a){
	map<string,Container*>::iterator it = data -> containers.find(container);
	Container* changer;
	if(it != data->containers.end())
	{
	   changer = it->second;
	   if(changer -> status == "locked"){
		   cout << changer -> name << " is not open." << endl;
	   }else{
		   if(changer->item.size() == 0){
			   cout << changer ->name << " is empty."<<endl;
		   }
		   else{
			   cout<<changer->name<<" contains ";
			   for(vector<string>::iterator counter_vec = changer->item.begin(); counter_vec!= changer->item.end(); counter_vec++){
				   temp = counter_vec;
				   temp++;
				   cout << *counter_vec;
				   if(temp != changer->item.end()) {
					   cout << ", ";
				   }
				   else {
					   cout << ".";
				   }
			   }
			   cout<<endl;
		   }
		   changer -> status = "open";
	   }

	}
	else{
		cout <<"Error" << endl;
	}
	}else{
		cout <<"Error" << endl;
	}
}

void Game::putCon(string item,string container,xmlpars* data){
	Room * currentRoomPtr = data -> rooms.find(currentRoom)->second;
	int a = findInVector(container,currentRoomPtr->container);
	if(a){
		if(inventory.find(item) != inventory.end()){
			map<string,Container*>::iterator compare = data -> containers.find(container);
			Container* changer = compare -> second;
			changer ->item.push_back(item);
			cout <<"Item "<< item << " added to " << changer -> name<< endl;
			inventory.erase(item);

		}else{
			cout << item <<"Error" << endl;
		}
	}else{
		cout << "Error"<<endl;
	}

}
void Game::turnOn(string item,xmlpars* data){
	Item* itemP;
	if(inventory.find(item) != inventory.end()){
		cout<<"You activate the "<<item <<endl;
		map<string,Item*>::iterator compare = data -> items.find(item);
		itemP = compare -> second;
		for(int i = 0; i < itemP->turnOnPrint.size();i++){
		cout<<itemP->turnOnPrint[i]<<endl;
		}
		if(itemP->turnOnAction.size() != 0){
			for(int i = 0; i < itemP->turnOnAction.size(); i++){
				bTS(itemP->turnOnAction[i],data);
			}
		}
	}
	else{
				cout << item <<" is not in inventory" << endl;
	}
}



void Game::readItem(string item,xmlpars* data){
	Item* ItemP;
	if(inventory.find(item) != inventory.end()){
		map<string,Item*>::iterator compare = data -> items.find(item);
		ItemP = compare -> second;
		if(ItemP->writing == ""){
			cout << "Nothing written." << endl;
		}else{
			cout << ItemP->writing <<endl ;
		}
	}else{
		cout << "Error" << endl;
	}

}


void Game::attack(string creature, string item, xmlpars* data) {
	bool inventor = checkInventory(item, data);
	bool found = false;
	Room * currRoom = data->rooms.find(currentRoom)->second;
	vector<string>::iterator i;
	int count_creatures= 0;
	if(inventor) {
		count_creatures = findInVector(creature,currRoom->creature);
		if(count_creatures) {
			if(!data->creatures[creature]->vulnerabilities.empty()) {
				i = data->creatures[creature]->vulnerabilities.begin();
				while(i != data->creatures[creature]->vulnerabilities.end()) {
					if((*i) == item) {
						cout<<"You assault the "<<creature<<" with "<<item<<endl;
						if(data->creatures[creature]->conditions.empty()) {
							found = creaturesWithoutConditions(creature, data);
						}
						else {
							found = creaturesWithConditions(creature, data);
						}
					}
					i++;
				}
			}
			else {
				cout << "Error" <<endl;
			}
		}
		else {
			cout <<"Error"<<endl;
		}
	}
	else {
		cout <<"Error"<< endl;
	}
}


void Game::takeItem(string item, xmlpars* data){
	Room * currentRoomPtr = data -> rooms.find(currentRoom)->second;
	bool flagR = false; // remove item from room after item taken
	bool flagC = false;
	int count = 0;
	int offset = 0;
	for(vector<string>::iterator counter_vec = currentRoomPtr->item.begin(); counter_vec!= currentRoomPtr->item.end(); counter_vec++) {
		if(*counter_vec == item){
			cout << "Item "<< item <<" added to the inventory." << endl;
			flagR = true ;
			offset = count;
		}
		count = count + 1;
	}
	if(flagR){// need to remove item from item
		inventory[item] = item;
		currentRoomPtr->item.erase(currentRoomPtr->item.begin()+offset);
		return;
	}
	count = 0;
	int a = 0;
	for(vector<string>::iterator counter_vec = currentRoomPtr->container.begin(); counter_vec!= currentRoomPtr->container.end(); counter_vec++) {
			a = findInVector(item,data->containers[*counter_vec]->item);
				if(a){
					if(data->containers[*counter_vec]->status == "open"){
						for(vector<string>::iterator vec = data->containers[*counter_vec]->item.begin(); vec!= data->containers[*counter_vec]->item.end(); vec++) {
								if(*vec == item){
									cout << "Item "<< item <<" added to the inventory." << endl;
									inventory[item] = item;
									flagC = true ;
									offset = count;
								}
								count = count + 1;
							}
						data->containers[*counter_vec]->item.erase(data->containers[*counter_vec]->item.begin()+offset);
						return;
					}
					else{
						cout <<"Error"<< endl;
						return;
					}
					count = count + 1 ;
				}
	}
	cout <<"Error"<<endl;
}
void Game::printInventory(){
	if(inventory.empty()){
		cout <<  "Inventory: empty" << endl;
		return;
	}
	typedef map<string, string>::const_iterator MapIterator;
	MapIterator temp;
	cout <<  "Inventory : ";
	for(MapIterator it= inventory.begin(); it != inventory.end(); ++it)
	{
	    std::cout<< it->second;
	    temp = it;
	    temp++;
	    if(temp != inventory.end())
	    cout<<", ";
	}
	cout<<"\n";
}

void Game::dropItem(string item,xmlpars* data){
	Room * currentRoomPtr = data -> rooms.find(currentRoom)->second;
	if(inventory.find(item) == inventory.end()){
		cout << "Item is not in the inventory" << endl;
	}
	else {
		currentRoomPtr->item.push_back(item);
		inventory.erase(item);
		cout<< item << " dropped." << endl;
	}
}

void Game::moveRoom(string command, xmlpars* data){
	Room * currentRoomPtr = data -> rooms.find(currentRoom)->second;
	string direction;
	string brName;
	if ( command == "n") {
		direction = "north";
	}
	else if( command == "s") {
		direction = "south";
	}
	else if( command == "w") {
		direction = "west";
	}
	else if( command == "e") {
	    direction = "east";
	}
	if( currentRoomPtr->border.count(direction) != 0){
		currentRoom = currentRoomPtr->border.find(direction)->second;
		cout << data -> rooms.find(currentRoom)->second->description <<endl;
	}
	else{
		cout << "Can't go that way" << endl;
	}
}

bool Game::creaturesWithoutConditions(string creature, xmlpars* data) {
	bool found = false;
	string temp;
	if(data->creatures[creature]->attack["print"] != "") {
		cout << data->creatures[creature]->attack["print"] << endl;
	}
	for(int j = 0; j < data->creatures[creature]->count; j++) {
		found = true;
		temp = int_To_String(j,data,creature);
		bTS(temp,data);
	}
	return found;
}

bool Game::creaturesWithConditions(string creature, xmlpars* data) {
	bool condition_found = false;
	bool found = false;
	string temp;
	condition_found = conditions("permanent",data->creatures[creature]->conditions,data);
	if(condition_found == true) {
		cout << data->creatures[creature]->attack["print"] << endl;
		for(int j = 0; j < data->creatures[creature]->count; j++) {
			found = true;
			temp = int_To_String(j,data,creature);
			bTS(temp,data);
		}
	}
	return found;
}

string Game::int_To_String(int i,xmlpars* data, string name) {
	string s;
	stringstream out;
	out << i;
	s=out.str();
	string k = data->creatures[name]->attack["action"+s];
	return k;
}

bool Game::checkInventory(string item, xmlpars* data) {
	bool init = false;
	if(inventory.count(item) > 0) {
		init = true;
	}
	return init;
}
