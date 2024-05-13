#include "character.h"
#include <string>

Character::Character(string description)
{
    itemsInCharacter.empty(); //Clear Char's Inventory before doing anything
    this->description = description;
    stamina = 10;
}

void Character::addItem(Item *item)
{
    itemsInCharacter.push_back(*item);
    carriedWeight += item->getWeight();
}

void Character::addItem(Item &item)
{
    itemsInCharacter.push_back(item);
    carriedWeight += item.getWeight();
}

vector<Item> Character::viewItems()
{
    return itemsInCharacter;
}

string Character::shortDescription()
{
    return this->description;
}

//Lists out all items held by the character and shows their longDescription
string Character::longDescription()
{
    string output = "";

    if (itemsInCharacter.empty())
    {
        output += "\nYou are carrying no items.";
    }
    else
    {
        output += "\nItem List:\n";

        for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        {
            output += "\t" + (*i).getLongDescription() + "\n";
        }
    }

    return output;
}

//Find all items held by the character
Item Character::findItem(Item item)
{
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++)
    {
        if (itemsInCharacter[i] == item)
        {
            return itemsInCharacter[i];
        }
    }
    //No return statement here because it is intended to send a null result if char has no items in inv
}

//Find all items in the room
int Character::findItemPos(Item item)
{
    for (unsigned int i = 0; i < (unsigned int)itemsInCharacter.size(); i++)
    {
        if (itemsInCharacter[i] == item)
        {
            return i;
        }
    }
    //Same as findItem. Will return NULL.
}

//Shows all the items held by the character.
string Character::viewCharacterInfo()
{
    string output = "";
    output += longDescription();
    output += "\nCarried Weight: " + to_string(carriedWeight) + "g.";
    return output;
}

void Character::removeItem(Item item) {
    itemsInCharacter.erase(itemsInCharacter.begin() + findItemPos(item));
}

// maxWeight = 10.0g
// Checks if weight of all held items > max weight
// Test this out by going to Garage and taking the victim's car
bool Character::isOverencumbered(float maxWeight)
{
    if (carriedWeight > maxWeight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Character::getStamina()
{
    return stamina;
}

void Character::setStamina(int stamina)
{
    this->stamina = stamina;
}

//Total stamina = 10
//Decrease stamina by 1 for every room traversed.
void Character::decrementStamina()
{
    stamina--;

    if (stamina < 0)
    {
        setStamina(10);
    }
}
