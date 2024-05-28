#ifndef MULTIPLEINHERIT_H_
#define MULTIPLEINHERIT_H_

#include "character.h"
#include "item.h"

class MultipleInherit : public Character, public Item {
public:
    MultipleInherit(string characterDescription, string itemDescription, string itemLongDescription, int itemWeightGrams) :
    Character(characterDescription),
    Item(itemDescription, itemLongDescription, itemWeightGrams) {}
    void demonstrateMultipleInheritance();
};

#endif
