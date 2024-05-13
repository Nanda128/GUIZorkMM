#include "gameException.h"
#include <iostream>

template<typename MessageT>
gameException<MessageT>::gameException(const MessageT& msg) :  message(msg) {}

template<typename MessageT>
const char* gameException<MessageT>::what() const noexcept {
    return message.c_str();
}

template class gameException<std::string>;
