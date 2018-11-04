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








	//Newly added functions definitions

	//***** All subfunctions for game commands *******//
	////
	///    13 functions
	///
	
	void putCon(string,string,xmlpars*);  // Together
	void moveRoom(string, xmlpars*);
	void openContainer(string,xmlpars*);
	void attack(string, string, xmlpars*);
	void printInventory();
	bool creaturesWithoutConditions(string, xmlpars*); //function used in attack()
	bool creaturesWithConditions(string, xmlpars*);    //function used in attack()
	bool checkInventory(string, xmlpars*);				//function used in attack()
	string int_To_String(int,xmlpars*,string);			//function used in attack() -> creaturesWithConditions()
	

	void turnOn(string,xmlpars*);		//Aakash
	void readItem(string,xmlpars*);		//Aakash
	void takeItem(string item, xmlpars*); //Aakash
	void dropItem(string,xmlpars*);			//Aakash


	//**** SUbfunctions for Behind the Scenes ***///
	///
	///    12 functions
	///
	void update_item(string, string, xmlpars*);
	void update_container(string, string, xmlpars*);
	void addToGame(string, string, xmlpars*);
	void deleteFromGame(string, xmlpars*);
	string findItemType(string,string,xmlpars*,string*);
	void addToItem(string,string,xmlpars*,string);
	void addToCreature(string,string,xmlpars*,string);
	void addToContainer(string,string,xmlpars*,string);
	bool deleteFromRoom(string, xmlpars*);
	bool deleteFromCreature(string, xmlpars*);
	bool deleteFromItem(string, xmlpars*);
	bool deleteFromContainer(string, xmlpars*);


};


#endif // !_PLAY_GAME_H
