#include "ConstrExample.h"
#include <iostream>

ConstrExample::ConstrExample(int s) : size(s), data(new int[s]) {
    for (int i = 0; i < s; ++i) {
        data[i] = i + 1; // Placeholder Values
    }
    std::cout << "Constructor called. Data initialized.\n";
}

ConstrExample::ConstrExample(const ConstrExample& other) : size(other.size) {
    data = new int[other.size];
    for (int i = 0; i < other.size; ++i) {
        data[i] = other.data[i];
    }
    std::cout << "Shallow copy constructor called.\n";
}

ConstrExample::ConstrExample(const ConstrExample& other, bool deepCopy) : size(other.size) { //Deep
    if (deepCopy) {
        data = new int[other.size];
        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "Deep copy constructor called.\n";
    } else {
        data = other.data;
        std::cout << "Shallow copy constructor called.\n";
    }
}

ConstrExample& ConstrExample::operator=(const ConstrExample& other) {
    if (this == &other) return *this;
    size = other.size;
    data = new int[other.size];
    for (int i = 0; i < other.size; ++i) {
        data[i] = other.data[i];
    }
    std::cout << "Assignment operator called.\n";
    return *this;
}


void ConstrExample::modifyData(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
        std::cout << "Data at index " << index << " modified to " << value << ".\n";
    } else {
        std::cout << "Index out of range.\n";
    }
}

void ConstrExample::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void ConstrExample::driver() {
    ConstrExample ex1(5);
    std::cout << "ex1: " << std::endl;
    ex1.display();

    ConstrExample ex2 = ex1;
    std::cout << "ex2 (shallow copy): " << std::endl;
    ex2.display();

    ex1.modifyData(2, 100);

    std::cout << "ex1 after modification: " << std::endl;
    ex1.display();
    std::cout << "ex2 after ex1 is modified (shallow copy): " << std::endl;
    ex2.display();

    ConstrExample ex3(ex1, true);
    std::cout << "ex3 (deep copy): " << std::endl;
    ex3.display();

    ex1.modifyData(3, 200);

    std::cout << "ex1 after second modification: " << std::endl;
    ex1.display();
    std::cout << "ex3 after ex1 is modified again (deep copy): " << std::endl;
    ex3.display();
}
