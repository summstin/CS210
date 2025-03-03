#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>

#include "GroceryTracker.h"
#include <vector>

using namespace std;

GroceryTracker::GroceryTracker() {

}

void GroceryTracker::setGroceryItemMap(map<string, int> t_groceryItemMap) {
    this->groceryItemMap = t_groceryItemMap;
}

map<string, int> GroceryTracker::getGroceryItemMap() {
    return this->groceryItemMap;
}

void GroceryTracker::initializeItemMap() {
// creates list of grocery items
    std::vector<std::string> groceryList = {
        "Milk"
        ,"Eggs"
        ,"Bread"
        ,"Cheese"
        ,"Apples"
        ,"Chicken"
        ,"Pasta"
        ,"Tomatoes"
        ,"Apples"
        ,"Zucchini"
        ,"Cranberries"
        ,"Zucchini"
        ,"Garlic"
        ,"Broccoli"
        ,"Garlic"
        ,"Onions"
        ,"Spinach"
        ,"Cucumbers"
        ,"Cucumbers"
        ,"Garlic"
        ,"Spinach"
        ,"Peaches"
        ,"Cucumbers"
        ,"Broccoli"
        ,"Zucchini"
        ,"Peas"
        ,"Celery"
        ,"Cucumbers"
        ,"Celery"
        ,"Yams"
        ,"Garlic"
        ,"Cucumbers"
        ,"Peas"
        ,"Beets"
        ,"Beets"
        ,"Yams"
        ,"Peas"
        ,"Apples"
        ,"Peaches"
        ,"Garlic"
        ,"Celery"
        ,"Garlic"
    };

    std::ofstream outputFile("frequency.dat");
// writes to file
    if (outputFile.is_open()) {
        for (const std::string& item : groceryList) {
            outputFile << item << std::endl;
        }
        outputFile.close();
        std::cout << "Grocery items saved to frequency.dat" << std::endl;
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }
// reads file
    std::ifstream file("frequency.dat"); 

    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string itemName;
    while (file >> itemName) {
        if (file.fail()) {
            std::cerr << "Error: Failed to read from file." << std::endl;
            return;
        }
        this->groceryItemMap[itemName]++; // maps content into class
    }

    if (file.bad()) {
        std::cerr << "Error: An I/O error occurred while reading the file." << std::endl;
        return;
    }

    file.close();

}

// searches specific item from map
void GroceryTracker::itemSearch(map<string, int> t_groceryItemMap) {
    std::string inputString;
    std::cout << "Search an item: ";
    std::cin >> inputString;

    if (t_groceryItemMap.count(inputString) > 0) {
        std::cout << t_groceryItemMap[inputString] << " " << inputString << "(s)" << std::endl;
    }
    else {
        std::cout << "Item not found." << std::endl;
    }
}

void GroceryTracker::printItemFrequency(map<string, int> t_groceryItemMap) {
// Display the map content with numbers
    std::cout << "Item List:" << std::endl;
    for (const auto& pair : this->getGroceryItemMap()) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

void GroceryTracker::printItemHistogram(map<string, int> t_groceryItemMap) {
// Display the map content with asterisks
    std::cout << "Item List:" << std::endl; 
    for (const auto& pair : this->getGroceryItemMap()) {
        std::cout << pair.first << " -> " << std::string(pair.second, '*') << std::endl;
    }
}

// Main menu options function
void GroceryTracker::printMainMenuOptions() {
    int userChoice = 0;

    while (true) {
        std::cout << "\nGrocery Tracker:" << std::endl;
        std::cout << "************************************" << std::endl;
        std::cout << "*      1-Item Input                *" << std::endl;
        std::cout << "*      2-Item Purchase Frequency   *" << std::endl;
        std::cout << "*      3-Item Purchase Histogram   *" << std::endl;
        std::cout << "*      4-Exit                      *" << std::endl;
        std::cout << "************************************" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> userChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1-4." << std::endl;
            continue;
        }
// branching logic for different menu options
        switch (userChoice) {
            case 1:
                itemSearch(this->getGroceryItemMap());
                break;
            case 2:
                printItemFrequency(this->getGroceryItemMap());
                break;
            case 3:
                printItemHistogram(this->getGroceryItemMap());
                break;
            case 4:
                std::cout << "Exiting Grocery Tracker..." << std::endl;
                return;
            default:

                break;
        }
    }
}



int main() {
// initilization of grocery tracker object
    auto groceryTracker = std::make_unique<GroceryTracker>();
    groceryTracker->initializeItemMap();
    groceryTracker->printMainMenuOptions();

    return 0;
}
