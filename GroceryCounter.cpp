#include "GroceryCounter.h"


//defines class constructor
GroceryCounter::GroceryCounter(const string& fileName) {
	ifstream inputFile(fileName);
	string item;

	if (inputFile.is_open()) { //checks if file is .txt file is open
		while (getline(inputFile, item)) {//gets next line in file
			if (!item.empty()) { //checks if line isn't empty
				++itemCount[ToLowercase(item)]; //if line isnt empty adds to item count and calls function to lower the case
			}
		}
		inputFile.close(); //closes file if line is empty
	}
	//display error message if file cannot be opened
	else {
		cout << "ERROR: file " << fileName << " was unable to open." << endl;
	}
	BackupData("counts.dat"); //creates backup file 
}

//defines function that counts item frequency
int GroceryCounter::GetItemCounts(const string& item) const {
	auto count = itemCount.find(item); //goes through .txt to find item
	if (count != itemCount.end()) { //checks if at the end map
		return count->second; //if at end, returns item count number
	}
	return 0;
}

//defines fucntion to display item counts
void GroceryCounter::DisplayItemCounts() const {
	for (const auto& pair : itemCount) {
		cout << pair.first << " " << pair.second << endl; //loop that prints the pair of items and counts
	}
}


//defines function to print a histogram of the items
void GroceryCounter::DisplayHistogram() const {
	for (const auto& pair : itemCount) { // loop that goes through itemcount map and prints itemname
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) { //nested loop that prints asteric for frequency of items in map
			cout << "*";
		}
		cout << endl;
	}
}

//defines function to convert all cases to lower case
string GroceryCounter::ToLowercase(const string& text) const {
	string result = text;
	for (size_t i = 0; i < result.length(); ++i) {
		// Convert uppercase letters (A–Z) to lowercase (a–z)
		if (result[i] >= 'A' && result[i] <= 'Z') {
			result[i] = result[i] + 32;
		}
	}
	return result; //returns lowercased string
}

//defines function to backup data of item counts
void GroceryCounter::BackupData(const string& backupFileName) const {
	ofstream outputFile(backupFileName); //opens outputfile  
	if (outputFile.is_open()) { //checks if file is open
		for (const auto& pair : itemCount) {
			outputFile << pair.first << " " << pair.second << endl; //if open outputs pair data from itemcount
		}
		outputFile.close(); //closes output file when done
	}
	else { //prints error message if output file cannot be opened
		cout << "ERROR: backup file " << backupFileName << " was unable to be created" << endl;
	}
}