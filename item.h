#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

union Weight {
    int intValue;
    float floatValue;
};//Unions!

class Item{
private:
    string description;
    string longDescription;
    Weight weight;

public:
    Item();
    Item(string description, string longDescription, int weightGrams);
    Item(string description);
    string getShortDescription();
    bool operator==(Item &i);
    string getLongDescription();
    int getWeight();
    float getWeightfloat();
    void setWeight(int inWeightGrams);
    void setWeight(float inWeightGrams);
    Item(string description, int weight) {
        this->description = description;
        this->weight.intValue = weight;
    }

    Item(string description, float weight) {
        this->description = description;
        this->weight.floatValue = weight;
    }
};

#endif
