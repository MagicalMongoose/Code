// File:  insertInOrder.cc
//
// This is the implementation file for the method that inserts an item in
// sorted order into a list for a ListClass object.

#include "inlab8.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "structs.h"


// This function appends the record 'newData' into the sorted position of the linked list.
// If the list is empty, the new node is the new head of the list.
void ListClass::insertInOrder(RecordType newData)
//		INOUT	IN
{
	NodePtrType pre, cur;//pointers to the new node and for
										//traversing the list

	//Create a new node to hold the record.
	//Replace this with the code necessary to create a new node to hold 
	//the record.
	Node *newNode = new Node;
	newNode->data = newData;

	//Replace this with the code:
	if (head == nullptr)
	{
		newNode->next = nullptr;
		head = newNode;
	}
	

	//Replace this with the code:
	else if (newNode->data.acctNum < head->data.acctNum)//expression to check if the new acctNum is less than the head accNum)
	{
		newNode->next = head;
		head = newNode;
	}
	
	else
	{
		cur = head;
		pre = nullptr;

		while (cur != nullptr && cur->data.acctNum < newNode->data.acctNum)
		{
			pre = cur;
			cur = cur->next;
		}

		// put the new node where it belongs.
	    //Replace this with the code necessary to traverse the list and find the
	    //correct location for the new node to go.
		pre->next = newNode;
		newNode->next = cur;

		

	   //Replace this with the code necessary to insert the new node into the list
		cur = newNode;
	}
}//end of insertInOrder function

