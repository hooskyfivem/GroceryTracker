#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

GroceryTracker::GroceryTracker(const string& inputFilename, const string& backupFilename) {
    loadItemsFromFile(inputFilename);
    saveFrequenciesToFile(backupFilename);
}

void GroceryTracker::loadItemsFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open input file: " << filename << endl;
        exit(1);
    }

    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void GroceryTracker::saveFrequenciesToFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error: Could not write to output file: " << filename << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

int GroceryTracker::getItemFrequency(const string& item) const {
    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        return it -> second;
    } else {
        return 0;
    }
}

void GroceryTracker::printAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        cout << setw(15) << left << pair.first << pair.second << endl;
    }
}

void GroceryTracker::printHistogram() const {
    for (const auto& pair : itemFrequency) {
        cout << setw(15) << left << pair.first << string(pair.second, '*') << endl;
    }
}