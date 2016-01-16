#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

//constructor
myHash::myHash() {
	for(int i = 0; i < tableSize; i++) {
		//create item struct
		hashTable[i] = new item;
		
		//initialize item values
		hashTable[i]->name = "empty";
		hashTable[i]->drink = "empty"; 
		hashTable[i]->next = NULL; 
	}
}

void myHash::printIndexItems(int index) {
	item* ptr = hashTable[index];

	if(ptr->name == "empty") {
		cout << "index " << index << " is empty!" << endl;
	}
	else {
		cout << "index " << index << " contains the following items: \n";
		while(ptr != NULL) {
			cout << "------------------------ \n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "------------------------ \n";
			ptr = ptr->next;
		}
	}
}

void myHash::printTable() {
	int num;

	for(int i = 0; i < tableSize; i++) {
		num = numIndexItems(i);
		cout << "------------------\n";
		cout << "index = " << i << endl;
		cout << hashTable[i]->name << endl;
		cout << hashTable[i]->drink << endl;
		cout << "# of items = " << num << endl;
		cout << "------------------\n";
	}
}

int myHash::numIndexItems(int index) {
	int count = 0;

	if(hashTable[index]->name == "empty")
		return count;
	else {
		count++;
		//point to beginning of list in index
		item* ptr = hashTable[index];

		//traverse list, inc count at each item
		while(ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

void myHash::addItem(string name, string drink) {
	//hash name as key
	int index = hashKey(name);

	if(hashTable[index]->name == "empty") {
		hashTable[index]->name = name;
		hashTable[index]->drink = drink;
	}
	else {
		//point to beginning of index
		item* ptr = hashTable[index];
		item* newItem = new item;
		
		//set variables
		newItem->name = name;
		newItem->drink = drink;
		newItem->next = NULL;

		//traverse list and set last item to point to newItem
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newItem;
	}
}

void myHash::findDrink(string name) {
	int index = hashKey(name);
	bool foundName = false;
	string drink;
	
	//point to first item in bucket
	item* ptr = hashTable[index];

	while(ptr != NULL) {
		if(ptr->name == name) {
			foundName = true;
			drink = ptr->drink;
		}	
		ptr = ptr->next;
	}
	if(foundName) 
		cout << "Favorite drink = " << drink << endl;
	else
		cout << name << "'s info was not found in the hash table!\n";
}

int myHash::hashKey(string key) {
	int hash = 0;
	int index;

	//hash each key
	for(int i = 0; i < key.length(); i++)
		hash += ((int) key[i] * 17);

	index = hash % tableSize;

	return index;
}

int main(int argc, char* argv[]) {
	//call constructor
	myHash hashy;
	string name = "";

	hashy.addItem("Paul", "Beer");
	hashy.addItem("Abby", "Beer");
	hashy.addItem("Kel", "Orange soda");
	hashy.addItem("Dan", "Decaf coffee");
	hashy.addItem("Queen of England", "Tea");
	hashy.addItem("Mike Meunier", "Gin and tonic");
	hashy.addItem("Anya", "Tuna juice");
	hashy.addItem("Mom", "Coffee");

	while(name != "exit") {
		cout << "Search for ";
		cin >> name;
		if(name != "exit")
			hashy.findDrink(name);
	}

	return 0;
}

