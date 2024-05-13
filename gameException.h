#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>
#include "character.h"
#include "item.h"

template<typename MessageT> //Template Classes!
class gameException : public Character, public Item, public std::exception { //Multiple Inheritance!
private:
    MessageT message;

public:
    gameException(const MessageT& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
    void demonstrateMultipleInheritance();
};

#include "gameException.h"

#endif
