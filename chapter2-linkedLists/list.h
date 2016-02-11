#ifndef LIST_H
#define LIST_H

class List{
	private:
		typedef struct node {
			int data;
			node *next;	
		} *nodePtr;

		nodePtr head;
		nodePtr curr;
		nodePtr temp;

	//public funcs to access private data
	public:
		List();  //constructor
		void AddNode(int addData);
		void DeleteNode(int delData);
		void DeleteDups(int dupData);
		void DeleteAllDups();
		void PrintList();
};

#endif
