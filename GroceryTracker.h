#pragma once
#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H
#include <map>
#include <string>
using namespace std;

class GroceryTracker {
private:
    map<string, int> groceryItemMap;

public:
    GroceryTracker();

//setters
    void setGroceryItemMap(map<string, int> groceryItemMap);

//getters
    map<string, int> getGroceryItemMap();
//reads frequency file and initializes groceryItemMap
    void initializeItemMap();
    void printMainMenuOptions();
    void itemSearch(map<string, int> t_groceryItemMap);
    void printItemFrequency(map<string, int> t_groceryItemMap);
    void printItemHistogram(map<string, int> t_groceryItemMap);

};
#endif // GROCERY_TRACKER_H