#include <exception>
#include <string>

class gameException : public std::exception {
private:
    std::string message;

public:
    gameException(const std::string& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};//Programmer-Defined Exceptions!
