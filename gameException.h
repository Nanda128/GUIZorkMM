#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

template<typename MessageT>
class gameException : public std::exception {
private:
    MessageT message;

public:
    gameException(const MessageT& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // GAMEEXCEPTION_H
