#include "multipleinherit.h"
#include "character.h"
#include "item.h"
#include <iostream>

void MultipleInherit::demonstrateMultipleInheritance() {
    // Accessing methods inherited from the Character class
    Character assistant("Detective's Assistant");

    // Accessing methods inherited from the Item class
    Item bathrobe("Victim's Bathrobe", "Smells like fish.", 1, 50.0);
    std::cout << "Item description: " << bathrobe.getShortDescription() << std::endl;
    std::cout << "Item weight: " << bathrobe.getWeight() << " grams" << std::endl;
    assistant.addItem(bathrobe);

    std::vector<Item> items = assistant.viewItems();
    std::cout << "Assistant's items: ";
    for (auto& item : items) {
        std::cout << item.getLongDescription() << ", ";
    }
    std::cout << std::endl;
}
