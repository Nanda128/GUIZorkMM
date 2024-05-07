#include "item.h"

Item::Item(string description, string longDescription, int weightGrams, float value)
{
    this->description = description;
    this->longDescription = longDescription;
    this->weight.intValue = weightGrams;
    this->value = value;
}

Item::Item(string description)
{
    this->description = description;
    this->longDescription = "No long description provided";
    this->weight.intValue = 1; // Default weight
    this->value = 1;
}

bool Item::operator==(Item &i)
{
    int test = 0;

    if (this->getShortDescription() == i.getShortDescription())
    {
        test = 1;
    }

    return test;
} //Operator Overloading!

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
    {
        std::cout << "Weight invalid, must be 0 < Weight < 9999." ;
    } else {
        weight.intValue = inWeightGrams;
    }
}

void Item::setWeight(float inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
        std::cout << "Weight invalid, must be 0 < Weight < 9999." ;
    else
        weight.floatValue = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "Value invalid, must be 0 < Value < 9999." ;
    else
       value = inValue;
}

int Item::getWeight()
{
    return weight.intValue;
}

float Item::getWeightfloat()
{
    return weight.floatValue;
}

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + "\n Description: " + longDescription + ".\n";
}
