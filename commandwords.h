#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_

#include "character.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CommandWords: public Item, public Character { //Multiple Inheritance!
private:
    //Define a static vector for our valid command words.
    //We'll populate this in the class constructor
    static vector<string> validCommands;

public:
    CommandWords();
    bool isCommand(string aString);
    string showAll();
    void demonstrateMultipleInheritance();
};


#endif /*COMMANDWORDS_H_*/
