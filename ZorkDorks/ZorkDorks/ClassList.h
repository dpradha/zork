#ifndef _CLASS_LIST_H
#define CLASS_LIST_H

#include <vector>
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"

using namespace std;

typedef std::vector <Room> RoomList;
typedef std::vector <Item> ItemList;
typedef std::vector <Container> ContainerList;
typedef std::vector <Creature> CreatureList;
typedef std::vector <Trigger> TriggerList;
typedef std::vector <char*> CharList;

#endif // !_CLASS_LIST_H
