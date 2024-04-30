#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#include "zorkul.h"

ZorkUL::ZorkUL() {
    createRooms();
    srand(time(0));
}
void ZorkUL::createRooms() {
    Room *Bedroom, *Suspect1BR, *Suspect2BR, *LivingRoom, *SubmissionRoom, *Garage;

    Bedroom = new Room("Bedroom");
        Bedroom->addItem(new Item("Coroner's Report", "Wow this report is unreadable, It's probably not relevant", 1, 11));
        Bedroom->addItem(new Item("Calling Card","A card left by the perp, mocking you. Distinct Handwriting", 2, 55));
    Suspect1BR = new Room("Suspect1BR");
        Suspect1BR->addItem(new Item("Suspect 1's Diary", "A diary that belongs to Suspect 1. Handwriting doesn't match the Calling Card", 1, 33));
    Suspect2BR = new Room("Suspect2BR");
        Suspect2BR->addItem(new Item("Suspect 2's Diary", "A diary that belongs to Suspect 2. Handwriting does match the Calling Card. This was easy", 1, 44));
    LivingRoom = new Room("LivingRoom");
        LivingRoom->addItem(new Item("Victim's Laptop", "Oh god, the victim's a Warhammer player. Maybe he had it coming", 2, 22));
    Garage = new Room("Garage");
        Garage->addItem(new Item("The Victim's Car", "This is a car that belonged to the victim. Attempting to lift it will instantly overencumber you", 9998, 66));
    SubmissionRoom = new Room("SubmissionRoom");

//             (N, E, S, W)
    Bedroom->setExits(Garage, Suspect1BR, LivingRoom, NULL);
    Suspect1BR->setExits(NULL, NULL, NULL, Bedroom);
    Suspect2BR->setExits(NULL, NULL, NULL, LivingRoom);
    LivingRoom->setExits(Bedroom, Suspect2BR, SubmissionRoom, NULL);
    SubmissionRoom->setExits(NULL, NULL, NULL, NULL);
    Garage->setExits(NULL, NULL, Bedroom, NULL);

    rooms.push_back(*Bedroom);
    rooms.push_back(*Suspect1BR);
    rooms.push_back(*Suspect2BR);
    rooms.push_back(*SubmissionRoom);
    rooms.push_back(*Garage);

    currentRoom = Bedroom;
}
string ZorkUL::printWelcome() {
    return "start \ninfo for help\n" + currentRoom->longDescription();
}
string ZorkUL::printEnd() {
    return "end";
}
string ZorkUL::printHelp() {
    return "Valid inputs are the buttons in this window. Click on the button corresponding to the action you would like to take.";
}
string ZorkUL::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());

    if (currentRoom == nullptr) {
        return "error teleporting";
    } else {
        return currentRoom->longDescription();
    }
}
string ZorkUL::map() {
    string output;
    output += "\n                       [Garage]                         ";
    output += "\n                           |                            ";
    output += "\n                           |                            ";
    output += "\n                       [Bedroom] --- [Suspect 1's Room] ";
    output += "\n                           |                            ";
    output += "\n                           |                            ";
    output += "\n                    [Living Room] --- [Suspect 2's Room]";
    output += "\n                           |                            ";
    output += "\n                           |                            ";
    output += "\n                    [Submission Room]                   ";
    return output;
}

string ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        return "You can't go that way.";
    } else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
string ZorkUL::viewItems() {
    return currentRoom->displayItems();
}
Room ZorkUL::getCurrentRoom() {
    return *currentRoom;
}
