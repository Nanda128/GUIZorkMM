#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H

#include "character.h"
#include "item.h"
#include <iostream>

// Abstract class!

class AbstractClass:  public Character, public Item {
public:
    // Pure virtual function
    virtual void display() const = 0;
    virtual void showInfo() const {
        std::cout << "This is an abstract class." << std::endl;
    }
    virtual ~AbstractClass() {}
    void demonstrateMultipleInheritance();
};

/*Create an AbstractClass.cpp file with the following code;
 * #include <iostream>
 * #include "AbstractClass.h"
 * int main() {
 *   // AbstractClass obj;
 *    return 0;
 * }
 * This line will cause a compilation error because you can't create an instance of an abstract class
*/
#endif
