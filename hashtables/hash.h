#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class myHash {
private:
	static const int tableSize = 40;

	struct item {
		string name;
		string drink;
		item* next;
	};

	//array with TableSize amount of buckets, each containing a pointer to an item
	item* hashTable[tableSize];

public:
	//function declarations
	myHash();
	int hashKey(string key);
	void addItem(string name, string drink);
	int numIndexItems(int index);
	void printTable();
	void printIndexItems(int index);
	void findDrink(string name);
};

#endif
