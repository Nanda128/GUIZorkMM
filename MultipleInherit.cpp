#include "multipleinherit.h"
#include "character.h"
#include "item.h"
#include <iostream>

void MultipleInherit::demonstrateMultipleInheritance() {
    // Accessing methods inherited from the Character class
    Character assistant("Detective's Assistant");

    // Accessing methods inherited from the Item class
    Item heirloom("Family Heirloom", "A taxidermized haddock. Its been passed through several generations. Smells like it.", 1);
    std::cout << "Item description: " << heirloom.getShortDescription() << std::endl;
    std::cout << "Item weight: " << heirloom.getWeight() << " grams" << std::endl;
    assistant.addItem(heirloom);

    std::vector<Item> items = assistant.viewItems();
    std::cout << "Assistant's items: ";
    for (auto& item : items) {
        std::cout << item.getLongDescription() << ", ";
    }
    std::cout << std::endl;
}
