#include "gameException.h"
#include "item.h"
#include "character.h"
#include <iostream>

template<typename MessageT>
void gameException<MessageT>::demonstrateMultipleInheritance() {
    // Accessing methods inherited from the Item class
    Item bathrobe("Victim's Bathrobe", "Smells like fish.", 1, 50.0);
    std::cout << "Item description: " << bathrobe.getShortDescription() << std::endl;
    std::cout << "Item weight: " << bathrobe.getWeight() << " grams" << std::endl;

    // Accessing methods inherited from the Character class
    Character character("Detective's Assistant Intern");
    character.addItem("Comically large glasses");
    Item glasses("Comically large glasses", "A pair of large, comedic glasses", 1, 0.5);
    std::vector<Item> items = character.viewItems();
    std::cout << "Character's items: ";
    for (const auto& item : items) {
        std::cout << character.longDescription() << ", ";
    }
    std::cout << std::endl;
}

template class gameException<std::string>;
