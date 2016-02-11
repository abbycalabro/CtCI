#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::AddNode(int addData) {
	//add node to end of list
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	//if existing list, iterate through list
	//else new node is head
	if(head != NULL) {
		curr = head;
		while(curr->next != NULL) 
			curr = curr->next;	
		curr->next = n;	
	}
	else
		head = n;
}

void List::DeleteNode(int delData) {
	nodePtr delPtr = NULL;
	temp = head; //trailing ptr
	curr = head;

	while(curr != NULL && curr->data != delData) {
		//advance two ptrs until end of list or delData found
		temp = curr;
		curr = curr->next;
	}
	if(curr == NULL) {
		cout << delData << " was not in the list.\n";
		delete delPtr;
	}
	//delete node containing delData
	else {
		//patch hole in list
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if(delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " has been deleted.\n";
	}
}

//q1
void List::DeleteDups(int dupData) {
	bool found = false;
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while(curr != NULL) {
		if(curr->data != dupData) {
			temp = curr;
			curr = curr->next;
		}
		//dupData found
		else {
			//first occurrence of dupData
			if(!found) {
				found = true;
				temp = curr;
				curr = curr->next;
			}
			//delete node
			else {
				cout << found << endl;
				delPtr = curr;
				curr = curr->next;
				temp->next = curr;
				cout << "Duplicate value " << dupData << " was deleted.\n";
			}
		}
	}
	delete delPtr;
}

void List::DeleteAllDups() {
	int hash[128];
	int asciiVal;
	nodePtr delPtr;
	curr = head;
	temp = head;

	//set hash table vals to 0 
	for(int i = 0; i < sizeof(hash) / sizeof(int); i++) 
		hash[i] = 0;

	while(curr != NULL) {
		asciiVal = int(curr->data);
		if(hash[asciiVal] == 0) {
			//first occurrence of dup
			hash[asciiVal]++;
			//advance ptrs
			temp = curr;
			curr = curr->next;
		}
		else {
			//delete dup node
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;			
			cout << "Node with dup value " << delPtr->data << " was deleted\n";			
		}
	}
	delete delPtr;
}

void List::PrintList() {
	curr = head;
	while(curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}

int main(int argc, char *argv[]) {
	List Abby;

	Abby.AddNode(3);
	Abby.AddNode(3);
	Abby.AddNode(7);
	Abby.AddNode(5);
	Abby.AddNode(7);
	Abby.AddNode(7);
	Abby.PrintList();

	Abby.DeleteAllDups();
	Abby.PrintList();

	return 0;
}
