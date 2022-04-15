#include<iostream>
#include"NumberList.h"
using namespace std;

//Constructor
NumberList::NumberList()
{
	head = nullptr;
	cout << "Constructor be called." << endl;
}

//~Destructor
NumberList::~NumberList()
{
	Node *cur = head;
	while(cur != nullptr)
	{
		//delete the Node pointed to by head
		head = head->next; // move head to the next Node
		cur->next = nullptr; 
		delete cur; //deallocate memory
		cur = head; //make cur point to the new Node
	}
	cout << "Destructor be called." << endl;
}
		
// Insertion Operations for the linked list
void NumberList::insertAtHead(int data)
{
	Node *newNode = new Node;
	newNode->value = data;
	newNode->next = head;
	head = newNode;
}

void NumberList::insertAtEnd(int data)
{
	Node *newNode = new Node;
	newNode->value = data;
	Node *tail = head;

	newNode->next = nullptr;
	if(head == nullptr)
		head = newNode;
	else
	{
		while(tail->next != nullptr)
			tail = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

void NumberList::insertInMiddle(int data, int pos)
{
	if(pos <= 0)
	{
		cout << "Invalid Index" << endl;
		exit(EXIT_FAILURE);
	}

	//(1) If head is NULL and position is not 0. Exit
	//(2) If head is NULL and position is 0. Insert new Node as head and exit.
	Node *newNode = new Node;
	newNode->value = data;
	
	if(head==nullptr)
	{
			newNode->next = nullptr;
			head = newNode;
			exit(EXIT_SUCCESS);
	}

	//(3) If head is not NULL and position is 0. 
	// Then insert new Node to the head and exit.
	if(head != nullptr && pos == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	//(4)If not, interate until finding the Nth position or end.
	Node *cur = head;
	Node *pre = nullptr;

	int i = 1;
	while(i < pos && cur != nullptr)
	{
		pre = cur;
		cur = cur->next;
		i++;
	}
	
	newNode->next = cur;
	pre->next = newNode;

}

void NumberList::insertInOrder(int data)
{
	Node *pre;
	Node *cur;
	//Create a new Node to hold the data
	Node *newNode = new Node;
	newNode->value = data;
	newNode->next = nullptr;
	
	
	//If the list is empty, make the new Node as the head of the list
	if(head == nullptr)
	{
		head = newNode;
	}
	else if(newNode->value < head->value)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{	
		cur = head;
		pre = nullptr;

		//while(cur->value < newNode->value && cur != nullptr)
		while(cur != nullptr && cur->value < newNode->value)
		{
			pre = cur;
			cur = cur->next;
		}	
		
		pre->next = newNode;
		newNode->next = cur;
	}
	
}

// Print out data in the list
void NumberList::printList()
{
	if(head == nullptr)
	{	
		cout << "The list is empty." << endl;
		return;
	}

	Node *cur = head; // start a pointer at the beginning of the list
	while(cur != nullptr) // as long as we haven't reached the list's end
	{
		//print the value
		cout << cur->value << endl;
		//move to the next node
		cur = cur->next;
	}	
}

void NumberList::deleteAtHead()
{
	if(head == nullptr)
	{
		cout << "Cannot delete. This list is empty." << endl;
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
}


void NumberList::deleteAtEnd()
{
	//(1) The list is empty
	if(head == nullptr)
	{
		cout << "Cannot delete. The list is empty." << endl;
		return;
	}

	//(2) There is only one Node in the list
	if(head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}

	//(3) 
	Node* cur = head;
	Node* pre = nullptr;
	
	while(cur->next != nullptr)
	{
		pre = cur;
		cur = cur->next;
	}
	
	pre->next = nullptr;
	delete cur;
}

void NumberList::deleteIthNode(int i)
{
	Node* cur = head;
	Node* prev;

	int j = 1;

	if(head == nullptr)
	{
		cout << "Cannot delete. The list is empty. " << endl;
	}
	else
	{
		if(i == 1)
		{
			head = head->next;
			delete cur;
			return;
		}

		while(j != i && cur->next != nullptr)
		{
			prev = cur;
			cur = cur->next;
			j++;
		}
		
		if(j==i)
		{
			prev->next = cur->next;
			delete cur;
		}
		else
			cout << "Not enough items in list." << endl;
	}	
}

