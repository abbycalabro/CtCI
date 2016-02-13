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

//q1, part 2
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

//q2
int List::KthToLast(int k) {
    nodePtr kthToLast = NULL;
    curr = head;
    int numNodes = 0;
    int ans;

	if(k < 1)
		return -1;

    if(curr != NULL) {
        numNodes++;
        //start advancing curr
		while(numNodes < k && curr != NULL) {
            curr = curr->next;
            if(curr != NULL)
				numNodes++;
        }
		//start advancing kthToLast (k - 1) nodes behind curr
        kthToLast = head;
    }
    while(curr != NULL) {
		ans = kthToLast->data;
        curr = curr->next;
        kthToLast = kthToLast->next;
		if(curr != NULL)
			numNodes++;
	}
	//k too high
	if(k > numNodes)
		ans = -1;
    
	return ans;
}

List::nodePtr List::GetNode(int data) {
	curr = head;

	while(curr != NULL) {
		if(curr->data == data)
			return curr;
		else
			curr = curr->next;
	}
	//if node not found, return NULL 
	return temp;
}

//q3
void List::DeleteMiddleNode(node n) {
	curr = n;

	while(curr->next != NULL) {
		curr->data = curr->next->data;
		curr->next = curr->next->next;
		curr = curr->next;
	}
}

int main(int argc, char *argv[]) {
	List Abby;

	Abby.AddNode(1);
	Abby.AddNode(2);
	Abby.AddNode(3);
	Abby.AddNode(4);
	Abby.AddNode(5);
	Abby.AddNode(6);
	Abby.AddNode(7);
	Abby.AddNode(8);

	cout << "Before: ";
	Abby.PrintList();

	//Abby.DeleteMiddleNode();
	//Abby.PrintList();

	return 0;
}
