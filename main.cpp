#include <iostream>
#include <limits>
#include "ItemTracker.h"

using namespace std;

//Display meny
void DisplayMenu() {
    
    cout << endl;
    cout << "Corner Grocer Menu" << endl;
    cout << "-------------------" << endl;

    cout << "1. Search Item Frequency" << endl;

    cout << "2. Print All Frequencies" << endl;

    cout << "3. Print Histogram" << endl;

    cout << "4. Exit" << endl;

    cout << "Enter Choice: ";
}

int main() {
    
    ItemTracker tracker;

    int choice = 0;

    string item;

    //Load the data and create backup automatically
    tracker.LoadDataFromFile("CS210_Project_Three_Input_File.txt");

    tracker.CreateBackupFile("frequency.dat");

    while (choice != 4) {
    
        DisplayMenu();

        cin >> choice;

        //Input validation
        if (cin.fail()) {
           
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "invalid input." << endl;

            continue;
        }

        switch (choice) {
        
        case 1:

            cout << "Enter item name: ";

            cin >> item;

            cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times." << endl;
            
            break;
        

        case 2:

            tracker.PrintAllFrequencies();

            break;

        case 3:

            tracker.PrintHistogram();

            break;

        default:

            cout << "invalid choice." << endl;

        }

    }

    return 0;

}