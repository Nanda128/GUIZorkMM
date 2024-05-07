#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
using namespace std;

class Command {
private:
    string commandWord;
    string secondWord;

public:
    Command(string firstWord, string secondWord);
    string getCommandWord();
    string getSecondWord();
    bool isUnknown();
    bool hasSecondWord();
    virtual void virtFunction() = 0; //Pure Virtual Function that makes it incomplete and not instantiated
    //Should make command an abstract class
};

#endif /*COMMAND_H_*/
