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

void myHash::removeItem(string name) {
	int index = hashKey(name);
	item* delPtr;
	item* ptr1;
	item* ptr2;

	//case 0 - bucket is empty
	if(hashTable[index]->name == "empty" && hashTable[index]->drink == "empty")
		cout << name << " was not found in the hash table!\n";
	//case 1 - only 1 item in bucket and item has matching name
	else if(hashTable[index]->name == name && hashTable[index]->next == NULL) {
		hashTable[index]->name = "empty";
		hashTable[index]->drink = "empty";
		cout << name << " was removed from the hash table. You're welcome.\n";
	}
	//case 2 - match located in first item, and bucket contains more items
	else if(hashTable[index]->name == name) {
		delPtr = hashTable[index];
		hashTable[index] = hashTable[index]->next;
		delete delPtr;
		cout << name << " was removed from the hash table. You're welcome.\n";
	}
	//case 3 - bucket contains item, and first item is not a match
	else {
		//ptr1 point to second item, ptr2 points to first item
		ptr1 = hashTable[index]->next;
		ptr2 = hashTable[index];		

		while(ptr1 != NULL && ptr1->name != name) {
			//advance pointers one item
			ptr2 = ptr1;
			ptr1 = ptr1->next;	
		}
		//no match
		if(ptr1 == NULL) 
			cout << name << " was not found in the hash table!\n";
		else {
			//point ptr1 to next item in list, ptr2
			delPtr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;
			delete delPtr;
			cout << name << " was removed from the hash table. You're welcome.\n";
		}
	}
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
	hashy.addItem("Homer", "Duff");
	hashy.addItem("Lil Wayne", "Cough syrup");

	hashy.printIndexItems(3);

	while(name != "exit") {
		cout << "Remove ";
		cin >> name;
		if(name != "exit")
			hashy.removeItem(name);
	}

	hashy.printIndexItems(3);
	
	return 0;
}

