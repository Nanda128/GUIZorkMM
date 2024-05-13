#ifndef MULTIPLEINHERIT_H_
#define MULTIPLEINHERIT_H_

#include "character.h"
#include "item.h"
#include <vector>

class MultipleInherit : public Character, public Item {
public:
    void demonstrateMultipleInheritance();
};

#endif
