//FIle: main8c.cc
//This program demonstrates simple linked list manipulation.
//It shows how to delete the third item in a list.

#include "structs.h"
#include "inlab8.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


int main(int argc, char *argv[])
{

	ListClass bankList;
	char EOLN;
	RecordType newRec;
	
	
	//Read all of the records from the file and insert them into the list.
	cin >> newRec.acctNum >> newRec.balance;
	cin.get(EOLN);
	while(cin)
	{
		bankList.insertAtEnd(newRec);
		cin >> newRec.acctNum >> newRec.balance;
		cin.get(EOLN);
	}
	
	//Output the initial list
	cout << "The initial list is: \n";	
	bankList.printList();

	//Delete the third item and then print the new list
	cout << "Trying to delete the 3rd item\n";
	bankList.deleteIthNode(3);
	cout << "The current list is:" << endl;
	bankList.printList();
	return(0);
}
