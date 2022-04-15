// inlab8.cc
//
// This is the implementation file for the ListClass object.  It contains the
// constructor and destructor

#include "inlab8.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "structs.h"

//This is the constructor for the ListClass object
ListClass::ListClass()
{
    head = NULL;
}//end of constructor

//This is the destructor for the ListClass object
ListClass::~ListClass()
{
    NodePtrType q = head;
    while (q != NULL)
    {
        head = head->next;
        q->next = NULL;
        delete q;
        q=head;
    }
}//end of destructor

//This is the function to print out records in the list
void ListClass::printList()
{
    //Place code here to check to see if the list is empty
    //if it is, print a message saying there are no items
    //in the list.
	Node* cur = head;
	if (head == NULL)
	{
		cout << "There are no items in the list" << endl;
	}
	
    //Place code here to check move from node to node, printing
    //the account number, a tab, then the balance on one line
    //with no labels.  For example
    //1114  395.67
	while (cur != NULL)
	{
		cout << cur->data.acctNum << "\t" << cur->data.balance << endl;
		cur = cur->next;
	}




}
// This function appends the record 'newData' onto the end of the linked list.
// If the list is empty, the new node is the new head of the list.
void ListClass::insertAtEnd(RecordType newData)
//      INOUT   IN
{
    NodePtrType newNode, prev;

    // Create a new node to hold the record.
    newNode = new Node;
    newNode->data = newData;
    newNode->next = NULL;

    if (head==NULL)
    {
        // The list is empty.  Make the new node the head of the list.
        head = newNode;
    }
    else
    {
        // The list is not empty, scan down to the end of the list and
        // put the new node there.
        prev = head;
        while (prev->next != NULL)
            prev = prev->next;
        prev->next = newNode;
    }
}//end of insertAtEnd function
