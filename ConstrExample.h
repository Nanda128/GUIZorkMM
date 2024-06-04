#ifndef CONSTR_EXAMPLE_H
#define CONSTR_EXAMPLE_H

#include <iostream>

class ConstrExample {
private:
    int* data;
    int size;

public:
    ConstrExample(int s);
    ConstrExample(const ConstrExample& other);
    ConstrExample(const ConstrExample& other, bool deepCopy);
    ConstrExample& operator=(const ConstrExample& other);
    void modifyData(int index, int value);
    static void driver();
    void display() const;
    int* getData() const { return data; }
};

#endif // CONSTR_EXAMPLE_H
