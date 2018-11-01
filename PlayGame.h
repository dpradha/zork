#ifndef _PLAY_GAME_H
#define _PLAY_GAME_H
#include <sstream>
#include "Item.h"
#include "Room.h"
#include "Container.h"
#include "Creature.h"
#include "Parse.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class PlayGame
{
public:
	PlayGame(Parse* parse);
	~PlayGame();

	
	// Member Functions
	void startGame(Parse* parse);

private:
	string presentRoom;
	map<string, string> inventory;
	int inventoryObjFreq;

	// Member Functions
	// Trigger functions
	bool PlayGame::checkTriggers(string cmd, Parse* parse);
	bool checkRoomTrigger(string cmd, Parse* parse);
	bool checkContainerTrigger(string cmd, Parse* parse);
	bool checkCreatureTrigger(string cmd, Parse* parse);
	bool checkTriggerCondition(TriggerCondition* tc, Parse* parse);

	// Game Command functions
	void behindTheSceneCmds(string cmd, Parse* parse);
	void gameCommands(string cmd, Parse* parse);

};


#endif // !_PLAY_GAME_H
