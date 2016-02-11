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
		delete delPtr;
		cout << "The value " << delData << " has been deleted.\n";
	}
}

int main() {

	return 0;
}
