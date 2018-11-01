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
	istringstream iss(cmd);
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