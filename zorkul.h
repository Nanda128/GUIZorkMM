#ifndef ZORKUL_H_
#warning "Boo!"
#define ZORKUL_H_

#include "room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ZorkUL {
private:
    Room *currentRoom;
    vector<Room> rooms;
    vector<Room*> Rooms;
    void createRooms();
    void createItems();
    void displayItems();

public:
    ZorkUL();
    ~ZorkUL();
    void play();
    string printWelcome();
    string printHelp();
    string printEnd();
    string go(string direction);
    string teleport();
    string map();
    string viewCharacterInfo();
    string viewItems();
    Room getCurrentRoom();
};

#endif
