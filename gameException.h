#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>
#include "character.h"
#include "item.h"

template<typename MessageT>
class gameException : public std::exception {
private:
    MessageT message;

public:
    gameException(const MessageT& msg);

    virtual const char* what() const noexcept override;
};

#endif
