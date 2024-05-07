#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

class gameException : public std::exception {
private:
    std::string message;

public:
    gameException(const std::string& msg) : message(msg) {}

    //Virtual Member Function
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // GAMEEXCEPTION_H
