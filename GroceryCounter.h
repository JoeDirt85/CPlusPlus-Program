#ifndef GROCERYCOUNTER_H
#define GROCERYCOUNTER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//Initaliaztion of GroceryCounter class
class GroceryCounter
{
public:
	//Initaliaztion of class constructor laods and backups data
	GroceryCounter(const string& fileName);

	//initalization of getitemcounts function, used to return item counts in file
	int GetItemCounts(const string& item) const;

	//initalization of displayitemcounts function, used to return items and the amount of times they are mentioned
	void DisplayItemCounts() const;

	//initalization of displayhistogram function, used to create histogram of items
	void DisplayHistogram() const;

	//initalization of backupdata fucntion, used to backup data of item counts
	void BackupData(const string& backupFileName) const;

	//initalization of tolowercase functioin, used to take make all cases lower
	string ToLowercase(const string& text) const;

private:
	//initalization of itemcount map
	map<string, int> itemCount;

};

#endif