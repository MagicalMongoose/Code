// File:  deleteIthNode.cc
//
// This is the implementation file for the method that deletes the ith item
// from a list of a ListClass object

#include "inlab8.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "structs.h"


//Function to delete the ith node from the list
//  If there are fewer than i nodes in the list, an error is returned.
void ListClass::deleteIthNode(int i)
{
	NodePtrType q = head; //q will point to the item to delete
	NodePtrType prev;     //prev will point to the item before q	
	int j = 1;            //j will keep count of which node in the list
                          //    we are currently on                   

	if (head == NULL)
	{	cout<<"Not enough items in list\n";}
	else
	{
		//Traverse the list to find the ith item
		//Replace this with a while loop that will traverse
		//the list until either j == i or the end of the list
		//is encountered.
		while (j != i && q->next != NULL)
		{
			prev = q;
			q = q->next;
			j++;
		}
		
		//If there are i items in the list, delete the ith one
		//Replace this with the if part of an if-else statement.
		//The if part should delete the ith item if there is an
		//ith item.
		if(j == i)
		{
			prev->next = q->next;
			delete q;
		}
		else
		{	cout<<"Not enough items in list\n";}
	}
}//end of deleteIthNode

