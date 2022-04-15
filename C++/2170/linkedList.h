#ifndef NUMBERLIST_H
#define NUMBERLIST_H
class NumberList
{
	private:
		//Declaration a structure of the Nodes
		struct Node
		{
			int value;
			Node* next;
		};	
		Node *head; // List head Pointer
	public:
		//Constructor
		NumberList();

		//~Destructor
		~NumberList();
		
		//Linked List Operations
		
		// Insertion Operations for the linked list
		void insertAtHead(int);
		void insertAtEnd(int);
		void insertInMiddle(int, int);
		void insertInOrder(int);

		// Print out data in the list
		void printList();
		
		//deletion oprations for the linked list
		void deleteAtHead();
		void deleteAtEnd();
		void deleteIthNode(int);

};
#endif
