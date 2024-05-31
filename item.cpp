#include "item.h"

Item::Item(string description, string longDescription, int weightGrams)
{
    this->description = description;
    this->longDescription = longDescription;
    this->weight.intValue = weightGrams;
}

Item::Item(string description)
{
    this->description = description;
    this->longDescription = "No long description provided";
    this->weight.intValue = 1; // Default weight
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
    if (inWeightGrams > 9999.99 || inWeightGrams < 0)
        std::cout << "Weight invalid, must be 0 < Weight < 9999.99" ;
    else
        weight.floatValue = inWeightGrams;
}

int Item::getWeight() const
{   const int wt = weight.intValue;
    return wt;
}

float Item::getWeightfloat() const
{   const float wt = weight.floatValue;
    return wt;
}

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + "\n Description: " + longDescription + ".\n";
}
