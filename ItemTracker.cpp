#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

//Loading grocery items and count frequency
void ItemTracker::LoadDataFromFile(string filename) {
    
    ifstream inputFile;

    string item;

    inputFile.open(filename);

    if (!inputFile.is_open()) {
    
        cout << "Error opening input file." << endl;
        return;
    }

    //Read each item and the count
    while (inputFile >> item) {
        
        itemFrequency[item]++;
    }

    inputFile.close();
}

//Creating backup frequency file

void ItemTracker::CreateBackupFile(string filename) {
    
    ofstream outputFile;

    outputFile.open(filename);

    for (auto& pair : itemFrequency) {
        
        outputFile << pair.first << " " << pair.second << endl;
    
    }

    outputFile.close();

}

//Return frequency of requested item

int ItemTracker::GetItemFrequency(string item) {

    //Ensure no empty strings,  accounts for non capitals
    if (!item.empty()) {
        item[0] = toupper(item[0]);
    }

    //Check if item exists in map
    if (itemFrequency.count(item)) {
    
        return itemFrequency[item];
    }

    return 0;
}


//Print all frequencies
void ItemTracker::PrintAllFrequencies() {

    for (auto& pair : itemFrequency) {
    
        cout << pair.first << " " << pair.second << endl;
    }
}

//Print histogram
void ItemTracker::PrintHistogram() {
    
    for (auto& pair : itemFrequency) {
    
        cout << pair.first << " ";

        for (int i = 0; i < pair.second; i++) {
        
            cout << "*";
        }

        cout << endl;
    }

}