#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {
    friend class MainWindow;

private:
    string description;
    map<string, Room*> exits;
    string exitString();
    vector<Item> itemsInRoom;

public:
    int numberOfItems();
    Room(string description);
    Room(string description, std::initializer_list<Item> items);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItem(Item &inItem);
    string displayItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    void removeItem(Item item);
    vector<Item> viewItems();
    Item findItem(Item item);
    bool allItemsCollected();
    bool containsExit(string exit);
};

#endif
