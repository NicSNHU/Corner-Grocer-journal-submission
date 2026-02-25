#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

using namespace std;

//Class that tracks grocery item frequency
class ItemTracker {

private:

	//Mapping to store item and frequency
	map<string, int> itemFrequency;

public:

	//Load data from input file
	void LoadDataFromFile(string filename);

	//Create backup file
	void CreateBackupFile(string filename);

	//Returns frequency of the specific item
	int GetItemFrequency(string item);

	//Prints all item frequency
	void PrintAllFrequencies();

	//Print histogram
	void PrintHistogram();

};


#endif
